#pragma once
#include "Zwierze.h"
#include"Swiat.h"
#include<string>
#ifndef CZ£OWIEK_H
#define CZ£OWIEK_H

using namespace std;

class Swiat;

class Human : public Animal
{
private:
	int skill_cooldown;
	int skill_duration;

public:
	Human(int strenght, int initiative, int x, int y, Swiat* world, string type);
	Human(int strenght, int initiative, int x, int y, Swiat* world, string type, int age);
	void Action() override;
	void Collision(Organism* attacked) override;
	char Drawing() override;
	int GetX() const;
	int GetY() const;
	int GetInitiative() const;
	int GetStrenght() const;
	string GetType() const;
	int GetAge() const;
	Organism* NewAnimal(int newx, int newy, Swiat* world);
	bool IsImmortal() override;
	void SkillUse();
	void EscapeMove(Organism* attacked) override;
	~Human();
};
#endif