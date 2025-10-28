#include <iostream>
#include "windows.h"
using namespace std;


unsigned short GetChoice(unsigned short min, unsigned short max) {
    unsigned short choice;
    cin >> choice;

    while (choice < min || choice > max) {
        cout << "Неверный ввод! Введите число от " << min << " до " << max << ": ";
        cin >> choice;
    }

    return choice;
}

//модификаторы доступа:
// private - приватный, запрещает доступ к свойствам и классам за пределами самого класса
// protected - защищенный, можно передавать свойства и методы в классы наследники, но не использовать в основном потоке программы
// public - публичный, общедоступный, можно использовать везде

class Npc
{
protected:
    string name{ "персонаж" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };
public:
    virtual void GetInfo()
    {
        cout << "Имя - " << name << endl;
        cout << "Здоровье - " << health << endl;
        cout << "Урон - " << damage << endl;
    }
    virtual void Create() {};
};

class Warrior : public virtual Npc
{
protected:
    unsigned short strenght{ 31 };
    string weapons[4] = { "кастет", "дубинка", "клинок", "меч" };
public:
    Warrior()
    {
        name = "воин";
        health = 35;
        damage = 10;
    }
    Warrior(string name, unsigned int health, float damage)
    {
        cout << "кастомный конструктор война" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }

    void GetWeapons()
    {
        cout << name << " взял в руки " << weapons[lvl - 1];
    }
    void GetInfo() override
    {
        Npc::GetInfo();
        cout << "Сила - " << strenght << endl;
        cout << "Доступное оружие - ";
        for (int i = 0; i < lvl; i++)
            cout << weapons[i] << endl;
    }
    void Create() override
    {
        cout << "Вы создали война" << endl;
        cout << "Введите имя персонажа\t";
        cin >> name;
        GetInfo();
        GetWeapons();
    }
    bool operator == (const Warrior& warrior) const
    {
        return ((warrior.damage == this->damage) && (warrior.health == this->health)
            && (warrior.strenght == this->strenght));
    }
    ~Warrior()
    {
        cout << name << " пал смертью храбрых" << endl;
    }
};

class Wizard : public virtual Npc
{
protected:
    unsigned short intellect = 27;
    string spell[4] = { "вспышка", "магическая стрела", "огненный шар", "метеоритный дождь" };
public:
    Wizard()
    {
        name = "волшебник";
        health = 23;
        damage = 15;
    }
    Wizard(string name, unsigned int health, float damage)
    {
        cout << "кастомный конструктор волшебника" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }
    void GetInfo() override
    {
        Npc::GetInfo();
        cout << "Интеллект - " << intellect << endl;
        cout << "Доступные заклинания в книге заклинаний - ";
        for (int i = 0; i < lvl; i++)
            cout << spell[i] << endl;
    }
    void CastSpell()
    {
        cout << name << " применяет " << spell[lvl - 1] << endl;
    }
    void Create() override
    {
        cout << "Вы создали волшебника" << endl;
        cout << "Введите имя персонажа\t";
        cin >> name;
        GetInfo();
        CastSpell();
    }
    Wizard operator + (const Wizard& wizard) const
    {
        return Wizard(this->name, (this->health + wizard.health), (this->damage + wizard.damage));
    }
    ~Wizard()
    {
        cout << name << " испустил дух" << endl;
    }
};

class Paladin : public Warrior, public Wizard
{
public:
    Paladin()
    {
        name = "паладин";
        health = 25;
        damage = 12;
        strenght = 27;
    }
    void GetInfo() override
    {
        Warrior::GetInfo();
        cout << "Интеллект - " << intellect << endl;
        cout << "Доступные заклинания - ";
        for (int i = 0; i < lvl; i++)
            cout << spell[i] << endl;
    }
    void Create() override
    {
        cout << "Вы создали паладина" << endl;
        cout << "Введите имя персонажа\t";
        cin >> name;
        GetInfo();
        CastSpell();
        GetWeapons();
    }
};

class Player
{
public:
    void Create(Npc* player)
    {
        player->Create();
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Warrior* warrior = new Warrior();
    Warrior* warrior2 = new Warrior();
    cout << (*warrior == *warrior2) << endl;

    Wizard* wizard1 = new Wizard();
    Wizard* wizard2 = new Wizard();
    Wizard* megaWizard = new Wizard();
    *megaWizard = *wizard1 + *wizard2;
    megaWizard->GetInfo();

    Paladin* paladin = new Paladin();
    Player* player = new Player();

    cout << "Привет, путник\nПрисядь у костра и расскажи о себе\n";
    cout << "Ты впервые тут? (1 - новый персонаж, 2 - загрузить)\n";

    unsigned short choice = GetChoice(1, 2); // использование функции

    if (choice == 1)
    {
        cout << "Расскажи о своих навыках\n\t1 - Воин\n\t2 - Волшебник\n\t3 - Паладин\n";
        choice = GetChoice(1, 3); // снова используем ту же функцию

        switch (choice)
        {
        case 1:
            player->Create(warrior);
            break;
        case 2:
            player->Create(wizard1);
            break;
        case 3:
            player->Create(paladin);
            break;
        }
    }

    delete warrior;
    delete warrior2;
    delete wizard1;
    delete wizard2;
    delete megaWizard;
    delete paladin;
    delete player;

    return 0;
}