#include "ShadowFiend.h"
#include <iostream>
#include <fstream>

using namespace std;

ShadowFiend::ShadowFiend()
{
	name = "сф";
	maxHealth = 35;
	health = 35;
	damage = 10;
	damageMultiplier = 10; // 0 - 100
}

ShadowFiend::ShadowFiend(std::string name, int health, float damage)
{
	cout << "кастомный конструктор сфа" << endl;
	this->name = name;
	this->health = health;
	this->damage = damage;
}

void ShadowFiend::TakeDamage(int damage)
{
	Npc::TakeDamage(damage);
}

int ShadowFiend::CalculateDamage()
{
	float tempDamage = static_cast<float>(damage) * (1.0f + static_cast<float>(damageMultiplier) / 100.0f);
	return static_cast<int>(tempDamage);
}

void ShadowFiend::GetInfo()
{
	Npc::GetInfo();
	cout << "Множитель урона(%) - " << damageMultiplier << endl;

}

void ShadowFiend::Create()
{
	cout << "Вы создали сфа" << endl;
	cout << "Введите имя персонажа\t";
	cin >> name;
	cout << endl;
	GetInfo();
	cout << endl;
	cout << endl;
}

void ShadowFiend::UpgradePassive()
{
	damageMultiplier += 5;
}

bool ShadowFiend::operator == (const ShadowFiend& warrior) const
{
	return (warrior.damage == this->damage) &&
		(warrior.health == this->health) &&
		(warrior.damageMultiplier == this->damageMultiplier);
}

ShadowFiend& ShadowFiend::operator = (const Npc& npc)
{
	if (this != &npc)
	{
		this->name = npc.GetName();
		this->health = npc.GetHealth();
		this->damage = npc.GetDamage();
		this->lvl = npc.GetLvl();
		return *this;
	}
	return *this;
}

ShadowFiend::~ShadowFiend()
{
	cout << name << " погиб с честью " << endl;
}
