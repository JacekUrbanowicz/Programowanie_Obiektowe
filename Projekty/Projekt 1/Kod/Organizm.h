#pragma once
#include <iostream>
#include <string>
#include "Swiat.h"
#ifndef ORGANIZM_H
#define ORGANIZM_H

using namespace std;

class Swiat;

class Organism
{
protected:
	int strenght;
	int initiative;
	int x, y;
	Swiat* world;
	string type;
	int age;

public:
	Organism(int strenght, int initiative, int x, int y, Swiat* world, string type);
	Organism(int strenght, int initiative, int x, int y, Swiat* world, string type, int age);
	virtual void Action() = 0;
	virtual void Collision(Organism* attacked) = 0;
	virtual char Drawing() = 0;
	virtual int GetX() const = 0;
	virtual int GetY() const = 0;
	virtual int GetInitiative() const = 0;
	virtual int GetStrenght() const = 0;
	virtual void SetStrenght(int new_strenght) = 0;
	virtual string GetType() const = 0;
	virtual int GetAge() const = 0;
	virtual void CreateLogs(int& choice, Organism* attacked) = 0;
	virtual bool AttackDeflected(Organism* attacker) = 0;
	virtual bool GoodSmell(Organism* checked) = 0;
	virtual bool DoubleMove() = 0;
	virtual bool AttackEscaped(Organism* checked) = 0;
	virtual void EscapeMove(Organism* attacked) = 0;
	virtual bool IsAnimal() const = 0;
	virtual bool PositiveFood() const = 0;
	virtual void PositiveEffect(Organism* eater) = 0;
	virtual bool NegativeFood() const = 0;
	virtual void NegativeEffect(Organism* eater) = 0;
	virtual bool IsImmortal() = 0;
	virtual ~Organism();
};
#endif