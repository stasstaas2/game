#pragma once
#include "Npc.h"
#include <string>

class Evil : public Npc
{
public:
    // Конструктор для создания враждебного персонажа с заданными параметрами
    Evil(std::string n, int h, int a, int d);
};
