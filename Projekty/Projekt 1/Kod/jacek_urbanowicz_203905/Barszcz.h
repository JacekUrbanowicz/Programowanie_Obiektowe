#pragma once
#include "Roslina.h"
#include"Swiat.h"
#include<string>
#ifndef BARSZCZ_H
#define BARSZCZ_H

using namespace std;

class Swiat;

class Borscht : public Plant
{
public:
	Borscht(int strenght, int initiative, int x, int y, Swiat* world, string type);
	Borscht(int strenght, int initiative, int x, int y, Swiat* world, string type, int age);
	char Drawing() override;
	bool NegativeFood() const override;
	Organism* NewPlant(int newx, int newy, Swiat* world);
	void KillAnimals() override;
	~Borscht();
};
#endif