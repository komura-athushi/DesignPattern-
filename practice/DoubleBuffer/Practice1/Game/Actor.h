#pragma once

#include <string>
#include <iostream>

class Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	/// <param name="name">���O�B</param>
	/// <param name="isSlapped">�@����Ă���Ȃ�true�B</param>
	Actor(std::string name,bool isSlapped) :m_name(name),m_isSlapped(isSlapped){}
	void Update()
	{
		//�@����Ă��Ȃ���΁B
		if (m_isSlapped == false)
		{
			std::cout << m_name << "�͒@����Ă��Ȃ��̂ŁA�������Ȃ�!\n";
			return;
		}

		//�@����Ă���Ȃ�B
		//������������B
		Slap();
		//�@���ꂽ�t���O��false�ɁB
		m_isSlapped = false;
	}
	/// <summary>
	/// �@�������ݒ肷��B
	/// </summary>
	/// <param name="facing">�@������B</param>
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
	/// �ݒ肳�ꂽ�����@���B
	/// </summary>
	void Slap()
	{
		if (m_facing == nullptr)
		{
			return;
		}
		m_facing->Slapped();
		std::cout << m_name << "��" << m_facing->m_name << "��@����!\n";
	}
	/// <summary>
	/// �@�����B
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