/*****************************************************************//**
 * \file   gatter_print.cpp
 * \brief  Klasse für die Darstellung Logikgatter
 * 
 * \author Ferenc *Andras* Kiss
 * \date   Mai 2022
 *********************************************************************/

#include <iostream>

#include "gatter_print.hpp"
#include "gatter_logik.hpp"
#include "gatter_steuer.hpp"
#include "gatter_sammlung.hpp"

using namespace std;

/**
 * Überladung des << Operators, um Gatter mit mehreren Eingängen darzustellen
 * 
 * \param out ostream Referenz
 * \param g Referenz aus das zu darstellene Gatter
 * \return ostream Referenz
 */

ostream& operator<<(ostream& out, binaerGatter& g) {
	switch (g.getPin()) {
	case 2:
		out << " _____________" << endl;
		out << "|     " << g.getNameChar(0) << g.getNameChar(1) << g.getNameChar(2) << "     |" << endl;
		out << "|-------------|" << endl;
		out << "|";
		for (int i = 1; i <= g.getPin(); i++) {
			if (find(g, i) != NULL) {
				out << find(g, i)->getName() << "|";
			}
			else {
				out << " " << i << " |";
			}
		}
		out << " aus |" << endl;
		out << "|-------------|" << endl;
		out << "| " << (char)(g.getVerbunden(1) ? g.getEingang(1) + 48 : 'x') << " | " << (char)(g.getVerbunden(2) ? g.getEingang(2) + 48 : 'x') << " |  " << g.getAusgang() << "  |" << endl;
		out << "|_____________|" << endl;
		break;
	case 3:
		out << " _________________" << endl;
		out << "|       " << g.getNameChar(0) << g.getNameChar(1) << g.getNameChar(2) << "       |" << endl;
		out << "|-----------------|" << endl;
		out << "|";
		for (int i = 1; i <= g.getPin(); i++) {
			if (find(g, i) != NULL) {
				out << find(g, i)->getName() << "|";
			}
			else {
				out << " " << i << " |";
			}
		}
		out << " aus |" << endl;
		out << "|-----------------|" << endl;
		out << "| " << (char)(g.getVerbunden(1) ? g.getEingang(1) + 48 : 'x') << " | " << (char)(g.getVerbunden(2) ? g.getEingang(2) + 48 : 'x') << " | " << (char)(g.getVerbunden(3) ? g.getEingang(3) + 48 : 'x') << " |  " << g.getAusgang() << "  |" << endl;
		out << "|_________________|" << endl;
		break;
	case 4:
		out << " _____________________" << endl;
		out << "|         " << g.getNameChar(0) << g.getNameChar(1) << g.getNameChar(2) << "         |" << endl;
		out << "|---------------------|" << endl;
		out << "|";
		for (int i = 1; i <= g.getPin(); i++) {
			if (find(g, i) != NULL) {
				out << find(g, i)->getName() << "|";
			}
			else {
				out << " " << i << " |";
			}
		}
		out << " aus |" << endl;
		out << "|---------------------|" << endl;
		out << "| " << (char)(g.getVerbunden(1) ? g.getEingang(1) + 48 : 'x') << " | " << (char)(g.getVerbunden(2) ? g.getEingang(2) + 48 : 'x') << " | " << (char)(g.getVerbunden(3) ? g.getEingang(3) + 48 : 'x') << " | " << (char)(g.getVerbunden(4) ? g.getEingang(4) + 48 : 'x') << " |  " << g.getAusgang() << "  |" << endl;
		out << "|_____________________|" << endl;
		break;

	}
	return out;
}

/**
 * Überladung des << Operators, um Gatter mit einem Eingang darzustellen
 *
 * \param out ostream Referenz
 * \param g Referenz aus das zu darstellene Gatter
 * \return ostream Referenz
 */

ostream& operator<<(ostream& out, unaerGatter& g) {
	out << " _________" << endl;
	out << "|   " << g.getNameChar(0) << g.getNameChar(1) << g.getNameChar(2) << "   |" << endl;
	out << "|---------|" << endl;
	out << "|";
	if (find(g) != NULL) {
		out << find(g)->getName() << "| aus |" << endl;;
	}
	else {
		out << " 1 | aus |" << endl;
	}
	out << "|---------|" << endl;
	out << "| " << (char)(g.getVerbunden() ? g.getEingang() + 48 : 'x') << " |  " << g.getAusgang() << "  |" << endl;
	out << "|_________|" << endl;
	return out;
}
