#include<iostream>
#include<string>
#include<Windows.h>
#include "Menu.h"
#include "Swiat.h"

using namespace std;

Menu::Menu()
{
	choose = '*';
	Management();
}

void Menu::SetChoose(char choose)
{
	this -> choose = choose;
}

char Menu::GetChoose() const
{
	return choose;
}

void Menu::Management()
{
	while (true)
	{
		if (choose == '*')
		{
			cout << "Autor: Jacek Urbanowicz 203905" << endl;
			cout << endl << "--------" << " MENU " << "--------" << endl;
			cout << "1. Nowa Gra" << endl;
			cout << "2. Wczytaj Gre" << endl;
			cout << "3. Wyjdz z Gry" << endl;
			cout << endl;
		}

		else
		{
			cout << endl << "--------" << " MENU " << "--------" << endl;
			cout << "1. Nowa Gra" << endl;
			cout << "2. Wczytaj Gre" << endl;
			cout << "3. Wyjdz z Gry" << endl;
			cout << endl;
		}
		cin >> choose;

		switch (choose)
		{
			case '1':
			{
				bool world_created = false;
				while(!world_created)
				{
					system("cls");
					string world_name;
					bool good_world = false;
					int lenght = 0;
					int hight = 0;
					cout << "Podaj nazwe swiata: ";
					cin >> world_name;
					cout << "Podaj szerokosc: ";
					cin >> lenght;
					cout << "Podaj wysokosc: ";
					cin >> hight;
					good_world = GoodWorld(lenght, hight);
					system("cls");

					if (good_world == true)
					{
						Swiat World(world_name, lenght, hight);
						world_created = true;
					}
				}
				break;
			}
			case '2':
			{
				system("cls");
				string world_name;
				cout << "Podaj nazwe swiata ktory wczytac: ";
				cin >> world_name;
				Swiat World(world_name);
				break;
			}
			case '3':
			{
				system("cls");
				cout << "Zamykanie programu" << endl << endl;
				break;
			}
			default:
			{
				system("cls");
				cout << "Przepraszam, nie ma takiej opcji w menu" << endl << endl;
				break;
			}
		}
		
		if (choose == '3')
		{
			break;
		}
		
	}
}

bool Menu::GoodWorld(int lenght, int hight)
{
	if (lenght < 5 && hight < 5)
	{
		cout << "Plansza zbyt mala minimalny wymiar to 5 na 5";
		Sleep(2000);
		system("cls");
		return false;
	}
	else
	{
		return true;
	}
}

Menu::~Menu()
{

}