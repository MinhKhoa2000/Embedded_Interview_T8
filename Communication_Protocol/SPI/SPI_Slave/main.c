#include "stm32f10x.h"
#include "stm32f10x_rcc.h"

#define SCK		GPIO_Pin_6
#define MOSI 	GPIO_Pin_7
#define SS		GPIO_Pin_8

void spi_Slave_Init();
uint8_t receive_Data();
void wait_To_Receive();
void receive_Array(uint8_t *data, uint8_t size, uint8_t dataBegin);

uint8_t data[10] = {0};

int main()
{
	uint8_t size = 10;
	uint8_t dataBegin = 1;
	
	spi_Slave_Init();
	
	while(1) {
		receive_Array(data, size, dataBegin);
	}
	
	return 0;
}

void spi_Slave_Init()
{	
	GPIO_InitTypeDef gpio_Spi;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	gpio_Spi.GPIO_Pin = SCK | MOSI;
	gpio_Spi.GPIO_Mode = GPIO_Mode_IPD;
	gpio_Spi.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &gpio_Spi);
	
	gpio_Spi.GPIO_Pin = SS;
	gpio_Spi.GPIO_Mode = GPIO_Mode_IPU;
	gpio_Spi.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &gpio_Spi);
}

uint8_t receive_Data()
{
	uint8_t data = 0;
	
	wait_To_Receive();
	
	for (uint8_t i = 0; i < 8; i++) {
		while (GPIO_ReadInputDataBit(GPIOB, SCK) == 0) {}
		if (GPIO_ReadInputDataBit(GPIOB, MOSI) == 1) data = data | (0x80 >> i);
		while (GPIO_ReadInputDataBit(GPIOB, SCK) == 1) {}
	}
	
	return data;
}

void receive_Array(uint8_t *data, uint8_t size, uint8_t dataBegin)
{
	int i = 0;
	while (i < size) {
		data[i] = receive_Data();
		
		if (i == 0 && data[i] != dataBegin) continue;
		else i++;
	}
}

void wait_To_Receive() {
	while (GPIO_ReadInputDataBit(GPIOB, SS) == 0) {}
	while (GPIO_ReadInputDataBit(GPIOB, SS) == 1) {}
}