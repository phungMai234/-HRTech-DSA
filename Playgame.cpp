#include <iostream>
#include "IStruct.h"
#include "IDraw.h"
#include "IPlaygame.h"

using namespace std;

//Hàm di chuyển con trỏ bằng các phím mũi tên.
 void movePointer(ToaDo * pnt, ToaDo * pntArr, int numCol, int numRow){
  if (GetAsyncKeyState(VK_LEFT)){   //Di chuyển sang trái sao cho vẫn ở trong khung chơi.
   if (pntArr->_y > 0){
    --(pntArr->_y);
    covertCoordToArr(pnt, pntArr);
    gotoxy(pnt->_x, pnt->_y);
   }
  }
  if (GetAsyncKeyState(VK_RIGHT)){  //Di chuyển sang phải sao cho vẫn ở trong khung chơi.
   if (pntArr->_y < numCol){
    ++(pntArr->_y);
    covertCoordToArr(pnt, pntArr);
    gotoxy(pnt->_x, pnt->_y);
   }
  }
  if (GetAsyncKeyState(VK_UP)){    //Di chuyển lên trên sao cho vẫn ở trong khung chơi.
   if (pntArr->_x > 0){
    --pntArr->_x;
    covertCoordToArr(pnt, pntArr);
    gotoxy(pnt->_x, pnt->_y);
   }
  }
  if (GetAsyncKeyState(VK_DOWN)){  //Di chuyển xuống dưới sao cho vẫn ở trong khung chơi.
   if (pntArr->_x < numRow){
    pntArr->_x++;
    covertCoordToArr(pnt, pntArr);
    gotoxy(pnt->_x, pnt->_y);
   }
  }
  Sleep(100);
}
void actionPointer(ToaDo * pnt, ToaDo * pntArr, int numCol, int numRow, int** arr, int* bomNotRemoved, int* realBomNotRemoved){
  if (GetAsyncKeyState(VK_SPACE)){  //sử dụng "Space" mở ô mà bạn cho rằng là không chứa mìn.
   if (arr[pntArr->_x][pntArr->_y] == -1){
    cout << "*";    //Dấu "*" sẽ hiện ra khi ô bạn mở chứa mìn.
    gotoxy(65, 18);
    textcolor(14);
    cout << "!!! YOU LOSE !!!";
    cin.ignore(1);    //Bỏ qua các dấu trắng không cần thiets.
    exit(0);
   }
   else{
    if (/*arr[pntArr->_x][pntArr->_y] != 0 &&*/ arr[pntArr->_x][pntArr->_y] != 13){
      if(arr[pntArr->_x][pntArr->_y] == 0){
       gotoxy(pnt->_x, pnt->_y);
       cout << " "; // Ô không chứa mìn và lân cận cũng không có mìn thì không hiên gì khi được mở.
       arr[pntArr->_x][pntArr->_y] = 13;   //Dánh dấu ô đó lại
       areaOpen(arr, pnt, pntArr, numCol, numRow); //Mở các ô lân cận.
       gotoxy(pnt->_x, pnt->_y);
      }
    }
    if(arr[pntArr->_x][pntArr->_y] != 0 && arr[pntArr->_x][pntArr->_y] != 15 //15 là dánh dấu các ô chứa mìn đã bị loại bỏ.
           && arr[pntArr->_x][pntArr->_y] != 13){ //13 là các ô khi mở hiện dấu trống.
       gotoxy(pnt->_x, pnt->_y);
        cout << arr[pntArr->_x][pntArr->_y];
        areaOpen(arr, pnt, pntArr, numCol, numRow);//Mở các ô lân cận.
        gotoxy(pnt->_x, pnt->_y);
      }
   }
  }

  if(GetAsyncKeyState(VK_BACK)){   //sử dụng "backspace" để đánh dấu ô mà bạn cho rằng là chứa mìn.
   if(arr[pntArr->_x][pntArr->_y] != 13 && arr[pntArr->_x][pntArr->_y] != 15){
    if(arr[pntArr->_x][pntArr->_y] == -1){
     --(*realBomNotRemoved);
     //gotoxy(1, 1);
     //textcolor(12);
     //Win
     if((*realBomNotRemoved) == 0){
           gotoxy(65, 18);
           textcolor(14);
           cout << "!!! YOU WIN !!!";
           cin.ignore(1);
           exit(0);
     }
    }
    gotoxy(pnt->_x, pnt->_y);
    textcolor(12);
    cout << char(CHAR);
    arr[pntArr->_x][pntArr->_y] = 15; //15 là dánh dấu các ô chứa mìn đã bị loại bỏ.
    updateBoomRemove(bomNotRemoved);
    gotoxy(pnt->_x, pnt->_y);
    textcolor(7);
   }
  }
  Sleep(100);
}
//Hàm chuyển đổi tọa độ sang mảng.
void covertCoordToArr(ToaDo * pnt, const ToaDo * pntArr){
 pnt->_x = X0 + 3 + pntArr->_y;
 pnt->_y = Y0 + 3 + pntArr->_x;
}
//Hàm mở một số ô lân cận khi bạn mở một ô không chứa mìn.
void areaOpen(int** arr,const ToaDo* pnt,const ToaDo* pntArr, int numCol, int numRow){
 for(int i = -2; i <= 2; i++){
  for(int j = -2; j <= 2; j++){
   if(0 <= pntArr->_x + i && pntArr->_x + i < numCol &&
                     0 <= pntArr->_y + j && pntArr->_y + j < numRow){
                      if(arr[pntArr->_x + i][pntArr->_y + j] != 13 && arr[pntArr->_x + i][pntArr->_y + j] != 15
           && arr[pntArr->_x + i][pntArr->_y + j] != -1){
                       gotoxy(pnt->_x + j, pnt->_y + i);
                        if(arr[pntArr->_x + i][pntArr->_y + j] == 0) cout << " ";
                        else{
                         cout << (arr[pntArr->_x + i][pntArr->_y + j]);      //một số ô lân cận sẽ hiện số lượng mìn mà gần nó có.
         }
                        arr[pntArr->_x + i][pntArr->_y + j] = 13;
          }

   }
  }
 }
}
//Hàm cập nhật số mìn hiện tại.
void updateBoomRemove(const int* boomNotRemoved){
 gotoxy(20, 5);
 cout << "BOOM : " << *boomNotRemoved;
}
//Hàm in thông tin khi một ô được mở.
void printArr(int** Arr, int* numCol, int* numRow){
 for(int i = 0; i < *numCol ; i++){
  for(int j = 0; j < *numRow ; j++){
   if(Arr[i][j] == -1) cout << "* ";
   else cout << Arr[i][j] << " ";
  }
  cout << endl;
 }
}
//Dùng phối hợp các phím chức năng để bắt đầu chơi.
void playGame(ToaDo * pnt, ToaDo * pntArr, int numCol, int numRow, int** arr, int* boomNotRemoved, int* realBomNotRemoved){
 while (1){
  movePointer(pnt, pntArr, numCol, numRow);
  actionPointer(pnt, pntArr, numCol, numRow, arr, boomNotRemoved, realBomNotRemoved);
 }
}
