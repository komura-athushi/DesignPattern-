#include "stdafx.h"
#include "GameLoop.h"

void GameLoop::Loop()
{
	//初期値として、GameLoop直前時の経過時間が入ってます。
	//サンプルコードのpreviousにあたります。
	m_previous;
	//プログラム実行からの経過時間を取得。
	float currentTime = CurrentTime();

	//フレーム開始時の処理。
	Start();
	//更新処理。
	Update();
	//描画処理。
	Render();

	//FPS確定。
	End();
}