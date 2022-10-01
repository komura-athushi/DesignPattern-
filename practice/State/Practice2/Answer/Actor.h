#pragma once

class ActorState;

class Actor : public IGameObject
{
public:
	//アニメーション。
	enum EnAnimationClip
	{
		enAnimationClip_Idle,				//待機アニメーション。	
		enAnimationClip_Attack,				//攻撃アニメーション。
		enAnimationClip_Jump,				//ジャンプアニメーション。
		enAnimationClip_Num,				//アニメーションの数。
	};
public:
	Actor(){}
	~Actor(){}
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	//アニメーションを再生する。
	void PlayAnimation(EnAnimationClip enAnimationClip)
	{
		m_modelRender.PlayAnimation(enAnimationClip);
	}
	//ジャンプ中の処理。
	void Jump();
	//ジャンプスピードを設定。
	void SetJumpSpeed();
	//アニメ―ションが再生中ならtrue。
	bool IsPlayAnimation()
	{
		return m_modelRender.IsPlayingAnimation();
	}
	//地面に着いていたらtrue。
	bool IsOnGround()
	{
		return m_charaCon.IsOnGround();
	}
private:
	AnimationClip			m_animationClips[enAnimationClip_Num];		//アニメーションクリップ。
	ModelRender				m_modelRender;
	Vector3					m_position;
	CharacterController		m_charaCon;
	Vector3					m_velocity = Vector3::Zero;
	ActorState*				m_actorState = nullptr;
};

