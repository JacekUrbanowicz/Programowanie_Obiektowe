#pragma once
#include<string>
#include<fstream>
#include "Organizm.h"
#include"Swiat.h"
#ifndef ZWIERZE_H
#define ZWIERZE_H

using namespace std;

class Swiat;

class Animal : public Organism
{
private:
	bool Breeding(Organism* partner);

public:
	Animal(int strenght, int initiative, int x, int y, Swiat* world, string type);
	Animal(int strenght, int initiative, int x, int y, Swiat* world, string type, int age);
	virtual void Action() override;
	virtual void Collision(Organism* attacked) override;
	virtual char Drawing() override = 0;
	int GetX() const;
	int GetY() const;
	int GetInitiative() const;
	int GetStrenght() const;
	void SetStrenght(int new_strenght);
	string GetType() const;
	int GetAge() const;
	virtual void CreateLogs(int& choice, Organism* attacked) override;
	bool AttackDeflected(Organism* attacker);
	bool GoodSmell(Organism* checked);
	bool DoubleMove();
	bool AttackEscaped(Organism* checked);
	void EscapeMove(Organism* attacked);
	bool IsAnimal() const override;
	bool PositiveFood() const;
	virtual void PositiveEffect(Organism* eater) override;
	bool NegativeFood() const;
	virtual void NegativeEffect(Organism* eater) override;
	virtual Organism* NewAnimal(int newx, int newy, Swiat* world) = 0;
	bool IsImmortal();
	virtual ~Animal();
};
#endif