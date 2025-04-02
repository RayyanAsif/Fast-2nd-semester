#include <iostream>
using namespace std;
class Employee{
	protected:
		string name;
		int id;
		double salary;
	public:
		Employee(string n,int id,double s):name(n),id(id),salary(s) {}
		void display_employee(){
			cout<<"=== Employee Details ==="<<"\nEmployee Name: "<<name<<"\nEmployee Id: "<<id
			<<"\nBase Salary: $"<<salary<<endl;
		}	
};
class Manager:public Employee{
	protected:
		double bonus;
	public:
		Manager(string n,int id,double s,double b):Employee(n,id,s),bonus(b) {}
		void display_Manager(){
			cout<<"\n=== Manager Details ==="<<"\nEmployee Name: "<<name<<"\nEmployee Id: "<<id
			<<"\nBase Salary: $"<<salary<<"\nBonus: $"<<bonus<<"\nTotal Salary: $"<<bonus+salary<<endl;
		}
};
int main(){
	Employee e("Alice Johnson",101,50000);
	Manager m("Bob Smith",102,75000,10000);
	e.display_employee();
	m.display_Manager();
	return 0;
}
