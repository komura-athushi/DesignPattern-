#pragma once

#include <iostream>
#include <Windows.h>

class GraphicsEngine
{
public:
	GraphicsEngine() {}
	~GraphicsEngine() {}
	void Begin();
	void Render()
	{
		HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos;
		pos.X = 0;
		pos.Y = 0;
		//標準コンソールのカーソルを0行目、0列に戻す。
		SetConsoleCursorPosition(hCons, pos);
		for (int i = 0; i < HEIGHT + 1; i++)
		{
			for (int j = 0; j < WIDTH + 1; j++)
			{
				if (i == HEIGHT || j == WIDTH)
				{
					//背景描画。
					printf("*");
				}
				else
				{
					printf("%c", m_modelList[j][i]);
				}
			}
			printf("\n");
		}

	}
	void Draw(int x, int y, char letter)
	{
		m_modelList[x][y] = letter;
	}
	static const int WIDTH = 20;
	static const int HEIGHT = 10;
private:
	char		m_modelList[WIDTH][HEIGHT];
};

extern GraphicsEngine g_graphicsEngine;