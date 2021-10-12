//============================================================================
// Name        : Factory.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

enum Colours {
	RED,
	BLUE,
	YELLOW
};

//Library Classes
class Colour
{
public:
	virtual ~Colour() {}
	virtual void printColour() = 0;
	static Colour* createColour( Colours type );
};

class Red: public Colour
{
public:
	void printColour()
	{
		cout << "RED _____ "<< endl;
	}
	virtual ~Red() {}
};

class Blue: public Colour
{
public:
	void printColour()
	{
		cout << "BLUE _____ "<< endl;
	}
};

class Yellow: public Colour
{
public:
	void printColour()
	{
		cout << "YELLOW _____ "<< endl;
	}
	virtual ~Yellow() {}
};

Colour* Colour::createColour( Colours type )
{
	switch(type)
	{
		case RED:
			return new Red();
		case BLUE:
			return new Blue();
		case YELLOW:
			return new Yellow();
		default:
			return NULL;
	}
}

//Client Side
class Client
{
public:
	Client()
	{
		Colours type = BLUE;
		pColour = Colour::createColour( type );
	}
	Client( Colours type )
	{
		pColour = Colour::createColour( type );
	}
	~Client()
	{
		if( pColour )
		{
			delete[] pColour;
			pColour = NULL;
		}
	}
	Colour* getColour()
	{
		return pColour;
	}

private:
	Colour* pColour;
};

int main() {

	Client* pClient = new Client();
	Colour* pColour = pClient->getColour();
	pColour->printColour();

	Client* pClient2 = new Client( YELLOW );
	Colour* pColour2 = pClient2->getColour();
	pColour2->printColour();

	delete pClient;
	delete pClient2;

	return 0;
}
