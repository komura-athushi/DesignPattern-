#pragma once

#include <vector>
#include <Windows.h>

#include "Valkyrie.h"
#include "SkeletonSoldier.h"

class World
{
public:
    void GameLoop();
    void Update();
private:
    Valkyrie                m_valkyrie;                 //ƒ”ƒ@ƒ‹ƒLƒŠ[
    SkeletonSoldier         m_skeletonSoldier;          //Š[œ•ºm
};
