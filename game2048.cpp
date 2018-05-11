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
//ham xoa man hinh
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
//ham in toa do gia tri 
void Draw(int x, int y,int a)
{
	gotoxy(x,y);	
	
	cout<<a;
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
//set mau cho tung gia tri
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
//ham tao khung game
int DrawMap()
{	
	
	for(int i=0;i<17;i++)
	{
		for(int j=0;j<25;j++)
		{
			
			if(i==0 || i==16|| j==0 || j==24 || i==4 || i==8 || i==12 || j==6 || j==12 || j== 18)
				textcolor(112);
			else
				textcolor(51);

			cout<<map[i][j];
		}
		cout<<endl;
	}

	paint hd={30, 4, 11, "Huong Dan: "};
	Paint(hd.x, hd.y, hd.color, hd.str);
	
	paint st={31,5,6,"A: Sang Trai"};
	Paint(st.x, st.y, st.color, st.str);
	

	paint sp={ 31, 6, 13, "D: Sang Phai"};
	Paint(sp.x, sp.y, sp.color, sp.str );

	paint lt={ 31, 7, 14, "W: Len Tren"};
	Paint(lt.x, lt.y, lt.color, lt.str );

	paint xd={ 31, 8, 10, "S: Xuong Duoi"};
	Paint(xd.x, xd.y, xd.color, xd.str);


	paint quit={ 30, 10, 15, "Nhan X de thoat game."};
	Paint(quit.x, quit.y, quit.color, quit.str );
	textcolor(10);
	return 0;
}

//Thiet Lap vi tri 2 gia tri dau tien

int SetPos(	)
{	
	srand(time(0));
	ViTri[0] = rand()%(4);		// Random 2 vi tri cua so dau tien
	ViTri[1] = rand()%(4);

	do {
		ViTri[2] = rand()%(4);		//Random 2 vi tri cua so thu hai
		ViTri[3] = rand()%(4);
	}
	while(ViTri[0]==ViTri[2] && ViTri[1]==ViTri[3]); 
	Val[ViTri[2]][ViTri[3]]=2;
	Val[ViTri[0]][ViTri[1]]=2;
    
	return 0;
}

// In cac gia tri len khung GameView
int DrawVal(int Val[][4])
{
		for (int i = 3; i <= 21; i += 6) 
		{
			for (int j = 3; j <= 15; j += 4)
			{
				if(Val[(j - 3) / 4][(i - 3) / 6]!=0)
				{
				setColor(Val[(j - 3) / 4][(i - 3) / 6]);
			 	if (Val[(j - 3) / 4][(i - 3) / 6] < 100 && Val[(j - 3) / 4][(i - 3) / 6]>0) 
				{
				 	Draw(i+1,j,Val[(j - 3) / 4][(i - 3) / 6]);
				
				}
				else {
				      Draw(i,j,Val[(j - 3) / 4][(i - 3) / 6]);
					}
				}
			
			}
		}	
}
//ham thuc hien yeu cau sang trai
void turnLeft()
{   
  	//day tat ca gia tri ve ben trai khung
	for(int hang=0;hang<4;hang++){



		for(int j=1;j<4;j++)
		{
			for(int i=j-1;i>=0;i--)		


			{
				if(Val[hang][i]==0)
				{Val[hang][i]=Val[hang][i+1];
				Val[hang][i+1]=0;}
			}
		}
	}

	//Xet 2 gia tri ke nhau ma bang nhau thi cong 2 so lai roi xoa di 1 so
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(Val[i][j] == Val[i][j+1])
			{
				Val[i][j]+=Val[i][j];
				diem+=Val[i][j];
				Val[i][j+1]=0;

			}

		}

	}
	//Di chuyen lai 1 lan nua cac phan tu trong hang
	for(int hang=0;hang<4;hang++){



		for(int j=1;j<4;j++)
		{
			for(int i=j-1;i>=0;i--)		


			{
				if(Val[hang][i]==0)
				{Val[hang][i]=Val[hang][i+1];
				Val[hang][i+1]=0;

				}


			}
		}
	}

}
//ham thuc hien yeu cau sang phai
void turnRight()
{
	//dich chuyen tat ca gia tri sang ben phai
	for(int hang=0;hang<4;hang++){
		for(int j=2;j>=0;j--)
		{
			for(int i=j+1;i<=3;i++)
			{
				if(Val[hang][i]==0)
				{Val[hang][i]=Val[hang][i-1];
				Val[hang][i-1]=0;}


			}
		}
	}
	//Xet 2 gia tri ke nhau ma bang nhau thi cong 2 so lai roi xoa di 1 so

	for(int i=0;i<=3;i++)
	{
		for(int j=2;j>=0;j--)
		{
			if (Val[i][j]==Val[i][j+1])
			{
				Val[i][j+1]+=Val[i][j+1];
				Val[i][j]=0;
				diem+=Val[i][j+1]; 
			}
		}
	}
	//dich chuyen lai 1 lan nua
	for(int hang=0;hang<4;hang++){
		for(int j=2;j>=0;j--)
		{
			for(int i=j+1;i<=3;i++)
			{
				if(Val[hang][i]==0)
				{Val[hang][i]=Val[hang][i-1];
				Val[hang][i-1]=0;
				}


			}
		}
	}
	

}

//ham thuc hien yeu cau len tren
void goUp()
{	
	//dich chuyen het tat ca gia tri len tren
	for(int cot=0;cot<4;cot++){
		for(int i=1;i<4;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				//Thay doi cot 1
				if(Val[j][cot]==0)
				{
					Val[j][cot]=Val[j+1][cot];
					Val[j+1][cot]=0;
				}

			}
		}
	}

	//Xet 2 gia tri ke nhau ma bang nhau thi cong 2 so lai roi xoa di 1 so

	for(int j=0;j<4;j++)
	{
		for(int i=1;i<4;i++)
		{
			if(Val[i][j]==Val[i-1][j])
			{
				Val[i-1][j]+=Val[i-1][j];
				diem=diem + Val[i-1][j];
				Val[i][j]=0;

			}

		}

	}
	//dich chuyen lai lan nua
	for(int cot=0;cot<4;cot++){
		for(int i=1;i<4;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				//Thay doi cot 1
				if(Val[j][cot]==0)
				{
					Val[j][cot]=Val[j+1][cot];
					Val[j+1][cot]=0;

				}

			}
		}
	}

}
//ham thuc hien yeu cau xuong duoi
void goDown()
{
	//dich chuyen tat ca gia tri xuong duoi
	for(int cot=0;cot<4;cot++){
		for(int j=2;j>=0;j--)
		{
			for(int i=j+1;i<=3;i++)
			{
				if(Val[i][cot]==0)
				{Val[i][cot]=Val[i-1][cot];
				Val[i-1][cot]=0;}


			}
		}
	}
	//Xet 2 gia tri ke nhau ma bang nhau thi cong 2 so lai roi xoa di 1 so

	for(int j=0;j<4;j++)
	{
		for(int i=3;i>=0;i--)
		{
			if(Val[i][j]==Val[i-1][j])
			{
				Val[i][j]+=Val[i][j];
				diem=diem +Val[i][j];
				Val[i-1][j]=0;

			}
		}
	}
	//dich chuyen lai lan nua
	for(int cot=0;cot<4;cot++){
		for(int j=2;j>=0;j--)
		{
			for(int i=j+1;i<=3;i++)
			{
				if(Val[i][cot]==0)
				{Val[i][cot]=Val[i-1][cot];
				Val[i-1][cot]=0;

				}


			}
		}
	}

}
int state=0,a[4][4],check=0; 
//ham kiem tra su thay doi cac gia tri
void crecheck()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++){
			if(a[i][j]!=Val[i][j])
			{
				check=1;		//khi co gia tri thay doi so voi luc truoc
				
			}

		}

	}
}
//ham kiem tra con gia tri nao cong duoc voi nhau nua khong
bool checkGameOver()
{
	
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (Val[i][j] == Val[i][j + 1] || 	Val[i][j] == Val[i + 1][j]) 
					return false;
			}
		}
	return true;
}
//Ham kiem tra xem ket thuc game chua
int checkGame(int Val[][4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(Val[i][j]==0)	//khi game khong con cho trong
				return 1;	
		}

	}
	if(checkGameOver()==false)	//khi game khong the cong lai
	return 1;
	else return 0;

}
// ham nhan thong tin tu ban phim
int getKey()
{

	char c=getch();
	if(c=='d' )
	{turnRight();
	state=1;}
	else if(c=='s')
	{goDown();
	state=1;}
	else if(c=='w')
	{goUp();
	state=1;}
	else if(c=='a')
	{turnLeft();
	state=1;}
	else if(c== 'x')
	{exit(0);
	}
	else
		state =0;

}
// ham tao so moi ngau nhien
void randPosNum(int Val[][4])
{
	
	int pos1,pos2;
	srand(time(0));
	do
	{

		pos1= rand()%(4);
		pos2= rand()%(4);
	} while (Val[pos1][pos2] !=0);
	do
	{ 
		Val[pos1][pos2]= 2 + rand()%(3);
	} while (Val[pos1][pos2] ==3);

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
//ham tao diem nguoi choi
int Score(int diem)
{
	int s=diem;

	return s;
}

// Ghi diem cao vao file
void write_bestScore(int a)
{
	ofstream fileScore;
	fileScore.open("score.txt", ios::out);
	fileScore << a;
	
	fileScore.close();
}

// Tra ve diem cao nhat
int bestScore()
{
	int score;
	ifstream fileScore;
	fileScore.open("score.txt", ios::in);
	fileScore >> score;

	fileScore.close();
	return score;
}


int main()
{
	
	begin();
	Start();
	getch();
	system("cls");
	
	
	DrawMap();
	SetPos();
	paint xd={ 40, 1, 10, "Best: "};
	Paint(xd.x, xd.y, xd.color, xd.str);

	DrawVal(Val);
	
	while(true)
	{		


		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				a[i][j]=Val[i][j];
				if(Val[i][j]==2048) 
				{
					
					paint end={30, 13, 12, "You Win! Diem cua ban: "};	//xuat hien gia tri 2048->win
					Paint(end.x,end.y,end.color,end.str);
					textcolor(12);
					cout << Score(diem);
					break;
			
				}
			}

		}
		check=0;
		gotoxy(28,1);
		textcolor(11);
		cout<<"Score :";
		
		Draw(35,1,diem);

		getKey();

		if(state==1)	
		{gotoxy(1,1);
		DrawMap();

		}
		if(checkGame(Val)==0 ) //game khong con o trong va khong co gia tri nao cong lai duoc voi nhau
		{
			
				paint lose={30, 13, 12, "Game Over! Diem cua ban: "};
				Paint(lose.x,lose.y,lose.color,lose.str);
				textcolor(12);
				cout<<Score(diem);
				break;
			
			
		
		}
		else
		{	
			crecheck();
			if(check==1)					
				randPosNum(Val);
			
			DrawVal(Val);
			
		}	
			if (diem > bestScore())
			{
				write_bestScore(diem);
		    } 
		    textcolor(10);
			Draw(45, 1, bestScore());	
		
	}

	getch();
	return 0;
}
