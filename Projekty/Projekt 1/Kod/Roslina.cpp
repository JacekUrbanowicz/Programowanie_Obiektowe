#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include"Roslina.h"
#include"Swiat.h"

using namespace std;

Plant::Plant(int strenght, int initiative, int x, int y, Swiat* world, string type) : Organism(strenght, initiative, x, y, world, type)
{

}

Plant::Plant(int strenght, int initiative, int x, int y, Swiat* world, string type, int age) : Organism(strenght, initiative, x, y, world, type, age)
{

}

void Plant::Action()
{
	age++;
	int choice = 0;

	KillAnimals();

	int chance = rand() % 5;
	if (chance == 0)
	{
		bool spawned = false;
		while(!spawned)
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

			int newx = x + addx;
			int newy = y + addy;

			if (newx >= 1 && newx < world->GetLenght() + 1 && newy >= 1 && newy < world->GetHeight() + 1)
			{
				Organism* target = world->GetOrganismAtPoint(newx, newy);

				if (target == nullptr)
				{
					Organism* new_plant = NewPlant(newx, newy, world);
					if (new_plant != nullptr)
					{
						choice = 4;
						world->NewOrganism(new_plant);
						CreateLogs(choice, new_plant);
						spawned = true;
					}
				}
				else
				{
					spawned = true;
				}
			}
		}
	}
}

void Plant::Collision(Organism* attacker)
{
	int choice = 0;

	if (this->NegativeFood() == true)
	{
		choice = 3;
		if (attacker->IsImmortal() == false)
		{
			NegativeEffect(attacker);
		}
		else
		{
			choice = 10;
		}
		CreateLogs(choice, attacker);
		world->OrganismKilled(this);
		return;
	}
	else if (this->PositiveFood() == true)
	{
		choice = 2;
		PositiveEffect(attacker);
		CreateLogs(choice, attacker);
		world->OrganismKilled(this);
		return;
	}
	else if (attacker->IsAnimal() == true)
	{
		choice = 1;
		CreateLogs(choice, attacker);
		world->OrganismKilled(this);
		return;
	}
}

void Plant::CreateLogs(int& choice, Organism* attacked)
{
	if (choice == 1)
	{
		ofstream log("log.txt", ios::app);
		log << "Organizm " << this->GetType() << " zostaje zjedzony przez " << attacked->GetType() << endl;
		log.close();
		cout << "Organizm " << this->GetType() << " zostaje zjedzony przez " << attacked->GetType() << endl;
	}
	else if (choice == 2)
	{
		ofstream log("log.txt", ios::app);
		log << "Organizm " << this->GetType() << " zostaje zjedzony przez " << attacked->GetType() << " zwiekszajac jego sile o 3" << endl;
		log.close();
		cout << "Organizm " << this->GetType() << " zostaje zjedzony przez " << attacked->GetType() << " zwiekszajac jego sile o 3" << endl;
	}
	else if (choice == 3)
	{
		ofstream log("log.txt", ios::app);
		log << "Organizm " << this->GetType() << " zostaje zjedzony i zabija " << attacked->GetType() << endl;
		log.close();
		cout << "Organizm " << this->GetType() << " zostaje zjedzony i zabija " << attacked->GetType() << endl;
	}
	else if (choice == 4)
	{
		ofstream log("log.txt", ios::app);
		log << "Organizm " << this->GetType() << " tworzy nowa rosline " << attacked->GetType() << endl;
		log.close();
		cout << "Organizm " << this->GetType() << " tworzy nowa rosline " << attacked->GetType() << endl;
	}
	else if (choice == 5)
	{
		ofstream log("log.txt", ios::app);
		log << "Organizm " << this->GetType() << " powoduje smiertelne popazenia na " << attacked->GetType() << endl;
		log.close();
		cout << "Organizm " << this->GetType() << " powoduje smiertelne popazenia na " << attacked->GetType() << endl;
	}
	else if (choice == 6)
	{
		ofstream log("log.txt", ios::app);
		log << "Organizm " << this->GetType() << " nie powoduje smiertelnych popazenia na " << attacked->GetType() << " bo jest niesmiertleny" << endl;
		log.close();
		cout << "Organizm " << this->GetType() << " nie powoduje smiertelnych popazenia na " << attacked->GetType() << " bo jest niesmiertleny" << endl;
	}
}

bool Plant::AttackDeflected(Organism* attacker)
{
	return false;
}

bool Plant::GoodSmell(Organism* checked)
{
	return true;
}

bool Plant::DoubleMove()
{
	return false;
}

bool Plant::AttackEscaped(Organism* checked)
{
	return false;
}

void Plant::EscapeMove(Organism* attacked)
{
	attacked->Action();
}

void Plant::SetStrenght(int new_strenght)
{
	this->strenght = new_strenght;
}

bool Plant::IsAnimal() const
{
	return false;
}

bool Plant::PositiveFood() const
{
	return false;
}

void Plant::PositiveEffect(Organism* eater)
{
	eater->SetStrenght(eater->GetStrenght() + 3);
}

bool Plant::NegativeFood() const
{
	return false;
}

void Plant::NegativeEffect(Organism* eater)
{
	if (eater->IsImmortal() == true)
	{
		return;
	}
	world->OrganismKilled(eater);
}

void Plant::KillAnimals()
{

}

int Plant::GetX() const
{
	return x;
}

int Plant::GetY() const
{
	return y;
}

int Plant::GetInitiative() const
{
	return initiative;
}

int Plant::GetStrenght() const
{
	return strenght;
}

string Plant::GetType() const
{
	return type;
}

int Plant::GetAge() const
{
	return age;
}

bool Plant::IsImmortal()
{
	return false;
}

Plant::~Plant()
{

}