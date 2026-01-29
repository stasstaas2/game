#include "MonkeyKing.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include "consoleManager.h"

using namespace std;

MonkeyKing::MonkeyKing()
{
	name = "МК";
	maxHealth = 25;
	health = 25;
	damage = 12;
	evasionFactor = 8; // 1 - 100;
	damageMultiplier = 10;
	doubleDamageChance = 2;
	srand(std::time(0));
}

void MonkeyKing::TakeDamage(int damage)
{
	int random_num = 1 + std::rand() % 100;
	if (random_num <= evasionFactor)
	{
		printSlowly("Вы уклонилось от удара! ", false);
		return;
	}
	Npc::TakeDamage(damage);
}

int MonkeyKing::CalculateDamage()
{
	int random_num = 1 + std::rand() % 100;

	if (random_num <= doubleDamageChance)
	{
		printSlowly("Вы совершили двойной удар!", false);
		return ShadowFiend::CalculateDamage() * 2;
	}

	return ShadowFiend::CalculateDamage();
}

void MonkeyKing::UpgradePassive()
{
	evasionFactor += 5;
	damageMultiplier += 2;
	doubleDamageChance += 2;
}

void MonkeyKing::GetInfo()
{
	ShadowFiend::GetInfo();
	cout << "Шанс уклонения(%) - " << evasionFactor << endl;
	cout << "Шанс на вторую атаку(%) - " << doubleDamageChance << endl;
}

void MonkeyKing::Create()
{
	cout << "Вы создали троль" << endl;
	cout << "Введите имя персонажа\t";
	cin >> name;
	cout << endl;
	GetInfo();
	cout << endl;
}