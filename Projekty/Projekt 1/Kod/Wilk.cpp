#include<iostream>
#include"Wilk.h"
#include"Swiat.h"

using namespace std;

Wolf::Wolf(int strenght, int initiative, int x, int y, Swiat* world, string type) : Animal(strenght, initiative, x, y, world, type)
{

}

Wolf::Wolf(int strenght, int initiative, int x, int y, Swiat* world, string type, int age) : Animal(strenght, initiative, x, y, world, type, age)
{

}

char Wolf::Drawing()
{
	return 'W';
}

Organism* Wolf::NewAnimal(int newx, int newy, Swiat* world)
{
	return new Wolf(9, 5, newx, newy, world, "Wilk");
}

Wolf::~Wolf()
{

}