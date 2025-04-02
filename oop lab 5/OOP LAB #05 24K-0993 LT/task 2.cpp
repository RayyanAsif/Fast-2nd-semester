#include <iostream>
using namespace std;
class Employee_Salary{
	private:
		string name;
		int salary;
	public:
		Employee_Salary(string n,int s) : name(n),salary(s) {}
		void display(){
			cout<<"Employee: "<<name<<" | Salary: $"<<salary<<endl;
		}	
};
int main(){
	Employee_Salary emp[] = {
	Employee_Salary("Rayyan",65000),Employee_Salary("Adden",50000),Employee_Salary("Sara",25000)};
	cout<<"Employee Salary Record:"<<endl;
	for(int i=0;i<3;i++){
		emp[i].display();
	}
}
