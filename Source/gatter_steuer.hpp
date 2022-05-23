#ifndef GATTER_STEUER_H
#define GATTER_STEUER_H

#include"gatter_logik.hpp"

using namespace std;

class verbindung {
private:
	gatter* von; /*!<Von-Gatter*/
	gatter* bis; /*!<Bis-Gatter*/
	int n; /*!<Nummer des bis-Gatter Pins*/
public:
	verbindung();
	verbindung(gatter* von, gatter* bis, const int n = 1);
	void aktual();
	gatter* getVon();
	gatter* getBis();
	int getPin();
	~verbindung();
};

class quelle {
private:
	gatter* bis; /*!<Bis-Gatter*/
	int n; /*!<Nummer des bis-Gatter Pins*/
	bool wert;  /*!<Logischer Wert der Quelle*/
public:
	quelle(gatter* bis, const int n = 1, const bool wert = true);
	gatter& getBis();
	quelle& operator! ();
	~quelle();
};

#endif
