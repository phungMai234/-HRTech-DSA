#include "IMenu.h"
#include <iostream>
#include <Windows.h>

using namespace std;

void inmenu(){
		system("cls");
		cout<<"      _ _ _ _ _ _ _ _ _ _ _ _ GAME DO MIN _ _ _ _ _ _ _ _ _ _ _ _\n";
	    cout<<"\n                                  MENU\n\n";
	    cout<<"                         1 : BAT DAU CHOI      \n\n";				//dung de in menu chinh
	    cout<<"                         2 : HUONG DAN CHOI\n\n";
}
void inhuongdan(){
		system("cls");
		cout<<"+ Dung cac phim mui ten de di chuyen\n\n";
		cout<<"+ Dung 'Space' de mo o ma ban cho la khong chua min\n\n";            //dùng để in hướng dẫn
		cout<<"+ Dung 'Backspace' de danh dau o chua min\n\n";
		cout<<"       * Nhan 'b' de tro lai menu *";
}
