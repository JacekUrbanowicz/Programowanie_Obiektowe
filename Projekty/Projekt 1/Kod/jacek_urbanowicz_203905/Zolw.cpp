#include<iostream>
#include"Zolw.h"
#include"Swiat.h"

using namespace std;

Turtle::Turtle(int strenght, int initiative, int x, int y, Swiat* world, string type) : Animal(strenght, initiative, x, y, world, type)
{

}

Turtle::Turtle(int strenght, int initiative, int x, int y, Swiat* world, string type, int age) : Animal(strenght, initiative, x, y, world, type, age)
{

}

void Turtle::Action()
{
	int chance = rand() % 4;
	if (chance == 1)
	{
		Animal::Action();
	}

	age++;
}

char Turtle::Drawing()
{
	return 'T';
}

bool Turtle::AttackDeflected(Organism* attacker)
{
	Animal* enemy = dynamic_cast<Animal*>(attacker);
	if (enemy != nullptr && enemy->GetStrenght() < 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Organism* Turtle::NewAnimal(int newx, int newy, Swiat* world)
{
	return new Turtle(2, 1, newx, newy, world, "Zolw");
}

Turtle::~Turtle()
{

}