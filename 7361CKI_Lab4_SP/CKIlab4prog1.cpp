#include <iostream>
#include <fstream>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;
int main(int argc, char* argv[])
{
	ifstream fs;
	ofstream ft;
	char ch;
	fs.open(argv[1]);
	if (!fs)
	{
		cout<<"\tOops,file doesn't exist"<<endl;
		exit(0);

	}
	ft.open(argv[2]);
	if (!ft)
	{
		cout<<"\tOops,target destenition doesn't exist"<<endl;
		fs.close();
		exit(0);

	}
	while (fs.eof() == 0)
	{
		fs >> ch;
		ft << ch;
	}
	cout<<"\t\t\tDone"<<endl;
	exit (1);
	fs.close();
	ft.close();
}
