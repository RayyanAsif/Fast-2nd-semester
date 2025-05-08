#include <fstream>
#include <iostream>
#include <fstream>
#include<iostream>
using namespace std;
int main(){
	ifstream file("story");
	if(!file.is_open()){
		cout<<"Error opening file"<<endl;
		return 1;
	}
	string word;
	while(file>>word){
		cout<<word<<endl;
	}
	file.close();
}
