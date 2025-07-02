#include<iostream>
#include"Barszcz.h"
#include"Swiat.h"

using namespace std;

Borscht::Borscht(int strenght, int initiative, int x, int y, Swiat* world, string type) : Plant(strenght, initiative, x, y, world, type)
{

}

Borscht::Borscht(int strenght, int initiative, int x, int y, Swiat* world, string type, int age) : Plant(strenght, initiative, x, y, world, type, age)
{

}

char Borscht::Drawing()
{
	return 'b';
}

bool Borscht::NegativeFood() const
{
	return true;
}

Organism* Borscht::NewPlant(int newx, int newy, Swiat* world)
{
	return new Borscht(0, 0, newx, newy, world, "BarszczSosnowskiego");
}

void Borscht::KillAnimals()
{
	int x_nearby[] = { -1, 1, 0, 0 };
	int y_nearby[] = { 0, 0, -1, 1 };

	for (int i = 0; i < 4; ++i)
	{
		int newx = x + x_nearby[i];
		int newy = y + y_nearby[i];

		if (newx >= 1 && newx < world->GetLenght() + 1 && newy >= 1 && newy < world->GetHeight() + 1)
		{
			Organism* victim = world->GetOrganismAtPoint(newx, newy);

			if (victim != nullptr && victim->IsAnimal() == true && victim->IsImmortal() == false)
			{
				int choice = 5;
				CreateLogs(choice, victim);
				world->OrganismKilled(victim);
				if (victim->DoubleMove() == true)
				{

				}
				else
				{
					delete victim;
				}
			}
			else if (victim != nullptr && victim->IsAnimal() == true && victim->IsImmortal() == true)
			{
				int choice = 6;
				CreateLogs(choice, victim);
			}
		}
	}
}

Borscht::~Borscht()
{

}