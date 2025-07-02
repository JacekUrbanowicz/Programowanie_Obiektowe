#pragma once
#include "Zwierze.h"
#include"Swiat.h"
#include<string>
#ifndef WILK_H
#define WILK_H

using namespace std;

class Swiat;

class Wolf : public Animal
{
public:
	Wolf(int strenght, int initiative, int x, int y, Swiat* world, string type);
	Wolf(int strenght, int initiative, int x, int y, Swiat* world, string type, int age);
	char Drawing() override;
	Organism* NewAnimal(int newx, int newy, Swiat* world);
	~Wolf();
};
#endif