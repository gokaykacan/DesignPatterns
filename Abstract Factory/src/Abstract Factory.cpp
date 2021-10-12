//============================================================================
// Name        : Abstract.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//Elves
class AbstractClassElf
{
public:
	virtual ~AbstractClassElf() {}
	virtual void printElfName() = 0;
};

class Legolas: public AbstractClassElf
{
public:
	virtual ~Legolas() {}
	void printElfName()
	{
		cout << "Hey! I am Legolas" << endl;
	}
};

class Elrond: public AbstractClassElf
{
public:
	virtual ~Elrond() {}
	void printElfName()
	{
		cout << "Hey! I am Elrond" << endl;
	}
};

//Humans
class AbstractClassHuman
{
public:
	virtual ~AbstractClassHuman() {}
	virtual void printHumanName() = 0;
};

class Boromir: public AbstractClassHuman
{
public:
	virtual ~Boromir() {}
	void printHumanName()
	{
		cout << "Hey! I am Boromir" << endl;
	}
};

class Faramir: public AbstractClassHuman
{
public:
	virtual ~Faramir() {}
	void printHumanName()
	{
		cout << "Hey! I am Faramir" << endl;
	}
};

class AbstractFactory
{
public:
	virtual ~AbstractFactory() {}
	virtual AbstractClassElf* getAbstractClassElf() = 0;
	virtual AbstractClassHuman* getAbstractClassHuman() = 0;
};

class CreateLegolasAndBoromir: public AbstractFactory
{
public:
	virtual ~CreateLegolasAndBoromir() {}
	AbstractClassElf* getAbstractClassElf()
	{
		return new Legolas();
	}
	AbstractClassHuman* getAbstractClassHuman()
	{
		return new Boromir();
	}
};

class CreateElrondAndFaramir: public AbstractFactory
{
public:
	virtual ~CreateElrondAndFaramir() {}
	AbstractClassElf* getAbstractClassElf()
	{
		return new Elrond();
	}
	AbstractClassHuman* getAbstractClassHuman()
	{
		return new Faramir();
	}
};

int main() {

	CreateLegolasAndBoromir* pLegolasAndBoromir = new CreateLegolasAndBoromir();
	AbstractClassElf* pElf1 = pLegolasAndBoromir->getAbstractClassElf();
	AbstractClassHuman* pHuman1 = pLegolasAndBoromir->getAbstractClassHuman();
	pElf1->printElfName();
	pHuman1->printHumanName();

	CreateElrondAndFaramir* pElrondAndFaramir = new CreateElrondAndFaramir();
	AbstractClassElf* pElf2 = pElrondAndFaramir->getAbstractClassElf();
	AbstractClassHuman* pHuman2 = pElrondAndFaramir->getAbstractClassHuman();
	pElf2->printElfName();
	pHuman2->printHumanName();

	delete pLegolasAndBoromir;
	delete pElrondAndFaramir;

	return 0;
}
