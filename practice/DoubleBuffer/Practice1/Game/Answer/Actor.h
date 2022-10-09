#pragma once

#include <string>
#include <iostream>

class Actor
{
public:
	/// <summary>
	/// コンストラクタ。
	/// </summary>
	/// <param name="name">名前。</param>
	/// <param name="isSlapped">叩かれているならtrue。</param>
	Actor(std::string name,bool isSlapped) :m_name(name),m_isCurrentSlapped(isSlapped){}
	void Update()
	{
		//今、叩かれていなければ。
		if (m_isCurrentSlapped == false)
		{
			std::cout << m_name << "は叩かれていないので、何もしない!\n";
			return;
		}

		//叩かれているなら。
		//相手をたたく。
		Slap();
		//次の叩かれたフラグをfalseに。
		m_isNextSlapped = false;
	}
	/// <summary>
	/// 現在と次の叩かれたフラグを入れ替える。
	/// </summary>
	void Swap()
	{
		//現在と次の叩かれたフラグを入れ替える。
		bool hoge = m_isCurrentSlapped;
		m_isCurrentSlapped = m_isNextSlapped;
		m_isNextSlapped = m_isCurrentSlapped;
	}
	/// <summary>
	/// 叩く相手を設定する。
	/// </summary>
	/// <param name="facing">叩く相手。</param>
	void SetFace(Actor* facing)
	{
		m_facing = facing;
	}
	/// <summary>
	/// 設定された名前を返す。
	/// </summary>
	/// <returns>名前。</returns>
	const std::string& GetName()
	{
		return m_name;
	}
private:
	/// <summary>
	/// 設定された相手を叩く。
	/// </summary>
	void Slap()
	{
		if (m_facing == nullptr)
		{
			return;
		}
		m_facing->Slapped();
		std::cout << m_name << "が" << m_facing->m_name << "を叩いた!\n";
	}
	/// <summary>
	/// 叩かれる。
	/// </summary>
	void Slapped()
	{
		//次の叩かれたフラグをtrueに。
		m_isNextSlapped = true;
	}
private:
	std::string m_name;
	Actor* m_facing = nullptr;
	bool m_isCurrentSlapped = false;
	bool m_isNextSlapped = false;
};