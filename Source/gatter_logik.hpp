#ifndef GATTER_LOGIK_H
#define GATTER_LOGIK_H

using namespace std;

class gatter {
protected:
	char* name; /*!<Name des Gatters*/
	bool ausgang; /*!<Logischer Wert am Ausgang*/
public:
	gatter(const char* name);
	char* getName();
	char getNameChar(const int n);
	bool getAusgang();
	virtual bool getVerbunden(const int n) = 0;
	virtual bool gatterLogik() = 0;
	virtual void setEingang(const int n, const bool wert) = 0;
	~gatter() { delete[] name; }
};

class unaerGatter : public gatter {
protected:
	bool eingang; /*!<Logischer Wert am Eingang*/
	bool verbunden; /*!<Der Eingang ist verbunden*/
public:
	unaerGatter(const char* name) : gatter(name) {
		verbunden = false;
	}
	bool getEingang();
	virtual bool getVerbunden(const int n = 1);
	virtual void setEingang(const int n, const bool wert);
	~unaerGatter() {}
};

class binaerGatter : public gatter {
protected:
	int pin; /*!<Anzahl der Pins*/
	bool* eingang; /*!<Logischer Wert an den Eingängen*/
	bool* verbunden; /*!<Die Eingänge sind verbunden*/
public:
	binaerGatter(const char* name, const int pin = 2);
	virtual bool getEingang(const int n);
	virtual void setEingang(const int n, const bool wert);
	bool getVerbunden(const int n);
	int getPin();
	~binaerGatter();
};

class undGatter : public binaerGatter {
public:
	undGatter(const char* name) : binaerGatter(name) {}
	undGatter(const char* name, const int pin) : binaerGatter(name, pin) {}
	virtual bool gatterLogik();
	~undGatter() {}
};

class oderGatter : public binaerGatter {
public:
	oderGatter(const char* name) : binaerGatter(name) {}
	oderGatter(const char* name, const int pin) : binaerGatter(name, pin) {}
	virtual bool gatterLogik();
	~oderGatter() {}
};

class nichtGatter : public unaerGatter {
public:
	nichtGatter(const char* name) : unaerGatter(name) {};
	virtual bool gatterLogik();
	~nichtGatter() {}
};

#endif
