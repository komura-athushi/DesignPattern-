#include "stdafx.h"
#include "GameLoop.h"

namespace
{
	//30FPS�̍ۂɁA1�t���[���Ɏ��s����鎞�ԁB
	const float MS_PER_FRAME = 0.033f;
}

void GameLoop::Loop()
{
	//�t���[���J�n���̎��Ԃ��擾�B
	float startTime = CurrentTime();

	//�t���[���J�n���̏����B
	Start();
	//�X�V�����B
	Update();
	//�`�揈���B
	Render();

	//�����_�̌o�ߎ��Ԃ��擾�B
	float currentTime = CurrentTime();
	//30FPS�̎���1�t���[���Ɏ��s���鎞��-���ۂ�1�t���[���Ōo�߂�������
	//�������������~����B
	//Stop(startTime + MS_PER_FRAME - currentTime);

	//FPS�\���B
	End();
}
