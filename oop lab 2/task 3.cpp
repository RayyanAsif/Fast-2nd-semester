#include <iostream>
using namespace std;
struct Vehicle{
	string owner;
	int registration_num;
	string model;
};
int main(){
	Vehicle x;
	cout<<"Enter owner name:"<<endl;
	cin>>x.owner;
	cout<<"Enter registration number:"<<endl;
	cin>>x.registration_num;
	cout<<"Enter car model:"<<endl;
	cin>>x.model;
	cout<<"Owner: "<<x.owner<<endl;
	cout<<"Model: "<<x.model<<endl;
	cout<<"Registration Number: "<<x.registration_num<<endl;
}

