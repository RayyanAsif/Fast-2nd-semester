#include <fstream>
#include<iostream>
#include <ctime>
using namespace std;
int main(){
	ofstream file("system_log",ios::app);
	if(!file){
		cout<<"Error opening file"<<endl;
		return 1;
	}
	time_t current = time(0);
	char* x = ctime(&current);
	file<<"System started at: "<<x;
	file.close();
}
