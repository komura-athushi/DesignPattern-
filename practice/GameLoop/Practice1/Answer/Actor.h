#pragma once

class ActorState;

class Actor : public IGameObject
{
public:
	//�A�j���[�V�����B
	enum EnAnimationClip
	{
		enAnimationClip_Idle,				//�ҋ@�A�j���[�V�����B	
		enAnimationClip_Attack,				//�U���A�j���[�V�����B
		enAnimationClip_Jump,				//�W�����v�A�j���[�V�����B
		enAnimationClip_Num,				//�A�j���[�V�����̐��B
	};
public:
	Actor(){}
	~Actor(){}
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	//�A�j���[�V�������Đ�����B
	void PlayAnimation(EnAnimationClip enAnimationClip)
	{
		m_modelRender.PlayAnimation(enAnimationClip);
	}
	//�W�����v���̏����B
	void Jump();
	//�W�����v�X�s�[�h��ݒ�B
	void SetJumpSpeed();
	//�A�j���\�V�������Đ����Ȃ�true�B
	bool IsPlayAnimation()
	{
		return m_modelRender.IsPlayingAnimation();
	}
	//�n�ʂɒ����Ă�����true�B
	bool IsOnGround()
	{
		return m_charaCon.IsOnGround();
	}
private:
	AnimationClip			m_animationClips[enAnimationClip_Num];		//�A�j���[�V�����N���b�v�B
	ModelRender				m_modelRender;
	Vector3					m_position;
	CharacterController		m_charaCon;
	Vector3					m_velocity = Vector3::Zero;
	ActorState*				m_actorState = nullptr;
};

