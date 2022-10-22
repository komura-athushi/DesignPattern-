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
		//�W���R���\�[���̃J�[�\����0�s�ځA0��ɖ߂��B
		SetConsoleCursorPosition(hCons, pos);
		for (int i = 0; i < HEIGHT + 1; i++)
		{
			for (int j = 0; j < WIDTH + 1; j++)
			{
				if (i == HEIGHT || j == WIDTH)
				{
					//�w�i�`��B
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