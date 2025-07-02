#include<iostream>
#include"Guarana.h"
#include"Swiat.h"

using namespace std;

Guarana::Guarana(int strenght, int initiative, int x, int y, Swiat* world, string type) : Plant(strenght, initiative, x, y, world, type)
{

}

Guarana::Guarana(int strenght, int initiative, int x, int y, Swiat* world, string type, int age) : Plant(strenght, initiative, x, y, world, type, age)
{

}

char Guarana::Drawing()
{
	return 'g';
}

bool Guarana::PositiveFood() const
{
	return true;
}

Organism* Guarana::NewPlant(int newx, int newy, Swiat* world)
{
	return new Guarana(0, 0, newx, newy, world, "Guarana");
}

Guarana::~Guarana()
{

}