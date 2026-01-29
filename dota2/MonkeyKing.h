#pragma once
#include "NpcClass.h"
#include "Lina.h"
#include "ShadowFiend.h"
#include <string>

class MonkeyKing : public ShadowFiend, public Lina
{
protected:
	unsigned short evasionFactor;
public:
	MonkeyKing();
	void TakeDamage(int damage) override;
	int CalculateDamage() override;
	void GetInfo() override;
	void Create() override;
	void UpgradePassive() override;
};