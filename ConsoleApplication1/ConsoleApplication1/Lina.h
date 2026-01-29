#pragma once
#include "Npc.h"
#include <string>

class Lina : public Npc
{
private:
    // Массив заклинаний персонажа
    std::string spells[3];
    // Характеристика интеллекта
    int intelligence;

public:
    // Конструктор по умолчанию
    Lina();

    // Переопределенные методы базового класса
    void Create() override;
    void GetInfo() const override;

    // Методы получения значений характеристик
    int GetIntelligence() const;
    std::string GetSpell(int index) const;

    // Методы установки значений характеристик
    void SetIntelligence(int intel);
    void SetSpell(int index, const std::string& spell);
};
