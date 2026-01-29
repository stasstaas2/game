#pragma once
#include "Npc.h"
#include <memory>
#include <iostream>

class Player {
private:
    // Указатель на текущего персонажа игрока
    std::unique_ptr<Npc> character;

public:
    // Метод создания персонажа для игрока
    void Create(std::unique_ptr<Npc> npc) {
        character = std::move(npc);
        if (character) character->GetInfo();
    }

    // Метод получения указателя на текущего персонажа
    Npc* GetCurrentCharacter() const { return character.get(); }

    // Метод проверки наличия персонажа у игрока
    bool HasCharacter() const { return character != nullptr; }
};
