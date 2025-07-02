#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include"Zwierze.h"
#include"Swiat.h"

using namespace std;

Animal::Animal(int strenght, int initiative, int x, int y, Swiat* world, string type) : Organism(strenght, initiative, x, y, world, type)
{

}

Animal::Animal(int strenght, int initiative, int x, int y, Swiat* world, string type, int age) : Organism(strenght, initiative, x, y, world, type, age)
{

}

void Animal::Action()
{
	int moves = 1;

	if (DoubleMove() == true)
	{
		moves++;
		age = age - 1;
	}
	for (int i = 0; i < moves; i++)
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

			int newx = x + addx;
			int newy = y + addy;

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
					x = newx;
					y = newy;
					possible_move = true;
					age++;
				}
				else
				{
					Collision(target_under_attack);
					possible_move = true;
					age++;
				}
			}
		}
	}
}

void Animal::Collision(Organism* attacked)
{
	int choice = 0;
	if (attacked->IsImmortal() == true && this->IsAnimal() == true)
	{
		choice = 7;
		CreateLogs(choice, attacked);
		x = attacked->GetX();
		y = attacked->GetY();
		attacked->EscapeMove(attacked);
		return;
	}

	if (attacked->NegativeFood() == true)
	{
		attacked->Collision(this);
		if (this->IsImmortal() == false)
		{
			delete this;
		}
		else
		{
			x = attacked->GetX();
			y = attacked->GetY();
		}
		delete attacked;
		return;
	}
	else if (attacked->IsAnimal() == false)
	{
		x = attacked->GetX();
		y = attacked->GetY();
		attacked->Collision(this);
		delete attacked;
		return;
	}

	if (this->type == attacked->GetType())
	{
		choice = 1;
		bool succes = true;
		succes = Breeding(attacked);
		if (succes == true)
		{
			CreateLogs(choice, attacked);
		}
		else
		{
			choice = 6;
			CreateLogs(choice, attacked);
		}
		return;
	}

	if (attacked->AttackDeflected(this))
	{
		choice = 4;
		CreateLogs(choice, attacked);
		return;
	}
	else if (attacked->AttackEscaped(attacked))
	{
		choice = 5;
		CreateLogs(choice, attacked);
		x = attacked->GetX();
		y = attacked->GetY();
		attacked->EscapeMove(attacked);
		return;
	}

	
	if (this->strenght >= attacked->GetStrenght())
	{
		choice = 2;
		CreateLogs(choice, attacked);
		world->OrganismKilled(attacked);
		x = attacked->GetX();
		y = attacked->GetY();
		delete attacked;
	}
	else
	{
		if (this->IsImmortal() == true)
		{
			choice = 8;
			CreateLogs(choice, attacked);
			this->EscapeMove(this);
		}
		else
		{
			choice = 3;
			CreateLogs(choice, attacked);
			world->OrganismKilled(this);
			if (this->DoubleMove() == true)
			{

			}
			else
			{
				delete this;
			}
		}
	}
}

void Animal::CreateLogs(int& choice, Organism* attacked)
{
	if (choice == 1)
	{
		ofstream log("log.txt", ios::app);
		log << "Organizm " << this->GetType() << " rozmnaza sie z organizmem " << attacked->GetType() << endl;
		log.close();
		cout << "Organizm " << this->GetType() << " rozmnaza sie z organizmem " << attacked->GetType() << endl;
	}
	else if (choice == 2)
	{
		ofstream log("log.txt", ios::app);
		log << "Organizm " << this->GetType() << " zabija organizm " << attacked->GetType() << endl;
		log.close();
		cout << "Organizm " << this->GetType() << " zabija organizm " << attacked->GetType() << endl;
	}
	else if (choice == 3)
	{
		ofstream log("log.txt", ios::app);
		log << "Organizm " << this->GetType() << " umiera atakujac organizm " << attacked->GetType() << endl;
		log.close();
		cout << "Organizm " << this->GetType() << " umiera atakujac organizm " << attacked->GetType() << endl;
	}
	else if (choice == 4)
	{
		ofstream log("log.txt", ios::app);
		log << "Organizm " << this->GetType() << " wykonuje nieskuteczny atak na " << attacked->GetType() << endl;
		log.close();
		cout << "Organizm " << this->GetType() << " wykonuje nieskuteczny atak na " << attacked->GetType() << endl;
	}
	else if (choice == 5)
	{
		ofstream log("log.txt", ios::app);
		log << "Organizm " << this->GetType() << " wykonuje nieskuteczny atak na z powodu ucieczki " << attacked->GetType() << endl;
		log.close();
		cout << "Organizm " << this->GetType() << " wykonuje nieskuteczny atak na z powodu ucieczki " << attacked->GetType() << endl;
	}
	else if (choice == 6)
	{
		ofstream log("log.txt", ios::app);
		log << "Organizm " << this->GetType() << " wykonuje nieskuteczna probe rozmnaza sie z organizmem " << attacked->GetType() << endl;
		log.close();
		cout << "Organizm " << this->GetType() << " wykonuje nieskuteczna probe rozmnaza sie z organizmem " << attacked->GetType() << endl;
	}
	else if (choice == 7)
	{
		ofstream log("log.txt", ios::app);
		log << "Organizm " << this->GetType() << " wykonuje nieskuteczna probe ataku na organizm " << attacked->GetType() << " bo jest niesmiertelny" << endl;
		log.close();
		cout << "Organizm " << this->GetType() << " wykonuje nieskuteczna probe ataku na organizm " << attacked->GetType() << " bo jest niesmiertelny" << endl;
	}
}

void Animal::SetStrenght(int new_strenght)
{
	this->strenght = new_strenght;
}

bool Animal::AttackDeflected(Organism* attacker)
{
	return false;
}

bool Animal::GoodSmell(Organism* checked)
{
	return true;
}

bool Animal::DoubleMove()
{
	return false;
}

bool Animal::AttackEscaped(Organism* checked)
{
	return false;
}

void Animal::EscapeMove(Organism* attacked)
{
	attacked->Action();
}

bool Animal::IsAnimal() const
{
	return true;
}

bool Animal::PositiveFood() const
{
	return false;
}

void Animal::PositiveEffect(Organism* eater)
{
	eater->SetStrenght(eater->GetStrenght() + 3);
}

bool Animal::NegativeFood() const
{
	return false;
}

void Animal::NegativeEffect(Organism* eater)
{
	world->OrganismKilled(eater);
	delete eater;
}

bool Animal::Breeding(Organism* partner)
{
	int x_nearby[] = { -1, 1, 0, 0 };
	int y_nearby[] = { 0, 0, -1, 1 };

	for (int i = 0; i < 4; ++i)
	{
		int newx = x + x_nearby[i];
		int newy = y + y_nearby[i];
		if (newx >= 1 && newx < world->GetLenght() + 1 && newy >= 1 && newy < world->GetHeight() + 1 && world->GetOrganismAtPoint(newx, newy) == nullptr)
		{
			Organism* potomek = NewAnimal(newx, newy, world);
			if (potomek != nullptr)
			{
				world->NewOrganism(potomek);
				return true;
			}
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		int newx = partner->GetX() + x_nearby[i];
		int newy = partner->GetY() + y_nearby[i];
		if (newx >= 1 && newx < world->GetLenght() + 1 && newy >= 1 && newy < world->GetHeight() + 1 && world->GetOrganismAtPoint(newx, newy) == nullptr)
		{
			Organism* potomek = NewAnimal(newx, newy, world);
			if (potomek != nullptr)
			{
				world->NewOrganism(potomek);
				return true;
			}
		}
	}

	return false;
}

bool Animal::IsImmortal()
{
	return false;
}

int Animal::GetX() const
{
	return x;
}

int Animal::GetY() const
{
	return y;
}

int Animal::GetInitiative() const
{
	return initiative;
}

int Animal::GetStrenght() const
{
	return strenght;
}

string Animal::GetType() const
{
	return type;
}

int Animal::GetAge() const
{
	return age;
}

Animal::~Animal()
{

}