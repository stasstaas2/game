#include "Lina.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "consoleManager.h"

using namespace std;

Lina::Lina()
{
	name = "лина";
	maxHealth = 20;
	health = 20;
	damage = 15;
	doubleDamageChance = 10; //1 - 100
	srand(std::time(0));
}

Lina::Lina(std::string name, int health, float damage)
{
	cout << "Кастомный конструктор лины" << endl;
	this->name = name;
	this->health = health;
	this->damage = damage;
}

void Lina::TakeDamage(int damage)
{
	Npc::TakeDamage(damage);
}

int Lina::CalculateDamage()
{
	int random_num = 1 + std::rand() % 100;

	if (random_num <= doubleDamageChance)
	{
		printSlowly("Вы совершили двойной удар!", false);
		return damage * 2;
	}

	return damage;
}

void Lina::UpgradePassive()
{
	doubleDamageChance += 5;
}

void Lina::GetInfo()
{
	Npc::GetInfo();
	cout << "Шанс на вторую атаку(%) - " << doubleDamageChance << endl;
}

void Lina::Create()
{
	cout << "Вы создали лину" << endl;
	cout << "Введите имя персонажа\t";
	cin >> name;
	cout << endl;
	GetInfo();
	cout << endl;
}

Lina Lina::operator + (const Lina& assasin) const
{
	return Lina(
		this->name,
		(this->health + assasin.health),
		(this->damage + assasin.damage)
	);
}

Lina::~Lina()
{
	cout << name << " испустил дух" << endl;
}

