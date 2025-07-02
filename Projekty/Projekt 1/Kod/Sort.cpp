#pragma once
#include"Sort.h"

using namespace std;

CompereOrganism::CompereOrganism()
{

}

bool CompereOrganism::operator()(Organism* one, Organism* two) const
{
	if (one->GetInitiative() != two->GetInitiative())
	{
		if (one->GetInitiative() > two->GetInitiative())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (one->GetAge() > two->GetAge())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

CompereOrganism::~CompereOrganism()
{

}