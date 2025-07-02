#pragma once
#include "Roslina.h"
#include"Swiat.h"
#include<string>
#ifndef MLECZ_H
#define MLECZ_H

using namespace std;

class Swiat;

class Milkweed : public Plant
{
public:
	Milkweed(int strenght, int initiative, int x, int y, Swiat* world, string type);
	Milkweed(int strenght, int initiative, int x, int y, Swiat* world, string type, int age);
	void Action() override;
	char Drawing() override;
	Organism* NewPlant(int newx, int newy, Swiat* world);
	~Milkweed();
};
#endif