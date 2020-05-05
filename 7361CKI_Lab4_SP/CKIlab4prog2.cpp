#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <unistd.h>
#include <signal.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;
int main()
{
	pid_t v;
	int j=0,k=0,status=0,i=0,f=0;
	const char *from, *progname="/7361CKI_Lab4_SP/A", *to, *forcom, *forobh;
	string s,p,b,g,z,w,q="/",m;
	cout<<"Enter the name of the sender folder:";
	cin>>b;
	cout<<"Enter the name of the recipient folder:";
	cin>>p;
	w="ls "+q+b+">1.txt";
	forobh=w.c_str();
	system(forobh);
	ifstream file ("/7361CKI_Lab4_SP/1.txt");
	ifstream file1 ("/7361CKI_Lab4_SP/1.txt");
	cout<<"\tList of files in directory "<<b<<" is:"<<endl;
	cout<<"\t*****************************************"<<endl;
	while (getline(file,s))
	{
		cout<<"\t*\t\t"<<s<<"\t\t\t*"<<endl;
		sleep(1);
		j++;
	}
	cout<<"\t*****************************************"<<endl;
	sleep(1);
	cout<<"\tThe number of files in directory is: "<<j<<endl;
	sleep(1);
	file.close();
	s.clear();
	while (getline(file1,s))
	{
		g=b+q+s;
		z=p+q+s;
		from=g.c_str();
		to=z.c_str();
		cout<<"\tThe file "<<s<<" is copying from: "<<b<<" to: "<<p<<endl;
		v=fork();
		switch(v)
		{
			case -1:
				cout<<"\tOops, My heart just stuck between these loops"<<endl;
			case 0:
				cout<<"\tThe PID of Child is: "<<getpid()<<endl;
				sleep(10);
				execl("A",progname,from,to,NULL);	
			default:
				cout<<"\tThe PID of Parent is: "<<getpid()<<endl;
				wait(&status);
				cout<<"\tExit status is: "<<WEXITSTATUS(status)<<endl;
				if (WEXITSTATUS(status) == 1)
				{
					i++;
				}
				else
				{
					f++;
				}


		}

	}
	file1.close();
	cout<<"The Number of successfully copied files is: "<<i<<endl;
	cout<<"The Number of fails is: "<<f<<endl;
	return 0;
}
