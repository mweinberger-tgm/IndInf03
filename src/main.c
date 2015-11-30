/**
  ******************************************************************************
  * @file    main.c
  * @author  Michael Weinberger
  * @version 1.0
  * @date    20.11.2015
  * @brief   Hauptklasse
  ******************************************************************************
*/

#include "ampel.h"
#include "control.h"
#include "stm32f3xx.h"
#include "stm32f3_discovery.h"

ampelparameter repr;
ampelparameter* val = &repr;

void EXTI0_Config();
void HAL_GPIO_EXTI_Callback(uint16_t);
void HAL_SYSTICK_Callback(void);

int main(void)	{
	SystemInit();
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000);
	led_init();

	EXTI0_Config();

	for (;;) {

	}

	return -1;

}

/**
 *	Enablen der Clock, User-Button konfigurieren, External Interrupt auf Rising Edge Trigger stellen
 */
void EXTI0_Config(void) {
	GPIO_InitTypeDef GPIO_InitStructure;
	__GPIOA_CLK_ENABLE();

	GPIO_InitStructure.Pin = GPIO_PIN_0;
	GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
	HAL_NVIC_SetPriority(EXTI0_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

/**
 * 	Der Systick-Callback fuer die Ampel
 */
void HAL_SYSTICK_Callback(void)	{
	ampelsteuerung(val);
}

/**
 *	Der EXTI-Callback fuer die Ampel
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	if (GPIO_Pin == USER_BUTTON_PIN) {
		ampelparameter* val = &repr;
		val->modus = true;

	}
}
