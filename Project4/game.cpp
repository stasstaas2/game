#include <iostream>
#include "windows.h"
using namespace std;


unsigned short GetChoice(unsigned short min, unsigned short max) {
    unsigned short choice;
    cin >> choice;

    while (choice < min || choice > max) {
        cout << "�������� ����! ������� ����� �� " << min << " �� " << max << ": ";
        cin >> choice;
    }

    return choice;
}

//������������ �������:
// private - ���������, ��������� ������ � ��������� � ������� �� ��������� ������ ������
// protected - ����������, ����� ���������� �������� � ������ � ������ ����������, �� �� ������������ � �������� ������ ���������
// public - ���������, �������������, ����� ������������ �����

class Npc
{
protected:
    string name{ "��������" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };
public:
    virtual void GetInfo()
    {
        cout << "��� - " << name << endl;
        cout << "�������� - " << health << endl;
        cout << "���� - " << damage << endl;
    }
    virtual void Create() {};
};

class Warrior : public virtual Npc
{
protected:
    unsigned short strenght{ 31 };
    string weapons[4] = { "������", "�������", "������", "���" };
public:
    Warrior()
    {
        name = "����";
        health = 35;
        damage = 10;
    }
    Warrior(string name, unsigned int health, float damage)
    {
        cout << "��������� ����������� �����" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }

    void GetWeapons()
    {
        cout << name << " ���� � ���� " << weapons[lvl - 1];
    }
    void GetInfo() override
    {
        Npc::GetInfo();
        cout << "���� - " << strenght << endl;
        cout << "��������� ������ - ";
        for (int i = 0; i < lvl; i++)
            cout << weapons[i] << endl;
    }
    void Create() override
    {
        cout << "�� ������� �����" << endl;
        cout << "������� ��� ���������\t";
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
        cout << name << " ��� ������� �������" << endl;
    }
};

class Wizard : public virtual Npc
{
protected:
    unsigned short intellect = 27;
    string spell[4] = { "�������", "���������� ������", "�������� ���", "����������� �����" };
public:
    Wizard()
    {
        name = "���������";
        health = 23;
        damage = 15;
    }
    Wizard(string name, unsigned int health, float damage)
    {
        cout << "��������� ����������� ����������" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }
    void GetInfo() override
    {
        Npc::GetInfo();
        cout << "��������� - " << intellect << endl;
        cout << "��������� ���������� � ����� ���������� - ";
        for (int i = 0; i < lvl; i++)
            cout << spell[i] << endl;
    }
    void CastSpell()
    {
        cout << name << " ��������� " << spell[lvl - 1] << endl;
    }
    void Create() override
    {
        cout << "�� ������� ����������" << endl;
        cout << "������� ��� ���������\t";
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
        cout << name << " �������� ���" << endl;
    }
};

class Paladin : public Warrior, public Wizard
{
public:
    Paladin()
    {
        name = "�������";
        health = 25;
        damage = 12;
        strenght = 27;
    }
    void GetInfo() override
    {
        Warrior::GetInfo();
        cout << "��������� - " << intellect << endl;
        cout << "��������� ���������� - ";
        for (int i = 0; i < lvl; i++)
            cout << spell[i] << endl;
    }
    void Create() override
    {
        cout << "�� ������� ��������" << endl;
        cout << "������� ��� ���������\t";
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

    cout << "������, ������\n������� � ������ � �������� � ����\n";
    cout << "�� ������� ���? (1 - ����� ��������, 2 - ���������)\n";

    unsigned short choice = GetChoice(1, 2); // ������������� �������

    if (choice == 1)
    {
        cout << "�������� � ����� �������\n\t1 - ����\n\t2 - ���������\n\t3 - �������\n";
        choice = GetChoice(1, 3); // ����� ���������� �� �� �������

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