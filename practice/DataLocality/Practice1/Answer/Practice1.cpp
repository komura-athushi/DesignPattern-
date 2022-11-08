// Practice1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <ctime>

using namespace std;

namespace
{
    const int NUMBER = 300;
}

int arr[NUMBER][NUMBER][NUMBER];

int main() {
    clock_t startTime, endTime;
    startTime = clock();
    long long int sum = 0;

    for (int l = 0; l < 50; l++)
    {
        for (int i = 0; i < NUMBER; i++) {
            for (int j = 0; j < NUMBER; j++) {
                for (int k = 0; k < NUMBER; k++) {
                    //連続するデータにアクセスするように。
                    //添え字を修正。
                    arr[i][j][k] = i * j * k;
                    sum += arr[i][j][k];
                }
            }
        }
    }
    endTime = clock();
    cout << "合計は" << sum << "です!" << endl;
    cout << (double)(endTime - startTime) / CLOCKS_PER_SEC << "秒掛かりました！" << endl;
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
