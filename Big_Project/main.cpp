#include <iostream>
#include"console.h"
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<windows.h>
#include<stdint-gcc.h>

#define LEFT 4
#define TOP 4

#define MaxI 22
#define MaxJ 10

int Board[MaxI][MaxJ];

using namespace std;

struct KhoiGach
{
    int **arr; // la cai j
    int Row, Col;
    int iBoard, jBoard; // jBoard chá»‰ hÃ ng, iBoard chá»‰ cá»™t
};
KhoiGach *TaoKhoiGach(int ID)
{
	KhoiGach *pkhoigach = new KhoiGach;
	switch(ID)
	{
		case 15: // hÃ¬nh chá»¯ I
			pkhoigach->Row=4;
			pkhoigach->Col = 1;
			pkhoigach->iBoard=0;
			pkhoigach->jBoard=5;
			break;
		case 31: // hinh vuÃ´ng
			pkhoigach->Row=pkhoigach->Col=2;
			pkhoigach->iBoard=2;
			pkhoigach->jBoard=5;
            break;
		default: // hÃ¬nh T,L,Z
			pkhoigach->Row=2;
			pkhoigach->Col=3;
			pkhoigach->iBoard=2;
			pkhoigach->jBoard=5;
			break;
	}
	pkhoigach->arr = new int*;
	for(int i = 0; i < pkhoigach->Row; i++)
	{
		pkhoigach->arr[i] = new int;
	}
	for(int k = 0; k < pkhoigach->Col * pkhoigach->Row; k++)
	{
		pkhoigach->arr[k / pkhoigach->Col][k % pkhoigach->Col] = (ID >> (pkhoigach->Col * pkhoigach->Row - 1 - k)) & 1;
	}
	return pkhoigach;
}
int Loai()
{
    srand(time(NULL));
    int x=rand()%7;
	switch(x)
	{
        case 0:
            return 15;
            break;
        case 1:
            return 31;
            break;
        case 2:
            return 51;
            break;
        case 3:
            return 30;
            break;
        case 4:
            return 58;
            break;
        case 5:
            return 57;
            break;
        case 6:
            return 60;
            break;
	}
}

void VeKhoiGach(KhoiGach* pkhoigach)
{
	int i;
	int j;
	for(i = 0;i < pkhoigach->Row; i++)
		for(j = 0;j < pkhoigach->Col; j++)
			if(pkhoigach->arr[i][j] == 1 && (pkhoigach->iBoard + i )> 3) // arr k hieu
			{
				TextColor(13);
				gotoXY(LEFT + pkhoigach->jBoard + j + 1, TOP + pkhoigach->iBoard + i - 3);
				cout << char(2); // nho cout ra
			}
}

void XoaKhoiGach(KhoiGach* pkhoigach)
{
    int i, j;
    for(i = 0; i < pkhoigach->Row; i++)
    {
        for(j = 0; j < pkhoigach->Col; j++)
        {
            if(pkhoigach->arr[i][j] == 1 && (pkhoigach->iBoard + i) > 3)
            {
                TextColor(0);
                gotoXY(LEFT + pkhoigach->jBoard + j + 1, TOP + pkhoigach->iBoard + i - 3);
                cout <<" ";
            }
        }
    }
}
// ham kiem tra khoi gach co nam trong bang hay k

int Inside(int i, int j)
{
    return ((i > 0 && i < MaxI) && (j > 0 && j < MaxJ));
}

// ham di chuyen mot khoi gach sang trai, phai, xuong

int Left(int i, int j)
{
    if(j > 0 && Inside(i, j) && Board[i][j - 1] == 0)
        return 1;
    return 0;
}
int Right(int i, int j)
{
    if((j < MaxJ - 1) && Inside(i, j) && Board[i][j + 1] == 0)
        return 1;
    return 0;
}
int Down(int i, int j)
{
    if((i < MaxI - 1) && Inside(i, j) && Board[i + 1][j] == 0)
        return 1;
    return 0;
}

// ham di chuyen ca khoi gach

void SangTrai(KhoiGach* pkhoigach)
{
    int i, j;
    for(i = 0; i < pkhoigach->Row; i++)
    {
        for(j = 0; j < pkhoigach->Col; j++)
        {
            if(pkhoigach->arr[i][j] == 1)
            {
                if(Left(pkhoigach->iBoard + i, pkhoigach->jBoard + j) == 0 || pkhoigach->iBoard <= 3)
                    return;
            }
        }
    }
    pkhoigach->jBoard-=1;
}

void SangPhai(KhoiGach* pkhoigach)
{
    int i, j;
    for(i = 0; i < pkhoigach->Row; i++)
    {
        for(j = 0; j < pkhoigach->Col; j++)
        {
            if(pkhoigach->arr[i][j] == 1)
            {
                if(Right(pkhoigach->iBoard + i, pkhoigach->jBoard + j) == 0 || pkhoigach->iBoard <= 3)
                    return;
            }
        }
    }
    pkhoigach->jBoard+=1;
}

int RoiXuong(KhoiGach* pkhoigach)
{
    int i, j;
    for(i = 0; i < pkhoigach->Row; i++)
    {
        for(j = 0; j < pkhoigach->Col; j++)
        {
            if(pkhoigach->arr[i][j] == 1)
            {
                if(Down(pkhoigach->iBoard + i, pkhoigach->jBoard + j) == 0)
                    return 0; // khong roi xuong
            }
        }
    }
    pkhoigach->iBoard+=1;
    return 1; // roi xuong
}
void XoayKhoiGach(KhoiGach* pkhoigach) // hoi quan
{
	int i,j;
	int ** tmpArr;
	int tmpRow = pkhoigach->Col;
	int tmpCol = pkhoigach->Row;
	//Cáº¥p phÃ¡t bá»™ nhá»› cho ma tráº­n phá»¥ tmpArr.
	tmpArr= new int*;
	for( i = 0; i < tmpRow; i++)
	{
		tmpArr[i] = new int;
	}
	///////////////////////////////////////////////
	for(i = pkhoigach->Row - 1; i >= 0; i--)
		for(j = pkhoigach->Col - 1; j >= 0; j--)
		{
			tmpArr[j][pkhoigach->Row - i - 1] = pkhoigach->arr[i][j];
		}
	//Kiá»ƒm tra há»£p lá»‡.
		for (i=0;i<tmpRow;i++)
		{
			for(j=0;j<tmpCol;j++)
				if(!Inside(pkhoigach->iBoard+i,pkhoigach->jBoard+j)||Board[pkhoigach->iBoard+i][pkhoigach->jBoard+j]==1)
					return;
		}
	for(i=0;i<pkhoigach->Row;i++) delete(pkhoigach->arr[i]);
	delete(pkhoigach->arr);
	//Cáº­p nháº­t thay Ä‘á»•i sau khi xoay.
	pkhoigach->Col=tmpCol;
	pkhoigach->Row=tmpRow;
	pkhoigach->arr=tmpArr;

}


//--------------------------------------------------------------------------------------------------
// hien thi thong tin tro choi
struct INFO
{
    int score;
    int level;
    float speed;
};

void InitGame(INFO *info)
{
	info->level=1;
	info->score=0;
	info->speed=0.5;
}

int CapNhat(INFO *info, int score)
{
	info->score+=score;
	if(info->score>=200&&info->level<2)
	{
		info->level++;
		info->speed-=0.1;
	}
	return 0; //Chua win game.
}
void VeBangDiem(INFO info)
{
	TextColor(15);
	gotoXY(LEFT+MaxJ+2,10);
	cout << "  SCORE: " << info.score;
	gotoXY(LEFT+MaxJ+2,11);
	cout << "  LEVEL: " << info.level;
	gotoXY(LEFT+MaxJ+2,12);
	cout << "  SPEED: " << info.speed;
}
//-------------------------------------------------

void HuyKhoiGach(KhoiGach* pkhoigach)
{
	int i;
	//Huy bo nho cua ma tran trang thai arr.
	for(i=0;i<pkhoigach->Row;i++)
        delete(pkhoigach->arr[i]);
	delete(pkhoigach->arr);
	/////////////////////////////////////////////////////////
	//Sau do moi free(pkhoigach)
	delete(pkhoigach);
	pkhoigach=NULL;
}
// ham xuat hien khoi gahc tiep theo
//--------------------------------------------------------------------
void Ve_Next(int ID)
{
	KhoiGach *pnext=TaoKhoiGach(ID);
	int iRoot=LEFT+MaxJ + 5;
	int jRoot=TOP;
	for(int i=0;i<pnext->Row;i++)
	{
		for (int j=0;j<pnext->Col;j++)
		{
			if(pnext->arr[i][j]==1)
			{
				TextColor(15);
				gotoXY(iRoot+j,jRoot+i);
				cout << char(2);
			}
		}

	}
	HuyKhoiGach(pnext);
}
void Xoa_Next()
{
	int iRoot=LEFT+MaxJ+5;
	int jRoot=TOP;
	for(int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{

				TextColor(0);
				gotoXY(iRoot+j,jRoot+i);
				cout << " "; // chÃº Ã½ in ra dáº¥u cÃ¡ch
		}

	}
}

// giai phong bo nhp

//---------------------------------------------------------------------------------------------
void GanGiaTri(KhoiGach* pkhoigach)
{
	for(int i=0;i<pkhoigach->Row;i++)
		for(int j=0;j<pkhoigach->Col;j++)
			if(pkhoigach->arr[i][j]==1)
			{
				Board[pkhoigach->iBoard+i][pkhoigach->jBoard+j]=1;
			}
}

void DisplayBoard()
{
	int i,j;
	for(i=0;i<MaxI;i++)
		for(j=0;j<MaxJ;j++)
		{
			if(Board[i][j]==1&&i>=4)
			{
				gotoXY(j+LEFT+1,i+TOP+1-4);TextColor(14);cout << char(2);
			}
			if(Board[i][j]==0&&i>=4)
			{
				TextColor(0);gotoXY(j+LEFT+1,i+TOP+1-4);cout << " ";
			}
		}
}

void CapNhatLaiToaDo(int hang)
{
	int i,j;
	for(i=hang;i>0;i--)
		for(j=0;j<MaxJ;j++)
		{
            Board[i][j]=Board[i-1][j];
		}
}
int KiemTra(KhoiGach *pkhoigach,INFO *infogame) //-1 : gameover 0: win
{
		int i,j,count;
		i=pkhoigach->Row - 1;
		if(pkhoigach->iBoard<=3) return -1;//Gameover
		if(infogame->score>=300) return 0;//Win
		do
		{
			count=0;
			for(j=0;j<MaxJ;j++)
			{
				if(Board[pkhoigach->iBoard+i][j]==1)	count++;
			}
			if(count==MaxJ)
			{
				CapNhat(infogame,20);
				CapNhatLaiToaDo(pkhoigach->iBoard+i);
				DisplayBoard();
			}
			else
			{
				i=i-1;
			}
		}while(i>=0);
		return 1;
}


void DrawBoard()
{
	int i,j;
	for(i=LEFT;i<=LEFT+10+1;i++)
		for(j=TOP;j<=TOP+18+1;j++)
		{
			if((j==TOP||j==TOP+18+1)&&i>LEFT&&i<LEFT+10+1)
			{
				gotoXY(i,j);TextColor(7);
				cout << char(205);
			}
			if((i==LEFT||i==LEFT+10+1)&&j>TOP&&j<TOP+18+1)
			{
				gotoXY(i,j);TextColor(7);
				cout << char(186);
			}
		}
		gotoXY(LEFT,TOP);TextColor(10);cout << char(219);
		gotoXY(LEFT+10+1,TOP);TextColor(10);cout << char(219);
		gotoXY(LEFT,TOP+18+1);TextColor(10);cout << char(219);
		gotoXY(LEFT+10+1,TOP+18+1);TextColor(10);cout << char(219);

}
bool help()
{
    char choice;
    cout << "------------------Guide to Play Tetris Game----------------\n"
            "- Tetris Game is a puzzle with the shapes each consisting -\n"
            "- of several squares, that are falling down the well.     -\n"
            "- When playing a tetris game, one turns them or moves left-\n"
            "- and right, trying to arrange the shapes in a line.      -\n"
            "- When a line of squares makes a line from edge to edge,  -\n"
            "- it disappears and all the pieces move down by a square. -\n"
            "- When the well is filled up, the player lose.            -\n";

    cout << "Do you want to back Main menu? (Y/N) \n";

    choice = _getch();
    if(choice == 'N' || choice == 'n')
        return false;
    return true;
}
bool credit()
{
    char choice;
    cout << "--------Credit Game Tetris-------\n"
            "-- Author: Phung Thi Tuyet Mai --\n"
            "-- Number: 17020875            --\n"
            "-- Class : K62IE3              --\n"
            "---------------------------------\n";
    cout << "Do you want to back Main menu? (Y/N) \n";

    choice = _getch();
    if(choice == 'N' || choice == 'n')
        return false;
    return true;
}
void dieuKhienChinh()
{
    clrscr();
    int IDKhoiTiepTheo;
    clock_t Start, End;
    char key;


    INFO info;
    KhoiGach *currKhoi;
    currKhoi = TaoKhoiGach(Loai());
    IDKhoiTiepTheo = Loai();
    DrawBoard();
    InitGame(&info);
    do
    {
        VeBangDiem(info);
        VeKhoiGach(currKhoi);
        Xoa_Next();
        Ve_Next(IDKhoiTiepTheo);
        Start = clock();
        do
        {
            if(_kbhit())
            {

                key = _getch();
                XoaKhoiGach(currKhoi);
                if(key == 'a' || key == 'A')
                    SangTrai(currKhoi);
                if(key == 'd' || key == 'D')
                    SangPhai(currKhoi);
                if(key == 's' || key == 'S')
                    RoiXuong(currKhoi);
                if(key == 'w' || key == 'W')
                    XoayKhoiGach(currKhoi);
                VeKhoiGach(currKhoi);
            }

            End = clock();
        }while(float(End - Start) / CLK_TCK < info.speed);
        XoaKhoiGach(currKhoi);
        if(RoiXuong(currKhoi) == 0)
        {
            GanGiaTri(currKhoi);

            int ketqua = KiemTra(currKhoi, &info);
            if(ketqua == -1 || ketqua == 0)
                break;

            HuyKhoiGach(currKhoi); // giai phong bÃ´j nhá»›

            currKhoi = TaoKhoiGach(IDKhoiTiepTheo);
            IDKhoiTiepTheo = Loai();
        }
        DisplayBoard(); // ve khoi Ä‘áº« rÆ¡i cuá»‘ng cuá»‘ibáº£ng
    }while(1);

    // hiá»‡n chá»¯ end game
    TextColor(15);
    gotoXY(35,25);
    cout << "End Game.Press anykey to exit.";
    _getch(); // cÃ¡i nÃ y Ä‘á»ƒ lÃ m j
}

int main() /* chay chÆ°a het game Ä‘Ã£ dá»«ng*/
{
    char choice;

    do
    {
        /*Draw a main menu */
        cout << "--------------GAME TETRIS-------------" << endl;
        cout << "**************MAIN MENU**************" << endl;
        cout << "(1) - New Game" <<  endl;
        cout << "(2) - Help" << endl;
        cout << "(3) - Credit" << endl;
        cout << "(4) - Quit Game" << endl;
        cout << "--------------------------------------" << endl;
        /*Get a character from keyvoard*/
        choice = _getch();
        /*choose a function to be exercuted*/

        if(choice == '1')
        {
            dieuKhienChinh();
        }
        if(choice == '2')
        {
            clrscr();
            if(!help())
                break;
        }
        if(choice == '3')
        {
            clrscr();
            if(!credit())
                break;
        }
        if(choice == '4')
        {
            break;
        }
        clrscr();
    }while(1);


    return 0;
//    int ID = Loai();
//    KhoiGach* currKhoi;
//
//    currKhoi = TaoKhoiGach(ID);
//    VeKhoiGach(currKhoi);
//    while(1)
//        {
//            if(_kbhit())
//            {
//                clrscr();
//                DrawBoard();
//                char key = _getch();
//                if(key == 'a' || key == 'A')
//                    SangTrai(currKhoi);
//                if(key == 'd' || key == 'D')
//                    SangPhai(currKhoi);
//                if(key == 's' || key == 'S')
//                    RoiXuong(currKhoi);
//                if(key == 'w' || key == 'W')
//                    XoayKhoiGach(currKhoi);
//                VeKhoiGach(currKhoi);
//            }
//            else
//            {   clrscr();
//                RoiXuong(currKhoi);
//                VeKhoiGach(currKhoi);
//
//            }
//            Sleep(500);
//        }


}
