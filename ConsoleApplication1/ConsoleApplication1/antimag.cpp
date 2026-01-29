#include "AntiMage.h"
#include <iostream>

AntiMage::AntiMage()
{
    // Инициализация основных параметров персонажа
    SetName("Анти маг");
    TakeDamage(0);
    AddDamage(8);
    AddArmor(1);

    // Установка значения ловкости
    agility = 26;

    // Назначение уникальных способностей персонажа
    abilities[0] = "Мана брейк";
    abilities[1] = "Мана войд";
}

void AntiMage::Create()
{
    // Ввод имени пользователя для персонажа
    std::cout << "Введите имя Anti mage: ";
    std::string inputName;
    std::cin >> inputName;
    SetName(inputName);
    SetHealth(22);
    Npc::Create();
}

void AntiMage::GetInfo() const
{
    // Вывод общей информации о персонаже
    Npc::GetInfo();
    std::cout << "Ловкость: " << agility << std::endl;
}