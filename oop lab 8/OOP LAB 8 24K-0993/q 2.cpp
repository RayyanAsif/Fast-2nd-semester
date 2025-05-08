#include <iostream>
using namespace std;
class BankAccount{
	private:
		int accountNumber;
		double balance;
	public:
		BankAccount(int a,double b):accountNumber(a),balance(b) {}
		friend class Transaction;	
};
class Transaction{
	public:
		static void processTransaction(BankAccount& b){
			int choice;
			double temp;
			cout<<"1. Deposit\n2.Withdrawal"<<endl;
			cin>>choice;
			switch(choice){
				case 1:
					cout<<"Enter amount to deposit"<<endl;
					cin>>temp;
					b.balance += temp;
					break;
				case 2:
					cout<<"Enter amount to deposit"<<endl;
					cin>>temp;
					if(temp>b.balance){
						cout<<"Not sufficient funds"<<endl;
						break;
					}	
					else{
						b.balance -= temp;
						break;
					}
				default:
					cout<<"Invalid choice"<<endl;	
			}
		}
};
int main(){
	BankAccount a(1002,200000);
	Transaction::processTransaction(a);
	Transaction::processTransaction(a);
	return 0;
}
