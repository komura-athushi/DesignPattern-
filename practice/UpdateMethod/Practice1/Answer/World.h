#pragma once

#include <vector>
#include <Windows.h>
#include "Entity.h"

class World
{
public:
    void GameLoop();
    void Update();
private:
    std::vector<Entity*> m_entityList;
};
