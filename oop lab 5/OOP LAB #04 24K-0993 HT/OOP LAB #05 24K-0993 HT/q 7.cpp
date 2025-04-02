#include <iostream>
using namespace std;
class Customer{
	private:
		string name;
		int id;
		static int customer_id;
	public:
		Customer(string n){
			customer_id++;
			name = n;
			id = customer_id;
		}
		void display(){
			cout<<"Customer ID: "<<id<<" | Name: "<<name<<endl;
		}
		static void next_id(){
			cout<<"Next Available Customer ID: "<<customer_id+1<<endl;
		}	
};
int Customer::customer_id=4999;
int main(){
	Customer x("Rayyan");
	Customer y("Asif");
	Customer z("Dossani");
	x.display();
	y.display();
	z.display();
	Customer::next_id();
	
}
