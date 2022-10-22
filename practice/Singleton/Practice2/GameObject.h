#pragma once

#include <list>
#include "GraphicsEngine.h"


class GameObject
{
public:
	GameObject() {};
	virtual ~GameObject(){}
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	static void BeginFrame()
	{
		g_graphicsEngine.Begin();
	}
	static void UpdateGameObjects()
	{
		for (auto gameObject : m_gameObjectList)
		{
			gameObject->Update();
		}

		m_gameObjectList.remove_if([&](GameObject* go) {
			if (go->m_isDead) {
				delete go;
				return true;
			}
			return false;
		});
	}
	static void DrawGameObjects()
	{
		for (auto gameObject : m_gameObjectList)
		{
			gameObject->Draw();
		}
	}
	static void EndFrame()
	{
		g_graphicsEngine.Render();
	}
	template<class T>
	static T* NewGO()
	{
		T* gameObject = new T();
		gameObject->Start();
		m_gameObjectList.push_back(gameObject);
		return gameObject;
	}
	static void DeleteGO(GameObject* gameObject)
	{
		gameObject->m_isDead = true;
	}
	int GetX()
	{
		return m_x;
	}
	int GetY()
	{
		return m_y;
	}
	char GetSymbol()
	{
		return m_symbol;
	}
protected:
	void SetX(int x)
	{
		m_x = x;
		if (x < 0)
		{
			m_x = 0;
		}
		if (x > GraphicsEngine::WIDTH -1)
		{
			m_x = GraphicsEngine::WIDTH - 1;
		}
	}
	void SetY(int y)
	{
		m_y = y;
		if (y < 0)
		{
			m_y = 0;
		}
		if (y > GraphicsEngine::HEIGHT - 1)
		{
			m_y = GraphicsEngine::HEIGHT - 1;
		}
	}
	void SetSymbol(char symbol)
	{
		m_symbol = symbol;
	}
private:
	int		m_x = 0;
	int		m_y = 0;
	char	m_symbol = ' ';
	bool	m_isDead = false;
	static std::list<GameObject*>		m_gameObjectList;
};