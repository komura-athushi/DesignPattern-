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
    Valkyrie                m_valkyrie;                 //���@���L���[
    SkeletonSoldier         m_skeletonSoldier;          //�[�����m
};
