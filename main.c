#include "stm32f4xx_conf.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"
#include "misc.h"
#include "stm32f4xx_spi.h"


#include "SPI.h"
#include "przyciski.h"
#include "debouncer.h"
#include "ff.h"
#include "diskio.h"

int main(void)
{
	SystemInit();
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);


	Konfiguracja_SPI();
	Konfiguracja_przyciskow();
	Konfiguracja_debouncera();





	FRESULT fresult;
	 FIL plik;
	 WORD zapisanych_bajtow;
	 FATFS fatfs;



	 disk_initialize(0);// inicjalizacja karty
	 	fresult = f_mount( &fatfs, 1,1 );// zarejestrowanie dysku logicznego w systemie


	  // Tworzenie pliku
	  fresult = f_open (&plik,"xdd.txt", FA_CREATE_ALWAYS);
	  fresult = f_close (&plik);

	  // Tworzenie katalogu

	  fresult = f_mkdir("aaaaaa");







	  	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	  	GPIO_InitTypeDef diody;

	  	diody.GPIO_Pin = GPIO_Pin_12;
	  	diody.GPIO_Mode = GPIO_Mode_OUT;
	  	diody.GPIO_OType = GPIO_OType_PP;
	  	diody.GPIO_Speed = GPIO_Speed_100MHz;
	  	diody.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  	GPIO_Init(GPIOD, &diody);





		//







	  while(1)
	      {


	      }
}

void EXTI1_IRQHandler ( void ){

	if (EXTI_GetITStatus(EXTI_Line1) != RESET){

		TIM_Cmd(TIM3, ENABLE);
	}
}

void EXTI2_IRQHandler ( void ){

	if (EXTI_GetITStatus(EXTI_Line2) != RESET){

		TIM_Cmd(TIM3, ENABLE);
	}
}

void EXTI3_IRQHandler ( void ){

	if (EXTI_GetITStatus(EXTI_Line3) != RESET){

		TIM_Cmd(TIM3, ENABLE);
	}
}

void EXTI4_IRQHandler ( void ){

	if (EXTI_GetITStatus(EXTI_Line4) != RESET){

		TIM_Cmd(TIM3, ENABLE);
	}
}

void EXTI9_5_IRQHandler ( void ){

	if (EXTI_GetITStatus(EXTI_Line5) |
		EXTI_GetITStatus(EXTI_Line6) |
		EXTI_GetITStatus(EXTI_Line7) |
		EXTI_GetITStatus(EXTI_Line8) |
		EXTI_GetITStatus(EXTI_Line9) != RESET){

		TIM_Cmd(TIM3, ENABLE);
	}
}

void TIM3_IRQHandler ( void ){

	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET){

		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)){

			GPIO_ToggleBits(GPIOD, GPIO_Pin_12);

			TIM_Cmd(TIM3, DISABLE);
			TIM3->CNT = 0;
		}

		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2)){

			GPIO_ToggleBits(GPIOD, GPIO_Pin_12);

			TIM_Cmd(TIM3, DISABLE);
			TIM3->CNT = 0;
		}

		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3)){

			GPIO_ToggleBits(GPIOD, GPIO_Pin_12);

			TIM_Cmd(TIM3, DISABLE);
			TIM3->CNT = 0;
		}

		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4)){

			GPIO_ToggleBits(GPIOD, GPIO_Pin_12);

			TIM_Cmd(TIM3, DISABLE);
			TIM3->CNT = 0;
		}

		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5)){

			GPIO_ToggleBits(GPIOD, GPIO_Pin_12);

			TIM_Cmd(TIM3, DISABLE);
			TIM3->CNT = 0;
		}

		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6)){

			GPIO_ToggleBits(GPIOD, GPIO_Pin_12);

			TIM_Cmd(TIM3, DISABLE);
			TIM3->CNT = 0;
		}

		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)){

			GPIO_ToggleBits(GPIOD, GPIO_Pin_12);

			TIM_Cmd(TIM3, DISABLE);
			TIM3->CNT = 0;
		}

		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8)){

			GPIO_ToggleBits(GPIOD, GPIO_Pin_12);

			TIM_Cmd(TIM3, DISABLE);
			TIM3->CNT = 0;
		}

		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9)){

			GPIO_ToggleBits(GPIOD, GPIO_Pin_12);

			TIM_Cmd(TIM3, DISABLE);
			TIM3->CNT = 0;
		}

		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		EXTI_ClearITPendingBit(EXTI_Line1);
		EXTI_ClearITPendingBit(EXTI_Line2);
		EXTI_ClearITPendingBit(EXTI_Line3);
		EXTI_ClearITPendingBit(EXTI_Line4);
		EXTI_ClearITPendingBit(EXTI_Line5);
		EXTI_ClearITPendingBit(EXTI_Line6);
		EXTI_ClearITPendingBit(EXTI_Line7);
		EXTI_ClearITPendingBit(EXTI_Line8);
		EXTI_ClearITPendingBit(EXTI_Line9);
	}
}

