#include <iostream>
using namespace std;
struct Customer{
	string name;
	float purchase_amount;
	Customer* z;
};
int main(){
	int f=0;
	Customer* x = new Customer[3];
	for(int i=0;i<3;i++){
		cout<<"Enter name:"<<endl;
		cin>>x[i].name;
		cout<<"Enter purchase amount:"<<endl;
		cin>>x[i].purchase_amount;
		if(i==2){
			x[i].z = NULL;
		}
		else{
			x[i].z = &x[i+1];
		}
	}
	Customer* st = &x[0]; 
	while(st != NULL){
		cout<<"Name: "<<st->name<<endl;
		cout<<"Purchase Amount: "<<st->purchase_amount<<endl;
		st = st->z;
	}
	delete[] x;
}
