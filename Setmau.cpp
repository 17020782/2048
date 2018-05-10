#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string>
#include<time.h>
#include<cstdlib>
#include <fstream>
#include<string>
using namespace std;
//toa do bien
int Val[4][4]={0};
char map[55][55];
int ViTri[4];
int diem=0;

void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void setColor(int Val)
{
	switch (Val) {
	case 2:		textcolor(63); break;
	case 4:		textcolor(62); break;
	case 8:		textcolor(61); break;
	case 16:	textcolor(60); break;
	case 32:	textcolor(59); break;
	case 64:	textcolor(58); break;
	case 128:	textcolor(57); break;
	case 256:	textcolor(49); break;
	case 512:	textcolor(48); break;
	case 1024:  textcolor(52); break;
	case 2048:  textcolor(50); break;
	
	}
}


int main()
{
	
	int i;
	for(i=2;i<=2048;i+=i)
	{
		setColor(i);
		cout << i << endl;
		
	}
	
	
}

