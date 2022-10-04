#include "stdafx.h"
#include "Actor.h"

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
	return true;
}

void Actor::Update()
{
	switch (m_state)
	{
	case State_Idle:
		//�L�[�{�[�h��Space�L�[�������ꂽ��B
		if (g_keyboard->IsKeyTrigger(Keyboard::Space))
		{
			//�W�����v�A�j���[�V�������Đ��B
			m_modelRender.PlayAnimation(enAnimationClip_Jump);
			//�W�����v���x��ݒ�B
			m_velocity.y = JUMP_VELOCITY;
			//�W�����v���ɂ���B
			m_state = State_Jump;
		}
		//�L�[�{�[�h��F�L�[�������ꂽ��B
		else if (g_keyboard->IsKeyTrigger(Keyboard::F))
		{
			//�U���A�j���[�V�������Đ��B
			m_modelRender.PlayAnimation(enAnimationClip_Attack);
			//�U�����ɂ���B
			m_state = State_Attack;
		}
		//Space�L�[�EF�L�[�����ɉ�����Ă��Ȃ���΁B
		else
		{
			//�ҋ@�A�j���[�V�������Đ��B
			m_modelRender.PlayAnimation(enAnimationClip_Idle);
		}
		break;
	case State_Attack:
		//�U���A�j���[�V�����̍Đ����I��������B
		if (!m_modelRender.IsPlayingAnimation())
		{
			//�U�����ł͂Ȃ��B
			m_state = State_Idle;
		}
		break;
	case State_Jump:
		//�d�͉��Z�B
		m_velocity.y -= GRAVITY_VELOCITY;
		//�ړ������B
		m_position = m_charaCon.Execute(m_velocity, g_gameTime->GetFrameDeltaTime());
		//�n�ʂɒ����Ă�����B
		if (m_charaCon.IsOnGround())
		{
			//�W�����v���ł͂Ȃ��B
			m_state = State_Idle;
			m_velocity.y = 0.0f;
		}
		break;
	}

	m_modelRender.SetPosition(m_position + Vector3(0.0f, 70.0f, 0.0f));
	m_modelRender.Update();
}

//�n��ɂ����ԃN���X�B
class OnGroundState : public ActorState
{
public:
	virtual ActorState* HandleInput(Actor* actor)
	{
		//B�{�^���������ꂽ��B
		if (IsPressButton(B))
		{
			//�W�����v�X�e�[�g��Ԃ��B
			return new JumpingState();
		}
		//���{�^���������ꂽ��B
		else if (IsPressButton(Down))
		{
			//���݃X�e�[�g��Ԃ��B
			return new DuckingState();
		}
		//...
	}
};

//���ݏ�ԃN���X�B
class DuckingState : public OnGroundState
{
public:
	virtual ActorState* HandleInput(Actor* actor)
	{
		//���{�^���������ꂽ��B
		if (IsPressButton(Down))
		{
			//������Ԃɖ߂��B
			return new StandingState();
		}
		//���͂���������Ȃ���΁B
		else
		{
			//�K�w��k��(�e��Ԃ̏������s��)�B
			return OnGroundState::HandleInput(actor);
		}
	}
};
