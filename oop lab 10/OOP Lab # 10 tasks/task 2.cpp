#include <fstream>
#include<iostream>
using namespace std;
int main(){
	ofstream file("diary",ios::app);
	if(!file){
		cout<<"Error opening file"<<endl;
		return 1;
	}
	string line;
	while(1){
		getline(cin,line);
		if(line == "exit"){
            return 0;
        }
		file<<line;
	}
	file.close();
}


