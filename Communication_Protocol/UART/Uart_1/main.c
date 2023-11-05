#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "delay.h"

#define Tx				GPIO_Pin_6

void config_Pin();
void transmit_Data_Frame(uint8_t data);
void transmit_Start_Bit();
void transmit_Data_Bit(uint8_t data);
void transmit_Parity_Bit(uint8_t count);
void transmit_Stop_Bit();
void transmit_Array(uint8_t *data_Array, uint8_t size_Of_Array);

int main()
{
	config_Pin();
	TIM2_INT_Init();
	
	uint8_t data[10] = {1,2,3,4,5,6,7,8,9,10};
	uint8_t size = sizeof(data);
	
	while(1) {
		transmit_Array(data, size);
	}
	
	return 0;
}

void config_Pin()
{
	GPIO_InitTypeDef gpio_Pin;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);
	
	gpio_Pin.GPIO_Pin = Tx;
	gpio_Pin.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_Pin.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &gpio_Pin);
	
	GPIO_SetBits(GPIOB, Tx);
}

void transmit_Data_Frame(uint8_t data)
{
	transmit_Start_Bit();
	transmit_Data_Bit(data);
	transmit_Stop_Bit();
}

void transmit_Start_Bit() {
	GPIO_ResetBits(GPIOB, Tx);
	delayMs(10);
}

void transmit_Data_Bit(uint8_t data)
{
	uint8_t count = 0;
	
	for (int i = 0; i < 8; i++) {
		if (data & (0x80 >> i)) {
			GPIO_SetBits(GPIOB, Tx);
			count++;
		}
		else GPIO_ResetBits(GPIOB, Tx);
		
		delayMs(10);
	}
	
	transmit_Parity_Bit(count);
}

void transmit_Parity_Bit(uint8_t count)
{
	if (count % 2 == 0) GPIO_ResetBits(GPIOB, Tx);
	else GPIO_SetBits(GPIOB, Tx);
	
	delayMs(10);
}

void transmit_Stop_Bit() {
	GPIO_SetBits(GPIOB, Tx);
	delayMs(20);
}

void transmit_Array(uint8_t *data, uint8_t size) {
	for (int i = 0; i < size; i++) {
		transmit_Data_Frame(data[i]);
		delayMs(50);
	}
}