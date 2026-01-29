#include "Lina.h"
#include <iostream>

Lina::Lina()
{
    // Установка базовых параметров персонажа
    SetName("Лина");
    TakeDamage(0);
    AddDamage(6);
    AddArmor(0);

    // Установка значения интеллекта
    intelligence = 20;

    // Назначение уникальных заклинаний персонажа
    spells[0] = "Dragon Slave";
    spells[1] = "Light Strike Array";
    spells[2] = "Laguna Blade";
}

void Lina::Create()
{
    // Ввод имени пользователя для персонажа
    std::cout << "Введите имя Lina: ";
    std::string inputName;
    std::cin >> inputName;
    SetName(inputName);
    SetHealth(18);
    Npc::Create();
}

void Lina::GetInfo() const
{
    // Вывод общей информации о персонаже
    Npc::GetInfo();
    std::cout << "Интеллект: " << intelligence << std::endl;
}