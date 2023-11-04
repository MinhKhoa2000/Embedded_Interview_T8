#include "stm32f10x.h"
#include "stm32f10x_rcc.h"

#define SCK		GPIO_Pin_6
#define MOSI 	GPIO_Pin_7
#define SS		GPIO_Pin_8

void spi_Master_Init();
void transmit_Data(uint8_t data);
void on_SS();
void off_SS();
void clock();

int main()
{
	uint8_t data[10] = {1,2,3,4,5,6,7,8,9,10};
	
	spi_Master_Init();
	
	while(1) {
		for (uint8_t i = 0; i < 10; i++) {
			transmit_Data(data[i]);
			for (int i = 0; i < 1000; i++);
		}
	}
	
	return 0;
}

void spi_Master_Init()
{
	GPIO_InitTypeDef gpio_Spi;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	gpio_Spi.GPIO_Pin = SCK | MOSI | SS;
	gpio_Spi.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_Spi.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &gpio_Spi);
	
	GPIO_ResetBits(GPIOB, SCK);
	GPIO_ResetBits(GPIOB, MOSI);
	GPIO_SetBits(GPIOB, SS);
}

void transmit_Data(uint8_t data)
{
	on_SS();
	
	for (uint8_t i = 0; i < 8; i++) {
		if ((data & (0x80 >> i)) == 0) GPIO_ResetBits(GPIOB, MOSI);
		else GPIO_SetBits(GPIOB, MOSI);
		clock();
	}
	
	off_SS();
}

void on_SS() {
	GPIO_ResetBits(GPIOB, SS);
}

void off_SS() {
	GPIO_SetBits(GPIOB, SS);
}

void clock() {
	for (int i = 0; i < 10000; i++) {}
	GPIO_SetBits(GPIOB, SCK);
		
	for (int i = 0; i < 10000; i++) {}
	GPIO_ResetBits(GPIOB, SCK);
}