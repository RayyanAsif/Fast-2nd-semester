#include <iostream>
using namespace std;
class Account{
	public:
		int acc_no;
		string name;
		static float RateOfIntrest;
		Account(int a,string n){
			this->acc_no = a;
			this->name = n;
		}
		void display(){
			cout<<"Account no: "<<acc_no<<" Name: "<<name<<" rate of intrest: "<<RateOfIntrest<<endl;
		}
};
float Account::RateOfIntrest=6.5;
int main(){
	Account a1 = Account(1234,"Rayyan");
	Account a2 = Account(12345,"Asif");
	a1.display();
	a2.display();
}
