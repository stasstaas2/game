#pragma once
#include "Npc.h"
#include <string>

// **********************************************************************
// * Автор: Владимир Титов                                               *
// * Дата создания: 25.01.2024                                           *
// * Описание: Интерфейс класса TrollWarlord - воинственный персонаж     *
// **********************************************************************

class TrollWarlord : public Npc
{
private:
    // Характеристика силы персонажа
    int strength;
    // Массив уникальных оружий персонажа
    std::string weapons[4];

public:
    // Конструктор по умолчанию
    TrollWarlord();

    // Переопределенные методы базового класса
    void Create() override;
    void GetInfo() const override;

    // Методы получения значений характеристик
    int GetStrength() const { return strength; }
    std::string GetWeapon(int index) const
    {
        if (index < 0 || index > 3) return "";
        return weapons[index];
    }

    // Методы установки значений характеристик
    void SetStrength(int s) { strength = s; }
    void SetWeapon(int index, const std::string& weapon)
    {
