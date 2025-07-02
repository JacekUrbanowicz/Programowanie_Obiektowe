#pragma once
#include "Zwierze.h"
#include"Swiat.h"
#include<string>
#ifndef OWCA_H
#define OWCA_H

using namespace std;

class Swiat;

class Sheep : public Animal
{
public:
	Sheep(int strenght, int initiative, int x, int y, Swiat* world, string type);
	Sheep(int strenght, int initiative, int x, int y, Swiat* world, string type, int age);
	char Drawing() override;
	Organism* NewAnimal(int newx, int newy, Swiat* world);
	~Sheep();
};
#endif