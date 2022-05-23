/*****************************************************************//**
 * \file   gatter_steuer.cpp
 * \brief  Klasse für die Behandlung Verbindungen und Quellen
 * 
 * \author Ferenc *Andras* Kiss
 * \date   Mai 2022
 *********************************************************************/
#include<iostream>

#include "gatter_steuer.hpp"
#include "gatter_logik.hpp"
#include "gatter_print.hpp"

/**
 * @brief Default Konstruktor
 */
verbindung::verbindung() {}
/**
 * Stellt eine Verbindung zwischen zwei Gattern
 * @brief Konstruktor
 * \param von Pointer des von-Gatters
 * \param bis Pointer des bis-Gatters
 * \param n Nummer des bis-Gatter-Pins, wo die Verbindung angeschlossen werden soll
 */
verbindung::verbindung(gatter* von, gatter* bis, const int n) : von(von), bis(bis), n(n) {
	if (von == bis) throw "fehler";
	bis->setEingang(n, von->getAusgang());
}
/**
 * Aktualisiert das Ende der Verbindung. Muss abgerufen werden, wenn es eine Änderung am Eingang gibt
 */
void verbindung::aktual() {
	bis->setEingang(n, von->getAusgang());
}
/**
 * \return Pointer auf das von-Gatter der Verbindung
 */
gatter* verbindung::getVon() {
	return von;
}
/**
 * \return Pointer auf das von-Gatter der Verbindung
 */
gatter* verbindung::getBis() {
	return bis;
}
/**
 * \return Nummer des von-Gatter-Pins, wozu die Verbindung angeschlossen ist
 */
int verbindung::getPin() {
	return n;
}
/**
 * @brief Destruktor
 */
verbindung::~verbindung() {
}
/**
 * Erzeugt eine Quelle
 * @brief Konstruktor
 *  
 * \param bis Pointer des bis-Gatters
 * \param n Nummer des bis-Gatter-Pins, wo die Verbindung angeschlossen werden soll
 * \param wert Logischer Wert des Gatters
 */
quelle::quelle(gatter* bis, const int n, const bool wert) : bis(bis), n(n), wert(wert) {
	bis->setEingang(n, wert);
}
/**
 * \return Pointer auf das von-Gatter der Verbindung
 */
gatter& quelle::getBis() {
	return *bis;
}
/**
 * Negiert den aktuellen Wert der Quelle
 * \return Referenz auf die originelle Quelle
 */
quelle& quelle::operator! () {
	wert = !wert;
	bis->setEingang(n, wert);
	return *this;
}

/**
 * Destruktor
 */
quelle::~quelle() {}
