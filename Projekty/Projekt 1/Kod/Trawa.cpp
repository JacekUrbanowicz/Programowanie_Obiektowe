#include<iostream>
#include"Trawa.h"
#include"Swiat.h"

using namespace std;

Grass::Grass(int strenght, int initiative, int x, int y, Swiat* world, string type) : Plant(strenght, initiative, x, y, world, type)
{

}

Grass::Grass(int strenght, int initiative, int x, int y, Swiat* world, string type, int age) : Plant(strenght, initiative, x, y, world, type, age)
{

}

char Grass::Drawing()
{
	return 't';
}

Organism* Grass::NewPlant(int newx, int newy, Swiat* world)
{
	return new Grass(0, 0, newx, newy, world, "Trawa");
}

Grass::~Grass()
{

}