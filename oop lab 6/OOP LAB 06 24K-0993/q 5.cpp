#include <iostream>
using namespace std;
class Person{
	protected:
		string name;
		string contact;
	public:
		Person(string n,string c):name(n),contact(c) {}	
};
class BankEmployee:public Person{
	protected:
		int id;
		string position;
	public:
		BankEmployee(string n,string c,int i,string p):Person(n,c),id(i),position(p) {}
};
class Customer:public BankEmployee{
	protected:
		double acc_no;
		double balance;
	public:
		Customer(string n,string c,int i,string p,double a,double b):BankEmployee(n,c,i,p)
		,acc_no(a),balance(b) {}	
};
class BankManager:Customer{
	public:
		BankManager(string n,string c,int i,string p,double a,double b):Customer(n,c,i,p,a,b) {}
		void display(){
			cout<<"===Bank Manager Detail==="<<"\nName: "<<name<<"\nContact: "<<
			contact<<"\nEmployee ID: "<<id<<"\nPosition: "<<position
			<<"\nAccount Number (for internal transactions): "<<acc_no<<"\nBalance: $"<<balance<<endl; 
		}
		void deposit(double amount){
			balance += amount;
			cout<<"Deposited $"<<amount<<" New Balance: "<<balance<<endl;
		}
		void withDrawal(double amount){
			if(amount>balance){
				cout<<"=== Insufficient Balance ==="<<endl;
				return;
			}
			balance -= amount;
			cout<<"Withdrawn $"<<amount<<" New Balance: "<<balance<<endl;
		}
		
};
int main(){
	BankManager b("Alice Johnson", "alice@email.com", 1001, "Branch Manager", 50001, 10000);
	b.display();
	cout<<"=== Transaction ==="<<endl;
	b.deposit(5000);
	b.withDrawal(3000);
	b.withDrawal(15000);
	
}
