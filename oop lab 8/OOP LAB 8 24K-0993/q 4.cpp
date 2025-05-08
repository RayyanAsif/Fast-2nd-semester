#include <iostream>
using namespace std;

class HR;
class Manager;

class Employee {
    string name;
    double salary;
public:
    Employee(string n, double s) : name(n), salary(s) {}
    friend class HR;
};

class HR {
public:
    void updateSalary(Employee& e, double amount) {
        e.salary = amount;
    }

    string getName(Employee& e) const { return e.name; }
    double getSal(Employee& e) const { return e.salary; }
    
    friend class Manager;
};

class Manager {
public:
    void viewSalary(HR& h, Employee& e) {
        cout << "Employee: " << h.getName(e) << " | Salary: " << h.getSal(e) << endl;
    }
};

int main() {
    Employee e("Rayyan", 30000);
    HR h;
    Manager m;
    
    m.viewSalary(h, e);
    
    h.updateSalary(e, 190000);
    
    cout << "After updating:" << endl;
    m.viewSalary(h, e);
    
    return 0;
}

