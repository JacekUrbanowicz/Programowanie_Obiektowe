#pragma once
#include"Organizm.h"
#ifndef SORT_H
#define SORT_H

using namespace std;

class Organism;

class CompereOrganism
{
public:
	CompereOrganism();
	bool operator()(Organism* one, Organism* two) const;
	~CompereOrganism();
};
#endif