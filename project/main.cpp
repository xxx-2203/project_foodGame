#include <SFML/Graphics.hpp>
#include<time.h>
#include <Windows.h> 
#pragma comment(lib,"winmm.lib") 
#include <mmsystem.h> 

//ũ��� 650px�� �����ϳ� �켱 ���� �ȼ��� �ľ��ϱ� ���� ����
#define WIDTH 450
#define HEIGHT 450

using namespace sf;

int main(void)
{
	RenderWindow app(VideoMode(WIDTH, HEIGHT), "foodGame");
	app.setFramerateLimit(60);

	//�̹��� ��������
	Texture t;
	t.loadFromFile("images/main.png");

	Sprite Backgroud(t);

	//�������
	PlaySound(TEXT("bgm.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);

	int cnt = 5;

	//�� ����
	while (app.isOpen())
	{

		Event e;
		while (app.pollEvent(e))
		{	
			Sleep(1000);
			cnt -= 1;
			if (cnt <0&&e.type == Event::Closed)
				app.close();
		}
		app.clear();
		app.draw(Backgroud);
		app.display();
	}
}