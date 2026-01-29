#include "Evil.h"

Evil::Evil(std::string n, int h, int a, int d)
{
    // ”становка имени враждебного персонажа
    SetName(n);

    // »нициализаци€ параметров здоровь€, урона и брони
    TakeDamage(0);
    Heal(h);

    AddDamage(d);
    AddArmor(a);
}