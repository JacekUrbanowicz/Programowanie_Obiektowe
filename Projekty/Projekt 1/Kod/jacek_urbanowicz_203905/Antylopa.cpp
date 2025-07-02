#include<iostream>
#include<ctime>
#include"Antylopa.h"
#include"Swiat.h"

using namespace std;

Antelope::Antelope(int strenght, int initiative, int x, int y, Swiat* world, string type) : Animal(strenght, initiative, x, y, world, type)
{

}

Antelope::Antelope(int strenght, int initiative, int x, int y, Swiat* world, string type, int age) : Animal(strenght, initiative, x, y, world, type, age)
{

}

char Antelope::Drawing()
{
	return 'A';
}

bool Antelope::DoubleMove()
{
	return true;
}

bool Antelope::AttackEscaped(Organism* checked)
{
	int chance = rand() % 2;
	if (chance == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Antelope::EscapeMove(Organism* attacked)
{
	bool possible_move = false;
	while (!possible_move)
	{
		int direction = rand() % 4;
		int addx = 0;
		int addy = 0;
		switch (direction)
		{
		case 0:
			addx = -1;
			break;
		case 1:
			addx = 1;
			break;
		case 2:
			addy = -1;
			break;
		case 3:
			addy = 1;
			break;
		}

		int newx = this->x + addx;
		int newy = this->y + addy;

		if (newx >= 1 && newx < world->GetLenght() + 1 && newy >= 1 && newy < world->GetHeight() + 1)
		{
			Organism* target_under_attack = world->GetOrganismAtPoint(newx, newy);

			bool stronger_enenmy = GoodSmell(target_under_attack);

			if (stronger_enenmy == false)
			{
				continue;
			}

			if (target_under_attack == nullptr)
			{
				this->x = newx;
				this->y = newy;
				possible_move = true;
				age++;
			}
			else
			{
				Collision(target_under_attack);
				possible_move = true;
				this->age++;
			}
		}
	}
}

Organism* Antelope::NewAnimal(int newx, int newy, Swiat* world)
{
	return new Antelope(4, 4, newx, newy, world, "Antylopa");
}

Antelope::~Antelope()
{

}