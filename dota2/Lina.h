#pragma once
#include "NpcClass.h"
#include <string>

class Lina : public virtual Npc
{
protected:
	unsigned short doubleDamageChance;
public:
	Lina();
	Lina(std::string name, int health, float damage);
	~Lina();

	void TakeDamage(int damage) override;
	int CalculateDamage() override;
	void GetInfo() override;
	void Create() override;

	void UpgradePassive() override;

	Lina operator + (const Lina& assasin) const;

};