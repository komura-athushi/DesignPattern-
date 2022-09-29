#pragma once
class Actor : public IGameObject
{
public:
	Actor(){}
	~Actor(){}
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	//�A�j���[�V�����B
	enum EnAnimationClip {
		enAnimationClip_Idle,				//�ҋ@�A�j���[�V�����B	
		enAnimationClip_Attack,				//�U���A�j���[�V�����B
		enAnimationClip_Jump,				//�W�����v�A�j���[�V�����B
		enAnimationClip_Num,				//�A�j���[�V�����̐��B
	};
	AnimationClip			m_animationClips[enAnimationClip_Num];		//�A�j���[�V�����N���b�v�B
	ModelRender				m_modelRender;
	Vector3					m_position;
	CharacterController		m_charaCon;
	Vector3					m_velocity = Vector3::Zero;
	bool					m_isJump = false;
	bool					m_isAttack = false;
};

