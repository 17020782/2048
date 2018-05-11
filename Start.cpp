#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string>
#include<time.h>
#include<cstdlib>
#include <fstream>
#include<string>
using namespace std;
//thay doi kich thuong khung
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
//ham to mau
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
//ham dich chuyen con tro toi vi tri x,y
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
//khoi tao kieu du lieu cho xau 
struct paint
{
	
	int x;
	int y;
	int color;
	string str;
	
};
//in xau 
void Paint(int x, int y, int color, string str)
{
	gotoxy(x,y);
	textcolor(color);
	cout << str;
}
//ham tao file mo dau
void begin()
{
	ofstream begin;
	begin.open("start.TXT", ios::out);
	begin << ("\n\n\n");
	begin <<"  222222222222222         000000000            444444444       888888888    \n "; 
	begin <<"2:::::::::::::::22     00:::::::::00         4::::::::4     88:::::::::88   \n"; 
	begin <<" 2::::::222222:::::2  00:::::::::::::00      4:::::::::4   88:::::::::::::88 \n"; 
	begin <<" 2222222     2:::::2 0:::::::000:::::::0    4::::44::::4  8::::::88888::::::8\n"; 
	begin <<"             2:::::2 0::::::0   0::::::0   4::::4 4::::4  8:::::8     8:::::8\n"; 
	begin <<"             2:::::2 0:::::0     0:::::0  4::::4  4::::4  8:::::8     8:::::8\n"; 
	begin <<"          2222::::2  0:::::0     0:::::0 4::::4   4::::4   8:::::88888:::::8 \n"; 
	begin <<"     22222::::::22   0:::::0 000 0:::::04::::444444::::444  8:::::::::::::8  \n"; 
	begin <<"   22::::::::222     0:::::0 000 0:::::04::::::::::::::::4 8:::::88888:::::8 \n"; 
	begin <<"  2:::::22222        0:::::0     0:::::04444444444:::::4448:::::8     8:::::8\n"; 
	begin <<" 2:::::2             0:::::0     0:::::0          4::::4  8:::::8     8:::::8\n"; 
	begin <<" 2:::::2             0::::::0   0::::::0          4::::4  8:::::8     8:::::8\n"; 
	begin <<" 2:::::2       2222220:::::::000:::::::0          4::::4  8::::::88888::::::8\n"; 
	begin <<" 2::::::2222222:::::2 00:::::::::::::00         44::::::44 88:::::::::::::88 \n"; 
	begin <<" 2::::::::::::::::::2   00:::::::::00           4::::::::4   88:::::::::88   \n"; 
	begin <<" 22222222222222222222     000000000             4444444444     888888888     \n"; 
	begin.close();
}

//in phan mo dau ra man hinh
void Start()
{	
	resizeConsole(1000,400);
	
	ifstream start;
	start.open("start.TXT", ios::in);
	while (!start.eof())
	{
		char temp[255];
		start.getline(temp, 255);
		string line = temp;
		textcolor(11);
		cout << line << endl;
		
	}
	start.close();	
	paint logo={50,24,12,"Bui Manh Hung"};
	Paint(logo.x, logo.y, logo.color, logo.str);
	paint letgo={4,24,13,"Press any key to start game..."};
	Paint(letgo.x, letgo.y, letgo.color, letgo.str);
}
int main()
{
	begin();
	Start();
}
