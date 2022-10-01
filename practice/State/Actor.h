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
	//アニメーション。
	enum EnAnimationClip {
		enAnimationClip_Idle,				//待機アニメーション。	
		enAnimationClip_Attack,				//攻撃アニメーション。
		enAnimationClip_Jump,				//ジャンプアニメーション。
		enAnimationClip_Num,				//アニメーションの数。
	};
	enum State
	{
		State_Idle,							//待機ステート。
		State_Attack,						//攻撃ステート。
		State_Jump,							//ジャンプステート。
		State_Num,							//ステートの数。
	};
	AnimationClip			m_animationClips[enAnimationClip_Num];		//アニメーションクリップ。
	ModelRender				m_modelRender;
	Vector3					m_position;
	CharacterController		m_charaCon;
	Vector3					m_velocity = Vector3::Zero;
	State					m_state = State_Idle;
};

