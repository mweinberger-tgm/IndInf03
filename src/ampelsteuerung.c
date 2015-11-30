/**
  ******************************************************************************
  * @file    ampelsteuerung.c
  * @author  Michael Weinberger
  * @version 1.0
  * @date    20.11.2015
  * @brief   Implementierung einer Event Centric State Machine zur Steuerung einer Ampel
  ******************************************************************************
*/

#include "control.h"
#include "ampel.h"

int blink = 0;

/**
 * @brief Implementierung einer Event Centric State Machine zur Steuerung einer Ampel
 *
 * @param none
 * @retval none
 */
void ampelsteuerung(ampelparameter* repr) {

	switch (repr->event) {

		case HALT:

			if (repr->zustand == ROT) {

				led_rot();

				repr->zustand = ROT_GELB;
				repr->event = VORBEREITUNG_FAHREN;

			} else {

				led_off();

				repr->event = FALSE;

			}

			break;

		case VORBEREITUNG_FAHREN:

			if (repr->zustand == ROT_GELB) {

				led_rot_gelb();

				repr->zustand = GRUEN;
				repr->event = FAHREN;

			} else {

				led_off();

				repr->event = FALSE;

			}

			break;

		case FAHREN:

			if (repr->zustand == GRUEN) {

				led_gruen();

				repr->zustand = GRUEN_BLINKEN;
				repr->event = VORBEREITUNG_HALT;

			} else {

				led_off();

				repr->event = FALSE;

			}

			break;

		case VORBEREITUNG_HALT:

			if (repr->zustand == GRUEN_BLINKEN) {

				led_gruen_blinken();

				repr->event = ACHTUNG;
				repr->zustand = GELB;

			} else {

				led_off();

				repr->event = FALSE;

			}

			break;

		case ACHTUNG:

			if (repr->zustand == GELB) {

				led_gelb();

				repr->event = HALT;
				repr->zustand = ROT;

			} else {

				led_off();

				repr->event = FALSE;

			}

			break;

		case NACHTSCHALTUNG_AN:

			if (repr->zustand == NACHTSCHALTUNG_AN) {

					led_gelb_blinken();

					repr->event = ROT_GELB;
					repr->zustand = GELB;

					} else {

						led_off();

						repr->event = FALSE;

					}

				break;

		case NACHTSCHALTUNG_AUS:

				repr->event = HALT;
				repr->zustand = ROT;

				break;

		default:

			repr->event = HALT;
			repr->zustand = ROT;

			break;
	}
}

