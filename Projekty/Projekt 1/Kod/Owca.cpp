#include<iostream>
#include"Owca.h"
#include"Swiat.h"

using namespace std;

Sheep::Sheep(int strenght, int initiative, int x, int y, Swiat* world, string type) : Animal(strenght, initiative, x, y, world, type)
{

}

Sheep::Sheep(int strenght, int initiative, int x, int y, Swiat* world, string type, int age) : Animal(strenght, initiative, x, y, world, type, age)
{

}

char Sheep::Drawing()
{
	return 'S';
}

Organism* Sheep::NewAnimal(int newx, int newy, Swiat* world)
{
	return new Sheep(4, 4, newx, newy, world, "Owca");
}

Sheep::~Sheep()
{

}