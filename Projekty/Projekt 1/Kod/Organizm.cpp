#include<iostream>
#include<string>
#include "Organizm.h"
#include"Swiat.h"

using namespace std;

Organism::Organism(int strenght, int initiative, int x, int y, Swiat* world, string type)
{
	this->strenght = strenght;
	this->initiative = initiative;
	this->x = x;
	this->y = y;
	this->world = world;
	this->type = type;
	this->age = 0;
}

Organism::Organism(int strenght, int initiative, int x, int y, Swiat* world, string type, int age)
{
	this->strenght = strenght;
	this->initiative = initiative;
	this->x = x;
	this->y = y;
	this->world = world;
	this->type = type;
	this->age = age;
}

Organism::~Organism()
{

}