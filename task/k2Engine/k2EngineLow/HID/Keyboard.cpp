
#include "k2EngineLowPreCompile.h"
#include "Keyboard.h"

namespace nsK2EngineLow {
	std::unique_ptr<Keyboard> g_keyboard = std::make_unique<Keyboard>(); 

	Keyboard::Keyboard()
	{
		m_keyboard = std::make_unique<DirectX::Keyboard>();
		m_state = m_keyboard->GetState();
	}

	void Keyboard::Update()
	{
		m_beforeState = m_state;
		m_state = m_keyboard->GetState();
	}
	bool Keyboard::IsKeyPress(Keys key)
	{
		DirectX::Keyboard::Keys directXKey = ConvertDirectKeys(key);
		if(m_state.IsKeyDown(directXKey))
		{
			return true;
		}
		return false;
	}
	bool Keyboard::IsKeyDown(Keys key)
	{
		DirectX::Keyboard::Keys directXKey = ConvertDirectKeys(key);
		if (m_state.IsKeyDown(directXKey) && !m_beforeState.IsKeyDown(directXKey))
		{
			return true;
		}
		return false;
	}
	bool Keyboard::IsKeyUp(Keys key)
	{
		DirectX::Keyboard::Keys directXKey = ConvertDirectKeys(key);
		if (m_state.IsKeyUp(directXKey))
		{
			return true;
		}
		return false;
	}
}
