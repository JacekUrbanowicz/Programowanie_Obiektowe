#pragma once
#include "Roslina.h"
#include"Swiat.h"
#include<string>
#ifndef TRAWA_H
#define TRAWA_H

using namespace std;

class Swiat;

class Grass : public Plant
{
public:
	Grass(int strenght, int initiative, int x, int y, Swiat* world, string type);
	Grass(int strenght, int initiative, int x, int y, Swiat* world, string type, int age);
	char Drawing() override;
	Organism* NewPlant(int newx, int newy, Swiat* world);
	~Grass();
};
#endif