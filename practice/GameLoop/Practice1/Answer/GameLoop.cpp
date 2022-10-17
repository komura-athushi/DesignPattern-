#include "stdafx.h"
#include "GameLoop.h"

namespace
{
	//30FPSの際に、1フレームに実行される時間。
	const float MS_PER_FRAME = 0.033f;
}

void GameLoop::Loop()
{
	//フレーム開始時の時間を取得。
	float startTime = CurrentTime();

	//フレーム開始時の処理。
	Start();
	//更新処理。
	Update();
	//描画処理。
	Render();

	//現時点の経過時間を取得。
	float currentTime = CurrentTime();
	//30FPSの時に1フレームに実行する時間-実際に1フレームで経過した時間
	//分だけ処理を停止する。
	//Stop(startTime + MS_PER_FRAME - currentTime);

	//FPS表示。
	End();
}
