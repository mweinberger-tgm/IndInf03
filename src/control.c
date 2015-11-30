/**
  ******************************************************************************
  * @file    control.c
  * @author  Michael Weinberger
  * @version 1.0
  * @date    20.11.2015
  * @brief   Steuern der benoetigten LEDs am Board
  ******************************************************************************
*/

#include "control.h"
#include "stm32f3xx.h"
#include "stm32f3_discovery.h"

/**
 * @brief Initialisiert die LEDs
 *
 * @param none
 * @retval none
 */
void led_init() {

	BSP_LED_Init(LED_RED);
	BSP_LED_Init(LED_ORANGE);
	BSP_LED_Init(LED_GREEN_2);

}

/**
 * @brief Schaltet die LEDs aus
 *
 * @param none
 * @retval none
 */
void led_off() {

	BSP_LED_Off(LED_RED);
	BSP_LED_Off(LED_ORANGE);
	BSP_LED_Off(LED_GREEN_2);

}

/**
 * @brief Die Rot-Phase der Ampel, 3 Sekunden
 *
 * @param none
 * @retval none
 */
void led_rot() {
	led_off();

	BSP_LED_On(LED_RED);

	HAL_Delay(3000);
}

/**
 * @brief Die Gelb-Phase der Ampel, 1.5 Sekunden
 * @param none
 * @retval none
 */
void led_gelb() {
	led_off();

	BSP_LED_On(LED_ORANGE);

	HAL_Delay(1500);
}

/**
 * @brief Die Gruen-Phase der Ampel, 3 Sekunden
 *
 * @param none
 * @retval none
 */
void led_gruen() {
	led_off();

	BSP_LED_On(LED_GREEN_2);

	HAL_Delay(3000);
}

/**
 * @brief Die Uebergangsphase der Ampel (rot, gelb), 1 Sekunde
 *
 * @param none
 * @retval none
 */
void led_rot_gelb() {
	led_off();

	BSP_LED_On(LED_RED);
	BSP_LED_On(LED_ORANGE);

	HAL_Delay(1000);
}


/**
 * @brief 3x gruen blinken, 0.5 Sekunden Delay
 * @param none
 * @retval none
 */
void led_gruen_blinken() {
	led_off();

	int i;
	for (i=0; i < 3; i++) {

		HAL_Delay(500);
		BSP_LED_On(LED_GREEN_2);

		HAL_Delay(500);
		BSP_LED_Off(LED_GREEN_2);

	}
}

void led_gelb_blinken() {
	led_off();

	int i;
	for (i=0; i < 3; i++) {

	HAL_Delay(500);
	BSP_LED_On(LED_ORANGE);

	HAL_Delay(500);
	BSP_LED_Off(LED_ORANGE);

	}
}
