#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct thread_data {
	
	string in;
	string out;
};

void *foo(void *threadarg) {

	struct thread_data *my_data;
	my_data = (struct thread_data *) threadarg;

	ifstream fs;
	ofstream ft;
	char ch;

	cout<<" The file: "<<my_data->in
		<<" is coping to: "<<my_data->out<<endl;

	fs.open(my_data->in);
	ft.open(my_data->out);

	if (!fs ||!ft) {
		cout<<"Oops,error"<<endl;
		exit (123);
	}	

	while (fs.eof()==0) {
		fs>>ch;
		ft<<ch;
	}

	fs.close();
	ft.close();
	pthread_exit(NULL);
}

int main() {

	const char *fullobh;
	int NUM_THREADS=0;
	int i=0;
	int call;
	void *status;
	string check;
	string obh;
	string sender;
	string recipient;

	cout<<"Enter the name of the sender folder: ";
	cin>>sender;
	cout<<"Enter the name of the recipient folder: ";
	cin>>recipient;

	obh="ls "+sender+">1.txt";
	fullobh=obh.c_str();
	system (fullobh);

	ifstream r1 ("/test/1.txt");
	cout<<"\tThe list of files in directory: "
		<<sender<<" is:"<<endl;
	cout<<"\t*****************************************"<<endl;

	while (getline(r1, check)) {
		cout<<"\t*\t\t"<<check<<"\t\t\t*"<<endl;
		sleep(1);
		++NUM_THREADS;
	}

	r1.close();

	cout<<"\t*****************************************"<<endl;
	cout<<"\tNum of files in directory "<<sender
		<<" is: " <<NUM_THREADS<<endl;
	
	pthread_t threads[NUM_THREADS];
	struct thread_data td[NUM_THREADS];
	string filenames[NUM_THREADS];

	ifstream r2 ("/test/1.txt");

	for (i=0;i<NUM_THREADS;++i) {
		getline(r2, filenames[i]);
	}

	r2.close();

	for(i=0; i<NUM_THREADS;++i) {
		td[i].in=sender+"/"+filenames[i];
		td[i].out=recipient+"/"+filenames[i];
		call = pthread_create(&threads[i],NULL,foo,(void *)&td[i]);
		if (call) {
			cout<<"Error unable to create thread" <<call<<endl;
			exit(-1);
		}
	}

	for (i=0;i<NUM_THREADS;++i) {
		call= pthread_join(threads[i],&status);
		if (call) {
			cout<<"Error unable to join"<<call<<endl;
			exit(-1);
		}
	}

	pthread_exit(NULL);
	delete [] &threads;
	delete [] &filenames;
	delete [] &td;

}

