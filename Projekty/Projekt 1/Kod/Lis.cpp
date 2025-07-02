#include<iostream>
#include"Lis.h"
#include"Swiat.h"

using namespace std;

Fox::Fox(int strenght, int initiative, int x, int y, Swiat* world, string type) : Animal(strenght, initiative, x, y, world, type)
{

}

Fox::Fox(int strenght, int initiative, int x, int y, Swiat* world, string type, int age) : Animal(strenght, initiative, x, y, world, type, age)
{

}

char Fox::Drawing()
{
	return 'F';
}

bool Fox::GoodSmell(Organism* checked)
{
    if (checked == nullptr)
    {
        return true;
    }

    if (checked->GetStrenght() > this->GetStrenght())
    {
        return false;
    }
    else
    {
        return true;
    }
}

Organism* Fox::NewAnimal(int newx, int newy, Swiat* world)
{
    return new Fox(3, 7, newx, newy, world, "Lis");
}

Fox::~Fox()
{

}