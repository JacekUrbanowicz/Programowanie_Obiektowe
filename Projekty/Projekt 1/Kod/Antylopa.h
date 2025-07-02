#pragma once
#include "Zwierze.h"
#include"Swiat.h"
#include<string>
#ifndef ANTYLOPA_H
#define ANTYLOPA_H

using namespace std;

class Swiat;

class Antelope : public Animal
{
public:
	Antelope(int strenght, int initiative, int x, int y, Swiat* world, string type);
	Antelope(int strenght, int initiative, int x, int y, Swiat* world, string type, int age);
	char Drawing() override;
	bool DoubleMove() override;
	bool AttackEscaped(Organism* checked) override;
	void EscapeMove(Organism* attacked) override;
	Organism* NewAnimal(int newx, int newy, Swiat* world);
	~Antelope();
};
#endif