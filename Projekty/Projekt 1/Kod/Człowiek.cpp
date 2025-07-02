#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"Cz³owiek.h"
#include"Swiat.h"

using namespace std;

Human::Human(int strenght, int initiative, int x, int y, Swiat* world, string type) : Animal(strenght, initiative, x, y, world, type)
{
	skill_cooldown = 0;
	skill_duration = 0;
}

Human::Human(int strenght, int initiative, int x, int y, Swiat* world, string type, int age) : Animal(strenght, initiative, x, y, world, type, age)
{
	skill_cooldown = 0;
	skill_duration = 0;
}

void Human::Action()
{
	if (skill_duration > 0)
	{
		skill_duration--;
	}
	else if (skill_cooldown > 0)
	{
		skill_cooldown--;
	}

	bool possible_move = false;
	while (!possible_move)
	{
		int addx = 0;
		int addy = 0;
		bool good_move = false;

		while(!good_move)
		{
			cout << "Podaj ruch: ";

			int ch = _getch();
			if (ch == 224)
			{
				ch = _getch();
				switch (ch)
				{
				case 72:
					addx = -1;
					good_move = true;
					break;
				case 80:
					addx = 1;
					good_move = true;
					break;
				case 75:
					addy = -1;
					good_move = true;
					break;
				case 77:
					addy = 1;
					good_move = true;
					break;
				default:
					cout << "\r\033[2K" << "Nieprawidlowy ruch";
					Sleep(2000);
					cout << "\r\033[2K";
				}

			}
			else if (ch == 'S')
			{
				SkillUse();
			}
			else
			{
				cout << "\r\033[2K" << "Nieprawidlowy ruch";
				Sleep(2000);
				cout << "\r\033[2K";
			}
		}

		int newx = x + addx;
		int newy = y + addy;

		if (newx >= 1 && newx < world->GetLenght() + 1 && newy >= 1 && newy < world->GetHeight() + 1)
		{
			Organism* target_under_attack = world->GetOrganismAtPoint(newx, newy);

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
		else
		{
			cout << "\r\033[2K" << "Nieprawidlowy ruch";
			Sleep(2000);
			cout << "\r\033[2K";
			continue;
		}
	}
}

void Human::Collision(Organism* attacked)
{
	Animal::Collision(attacked);
}

char Human::Drawing()
{
	return 'H';
}

int Human::GetX() const
{
	return x;
}

int Human::GetY() const
{
	return y;
}

int Human::GetInitiative() const
{
	return initiative;
}

int Human::GetStrenght() const
{
	return strenght;
}

string Human::GetType() const
{
	return type;
}

int Human::GetAge() const
{
	return age;
}

Organism* Human::NewAnimal(int newx, int newy, Swiat* world)
{
	return new Human(0, 0, newx, newy, world, "Human");
}

bool Human::IsImmortal()
{
	if (skill_duration <= 0)
	{
		return false;
	}
	else if (skill_duration > 0)
	{
		return true;
	}
}

void Human::SkillUse()
{
	if (skill_duration == 0 && skill_cooldown == 0)
	{
		skill_duration = 5;
		skill_cooldown = 5;

		cout << "\r\033[2K" << "Umiejetnosc aktywowana";
		Sleep(2000);
		cout << "\r\033[2K";
	}
	else if (skill_duration != 0)
	{
		cout << "\r\033[2K" << "Umiejetnosc dziala jeszcze przez: " << skill_duration << " rund";
		Sleep(2000);
		cout << "\r\033[2K";
	}
	else if (skill_cooldown != 0)
	{
		cout << "\r\033[2K" << "Umiejetnosc jeszcze nie odnowiona bedzie dostepna za: " << skill_cooldown << " rund";
		Sleep(2000);
		cout << "\r\033[2K";
	}
}

void Human::EscapeMove(Organism* attacked)
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

Human::~Human()
{

}