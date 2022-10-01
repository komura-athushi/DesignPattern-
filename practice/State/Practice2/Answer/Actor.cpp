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
	//アニメーションをロードする。
	m_animationClips[enAnimationClip_Idle].Load("Assets/animData/human/idle.tka");
	m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	m_animationClips[enAnimationClip_Attack].Load("Assets/animData/human/attack.tka");
	m_animationClips[enAnimationClip_Attack].SetLoopFlag(false);
	m_animationClips[enAnimationClip_Jump].Load("Assets/animData/human/jump.tka");
	m_animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	//モデルレンダ―を初期化。
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
	//ジャンプ速度を設定。
	m_velocity.y = JUMP_VELOCITY;
}

void Actor::Jump()
{
	//重力加算。
	m_velocity.y -= GRAVITY_VELOCITY;
	//移動処理。
	m_position = m_charaCon.Execute(m_velocity, g_gameTime->GetFrameDeltaTime());
	//地面に着いていたら。
	if (m_charaCon.IsOnGround())
	{
		m_velocity.y = 0.0f;
	}
}

void Actor::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}