#include <iostream>
using namespace std;

class Doctor;

class Patient {
    string name;
    int age;
    string medHis;
public:
    Patient(string n, int a, string m) : name(n), age(a), medHis(m) {}
    friend class Doctor;
};

class Doctor {
public:
    void display(Patient& p) {
        cout << "Patient name: " << p.name << endl;
        cout << "Patient age: " << p.age << endl;
        cout << "Patients medical history: " << p.medHis << endl;
    }

    void update(Patient& p, string history) {
        p.medHis = history;
        cout << "Updated medical history: " << p.medHis << endl;
    }
};

int main() {
    Patient p("RAYYAN ASIF", 18, "FEVER");
    Doctor d;
    d.display(p);
    d.update(p, "COUGH");
    return 0;
}

