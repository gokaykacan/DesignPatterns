//============================================================================
// Name        : Factory.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//Library Classes
class ProductColour
{
public:
	virtual ~ProductColour() {}
	virtual string getProductColour() = 0;
};

class ProductRed: public ProductColour
{
public:
	virtual ~ProductRed() {}
	string getProductColour()
	{
		return "Red Product is produced! \n";
	}
};

class ProductBlue: public ProductColour
{
public:
	virtual ~ProductBlue() {}
	string getProductColour()
	{
		return "Blue Product is produced! \n";
	}
};

class ProductYellow: public ProductColour
{
public:
	virtual ~ProductYellow() {}
	string getProductColour()
	{
		return "Yellow Product is produced! \n";
	}
};

//ClientSide classes and codes
class CreaterProduct
{
public:
	virtual ~CreaterProduct() {}
	virtual ProductColour* getFactoryMethod() = 0;
};

class CreaterRed: public CreaterProduct
{
	virtual ~CreaterRed() {}
	ProductColour* getFactoryMethod()
	{
		return new ProductRed();
	}
};

class CreaterBlue: public CreaterProduct
{
	virtual ~CreaterBlue() {}
	ProductColour* getFactoryMethod()
	{
		return new ProductBlue();
	}
};

class CreaterYellow: public CreaterProduct
{
	virtual ~CreaterYellow() {}
	ProductColour* getFactoryMethod()
	{
		return new ProductYellow();
	}
};


int main() {

	CreaterProduct* pCreater = new CreaterYellow();
	ProductColour* pProductColour = pCreater->getFactoryMethod();

	CreaterProduct* pCreater2 = new CreaterBlue();
	ProductColour* pProductColour2 = pCreater2->getFactoryMethod();

	cout << pProductColour->getProductColour();
	cout << pProductColour2->getProductColour();

	delete pCreater;
	delete pCreater2;

	return 0;
}
