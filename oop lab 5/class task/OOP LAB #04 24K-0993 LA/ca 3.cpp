#include <iostream>
using namespace std;

class Employee{
private:
    string name;
    const int id;

public:
    Employee(string empName, int empId) : name(empName), id(empId){}

    void displayDetails() const {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
    }

    void updateName(string newName){
        name = newName;
        cout << "Name updated to: " << name << endl;
    }
};

int main(){
    Employee emp("Rayyan Asif", 1200);

    cout << "Initial Employee Details:" << endl;
    emp.displayDetails();

    emp.updateName("RAD");

    cout << "Updated Employee Details:" << endl;
    emp.displayDetails();

    return 0;
}
