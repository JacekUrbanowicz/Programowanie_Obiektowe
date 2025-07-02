#pragma once
#include "Organizm.h"
#include"Swiat.h"
#ifndef ROSLINA_H
#define ROSLINA_H

using namespace std;

class Swiat;

class Plant : public Organism
{
public:
	Plant(int strenght, int initiative, int x, int y, Swiat* world, string type);
	Plant(int strenght, int initiative, int x, int y, Swiat* world, string type, int age);
	virtual void Action() override;
	virtual void Collision(Organism* attacker) override;
	virtual void CreateLogs(int& choice, Organism* attacked) override;
	bool AttackDeflected(Organism* attacker);
	bool GoodSmell(Organism* checked);
	bool DoubleMove();
	bool AttackEscaped(Organism* checked);
	void EscapeMove(Organism* attacked);
	virtual char Drawing() override = 0;
	int GetX() const;
	int GetY() const;
	int GetInitiative() const;
	int GetStrenght() const;
	string GetType() const;
	int GetAge() const;
	void SetStrenght(int new_strenght);
	bool IsAnimal() const override;
	bool PositiveFood() const;
	void PositiveEffect(Organism* eater);
	bool NegativeFood() const;
	virtual void NegativeEffect(Organism* eater) override;
	virtual Organism* NewPlant(int newx, int newy, Swiat* world) = 0;
	virtual void KillAnimals();
	bool IsImmortal();
	virtual ~Plant();
};
#endif