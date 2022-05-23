/*****************************************************************//**
 * \file   gatter_sammlung.cpp
 * \brief  Klasse für die Speicherung von Verbindungen
 * 
 * \author Ferenc *Andras* Kiss
 * \date   Mai 2022
 *********************************************************************/

#include<cstdint>

#include "gatter_logik.hpp"
#include "gatter_steuer.hpp"
#include "gatter_sammlung.hpp"

verbindung* gesamt; 
int element;

/**
 * Fügt eine neue Verbindung hinzu
 * 
 * \param v Verbindung
 */

void add(const verbindung& v) {
	verbindung* temp = new verbindung[++element];
	temp[0] = v;
	for (int i = 1; i < element; i++) {
		temp[i] = gesamt[i - 1];
	}
	delete[] gesamt;
	gesamt = temp;
}

/**
 * Entscheidet, ob ein gegebenes Pin eines Gatters mit einem anderen Gatter verbunden ist
 * 
 * \param g Gatter
 * \param n Pin
 * \return  Speicheraddresse des anderen Gatters, wenn verbunden
 * \return 0, wenn nicht verbunden
 */
gatter* find(const gatter& g, const int n) {
	for (int i = 0; i < element; i++) {
		if (((intptr_t)gesamt[i].getBis() == (intptr_t)&g) && (gesamt[i].getPin() == n)) {
			return gesamt[i].getVon();
		}
	}
	return 0;
}

/**
 * Löscht das Arrays von Verbindungen
 */
void deleteSammlung() {
	delete[] gesamt;
}
