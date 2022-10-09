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
	Actor(std::string name,bool isSlapped) :m_name(name),m_isSlapped(isSlapped){}
	void Update()
	{
		//叩かれていなければ。
		if (m_isSlapped == false)
		{
			std::cout << m_name << "は叩かれていないので、何もしない!\n";
			return;
		}

		//叩かれているなら。
		//相手をたたく。
		Slap();
		//叩かれたフラグをfalseに。
		m_isSlapped = false;
	}
	/// <summary>
	/// 叩く相手を設定する。
	/// </summary>
	/// <param name="facing">叩く相手。</param>
	void SetFace(Actor* facing)
	{
		m_facing = facing;
	}
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
		m_isSlapped = true;
	}
private:
	std::string m_name;
	Actor* m_facing = nullptr;
	bool m_isSlapped = false;
};