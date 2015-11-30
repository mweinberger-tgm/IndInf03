/**
  ******************************************************************************
  * @file    ampel.h
  * @author  Michael Weinberger
  * @version 1.0
  * @date    20.11.2015
  * @brief	 Definition der States & Events
  ******************************************************************************
*/

#ifndef AMPEL_H_
#define AMPEL_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *	Auflistung der Zustaende inklusive der Komponente fuer die Nachtschaltung
 */
typedef enum {
	ROT,
	ROT_GELB,
	GRUEN,
	GRUEN_BLINKEN,
	GELB,
	GELB_BLINKEN
} ampelzustand;

/**
 *	Auflistung der Events inklusive Nachtschaltung
 */
typedef enum {
	FAHREN,
	HALT,
	VORBEREITUNG_FAHREN,
	VORBEREITUNG_HALT,
	ACHTUNG,
	FALSE,
	NACHTSCHALTUNG_AN,
	NACHTSCHALTUNG_AUS
} ampelevent;

/**
 * 	Auflistung der ges. Parameter inkl. Wert zur Bestimmung der Schaltung
 */
typedef struct {
	bool modus;
	ampelzustand zustand;
	ampelevent event;
} ampelparameter;

void ampel(ampelparameter* ampel);

#endif /* AMPEL_H_ */
