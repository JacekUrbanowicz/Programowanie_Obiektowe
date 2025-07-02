#include<iostream>
#include"Jagody.h"
#include"Swiat.h"

using namespace std;

Wolfberries::Wolfberries(int strenght, int initiative, int x, int y, Swiat* world, string type) : Plant(strenght, initiative, x, y, world, type)
{

}

Wolfberries::Wolfberries(int strenght, int initiative, int x, int y, Swiat* world, string type, int age) : Plant(strenght, initiative, x, y, world, type, age)
{

}

char Wolfberries::Drawing()
{
	return 'w';
}

bool Wolfberries::NegativeFood() const
{
	return true;
}

Organism* Wolfberries::NewPlant(int newx, int newy, Swiat* world)
{
	return new Wolfberries(0, 0, newx, newy, world, "WilczeJagody");
}

Wolfberries::~Wolfberries()
{

}