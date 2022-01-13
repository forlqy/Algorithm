#pragma warning(disable:4996)
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>  //标准库头文件 
#include<time.h>
#include<math.h>
#include<iostream>  //非法的输入输出流 
using namespace std;  //解决命名冲突问题 
#define Random(x) (rand() % x)  //产生随机数 

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


//蛇的初始化 
typedef struct Snake {
	Point body[bodyLen];//蛇的身体 
	int tail;  // 蛇的尾巴 
	int head;  //蛇的头 
}Snake;


//入队列 
void InsertQuery(Snake& snake, Point point)
{
	snake.head = (snake.head + 1) % bodyLen;//队满 
	int ipos = snake.head;
	snake.body[ipos].x = point.x;
	snake.body[ipos].y = point.y;
}



//删除队列 
void DeleteQuery(Snake& snake)
{
	snake.tail = (snake.tail + 1) % bodyLen;
}


double d = -1;

Snake snake;
int newx, newy;
int Foodx, Foody;
PIMAGE bjImg, bgPimg, headImg, bodyImg, overImg, fengmianImg; //定义全局变量 
MUSIC bgMusic;
int score = 0;

// 
void init()
{
	overImg = newimage();
	bjImg = newimage();  //调用赋值 
	headImg = newimage();
	bodyImg = newimage();
	bgPimg = newimage();
	fengmianImg = newimage();
	getimage(fengmianImg, "C:/vscode/Algorithm/tanchishe/fengmian.jpg");
	getimage(overImg, "C:/vscode/Algorithm/tanchishe/over.jpg");
	getimage(bjImg, "C:/vscode/Algorithm/tanchishe/background.jpg");  //获取图像 
	getimage(bgPimg, "C:/vscode/Algorithm/tanchishe/food.png");
	getimage(headImg, "C:/vscode/Algorithm/tanchishe/snake_head.png");
	getimage(bodyImg, "C:/vscode/Algorithm/tanchishe/snake_body.png");

	bgMusic.OpenFile("./bjmusic.mp3");  //打开音乐文件 
	bgMusic.SetVolume(1.0f);    //声音 
	if (bgMusic.IsOpen()) {
		bgMusic.Play(0);
	}

	snake.tail = 0;
	snake.head = 1;//左边反弹 
	newx = rand() % (Width / 10);
	newy = rand() % (Height / 10);
	Point point;
	point.x = newx;
	point.y = newy;
	InsertQuery(snake, point);  //插入队列 
	srand((unsigned)time(NULL));//初始化随机数 
	Foodx = rand() % (Width / 10);
	Foody = rand() % (Height / 10);

}
void welcome()                                           //封面，进入游戏 
{



	for (; is_run(); delay_fps(60))
	{

		putimage(0, 0, fengmianImg);
		setcolor(GREEN);
		setfont(75, 0, "方正舒体");
		setbkmode(TRANSPARENT);
		xyprintf(300, 50, "贪吃蛇游戏");
		setcolor(0x000000);
		setfont(30, 0, "方正舒体");
		setbkmode(TRANSPARENT);
		xyprintf(350, 500, "开始");

		//打印图片
		if (getch() == 's' || 'S')
			break;

	}


	delimage(fengmianImg);

}
void drawScore()
{
	setcolor(BLACK);                                               //暂停游戏 
	setfont(30, 0, "方正舒体");
	setbkmode(TRANSPARENT);
	xyprintf(0, 0, "Q：暂停");

	setcolor(RED);
	setfont(30, 0, "华文琥珀");                                      //分数
	setbkmode(TRANSPARENT);
	xyprintf(0, 30, "分数：");
	char s[10];
	setcolor(EGERGB(0x00, 0x0, 0x0));//设置字体颜色
	setfont(30, 0, "华文琥珀");
	setbkmode(TRANSPARENT);//文字背景透明 
	sprintf(s, "%d", score);
	outtextxy(170, 30, s);


}

void destroyAll()
{
	delimage(bgPimg);//销毁 
	delimage(bjImg);
	delimage(bodyImg);
	delimage(headImg);
	delimage(fengmianImg);
}

int direction = 1;//3 left,1right,2up,0down
void UpdateWithInput()   //操作更新 
{

	if (kbhit())  //检查键盘是否输入 
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
			break;                                                       //暂停游戏 

		}
	}
}
void UpdateWithoutInput()//操作更新 
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
				setfont(30, 0, "华文琥珀");
				setbkmode(TRANSPARENT);
				xyprintf(400, 500, "您的分数为：");
				char s[10];
				setcolor(RED);//设置字体颜色
				setfont(30, 0, "华文琥珀");
				setbkmode(TRANSPARENT);//文字背景透明 
				sprintf(s, "%d", score);
				outtextxy(600, 500, s);

				//打印图片
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
				putimage(0, 0, overImg);                                 //创新！！！！！撞到墙，游戏结束 


				setcolor(RED);
				setfont(30, 0, "华文琥珀");
				setbkmode(TRANSPARENT);
				xyprintf(400, 500, "您的分数为：");
				char s[10];
				setcolor(RED);//设置字体颜色
				setfont(30, 0, "华文琥珀");
				setbkmode(TRANSPARENT);//文字背景透明 
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
				setfont(30, 0, "华文琥珀");
				setbkmode(TRANSPARENT);
				xyprintf(400, 500, "您的分数为：");
				char s[10];
				setcolor(RED);//设置字体颜色
				setfont(30, 0, "华文琥珀");
				setbkmode(TRANSPARENT);//文字背景透明 
				sprintf(s, "%d", score);
				outtextxy(600, 500, s);

				//打印图片
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
				setfont(30, 0, "华文琥珀");
				setbkmode(TRANSPARENT);
				xyprintf(400, 500, "您的分数为：");
				char s[10];
				setcolor(RED);//设置字体颜色
				setfont(30, 0, "华文琥珀");
				setbkmode(TRANSPARENT);//文字背景透明 
				sprintf(s, "%d", score);
				outtextxy(600, 500, s);

				//打印图片
				if (getch() == ' ')
					return;
			}

			//direction=RIGHT;
		}



	}

	Point point;
	point.x = newx;
	point.y = newy;
	InsertQuery(snake, point);  //插入队列 
	DeleteQuery(snake);

	d = (newx - Foodx) * (newx - Foodx) + (newy - Foody) * (newy - Foody);

	if (d < 9)//距离小于3个像素就认为吃到食物了 
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
	putimage(0, 0, bjImg);//输出图像 
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
		putimage_withalpha(NULL, bodyImg, 10 * snake.body[position].x, 10 * snake.body[position].y);//图像处理 
	}
	//NULL默认，图像透明，更加契合 
		//head
	putimage_withalpha(NULL, headImg, 10 * snake.body[head].x, 10 * snake.body[head].y);
	//	putimage_rotate(NULL,headImg,10*snake.body[head].x,10*snake.body[head].y,0,0,(direction-1)*90,1) ;

		//food
	putimage_withalpha(NULL, bgPimg, Foodx * 10, Foody * 10);
	Sleep(100);//速度 





}




int main()
{

	//welcome();//欢迎界面 

	initgraph(Width, Height, 0 | INIT_NOFORCEEXIT);   //初始化 
	init();
	bgMusic.SetVolume(1.0f);
	if (bgMusic.IsOpen()) {
		bgMusic.Play(0);
	}
	welcome();//欢迎界面 

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
