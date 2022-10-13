#include "stdafx.h"
#include "ActorState.h"

#include "Actor.h"

ActorState* IdleState::HandleInput(Actor* actor)
{
	//キーボードのSpaceキーが押されたら。
	if (g_keyboard->IsKeyTrigger(Keyboard::Space))
	{
		//ジャンプステートに移行。
		return new JumpState();
	}
	//キーボードのFキーが押されたら。
	else if (g_keyboard->IsKeyTrigger(Keyboard::F))
	{
		//攻撃ステートに移行。
		return new AttackState();
	}
	//Spaceキー・Fキーが共に押されていなければ。
	//ステートはそのまま。
	return nullptr;
}

void IdleState::Update(Actor* actor)
{

}

void IdleState::Enter(Actor* actor)
{
	//待機アニメーションを再生する。
	actor->PlayAnimation(Actor::enAnimationClip_Idle);
}




ActorState* AttackState::HandleInput(Actor* actor)
{
	//アニメーションの再生が終了したら。
	if (actor->IsPlayAnimation() == false)
	{
		//待機ステートに移行。
		return new IdleState();
	}
	//ステートはそのまま。
	return nullptr;
}

void AttackState::Update(Actor* actor)
{

}

void AttackState::Enter(Actor* actor)
{
	//攻撃ステートに移行。
	actor->PlayAnimation(Actor::enAnimationClip_Attack);
}




ActorState* JumpState::HandleInput(Actor* actor)
{
	//アクターが地面に着いていたら。
	if (actor->IsOnGround())
	{
		//待機ステートに移行。
		return new IdleState();
	}
	//ステートはそのまま。
	return nullptr;
}

void JumpState::Update(Actor* actor)
{
	//ジャンプ中の処理をさせる。
	actor->Jump();
}

void JumpState::Enter(Actor* actor)
{
	//ジャンプアニメーションを再生。
	actor->PlayAnimation(Actor::enAnimationClip_Jump);
	//ジャンプ速度を設定。
	actor->SetJumpSpeed();
}