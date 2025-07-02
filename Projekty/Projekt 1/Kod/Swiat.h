#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Organizm.h"

using namespace std;

class Organism;

class Swiat
{
private:
	string Name;
	vector<Organism*> tab_organism;
	int organism_ammount;
	int max_ammonut;
	char** world;
	int lenght;
	int height;
	int round;
	void CreateWorld();
	void CreateOrganism();
	void CheckOrganism();
	void DrawWorld();
	void NewTurn();
	void CleanWorld();
	void Informations();
	void RoundLogs();
	void SortOrgnaism();
	void SaveOrMenu();
	void SaveWorld();
	void LoadWorld();
public:
	void NewOrganism(Organism* new_Organism);
	Swiat(string Name, int lenght, int height);
	Swiat(string Name);
	void SetName(string name);
	string GetName();
	int GetOrAmmount();
	vector<Organism*>& GetOrganism();
	Organism* GetOrganismAtPoint(int x, int y);
	void OrganismKilled(Organism* dead);
	int GetLenght() const;
	int GetHeight() const;
	~Swiat();
};