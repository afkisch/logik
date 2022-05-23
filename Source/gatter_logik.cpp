/*****************************************************************//**
 * \file   gatter_logik.cpp
 * \brief  Klasse für die Verwirklichung von logischen Funktionen der Gatter
 * 
 * \author Ferenc *Andras* Kiss
 * \date   Mai 2022
 *********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "gatter_logik.hpp"

using namespace std;

/**
 * \brief Default Konstruktor
 * \param name Name des Gatters, erscheint bei Darstellung
 */

gatter::gatter(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

/**
 * \return Name des Gatters
 */
char* gatter::getName() {
	if (name) {
		return name;
	}
	return 0;
}

/**
 * \param n 
 * \return n-ter Charakter des Names
 */
char gatter::getNameChar(const int n) {
	if (n>=strlen(name)) {
		return 0;
	}
	return name[n];
}

/**
 * \return Aktueller Ausgang des Gatters
 */
bool gatter::getAusgang() {
	ausgang = gatterLogik();
	return ausgang;
}

/**
 * \return Eingang des Gatters mit einem Eingang
 */
bool unaerGatter::getEingang() {
	if (verbunden == false) {
		cout << "Gib den wert fuer gatter " << n << getName() << "an" << ": ";
		cin >> eingang;
		verbunden = true;
	}
	return eingang;
}

/**
 * \param n Nummer des Gatter-Pins - automatisch 1 für unäre Gatter
 * \return true, wenn der Eingang des Gatters verbunden ist
 * \return false, wenn der Eingang des Gatters nicht verbunden ist
 */
bool unaerGatter::getVerbunden(const int n) {
	return verbunden;
}

/**
 * \brief Stellt den Eingang des Gatters ein
 * \param n Nummer des Gatter-Pins - automatisch 1 für unäre Gatter
 * \param wert Logischer Wert des Eingangs
 */
void unaerGatter::setEingang(const int n, const bool wert) {
	if (verbunden == false) {
		verbunden = true;
	}
	eingang = wert;
}

/**
 * \brief Default Konstruktor
 * \param name Name des Gatters, erscheint bei Darstellung
 * \param pin Anzahl der Eingänge
 */
binaerGatter::binaerGatter(const char* name, const int pin) : gatter(name) {
	if (pin > 0) {
		eingang = new bool[pin];
		verbunden = new bool[pin];
		for (int i = 0; i < pin; i++) {
			verbunden[i] = false;
		}
		this->pin = pin;
	}
}

/**
 * \param n Nummer des bis-Gatter-Pins
 * \return true, falls am Eingang 1 ist
 * \return false, falls am Eingang 0 ist
 */
bool binaerGatter::getEingang(const int n) {
	if (verbunden[n - 1] == false) {
		cout << "Gib den wert fuer gatter " << n << getName() << "an" << ": ";
		cin >> eingang[n - 1];
		verbunden[n - 1] = true;
	}
	return eingang[n - 1];
}

/**
 * \brief Einstellung des Eingangs des Gatters
 * \param n Nummer des Gatter-Pins
 * \param wert Logischer Wert der Eingang
 */
void binaerGatter::setEingang(const int n, const bool wert) {
	if (verbunden[n - 1] == false) {
		verbunden[n - 1] = true;
	}
	eingang[n - 1] = wert;
}

/**
 * \param n Nummer des Gatter-Pins
 * \return true, falls der Pin Verbunden ist
 * \return false, falls der Pin nicht verbunden ist
 */
bool binaerGatter::getVerbunden(const int n) {
	return verbunden[n - 1];
}

/**
 * \return Anzahl der Pins des Gatters
 */
int binaerGatter::getPin() {
	return pin;
}

/**
 * Destruktor
 */
binaerGatter::~binaerGatter() {
	delete[] eingang;
	delete[] verbunden;
}

/**
 * Und Gatter - Logik
 * \return true, falls am Ausgang 1 ist
 * \return false, falls am Ausgang 0 ist
 */
bool undGatter::gatterLogik() {
	for (int i = 1; i <= pin; i++) {
		if (!getEingang(i)) {
			return false;
		}
	}
	return true;
}

/**
 * Oder Gatter - Logik
 * \return true, falls am Ausgang 1 ist
 * \return false, falls am Ausgang 0 ist
 */
bool oderGatter::gatterLogik() {
	for (int i = 1; i <= pin; i++) {
		if (getEingang(i)) {
			return true;
		}
	}
	return false;
}

/**
 * Nicht Gatter - Logik
 * \return true, falls am Ausgang 1 ist
 * \return false, falls am Ausgang 0 ist
 */
bool nichtGatter::gatterLogik() {
	if (getEingang()) {
		return false;
	}
	else {
		return true;
	}
}
