#ifndef IDRAW_H_INCLUDED
#define IDRAW_H_INCLUDED

void textcolor(int x);  //Hàm tô màu
void gotoxy(int x, int y);   //đưa con trỏ tới tọa độ (x,y) trên bản đồ.
void setScreen();        //Tạo lập viền khung.
void printmap(int** arr, int c, int r);   //Hiện hệ thống lưới ô.
void randBoom(int** arr, int c, int r);   //Hàm sinh mìn ngẫu nhiên.
void setCell(int** arr, int c, int r);    ////Hàm cung cấp số mìn lân cận cho toàn khung chơi.
int countBoom(int** arr, int x, int y, int col, int row); //Đếm số mìn lân cận.
void creatMapBoom(int **arr, int numCol, int numRow);  //Tạo thánh cả bản đồ chơi.

#endif // IDRAW_H_INCLUDED
