#include <iostream>
using namespace std;
class ATM{
	private:
		string accountHolderName; int accountNumber; float balance;
	public:
		ATM(string a,int num,float bal) : accountHolderName(a), accountNumber(num), balance(bal) {}
		void check_balance(){
			cout<<"Your current balance: "<<balance<<endl;
		}
		void deposit_money(){
			float temp;
			cout<<"Enter the amount you want to deposit:"<<endl;
			cin>>temp;
			balance += temp;
			cout<<"Successfull deposit"<<endl;
		}
		void with_draw_money(){
			float temp,x;
			cout<<"Enter money you want to withdraw:"<<endl;
			cin>>temp;
			if(temp > balance){
				cout<<"Unsufficient funds"<<endl;
				return;
			}
			balance -=temp;
			cout<<"Withdrawal Successfull"<<endl;
		}
};
int main(){
	int choice;
	ATM x("Rayyan",12345,23000);
	cout<<"Welcome to lena dena bank"<<endl;
	do{
		cout<<"Press 1: To deposit money"<<endl;
		cout<<"Press 2: To with draw money"<<endl;
		cout<<"Press 3: To view your current balance"<<endl;
		cout<<"Press 4: To exit the program"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				x.deposit_money();
				break;
			case 2:
				x.with_draw_money();
				break;
			case 3:
				x.check_balance();
				break;
			case 4:
				cout<<"Thank you!, for visiting us"<<endl;
				break;	
			default:
				cout<<"Inavalid choice"<<endl;
		}
	}while(choice != 4);
}
