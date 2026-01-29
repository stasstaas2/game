#include <iostream>
#include <fstream> 
#include <chrono>
#include <thread>
#include <cstdlib>
#include <string>
#include <ctime>
#include <windows.h>

#include "MonkeyKing.h"
#include "ShadowFiend.h"
#include "Lina.h"
#include "NpcClass.h"
#include "playerClass.h"
#include "Enemy.h"
#include "ConsoleManager.h"

using namespace std;

enum ColorConsole {
    Black = 0,
    DarkBlue = 1,
    Green = 2,
    Blue = 3,
    Red = 4,
    Purple = 5,
    Yellow = 6,
    White = 7,
    Gray = 8
};

enum class ValueQuality
{
    МУСОР, ОБЫЧНОЕ, РЕДКОЕ, МИФИЧЕСКОЕ, ЛЕГЕНДАРНОЕ
};

struct Treasure
{
    Treasure() = default;
    string name{ "добыча" };
    ValueQuality quality = ValueQuality::МИФИЧЕСКОЕ;
    unsigned int price{ 0 };
    Treasure(ValueQuality quality)
    {
        switch (quality)
        {
        case ValueQuality::МУСОР:
            cout << "качество плохое\n";
            break;
        case ValueQuality::ОБЫЧНОЕ:
            cout << "качество среднее\n";
            break;
        case ValueQuality::РЕДКОЕ:
            cout << "качество хорошее\n";
            break;
        case ValueQuality::МИФИЧЕСКОЕ:
            cout << "качество отличное\n";
            break;
        case ValueQuality::ЛЕГЕНДАРНОЕ:
            cout << "качество превосходное\n";
            break;
        default:
            break;
        }
    }
};

struct Cloth : Treasure
{
    Cloth(ValueQuality quality) : Treasure(quality) {};
    string valueSite[5]{ "Ботинки", "Поножи", "Нагрудник", "Шлем"};
    string site{ NULL };
    unsigned short armor{ 1 };
};

enum class CharacterType {
    UNKNOWN,
    SHADOWFIEND,
    LINA,
    MONKEYKING
};

unsigned short TestChoise(unsigned short maxChoise, string text)
{
    unsigned short choise = 1;
    cin >> choise;
    while (choise > maxChoise || choise < 1)
    {
        cout << text << endl;
        cin >> choise;
    }
    return choise;
};

unsigned short TestChoise(unsigned short maxChoise)
{
    unsigned short choise = 1;
    cin >> choise;
    while (choise > maxChoise || choise < 1)
    {
        cout << "Такого выбора не существует!" << endl;
        cin >> choise;
    }
    return choise;
};

unique_ptr<Npc> CreateCharacter(CharacterType type)
{
    switch (type)
    {
    case CharacterType::UNKNOWN:
        return make_unique<Npc>();
        break;
    case CharacterType::SHADOWFIEND:
        return make_unique<ShadowFiend>();
        break;
    case CharacterType::LINA:
        return make_unique<Lina>();
        break;
    case CharacterType::MONKEYKING:
        return make_unique<MonkeyKing>();
        break;
    default:
        invalid_argument("Неизвестный тип персонажа");
        break;
    }
}

int GetRandom(int min, int max)
{
    return min + std::rand() % (max - min + 1);
}

int AttackEnemy(Player* player, Enemy* enemy)
{
    int damage = player->GetCharacter()->CalculateDamage();

    enemy->TakeDamage(damage);
    printSlowly("Вы нанесли ", false);
    printSlowly(to_string(damage), 4, false, Yellow);
    printSlowly(" урона.\n ", false);

    enemy->GetInfo();

    Pause(false);

    return damage;
}

int EnemyAttack(Player* player, Enemy* enemy)
{
    int damage = enemy->GetDamage();

    printSlowly("Враг атакует! Оставшееся здоровье: ", false);
    player->GetCharacter()->TakeDamage(damage);
    printSlowly(to_string(player->GetCharacter()->GetHealth()),2 ,false, Red);

    Pause(false);

    return damage;
}

void Fight(bool attackFirst, Player* player, Enemy* enemy)
{
    if (attackFirst)
    {
        printSlowly("\nВы атакуете первым. ", false);

        while (enemy->GetHealth() > 0 && player->GetCharacter()->GetHealth() > 0)
        {
            AttackEnemy(player, enemy);
            if (enemy->GetHealth() <= 0)
                continue;
            EnemyAttack(player, enemy);
        }
        if (enemy->GetHealth() <= 0)
        {
            printSlowly("Вы одолели врага!\n\n", false);
            return;
        }
        else
        {
            ClearScreen();
            printSlowly("ВЫ ПОГИБЛИ!",3, false, Red);
            exit(0);
        }
    }
    else
    {
        printSlowly(enemy->GetName(), false);
        printSlowly(" атакует первым.", true);

        while (enemy->GetHealth() > 0 && player->GetCharacter()->GetHealth() > 0)
        {
            EnemyAttack(player, enemy);
            if (player->GetCharacter()->GetHealth() <= 0)
                continue;
            AttackEnemy(player, enemy);
        }
        if (enemy->GetHealth() <= 0)
        {
            printSlowly("Вы одолели врага!\n\n", false);
            return;
        }
        else
        {
            ClearScreen();
            printSlowly("ВЫ ПОГИБЛИ!", 3, false, Red);
            exit(0);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(std::time(0));

    Player* player = new Player();

    ShowName("Настройка");
    printSlowly("Выберите скорость текста:\n\t1 - Медленная\n\t2 - Оптимальная\n\t3 - Быстрая\n\t4 - Моментальная\n", false);

    switch (TestChoise(4, "Такой настройки нет!"))
    {
    case 1:
        ChangeDefaultSpeed(30);
        break;
    case 2:
        ChangeDefaultSpeed(60);
        break;
    case 3:
        ChangeDefaultSpeed(90);
        break;
    case 4:
        ChangeDefaultSpeed(0);
        break;
    }

    ClearScreen();

    ShowName("Незнакомец");
    printSlowly("Привет, путник\nПрисядь у костра и расскажи о себе\nТы кем будешь?\n\t", true);
    cout << "\t1 - ShadowFiend\n\t2 - Lina\n\t3 - MonkeyKing\n";

    unique_ptr<Npc> character;
    switch (TestChoise(3, "Ты не ошибся?\nНе мог бы ты повторить"))
    {
    case 1:
        character = CreateCharacter(CharacterType::SHADOWFIEND);
        break;
    case 2:
        character = CreateCharacter(CharacterType::LINA);
        break;
    case 3:
        character = CreateCharacter(CharacterType::MONKEYKING);
        break;
    }

    ClearScreen();

    player->Create(move(character));

    auto playerCharacter = player->GetCharacter();

    Pause(false);
    Pause(true);

    ClearScreen();

    Enemy* enemy = new Enemy("ПУДЖ", 650, 67);

    printSlowly("Вы встретились с врагом", true);
    
    Fight(true, player, enemy);

    return 0;
}