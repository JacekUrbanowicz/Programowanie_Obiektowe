#pragma once
#include <iostream>
#include <string>

using namespace std;

class Menu
{
private:
	char choose;
	void Management();
	bool GoodWorld(int lenght, int hight);
public:
	Menu();
	void SetChoose(char choose);
	char GetChoose() const;
	~Menu();
};