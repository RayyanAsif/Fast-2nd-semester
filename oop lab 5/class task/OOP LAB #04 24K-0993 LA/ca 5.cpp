#include <iostream>
using namespace std;
class employee{
public:
	string name;
	int id;
	employee(string empName, int empId) : name(empName), id(empId) {}
	void display() const {
		cout << "Emloyee id: " << id << ",Name: " << name << endl;
	}
};
class department{
	string deptName;
	employee* employees[10];
	int employeeCount = 0;
public:
	department(string name) : deptName(name){}

	void addEmployee(employee* emp){
		employees[employeeCount++] = emp;
	}

	void displayDepartment()const{
		cout << "Department:" << deptName << endl << "Employees:" << endl;
		for (int i = 0; i < employeeCount; i++) employees[i]->display();
	}
};
int main(){
	employee e1("Saim Ayub", 18), e2("Asad Shafique", 12), e3("Fakhar Zaman", 43);
	department dept("Computer Science");
	dept.addEmployee(&e1);
	dept.addEmployee(&e2);
	dept.displayDepartment();
	cout << endl << "Independent employee: " << endl;
	e3.display();
}
