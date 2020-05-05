#include <iostream>
#include <ctime>
using namespace std;
int genmass(unsigned char a[3][3])
{
	srand(unsigned(time(NULL)));
	for (int i=0;i<3;++i)
	{
		for (int j=0;j<3;++j)
		{
			a[i][j]=((rand () % 10));
		}
	}
	for (int i=0;i<3;++i)
	{
		for (int j=0;j<3;++j)
		{
			cout<<(int)a[i][j]<<" ";
		}
		cout<<endl;
	}
	return a[3][3];
}

int sumsqrt(unsigned char *data)
{
	int sum=0;
	__asm__
	(
	 "movl $9, %%ecx\n\t"
	 "prohod:\n\t"
	 "movb (%%rbx), %%al\n\t"
	 "movb (%%rbx), %%dl\n\t"
	 "mulb %%dl\n\t"
	 "addw %%ax, %%si\n\t"
	 "incq %%rbx\n\t"
	 "loop prohod\n\t"
	 :"=S"(sum)
	 :"S"(sum), "b"(data)
	 :"cc", "memory"
	);
	return sum;
}

int main()
{
	unsigned char mass[3][3];
	int sum=0;
	cout<<"your massive is:"<<endl;
	genmass(mass);
	sum=sumsqrt(&mass[0][0]);
	cout<<"sum of squares is:"<<sum<<endl;
	return 0;
}
