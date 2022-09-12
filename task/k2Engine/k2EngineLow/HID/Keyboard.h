#pragma once

#include "DirectXTK/Inc/Keyboard.h"

namespace nsK2EngineLow {
    /// <summary>
    /// �L�[�{�[�h���͂̔�����s���N���X�B
    /// DirectX::KeyBoard���g�p���Ă��܂��B
    /// </summary>
	class Keyboard : public Noncopyable
	{
	public:
		Keyboard();
		~Keyboard(){}
		void Update();
        enum Keys
        {
            None = 0,

            Back = 0x8,
            Tab = 0x9,

            Enter = 0xd,

            Pause = 0x13,
            
            Escape = 0x1b,
            
            Space = 0x20,
            PageUp = 0x21,
            PageDown = 0x22,
            End = 0x23,
            Home = 0x24,
            Left = 0x25,
            Up = 0x26,
            Right = 0x27,
            Down = 0x28,
            
            A = 0x41,
            B = 0x42,
            C = 0x43,
            D = 0x44,
            E = 0x45,
            F = 0x46,
            G = 0x47,
            H = 0x48,
            I = 0x49,
            J = 0x4a,
            K = 0x4b,
            L = 0x4c,
            M = 0x4d,
            N = 0x4e,
            O = 0x4f,
            P = 0x50,
            Q = 0x51,
            R = 0x52,
            S = 0x53,
            T = 0x54,
            U = 0x55,
            V = 0x56,
            W = 0x57,
            X = 0x58,
            Y = 0x59,
            Z = 0x5a, 
            LeftControl = 0xa2,
            RightControl = 0xa3,
        };
        /// <summary>
        /// �e�L�[��������Ă��邩����B
        /// </summary>
        /// <param name="key">�L�[�B</param>
        /// <returns>������Ă����true�B</returns>
        bool IsKeyDown(Keys key);
        /// <summary>
        /// �e�L�[��������Ă��邩����(��x����)�B
        /// </summary>
        /// <param name="key">�L�[�B</param>
        /// <returns>������Ă����true�B</returns>
        bool IsKeyTrigger(Keys key);
        /// <summary>
        /// �e�L�[��������Ă��Ȃ�������B
        /// </summary>
        /// <param name="key">�L�[�B</param>
        /// <returns>������Ă��Ȃ����true�B</returns>
        bool IsKeyUp(Keys key);
    private:
        /// <summary>
        /// �L�[��DirectX::Keyboard::Keys�ɕϊ��B
        /// </summary>
        /// <param name="key">�L�[�B</param>
        /// <returns>DirectX::Keyboard::Keys�B</returns>
        DirectX::Keyboard::Keys ConvertDirectKeys(Keys key)
        {
            return static_cast<DirectX::Keyboard::Keys>((static_cast<int>(key)));
        }
    private:
		std::unique_ptr<DirectX::Keyboard> m_keyboard;
		DirectX::Keyboard::State m_beforeState;
		DirectX::Keyboard::State m_state;
	};

	extern std::unique_ptr<Keyboard> g_keyboard;
}
