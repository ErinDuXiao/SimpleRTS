// SimpleRTS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
#define _CRTDBG_MAP_ALLOC #include <stdlib.h> #include <crtdbg.h>  

using namespace std;

class Units
{

protected:
	string _name;
	int _health;
	int _attackDamage;
	int _walkSpeed;

public:
	Units() {
		cout << "Unit Contructed" << endl; 
	}

	Units(string name, int health, int attackDamage, int walkSpeed) {
		_name = name;
		_health = health;
		_attackDamage = attackDamage;
		_walkSpeed = walkSpeed;

		cout << "Unit Constructed by constructor2" << endl;
	}

	virtual ~Units() { cout << "Unit Destroyed" << endl; }
	virtual void Attack() { cout << "Unit Attack!" << endl; }
	virtual void Walk() { cout << "Unit Walks!" << endl; }
};

class FlyingUnits : public Units 
{

private:
	int flyspeed;

public:
	FlyingUnits() { cout << "FlyingUnits Contructed" << endl; }

	FlyingUnits(string name, int health, int attackDamage, int walkSpeed) 
		: Units( name,  health, attackDamage,  walkSpeed) {
		cout << "FlyingUnits Contructed by constructor2" << endl; 
	}

	~FlyingUnits() { cout << "FlyingUnits Destroyed" << endl; }
	void Attack() { cout << "FlyingUnits Attack!" << endl; }
	void Fly() {
		cout << "FlyingUnits flies!" << endl;
	}
	void Walk() {
		cout << "FlyingUnits walks!" << endl;
	}
};

class GroundUnits : public Units 
{
public:
	GroundUnits() { cout << "GroundUnits Contructed" << endl; }
	GroundUnits(string name, int health, int attackDamage, int walkSpeed)
		: Units(name, health, attackDamage, walkSpeed) {
		cout << "GroundUnits Contructed by constructor2" << endl;
	}
	~GroundUnits() { cout << "GroundUnits Destroyed" << endl; }
	void Attack() { cout << "GroundUnits Attack!" << endl; }
	void Walk() {
		cout << "GroundUnits walks!" << endl;
	}
};

class UnitsFactory
{
public:
	static Units* MakeFlyingUnits(string name, int health, int attackDamage, int walkSpeed)
	{
		return new FlyingUnits(name, health, attackDamage, walkSpeed);
	}

	static Units* MakeGroundUnits(string name, int health, int attackDamage, int walkSpeed)
	{
		return new GroundUnits(name, health, attackDamage, walkSpeed);
	}
};

int main()
{

	Units *birdman = UnitsFactory::MakeFlyingUnits("Birdman", 100, 20, 5);
	FlyingUnits *b = dynamic_cast<FlyingUnits *>(birdman);
	Units *f = UnitsFactory::MakeFlyingUnits("Flyman", 100, 20, 5);
	Units *barbarian = UnitsFactory::MakeGroundUnits("Barbarian", 100, 20, 5);
	Units *archer = UnitsFactory::MakeGroundUnits("Archer ", 100, 10, 10);

	birdman->Walk();
	birdman->Attack();

	b->Fly();

	f->Walk();
	f->Attack();

	barbarian->Walk();
	barbarian->Attack();

	archer->Walk();
	archer->Attack();

	delete birdman;
	delete f;
	delete barbarian;
	delete archer;

	getchar();
    return 0;
}

