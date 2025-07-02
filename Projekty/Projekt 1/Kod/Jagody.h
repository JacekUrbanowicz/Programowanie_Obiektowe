#pragma once
#include "Roslina.h"
#include"Swiat.h"
#include<string>
#ifndef JAGODY_H
#define JAGODY_H

using namespace std;

class Swiat;

class Wolfberries : public Plant
{
public:
	Wolfberries(int strenght, int initiative, int x, int y, Swiat* world, string type);
	Wolfberries(int strenght, int initiative, int x, int y, Swiat* world, string type, int age);
	char Drawing() override;
	bool NegativeFood() const override;
	Organism* NewPlant(int newx, int newy, Swiat* world);
	~Wolfberries();
};
#endif