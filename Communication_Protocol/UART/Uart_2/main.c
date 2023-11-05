#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "delay.h"

#define Rx GPIO_Pin_6

void			config_Pin();
void			find_Start_Bit();
void			wait_Start_Bit();
uint8_t		receive_Data();
void			receive_Array(uint8_t *data, uint8_t size, uint8_t dataBegin);

uint8_t data[10] = {0};

int main()
{
	config_Pin();
	TIM2_INT_Init();
	
	find_Start_Bit();
	
	while(1) {
		receive_Array(data, 10, 1);
	}
	
	return 0;
}

void config_Pin()
{	
	GPIO_InitTypeDef gpio_Pin;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	gpio_Pin.GPIO_Pin = Rx;
	gpio_Pin.GPIO_Mode = GPIO_Mode_IPU;
	gpio_Pin.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &gpio_Pin);
}

void find_Start_Bit() {
	while (GPIO_ReadInputDataBit(GPIOB, Rx) == 1);
	while (GPIO_ReadInputDataBit(GPIOB, Rx) == 0);
	
	while(1) {
		delayMs(95); // 8 'bit data' + 1 'bit parity' + 0,5 'bit stop 1' = 9,5 bit * 10ms = 95
		
		// middle of stop bit 1
		if (GPIO_ReadInputDataBit(GPIOB, Rx) == 0) {
			delayMs(5);
			continue;
		}
		
		delayMs(10);
		// middle of stop bit 2
		if (GPIO_ReadInputDataBit(GPIOB, Rx) == 0) {
			delayMs(5);
			continue;
		}
		
		// stop bit 1 = 1
		// stop bit 2 = 1
		break;
	}
}

void wait_Start_Bit() {
	while (GPIO_ReadInputDataBit(GPIOB, Rx) == 1);
	delayMs(15);
}

uint8_t receive_Data()
{
	uint8_t data = 0;
	uint8_t count = 0;
	
	wait_Start_Bit();
	
	for (int i = 0; i < 9; i++) {
		if (GPIO_ReadInputDataBit(GPIOB, Rx) == 1) {
			data |= (0x100 >> i);
			count++;
		}
		
		delayMs(10);
	}
	
	if (count % 2 != 0) data = 0;
	
	data = data >> 1;
	
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