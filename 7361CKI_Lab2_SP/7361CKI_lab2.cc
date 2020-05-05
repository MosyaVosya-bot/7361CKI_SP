#include <iostream>
using namespace std;
int main  ()
{
	short a[12] = {-13214, -156, 10, 1500, -10, -200, 24536, 500, -70, -3230, 2100, 61};
	int i = 0;
	long b = 0;
	for (i=0; i<12; ++i)
	{
		if (a[i] < 0)
		{
			a[i] *= -1;
		}	
		b += a[i];
	}
	cout << b << endl;
	return 0;
}
