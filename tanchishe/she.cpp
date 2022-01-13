#pragma warning(disable:4996)
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>  //��׼��ͷ�ļ� 
#include<time.h>
#include<math.h>
#include<iostream>  //�Ƿ������������ 
using namespace std;  //���������ͻ���� 
#define Random(x) (rand() % x)  //��������� 

#define Width 1024
#define Height 578
#define bodyLen 100
//3 left,1right,2up,0down
#define LEFT 3
#define RIGHT 1
#define UP 2
#define DOWN 0


typedef struct Point
{
	int x;
	int y;
}Point;


//�ߵĳ�ʼ�� 
typedef struct Snake {
	Point body[bodyLen];//�ߵ����� 
	int tail;  // �ߵ�β�� 
	int head;  //�ߵ�ͷ 
}Snake;


//����� 
void InsertQuery(Snake& snake, Point point)
{
	snake.head = (snake.head + 1) % bodyLen;//���� 
	int ipos = snake.head;
	snake.body[ipos].x = point.x;
	snake.body[ipos].y = point.y;
}



//ɾ������ 
void DeleteQuery(Snake& snake)
{
	snake.tail = (snake.tail + 1) % bodyLen;
}


double d = -1;

Snake snake;
int newx, newy;
int Foodx, Foody;
PIMAGE bjImg, bgPimg, headImg, bodyImg, overImg, fengmianImg; //����ȫ�ֱ��� 
MUSIC bgMusic;
int score = 0;

// 
void init()
{
	overImg = newimage();
	bjImg = newimage();  //���ø�ֵ 
	headImg = newimage();
	bodyImg = newimage();
	bgPimg = newimage();
	fengmianImg = newimage();
	getimage(fengmianImg, "C:/vscode/Algorithm/tanchishe/fengmian.jpg");
	getimage(overImg, "C:/vscode/Algorithm/tanchishe/over.jpg");
	getimage(bjImg, "C:/vscode/Algorithm/tanchishe/background.jpg");  //��ȡͼ�� 
	getimage(bgPimg, "C:/vscode/Algorithm/tanchishe/food.png");
	getimage(headImg, "C:/vscode/Algorithm/tanchishe/snake_head.png");
	getimage(bodyImg, "C:/vscode/Algorithm/tanchishe/snake_body.png");

	bgMusic.OpenFile("./bjmusic.mp3");  //�������ļ� 
	bgMusic.SetVolume(1.0f);    //���� 
	if (bgMusic.IsOpen()) {
		bgMusic.Play(0);
	}

	snake.tail = 0;
	snake.head = 1;//��߷��� 
	newx = rand() % (Width / 10);
	newy = rand() % (Height / 10);
	Point point;
	point.x = newx;
	point.y = newy;
	InsertQuery(snake, point);  //������� 
	srand((unsigned)time(NULL));//��ʼ������� 
	Foodx = rand() % (Width / 10);
	Foody = rand() % (Height / 10);

}
void welcome()                                           //���棬������Ϸ 
{



	for (; is_run(); delay_fps(60))
	{

		putimage(0, 0, fengmianImg);
		setcolor(GREEN);
		setfont(75, 0, "��������");
		setbkmode(TRANSPARENT);
		xyprintf(300, 50, "̰������Ϸ");
		setcolor(0x000000);
		setfont(30, 0, "��������");
		setbkmode(TRANSPARENT);
		xyprintf(350, 500, "��ʼ");

		//��ӡͼƬ
		if (getch() == 's' || 'S')
			break;

	}


	delimage(fengmianImg);

}
void drawScore()
{
	setcolor(BLACK);                                               //��ͣ��Ϸ 
	setfont(30, 0, "��������");
	setbkmode(TRANSPARENT);
	xyprintf(0, 0, "Q����ͣ");

	setcolor(RED);
	setfont(30, 0, "��������");                                      //����
	setbkmode(TRANSPARENT);
	xyprintf(0, 30, "������");
	char s[10];
	setcolor(EGERGB(0x00, 0x0, 0x0));//����������ɫ
	setfont(30, 0, "��������");
	setbkmode(TRANSPARENT);//���ֱ���͸�� 
	sprintf(s, "%d", score);
	outtextxy(170, 30, s);


}

void destroyAll()
{
	delimage(bgPimg);//���� 
	delimage(bjImg);
	delimage(bodyImg);
	delimage(headImg);
	delimage(fengmianImg);
}

int direction = 1;//3 left,1right,2up,0down
void UpdateWithInput()   //�������� 
{

	if (kbhit())  //�������Ƿ����� 
	{
		char ch = getch();
		switch (ch)
		{
		case 'a':
		case 'A':
			direction = LEFT;//left
			break;
		case 'd':
		case 'D':
			direction = RIGHT;//right
			break;
		case 's':case 'S':
			direction = DOWN;//down
			break;
		case 'w':case 'W':
			direction = UP;//up
			break;
		case'q':
		case'Q':
			while (1)
			{
				if (getch() == 'q' || 'Q')
					return;

			}
			break;                                                       //��ͣ��Ϸ 

		}
	}
}
void UpdateWithoutInput()//�������� 
{
	if (direction == LEFT)
	{
		newx--;


		if (newx <= 0)
		{

			for (; is_run(); delay_fps(60))
			{


				putimage(0, 0, overImg);
				setcolor(RED);
				setfont(30, 0, "��������");
				setbkmode(TRANSPARENT);
				xyprintf(400, 500, "���ķ���Ϊ��");
				char s[10];
				setcolor(RED);//����������ɫ
				setfont(30, 0, "��������");
				setbkmode(TRANSPARENT);//���ֱ���͸�� 
				sprintf(s, "%d", score);
				outtextxy(600, 500, s);

				//��ӡͼƬ
				if (getch() == ' ')
					return;
			}


			//direction=DOWN;
		}
	}

	if (direction == RIGHT)
	{
		newx++;
		if (newx * 10 > Width - 2)
		{

			for (; is_run(); delay_fps(60))
			{
				putimage(0, 0, overImg);                                 //���£���������ײ��ǽ����Ϸ���� 


				setcolor(RED);
				setfont(30, 0, "��������");
				setbkmode(TRANSPARENT);
				xyprintf(400, 500, "���ķ���Ϊ��");
				char s[10];
				setcolor(RED);//����������ɫ
				setfont(30, 0, "��������");
				setbkmode(TRANSPARENT);//���ֱ���͸�� 
				sprintf(s, "%d", score);
				outtextxy(600, 500, s);

				if (getch() == ' ')
					return;
			}



			//direction=UP;
		}
	}
	if (direction == UP)
	{
		newy--;
		if (newy <= 0)
		{


			for (; is_run(); delay_fps(60))
			{
				putimage(0, 0, overImg);


				setcolor(RED);
				setfont(30, 0, "��������");
				setbkmode(TRANSPARENT);
				xyprintf(400, 500, "���ķ���Ϊ��");
				char s[10];
				setcolor(RED);//����������ɫ
				setfont(30, 0, "��������");
				setbkmode(TRANSPARENT);//���ֱ���͸�� 
				sprintf(s, "%d", score);
				outtextxy(600, 500, s);

				//��ӡͼƬ
				if (getch() == ' ')
					return;
			}


			//direction=DOWN;
		}
	}
	if (direction == DOWN)
	{
		newy++;
		if (newy * 10 > Height - 3)
		{


			for (; is_run(); delay_fps(60))
			{
				putimage(0, 0, overImg);


				setcolor(RED);
				setfont(30, 0, "��������");
				setbkmode(TRANSPARENT);
				xyprintf(400, 500, "���ķ���Ϊ��");
				char s[10];
				setcolor(RED);//����������ɫ
				setfont(30, 0, "��������");
				setbkmode(TRANSPARENT);//���ֱ���͸�� 
				sprintf(s, "%d", score);
				outtextxy(600, 500, s);

				//��ӡͼƬ
				if (getch() == ' ')
					return;
			}

			//direction=RIGHT;
		}



	}

	Point point;
	point.x = newx;
	point.y = newy;
	InsertQuery(snake, point);  //������� 
	DeleteQuery(snake);

	d = (newx - Foodx) * (newx - Foodx) + (newy - Foody) * (newy - Foody);

	if (d < 9)//����С��3�����ؾ���Ϊ�Ե�ʳ���� 
	{
		Point p;
		p.x = newx;
		p.y = newy;
		InsertQuery(snake, p);
		Foodx = rand() % (Width / 10);
		Foody = rand() % (Height / 10);
		score += 10;
	}

}





void show()
{
	putimage(0, 0, bjImg);//���ͼ�� 
	drawScore();
	int tail, head, t;
	tail = snake.tail;
	head = snake.head;

	if (tail > head) {
		//body
		for (int position = 0; position < bodyLen; position++)
		{
			if (position < head || position >= tail)
				putimage_withalpha(NULL, bodyImg, 10 * snake.body[position].x, 10 * snake.body[position].y);
		}
	}


	//body
	for (int position = tail; position < head; position++)
	{
		putimage_withalpha(NULL, bodyImg, 10 * snake.body[position].x, 10 * snake.body[position].y);//ͼ���� 
	}
	//NULLĬ�ϣ�ͼ��͸������������ 
		//head
	putimage_withalpha(NULL, headImg, 10 * snake.body[head].x, 10 * snake.body[head].y);
	//	putimage_rotate(NULL,headImg,10*snake.body[head].x,10*snake.body[head].y,0,0,(direction-1)*90,1) ;

		//food
	putimage_withalpha(NULL, bgPimg, Foodx * 10, Foody * 10);
	Sleep(100);//�ٶ� 





}




int main()
{

	//welcome();//��ӭ���� 

	initgraph(Width, Height, 0 | INIT_NOFORCEEXIT);   //��ʼ�� 
	init();
	bgMusic.SetVolume(1.0f);
	if (bgMusic.IsOpen()) {
		bgMusic.Play(0);
	}
	welcome();//��ӭ���� 

	for (; is_run(); delay_fps(60))
	{


		show();
		//drawScore();
		UpdateWithInput();
		UpdateWithoutInput();
	}
	destroyAll();

	closegraph();

	return 0;
}
