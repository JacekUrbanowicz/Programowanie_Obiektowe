#include<iostream>
#include"Mlecz.h"
#include"Swiat.h"

using namespace std;

Milkweed::Milkweed(int strenght, int initiative, int x, int y, Swiat* world, string type) : Plant(strenght, initiative, x, y, world, type)
{

}

Milkweed::Milkweed(int strenght, int initiative, int x, int y, Swiat* world, string type, int age) : Plant(strenght, initiative, x, y, world, type, age)
{

}

void Milkweed::Action()
{
	for (int i = 0; i < 3; i++)
	{
		Plant::Action();
	}
	for (int i = 0; i < 2; i++)
	{
		age--;
	}
}

char Milkweed::Drawing()
{
	return 'm';
}

Organism* Milkweed::NewPlant(int newx, int newy, Swiat* world)
{
	return new Milkweed(0, 0, newx, newy, world, "Mlecz");
}

Milkweed::~Milkweed()
{

}