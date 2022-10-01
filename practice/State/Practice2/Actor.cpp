#include "stdafx.h"
#include "Actor.h"

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
	return true;
}

void Actor::Update()
{
	switch (m_state)
	{
	case State_Idle:
		//キーボードのSpaceキーが押されたら。
		if (g_keyboard->IsKeyTrigger(Keyboard::Space))
		{
			//ジャンプアニメーションを再生。
			m_modelRender.PlayAnimation(enAnimationClip_Jump);
			//ジャンプ速度を設定。
			m_velocity.y = JUMP_VELOCITY;
			//ジャンプ中にする。
			m_state = State_Jump;
		}
		//キーボードのFキーが押されたら。
		else if (g_keyboard->IsKeyTrigger(Keyboard::F))
		{
			//攻撃アニメーションを再生。
			m_modelRender.PlayAnimation(enAnimationClip_Attack);
			//攻撃中にする。
			m_state = State_Attack;
		}
		//Spaceキー・Fキーが共に押されていなければ。
		else
		{
			//待機アニメーションを再生。
			m_modelRender.PlayAnimation(enAnimationClip_Idle);
		}
		break;
	case State_Attack:
		//攻撃アニメーションの再生が終了したら。
		if (!m_modelRender.IsPlayingAnimation())
		{
			//攻撃中ではない。
			m_state = State_Idle;
		}
		break;
	case State_Jump:
		//重力加算。
		m_velocity.y -= GRAVITY_VELOCITY;
		//移動処理。
		m_position = m_charaCon.Execute(m_velocity, g_gameTime->GetFrameDeltaTime());
		//地面に着いていたら。
		if (m_charaCon.IsOnGround())
		{
			//ジャンプ中ではない。
			m_state = State_Idle;
			m_velocity.y = 0.0f;
		}
		break;
	}

	m_modelRender.SetPosition(m_position + Vector3(0.0f, 70.0f, 0.0f));
	m_modelRender.Update();
}

void Actor::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}