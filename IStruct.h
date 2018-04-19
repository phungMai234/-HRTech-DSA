#ifndef _ISTRUCT_H_INCLUDED
#define _ISTRUCT_H_INCLUDED

#include <windows.h>
#include <vector>

#define YMAX 50
#define XMAX 50
//Row 0 = column 0 = 10
#define X0 10
#define Y0 10
#define CHAR 219
#define BOOM 50

//Khai báo cấu trúc tọa độ của bản đồ.
struct ToaDo{
 int _x;
 int _y;

 ToaDo(int x, int y);
};
#endif // ISTRUCT_H_INCLUDED
