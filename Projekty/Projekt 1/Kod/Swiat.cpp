#include<iostream>
#include<string>
#include<Windows.h>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include"Swiat.h"
#include"Organizm.h"
#include"Sort.h"
#include"Cz³owiek.h"
#include"Wilk.h"
#include"Owca.h"
#include"Zolw.h"
#include"Lis.h"
#include"Antylopa.h"
#include"Trawa.h"
#include"Mlecz.h"
#include"Guarana.h"
#include"Jagody.h"
#include"Barszcz.h"

using namespace std;

Swiat::Swiat(string Name, int lenght, int height) : lenght(lenght), height(height)
{
	this->Name = Name;
	cout << "Stworzenie Swiata " << this->Name << endl;
	round = 1;
	organism_ammount = 0;
	max_ammonut = 400;
	world = nullptr;
	CreateWorld();
	CreateOrganism();

	while(true)
	{
		Informations();
		CheckOrganism();
		DrawWorld();
		RoundLogs();
		SaveOrMenu();
		system("cls");
		NewTurn();
	}
	
}

Swiat::Swiat(string Name) : Name(Name)
{
	LoadWorld();

	CreateWorld();

	
	while(true)
	{
		Informations();
		CheckOrganism();
		DrawWorld();
		RoundLogs();
		SaveOrMenu();
		system("cls");
		NewTurn();
	}
}

void Swiat::CreateWorld()
{
	world = new char* [height + 2];
	for (int i = 0; i < height + 2; i++)
	{
		world[i] = new char[lenght + 2];
	}

	for (int i = 0; i < height + 2; i++)
	{
		for (int j = 0; j < lenght + 2; j++)
		{
			if (i == 0 && j == 0)
			{
				world[i][j] = 201;
			}
			else if (i == 0 && j == lenght + 1)
			{
				world[i][j] = 187;
			}
			else if (i == height + 1 && j == 0)
			{
				world[i][j] = 200;
			}
			else if (i == height + 1 && j == lenght + 1)
			{
				world[i][j] = 188;
			}
			else if (i == 0 || i == height + 1)
			{
				world[i][j] = 205;
			}
			else if (j == 0 || j == lenght + 1)
			{
				world[i][j] = 186;
			}
			else
			{
				world[i][j] = '.';
			}
		}
	}
}

void Swiat::NewOrganism(Organism* new_Organism)
{
	tab_organism.push_back(new_Organism);
	organism_ammount++;
}

void Swiat::CreateOrganism()
{
	srand(time(NULL));

	int human_x = rand() % (lenght - 2) + 1;
	int human_y = rand() % (height - 2) + 1;

	NewOrganism(new Human(5, 4, human_x, human_y, this, "Czlowiek"));

	
	while(organism_ammount < 3)
	{
		int x = rand() % (lenght - 2) + 1;
		int y = rand() % (height - 2) + 1;

		if (GetOrganismAtPoint(x,y) == nullptr)
		{
			NewOrganism(new Wolf(9, 5, x, y, this, "Wilk"));
		}
	}

	while (organism_ammount < 5)
	{
		int x = rand() % (lenght - 2) + 1;
		int y = rand() % (height - 2) + 1;

		if (GetOrganismAtPoint(x, y) == nullptr)
		{
			NewOrganism(new Sheep(4, 4, x, y, this, "Owca"));
		}
	}

	while (organism_ammount < 7)
	{
		int x = rand() % (lenght - 2) + 1;
		int y = rand() % (height - 2) + 1;

		if (GetOrganismAtPoint(x, y) == nullptr)
		{
			NewOrganism(new Fox(3, 7, x, y, this, "Lis"));
		}
	}

	while (organism_ammount < 9)
	{
		int x = rand() % (lenght - 2) + 1;
		int y = rand() % (height - 2) + 1;

		if (GetOrganismAtPoint(x, y) == nullptr)
		{
			NewOrganism(new Turtle(2, 1, x, y, this, "Zolw"));
		}
	}

	while (organism_ammount < 11)
	{
		int x = rand() % (lenght - 2) + 1;
		int y = rand() % (height - 2) + 1;

		if (GetOrganismAtPoint(x, y) == nullptr)
		{
			NewOrganism(new Antelope(4, 4, x, y, this, "Antylopa"));
		}
	}

	while (organism_ammount < 13)
	{
		int x = rand() % (lenght - 2) + 1;
		int y = rand() % (height - 2) + 1;

		if (GetOrganismAtPoint(x, y) == nullptr)
		{
			NewOrganism(new Grass(0, 0, x, y, this, "Trawa"));
		}
	}

	while (organism_ammount < 15)
	{
		int x = rand() % (lenght - 2) + 1;
		int y = rand() % (height - 2) + 1;

		if (GetOrganismAtPoint(x, y) == nullptr)
		{
			NewOrganism(new Milkweed(0, 0, x, y, this, "Mlecz"));
		}
	}

	while (organism_ammount < 17)
	{
		int x = rand() % (lenght - 2) + 1;
		int y = rand() % (height - 2) + 1;

		if (GetOrganismAtPoint(x, y) == nullptr)
		{
			NewOrganism(new Guarana(0, 0, x, y, this, "Guarana"));
		}
	}

	while (organism_ammount < 19)
	{
		int x = rand() % (lenght - 2) + 1;
		int y = rand() % (height - 2) + 1;

		if (GetOrganismAtPoint(x, y) == nullptr)
		{
			NewOrganism(new Wolfberries(99, 0, x, y, this, "WilczeJagody"));
		}
	}

	while (organism_ammount < 21)
	{
		int x = rand() % (lenght - 2) + 1;
		int y = rand() % (height - 2) + 1;

		if (GetOrganismAtPoint(x, y) == nullptr)
		{
			NewOrganism(new Borscht(10, 0, x, y, this, "BarszczSosnowskiego"));
		}
	}

	SortOrgnaism();

}

void Swiat::CheckOrganism()
{
	for (int i = 0; i < height + 2; i++)
	{
		for (int j = 0; j < lenght + 2; j++)
		{
			for (int a = 0; a < organism_ammount; a++)
			{
				if (tab_organism[a]->GetX() == i && tab_organism[a]->GetY() == j)
				{
					world[i][j] = tab_organism[a]->Drawing();
				}
			}
		}
	}
}

void Swiat::DrawWorld()
{
	for (int i = 0; i < height + 2; i++)
	{
		for (int j = 0; j < lenght + 2; j++)
		{
			cout << world[i][j];
		}
		cout << endl;
	}
}

void Swiat::NewTurn()
{
	SortOrgnaism();

	vector<Organism*> old_tab = tab_organism;

	for (Organism* organism : old_tab)
	{
		auto it = find(tab_organism.begin(), tab_organism.end(), organism);
		if (it == tab_organism.end()) continue;

		cout << endl;
		cout << "===== Ruch organizmu: " << organism->GetType() << " o wieku: " << organism->GetAge() << " (" << organism->GetX() << "," << organism->GetY() << ") =====" << endl;

		CheckOrganism();
		DrawWorld();
		organism->Action();
		CleanWorld();
		system("cls");
	}

	SaveWorld();
}

void Swiat::CleanWorld()
{
	for (int i = 1; i < height + 1; i++)
	{
		for (int j = 1; j < lenght + 1; j++)
		{
			world[i][j] = '.';
		}
	}
}

void Swiat::Informations()
{
	cout << "======== Runda " << round << " ========";
	cout << endl << endl;
	round++;
}

void Swiat::RoundLogs()
{
	ifstream log("log.txt");
	string line;
	cout << "===== Zdarzenia w tej rundzie =====" << endl;
	while (getline(log, line)) 
	{
		cout << line << endl;
	}
	log.close();
	ofstream clear("log.txt", ios::trunc);
	clear.close();
}

void Swiat::SortOrgnaism()
{
	stable_sort(tab_organism.begin(), tab_organism.end(), CompereOrganism());
}

void Swiat::SaveOrMenu()
{
	char instruction = '*';
	cout << "Aby wyjsc z gry wybierz 1 nastepna runda wybierz dowolny przycisk: ";
	cin >> instruction;
	if (instruction == '1')
	{
		system("cls");
		exit(0);
	}
}

void Swiat::SaveWorld()
{
	string name = Name + ".txt";
	ofstream file(name);

	file << lenght << " " << height << endl;
	file << round << " " << organism_ammount << endl;

	for (Organism* organism : tab_organism)
	{
		file << organism->GetType() << " " << organism->GetStrenght() << " " << organism->GetInitiative() << " " << organism->GetX() << " " << organism->GetY() << " " << organism->GetAge() << endl;
	}
	file.close();
}

void Swiat::LoadWorld()
{
	string name = Name + ".txt";
	ifstream file(name);
	if (file.is_open())
	{
		int help_organism = 0;

		file >> lenght >> height;
		file >> round >> help_organism;

		for (int i = 0; i < help_organism; i++)
		{
			string type;
			int strenght;
			int initiative;
			int x;
			int y;
			int age;
			file >> type >> strenght >> initiative >> x >> y >> age;

			if (type == "Czlowiek")
			{
				NewOrganism(new Human(strenght, initiative, x, y, this, "Czlowiek", age));
			}
			else if (type == "Wilk") 
			{
				NewOrganism(new Wolf(strenght, initiative, x, y, this, "Wilk", age));
			}
			else if (type == "Owca") 
			{
				NewOrganism(new Sheep(strenght, initiative, x, y, this, "Owca", age));
			}
			else if (type == "Lis") 
			{
				NewOrganism(new Fox(strenght, initiative, x, y, this, "Lis", age));
			}
			else if (type == "Zolw") 
			{
				NewOrganism(new Turtle(strenght, initiative, x, y, this, "Zolw", age));
			}
			else if (type == "Antylopa") 
			{
				NewOrganism(new Antelope(strenght, initiative, x, y, this, "Antylopa", age));
			}
			else if (type == "Trawa") 
			{
				NewOrganism(new Grass(strenght, initiative, x, y, this, "Trawa", age));
			}
			else if (type == "Mlecz") 
			{
				NewOrganism(new Milkweed(strenght, initiative, x, y, this, "Mlecz", age));
			}
			else if (type == "Guarana") 
			{
				NewOrganism(new Guarana(strenght, initiative, x, y, this, "Guarana", age));
			}
			else if (type == "WilczeJagody") 
			{
				NewOrganism(new Wolfberries(strenght, initiative, x, y, this, "WilczeJagody", age));
			}
			else if (type == "BarszczSosnowskiego") 
			{
				NewOrganism(new Borscht(strenght, initiative, x, y, this, "BarszSosnowskiego", age));
			}

		}
		file.close();
		cout << "Wczytano stan swiata z pliku: " << name << endl;
		Sleep(2000);
		system("cls");
	}
	else
	{
		cout << "Podano bledna nazwe swiata";
		Sleep(2000);
		exit(0);
	}
}

void Swiat::SetName(string name)
{
	this->Name = name;
}

string Swiat::GetName()
{
	return Name;
}

int Swiat::GetOrAmmount()
{
	return organism_ammount;
}

vector<Organism*>& Swiat::GetOrganism()
{
	return tab_organism;
}

Organism* Swiat::GetOrganismAtPoint(int x, int y)
{
	for (int i = 0; i < organism_ammount; i++)
	{
		if (tab_organism[i]->GetX() == x && tab_organism[i]->GetY() == y)
		{
			return tab_organism[i];
		}
	}

	return nullptr;
}

void Swiat::OrganismKilled(Organism* dead)
{
	for (auto deleted = tab_organism.begin(); deleted != tab_organism.end(); deleted++)
	{
		if(*deleted == dead)
		{
			tab_organism.erase(deleted);
			organism_ammount--;
			break;
		}
	}
}

int Swiat::GetLenght() const
{
	return lenght;
}

int Swiat::GetHeight() const
{
	return height;
}

Swiat::~Swiat()
{
	if (world != nullptr)
	{
		for(int i = 0; i < height + 2; i++)
		{
			delete[] world[i];
		}
		delete[] world;
	}
}