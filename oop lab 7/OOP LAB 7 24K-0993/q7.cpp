#include<iostream>
using namespace std;
class Ticket{
	public:
		virtual void calculateFare(){
			cout<<"class batao pehla"<<endl;
		}
};
class EconomyTicket:public Ticket{
	public:
		void calculateFare()override{
			cout<<"Economy Ticket Fare: $300"<<endl;
		}
};
class BuisnessTicket:public Ticket{
	public:
		void calculateFare()override{
			cout<<"Business Ticket Fare: $1200"<<endl;
		}
};
int main(){
	Ticket *t1;
	Ticket *t2;
	EconomyTicket e1;
	BuisnessTicket b1;
	t1=&e1;
	t2=&b1;
	t1->calculateFare();
	t2->calculateFare();
}
