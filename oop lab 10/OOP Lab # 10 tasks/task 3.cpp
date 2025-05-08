#include <fstream>
#include<iostream>
using namespace std;
int main(){
	ofstream file("signup",ios::app);
	if(!file){
		cout<<"Error opening file"<<endl;
		return 1;
	}
	string name,email;
	cout<<"Enter your name: "<<endl;
	getline(cin,name);
	cout<<"Enter your email: "<<endl;
	getline(cin,email);
	file<<"Name: "<<name<<"\tEmail: "<<email<<endl;
	file.close();
}
