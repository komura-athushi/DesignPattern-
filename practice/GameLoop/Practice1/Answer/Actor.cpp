#include "stdafx.h"
#include "Actor.h"

#include "ActorState.h"

namespace
{
	const float JUMP_VELOCITY = 100.0f;
	const float GRAVITY_VELOCITY = 2.98f;
}

bool Actor::Start()
{
	//�A�j���[�V���������[�h����B
	m_animationClips[enAnimationClip_Idle].Load("Assets/animData/human/idle.tka");
	m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	m_animationClips[enAnimationClip_Attack].Load("Assets/animData/human/attack.tka");
	m_animationClips[enAnimationClip_Attack].SetLoopFlag(false);
	m_animationClips[enAnimationClip_Jump].Load("Assets/animData/human/jump.tka");
	m_animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	//���f�������_�\���������B
	m_modelRender.Init("Assets/modelData/human/human.tkm", m_animationClips, enAnimationClip_Num);

	m_charaCon.Init(20.0f, 100.0f, m_position+Vector3(0.0f,0.0f,0.0f));
	m_actorState = new IdleState();
	m_actorState->Enter(this);
	return true;
}

void Actor::Update()
{
	ActorState* actorState = m_actorState->HandleInput(this);
	if (actorState != nullptr)
	{
		delete m_actorState;
		m_actorState = actorState;
		m_actorState->Enter(this);
	}
	m_actorState->Update(this);

	m_modelRender.SetPosition(m_position + Vector3(0.0f, 70.0f, 0.0f));
	m_modelRender.Update();
}

void Actor::SetJumpSpeed()
{
	//�W�����v���x��ݒ�B
	m_velocity.y = JUMP_VELOCITY;
}

void Actor::Jump()
{
	//�d�͉��Z�B
	m_velocity.y -= GRAVITY_VELOCITY;
	//�ړ������B
	m_position = m_charaCon.Execute(m_velocity, g_gameTime->GetFrameDeltaTime());
	//�n�ʂɒ����Ă�����B
	if (m_charaCon.IsOnGround())
	{
		m_velocity.y = 0.0f;
	}
}

void Actor::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}