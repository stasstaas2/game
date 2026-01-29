#include "Treasure.h"
#include <iostream>

Treasure::Treasure(ValueQuality q)
{
    // Установка качества сокровища
    quality = q;
}

void Treasure::ShowInfo() const
{
    // Вывод информации о сокровище
    std::cout << "Сокровище: " << name << std::endl;
}