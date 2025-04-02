#include <iostream>
using namespace std;
struct library{
	string title;
	string author;
	int ISBN;
	string availablity;
};
int main(){
	library* x = new library[3];
	for(int i=0;i<3;i++){
		cout<<"Enter book title:"<<endl;
		cin>>x[i].title;
		cout<<"Enter the name of the author:"<<endl;
		cin>>x[i].author;
		cout<<"Enter ISBN number:"<<endl;
		cin>>x[i].ISBN;
		cout<<"Enter availablity status:"<<endl;
		cin>>x[i].availablity;
	}
	for(int i=0;i<3;i++){
		cout<<"Title: "<<x[i].title<<endl;
		cout<<"Author: "<<x[i].author<<endl;
		cout<<"ISBN: "<<x[i].ISBN<<endl;
		cout<<"Availablity: "<<x[i].availablity<<endl;
	}
	delete[] x;	
}
