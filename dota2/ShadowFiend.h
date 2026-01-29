#pragma once
#include "NpcClass.h"
#include <string>

class ShadowFiend : public virtual Npc
{
protected:
	unsigned short damageMultiplier;
public:
	ShadowFiend();
	ShadowFiend(string name, int health, float damage);
	~ShadowFiend();

	int CalculateDamage() override;
	void TakeDamage(int damage) override;
	void GetInfo() override;
	void Create() override;

	void UpgradePassive() override;

	bool operator == (const ShadowFiend& warrior) const;

	ShadowFiend& operator = (const Npc& npc);
};