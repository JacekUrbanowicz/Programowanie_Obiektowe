#pragma once
#include "Zwierze.h"
#include"Swiat.h"
#include<string>
#ifndef LIS_H
#define LIS_H

using namespace std;

class Swiat;

class Fox : public Animal
{
public:
	Fox(int strenght, int initiative, int x, int y, Swiat* world, string type);
	Fox(int strenght, int initiative, int x, int y, Swiat* world, string type, int age);
	char Drawing() override;
	bool GoodSmell(Organism* checked) override;
	Organism* NewAnimal(int newx, int newy, Swiat* world);
	~Fox();
};
#endif