include "TrollWarlord.h"
#include <iostream>

TrollWarlord::TrollWarlord()
{
    // Установка базовых параметров персонажа
    SetName("Троль Варлорд");
    AddDamage(10);
    AddArmor(2);

    // Инициализация силы персонажа
    strength = 30;

    // Назначение уникальных оружий персонажа
    weapons[0] = "топоры (дальний бой)";
    weapons[1] = "топоры (ближний бой)";
    weapons[2] = "ярость войны";
    weapons[3] = "Батл транс";
}

void TrollWarlord::Create()
{
    // Ввод имени пользователя для персонажа
    std::cout << "Введите имя Troll Warlord: ";
    std::string inputName;
    std::cin >> inputName;
    SetName(inputName);
    SetHealth(32);
    Npc::Create();
}

void TrollWarlord::GetInfo() const
{
    // Вывод общей информации о персонаже
    Npc::GetInfo();
    std::cout << "Сила: " << strength << std::endl;