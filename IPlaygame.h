#ifndef IPLAYGAME_H_INCLUDED
#define IPLAYGAME_H_INCLUDED

void covertCoordToArr(ToaDo * pnt, const ToaDo * pntArr);  //Chuyển bản đồ sang mảng.
void movePointer(ToaDo * pnt, ToaDo * pntArr, int numCol, int numRow);  //Thiết lập di chuyển con trỏ bằng phím mũi tên.
void actionPointer(ToaDo * pnt, ToaDo * pntArr, int numCol, int numRow, int** arr, int* bomNotRemoved, int* realBomNotRemoved);
//Dùng "Space" để mở ô không chứa mìn và "Backspace" để đánh dấu ô chứa mìn.
void areaOpen(int** arr, const ToaDo* pnt, const ToaDo* pntArr, int numCol, int numRow);  //Mở một số ô không chứa mìn lân cận.
void updateBoomRemove(const int* bomNotRemoved); //Cập nhật số mìn sau khi đã tìm ra ở hiện tại.
void printArr(int** Arr, int* numCol, int* numRow); //In thông tin khi mở một ô.
void playGame(ToaDo * pnt, ToaDo * pntArr, int numCol, int numRow, int** arr, int* boomNotRemoved, int* realBomNotRemoved);
//Dùng phối hợp các phím chức năng để bắt đầu chơi.

#endif // IPLAYGAME_H_INCLUDED
