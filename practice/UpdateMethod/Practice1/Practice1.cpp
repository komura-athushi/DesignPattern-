// Practice1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <Windows.h>
#include <vector>

#include "Entity.h"
#include "SkeletonSoldier.h"
#include "Valkyrie.h"

class World
{
public:
    void Update()
    {
        for (auto& entity : m_entityList)
        {
            Sleep(2000.0f);
            entity->Update();
           
        }
    }
    void AddEntity(Entity* entity)
    {
        m_entityList.push_back(entity);
    }
private:
    std::vector<Entity*> m_entityList;
};

int main()
{
    World world;
    Valkyrie valkyrie;
    SkeletonSoldier skeletonSoldier;
    valkyrie.SetHP(1000);
    skeletonSoldier.SetHP(500);
    valkyrie.SetAttack(80);
    skeletonSoldier.SetAttack(100);
    valkyrie.SetTarget(&skeletonSoldier);
    skeletonSoldier.SetTarget(&valkyrie);

    world.AddEntity(&valkyrie);
    world.AddEntity(&skeletonSoldier);

    std::cout << "戦闘開始！\n";
    printf("骸骨兵士が現れた！\n");

    int count = 1;
    while (true)
    {
        Sleep(4000.0f);

        printf("%dターン目！\n",count);
        world.Update();
        count++;
        printf("\n");
        /*
        //標準出力コンソールのハンドルを取得。
        HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos;
        pos.X = 0;
        pos.Y = 0;
        //標準コンソールのカーソルを0行目、0列に戻す。
        SetConsoleCursorPosition(hCons, pos);
        for (int i = 0; i < 8; i++)
        {
            printf("aaaaaaaaaaaaaaaaaaaa\n");
        }
        */
    }
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
