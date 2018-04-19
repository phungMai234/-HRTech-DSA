#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "IStruct.h"    //Cấu trúc tọa độ của bản đồ.
#include "IDraw.h"      //Tạo lập khung chơi và khởi tạo ban đầu.
#include "IMenu.h"      //In menu chính.
#include "IPlaygame.h"  //Thiết lập cách chơi game.

using namespace std;

int main(){
    BATDAU:
	{
		NHAPLAI: while(1) {
			inmenu();
			char chon=getch();
	    	if(chon=='1') goto CHOI;  //Người chơi chọn "1" sẽ bắt đầu chơi.
	    	else if(chon=='2') goto TIEPTUC;
                else goto NHAPLAI;
		}
	}
    TIEPTUC:
		{
			while(1)
			{
				inhuongdan();       //Chọn "2 " thì in hướng dẫn.
			    char quaylai=getch();
			    if(quaylai=='b'||quaylai=='B') goto BATDAU;  //Nhán "b" để quay lại menu chính.
			}
		}
    CHOI:
	{
    system("cls");          //Xóa màn hình để bắt đầu chơi.
    int bomNotRemoved = BOOM;
    int realBomNotRemoved = BOOM;  //Cập nhật số mìn hiện tại

    int numCol = XMAX - X0 + 10;
    int numRow = YMAX - Y0 + 10;
    int **arr = new int*[numCol];

    for (int i = 0; i < numCol; i++){
    arr[i] = new int[numRow];
    }

    numCol -= 16;
    numRow -= 16;

    creatMapBoom(arr, numCol, numRow);
    ToaDo pnt(X0 + 3, Y0 + 3);
    ToaDo pntArr(0, 0);
    setScreen();
    //printArr(arr, &numCol, &numRow);

    updateBoomRemove(&bomNotRemoved);
    gotoxy(pnt._x, pnt._y);
    playGame(&pnt, &pntArr, numCol, numRow, arr, &bomNotRemoved, &realBomNotRemoved);  //Chơi game theo hướng dẫn.
    _getch();
	}
    return 0;
}
