/*****************************************************************//**
 * \file   main.cpp
 * \brief  LogikGatter - Grundlagen der Programmierung 2.
 * 
 * \author Ferenc *Andras* Kiss
 * \date   Mai 2022
 *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cstdint>

#include "gatter_logik.hpp"
#include "gatter_print.hpp"
#include "gatter_steuer.hpp"
#include "gatter_sammlung.hpp"

using namespace std;

int main() {

	undGatter gand("AND", 3); /*Und Gatter erzeugen*/
	oderGatter gor("OR ", 2); /*Oder Gatter erzeugen*/
	nichtGatter gnicht("NOT"); /*Nicht Gatter erzeugen*/

	quelle q1(&gand, 3, true); /*Quellen für die Gattereingänge erzeugen*/
	quelle q2(&gor, 1, true);
	quelle q3(&gor, 2, false);
	quelle q4(&gnicht, false);
	
	verbindung v1(&gor, &gand, 2); /*Verbindung von OR bis Pin2 des AND Gatters*/
	add(v1); /*Verbindung zur Liste von Verbindungen addieren*/
	verbindung v2(&gnicht, &gand, 1); /*Verbindung von NOT bis Pin1 des AND Gatters*/
	add(v2); /*Verbindung zur Liste von Verbindungen addieren*/

	cout << gand; /*Gatter in der Kommandozeile darstellen*/
	cout << gor;
	cout << gnicht;

	deleteSammlung(); /*Liste von Verbindungen wird gelöscht*/
	
	return 0;
}