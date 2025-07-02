#pragma once
#include "Zwierze.h"
#include"Swiat.h"
#include<string>
#ifndef ZOLW_H
#define ZOLW_H

using namespace std;

class Swiat;

class Turtle : public Animal
{
public:
	Turtle(int strenght, int initiative, int x, int y, Swiat* world, string type);
	Turtle(int strenght, int initiative, int x, int y, Swiat* world, string type, int age);
	void Action() override;
	char Drawing() override;
	bool AttackDeflected(Organism* attacker) override;
	Organism* NewAnimal(int newx, int newy, Swiat* world);
	~Turtle();
};
#endif