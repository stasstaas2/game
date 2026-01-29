#pragma once
#include <iostream>
#include <string>

class Npc
{
private:
    // Основные характеристики персонажа
    std::string name;
    int health;
    int maxHealth;
    int damage;
    int armor;
    int lvl;
    int potions;

public:
    // Конструктор по умолчанию
    Npc()
    {
        name = "Npc";
        health = 10;
        maxHealth = health;
        armor = 5;
        damage = 2;
        lvl = 1;
        potions = 2;
    }

    // Виртуальный метод создания персонажа
    virtual void Create()
    {
        maxHealth = health;
        potions = 2;
    }

    // Виртуальный метод вывода информации о персонаже
    virtual void GetInfo() const
    {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Здоровье: " << health << "/" << maxHealth << std::endl;
        std::cout << "Урон: " << damage << std::endl;
        std::cout << "Броня: " << armor << std::endl;
        std::cout << "Уровень: " << lvl << std::endl;
        std::cout << "Зелья: " << potions << std::endl;
    }

    // Виртуальный метод получения имени класса
    virtual std::string GetClassName() const
    {
        return name;
    }

    // Виртуальный деструктор
    virtual ~Npc() {}

    // Метод установки здоровья
    void SetHealth(int hp)
    {
        health = hp;
        maxHealth = hp;
    }

    // Методы получения значений характеристик
    int GetHealth() const { return health; }
    int GetMaxHealth() const { return maxHealth; }
    int GetDamage() const { return damage; }
    int GetArmor() const { return armor; }
    int GetLevel() const { return lvl; }
    int GetPotions() const { return potions; }
    std::string GetName() const { return name; }

    // Метод получения урона
    void TakeDamage(int dmg)
    {
        int effectiveDmg = dmg - armor;
        if (effectiveDmg < 0) effectiveDmg = 0;
        health -= effectiveDmg;
        if (health < 0) health = 0;
    }

    // Метод восстановления здоровья
    void Heal(int amount)
    {
        health += amount;
        if (health > maxHealth) health = maxHealth;
    }

    // Метод использования зелья
    bool UsePotion()
    {
        if (potions > 0 && health < maxHealth)
        {
            Heal(20);
            potions--;
            return true;
        }
        return false;
    }

    // Методы добавления характеристик
    void AddDamage(int amount) { damage += amount; }
    void AddArmor(int amount) { armor += amount; }
    void AddPotions(int amount) { potions += amount; }
    void SetName(const std::string& n) { name = n; }
};