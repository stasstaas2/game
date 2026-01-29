#pragma once
#pragma once
#include "Npc.h"
#include <string>

class AntiMage : public Npc
{
private:
    // ћассив уникальных способностей персонажа
    std::string abilities[2];
    // ’арактеристика ловкости
    int agility;

public:
    //  онструктор по умолчанию
    AntiMage();

    // ѕереопределенные методы базового класса
    void Create() override;
    void GetInfo() const override;

    // ћетоды получени€ значений характеристик
    int GetAgility() const { return agility; }
    std::string GetAbility(int index) const
    {
        if (index < 0 || index > 1) return "";
        return abilities[index];
    }

    // ћетоды установки значений характеристик
    void SetAgility(int a) { agility = a; }
    void SetAbility(int index, const std::string& ability)
    {