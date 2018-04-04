/*to hop*/
#include<iostream>

using namespace std;
#define MAX 10

int n, k;
int arr[MAX];

void dequi(int);
void print();

int main()
{
	
	cout << "Nhap n : " << endl;
	cin >> n;
	cout << "Nhap k : " << endl;
	cin >> k;
	dequi(1);
	
}

void dequi(int i)
{
	int j;
	for(j = arr[i - 1] + 1; j <= n - k + i; j++)
	{
		arr[i] = j;
		if(i == k)
			print();
		else
			dequi(i + 1);
	}
}
void print()
{
	int i;
	for(i = 1; i <= k; i++)
		cout << arr[i];
	cout << endl;
}
