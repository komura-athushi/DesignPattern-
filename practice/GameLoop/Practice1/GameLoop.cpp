#include "stdafx.h"
#include "GameLoop.h"

void GameLoop::Loop()
{
	//�t���[���J�n���̏����B
	Start();
	//�X�V�����B
	Update();
	//�`�揈���B
	Render();

	//�����_�ŁA�v���O�������s������̌o�ߎ��Ԃ��擾(�P��:�b)�B
	float currentTime = CurrentTime();
	//�ݒ肵�����Ԃ����v���O�������~(�P��:�b)
	Stop(0.01f);

	//FPS�m��B
	End();
}