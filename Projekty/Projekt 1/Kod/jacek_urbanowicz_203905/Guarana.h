#pragma once
#include "Roslina.h"
#include"Swiat.h"
#include<string>
#ifndef GUARANA_H
#define GUARANA_H

using namespace std;

class Swiat;

class Guarana : public Plant
{
public:
	Guarana(int strenght, int initiative, int x, int y, Swiat* world, string type);
	Guarana(int strenght, int initiative, int x, int y, Swiat* world, string type, int age);
	char Drawing() override;
	bool PositiveFood() const override;
	Organism* NewPlant(int newx, int newy, Swiat* world);
	~Guarana();
};
#endif