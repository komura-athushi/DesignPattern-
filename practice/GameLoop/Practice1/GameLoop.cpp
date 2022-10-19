#include "stdafx.h"
#include "GameLoop.h"

void GameLoop::Loop()
{
	//フレーム開始時の処理。
	Start();
	//更新処理。
	Update();
	//描画処理。
	Render();

	//現時点で、プログラム実行時からの経過時間を取得(単位:秒)。
	float currentTime = CurrentTime();
	//設定した時間だけプログラムを停止(単位:秒)
	Stop(0.01f);

	//FPS確定。
	End();
}