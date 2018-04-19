#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "IDraw.h"
#include "IStruct.h"

using namespace std;

// Hàm tô màu.
void textcolor(int x)
{
 HANDLE mau;
 mau = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(mau, x);
}
// Hàm dịch chuyển con trỏ tới tọa độ x, y.
void gotoxy(int x, int y)     //Đưa vào giá trị là hàng thứ x và cột thứ y trong bản đồ.
{
 HANDLE hConsoleOutput;
 COORD Cursor_an_Pos = { x-1, y-1 };
 hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//Hàm tạo lập khung chơi.
void setScreen(){
 for (int i = X0; i <= XMAX; i++){
  textcolor(14);
  gotoxy(i, Y0);
  cout << char(CHAR);
  gotoxy(i, YMAX);
  cout << char(CHAR);
 }
 for (int i = Y0; i <= YMAX; i++){
  textcolor(14);
  gotoxy(X0, i);
  cout << char(CHAR);
  gotoxy(XMAX, i);
  cout << char(CHAR);
 }
 for (int i = X0 + 3; i <= XMAX - 3; i++){
  for (int j = Y0 + 3; j <= YMAX - 3; j++){
   if (i % 2 == 0){
    if (j % 2 == 0){
     textcolor(8);
     gotoxy(i, j);
     cout << char(CHAR);
    }
    else{
     textcolor(5);
     gotoxy(i, j);
     cout << char(CHAR);
    }
   }
   else{
    if (j % 2 == 0){
     textcolor(5);
     gotoxy(i, j);
     cout << char(CHAR);
    }
    else{
     textcolor(8);
     gotoxy(i, j);
     cout << char(CHAR);
    }
   }
  }
 }
}
//Hàm thiết lập giá trị ban đầu bằng 0 cho các ô.
void printmap(int** arr, int c, int r){
 for (int i = 0; i < c; i++){
  for (int j = 0; j < r; j++){
   arr[i][j] = 0;           //Ban đầu không có mìn ở lân cận.
  }
 }
}
//Hàm sinh mìn ngẫu nhiên.
void randBoom(int** arr, int c, int r){
 int boom = BOOM;
 int x, y;
 while (boom){
  do{
   x = rand() % c;
   y = rand() % r;
  } while (arr[x][y] != 0);
  arr[x][y] = -1; // Số "-1" đại diện cho ô chứa mìn..
  boom--;
 }
}
//Hàm cung cấp số mìn lân cận cho toàn khung chơi.
void setCell(int** arr, int c, int r){
 for (int i = 0; i < c; i++){
  for (int j = 0; j < r; j++){
   if (arr[i][j] != -1){
    arr[i][j] = countBoom(arr, i, j, c, r);   //Đếm số mìn ở các ô lân cận
   }
  }
 }
}
//Hàm cung cấp số mìn tại một ô.
int countBoom(int** arr, int x, int y, int col, int row){
 int numBoom = 0;
 for (int i = -1; i <= 1; i++){
  for (int j = -1; j <= 1; j++){
   if ((i != 0 || j != 0) && 0 <= x + i && x + i < col && 0 <= y + j && y + j < row){
    if (arr[x + i][y + j] == -1){
     numBoom++;
    }
   }
  }
 }
 return numBoom;  //Trả về số lượng mìn đếm được.
}
//Hàm tạo lập lưới các ô chứa mìn.
void creatMapBoom(int **arr, int numCol, int numRow){
 printmap(arr, numCol, numRow);
 srand(time(NULL));
 randBoom(arr, numCol, numRow);   //Sinh mìn ngẫu nhiên với số lượng định sẵn rồi đưa vào bản đồ.
 setCell(arr, numCol, numRow);
}
