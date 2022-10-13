#include "stdafx.h"
#include "ActorState.h"

#include "Actor.h"

ActorState* IdleState::HandleInput(Actor* actor)
{
	//�L�[�{�[�h��Space�L�[�������ꂽ��B
	if (g_keyboard->IsKeyTrigger(Keyboard::Space))
	{
		//�W�����v�X�e�[�g�Ɉڍs�B
		return new JumpState();
	}
	//�L�[�{�[�h��F�L�[�������ꂽ��B
	else if (g_keyboard->IsKeyTrigger(Keyboard::F))
	{
		//�U���X�e�[�g�Ɉڍs�B
		return new AttackState();
	}
	//Space�L�[�EF�L�[�����ɉ�����Ă��Ȃ���΁B
	//�X�e�[�g�͂��̂܂܁B
	return nullptr;
}

void IdleState::Update(Actor* actor)
{

}

void IdleState::Enter(Actor* actor)
{
	//�ҋ@�A�j���[�V�������Đ�����B
	actor->PlayAnimation(Actor::enAnimationClip_Idle);
}




ActorState* AttackState::HandleInput(Actor* actor)
{
	//�A�j���[�V�����̍Đ����I��������B
	if (actor->IsPlayAnimation() == false)
	{
		//�ҋ@�X�e�[�g�Ɉڍs�B
		return new IdleState();
	}
	//�X�e�[�g�͂��̂܂܁B
	return nullptr;
}

void AttackState::Update(Actor* actor)
{

}

void AttackState::Enter(Actor* actor)
{
	//�U���X�e�[�g�Ɉڍs�B
	actor->PlayAnimation(Actor::enAnimationClip_Attack);
}




ActorState* JumpState::HandleInput(Actor* actor)
{
	//�A�N�^�[���n�ʂɒ����Ă�����B
	if (actor->IsOnGround())
	{
		//�ҋ@�X�e�[�g�Ɉڍs�B
		return new IdleState();
	}
	//�X�e�[�g�͂��̂܂܁B
	return nullptr;
}

void JumpState::Update(Actor* actor)
{
	//�W�����v���̏�����������B
	actor->Jump();
}

void JumpState::Enter(Actor* actor)
{
	//�W�����v�A�j���[�V�������Đ��B
	actor->PlayAnimation(Actor::enAnimationClip_Jump);
	//�W�����v���x��ݒ�B
	actor->SetJumpSpeed();
}