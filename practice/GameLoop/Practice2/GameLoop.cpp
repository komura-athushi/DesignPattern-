#include "stdafx.h"
#include "GameLoop.h"

void GameLoop::Loop()
{
	//�����l�Ƃ��āAGameLoop���O���̌o�ߎ��Ԃ������Ă܂��B
	//�T���v���R�[�h��previous�ɂ�����܂��B
	m_previous;
	//�v���O�������s����̌o�ߎ��Ԃ��擾�B
	float currentTime = CurrentTime();

	//�t���[���J�n���̏����B
	Start();
	//�X�V�����B
	Update();
	//�`�揈���B
	Render();

	//FPS�m��B
	End();
}