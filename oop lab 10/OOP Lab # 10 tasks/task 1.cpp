#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ofstream write("greeting");
	string name,message;
	cout<<"Enter your name: ";
	getline(cin,name);
	cout<<"Enter message: ";
	getline(cin,message);
	write<<"Dear "<<name<<"\n"<<message<<"\nBest Regards!";
	write.close();
}
