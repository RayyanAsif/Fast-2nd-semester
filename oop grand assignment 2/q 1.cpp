#include <iostream>
using namespace std;
class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {}
    virtual void printInfo() {
        cout << "Name: " << name << endl;
    }
    string get_name() { return name; }
};
class Driver : public Person {
public:
    Driver(string n) : Person(n) {}
    void printInfo() override {
        cout << "Driver Name: " << name << endl;
    }
};
class BusStop {
private:
    Driver* driver;
    string stopName;
public:
    BusStop(string d, string s) : stopName(s) {
        driver = new Driver(d);
    }
    string get_stopName() { return stopName; }
    string get_Driver() { return driver->get_name(); }
    ~BusStop() { delete driver; }
};
class Student : public Person {
private:
    int id;
    BusStop* stop;
    bool FeePaid;
    bool cardActive;
public:
    Student(string n, int i) : Person(n), id(i), FeePaid(false), stop(NULL), cardActive(false) {}
    void payFee() { FeePaid = true; }
    void Activate() {
        if (FeePaid) cardActive = true;
    }
    void TapCard() {
        if (cardActive && FeePaid)
            cout << name << " attendance marked" << endl;
        else
            cout << name << " cannot mark attendance" << endl;
    }
    void assign(BusStop* x) { stop = x; }
    int get_id() { return id; }
    void printInfo() override {
        cout << "Student Name: " << name << ", ID: " << id << endl;
    }
    bool operator==(const Student& other) {
        return (this->id == other.id);
    }
};
class TransportSystem {
private:
    Student* x[50];
    BusStop* y[6];
    int scount = 0, bcount = 0;
public:
    void RegisterStudent(Student* z) {
        if (scount < 50) {
            x[scount++] = z;
            cout << z->get_name() << " Registered Successfully" << endl;
        } else {
            cout << "Seats full, can't register" << endl;
        }
    }
    void addStop(string stop, string driver) {
        if (bcount < 6) {
            y[bcount++] = new BusStop(driver, stop);
        } else {
            cout << "Stop limit reached!" << endl;
        }
    }
    void ProcessPayments(int id, int stop) {
        if (stop >= bcount || stop < 0) {
            cout << "Invalid Stop" << endl;
            return;
        }
        for (int i = 0; i < scount; i++) {
            if (x[i]->get_id() == id) {
                x[i]->assign(y[stop]);
                cout << "Bus stop assigned to " << x[i]->get_name() << endl;
                return;
            }
        }
        cout << "Student not found" << endl;
    }
    void ProcessPayments(Student* s, int stop) {
        ProcessPayments(s->get_id(), stop);
    }
    void attendence(int id) {
        for (int i = 0; i < scount; i++) {
            if (x[i]->get_id() == id) {
                x[i]->TapCard();
                return;
            }
        }
        cout << "Student not found" << endl;
    }
    ~TransportSystem() {
        for (int i = 0; i < bcount; i++) {
            delete y[i];
        }
    }
};
int main() {
    TransportSystem NadeemTransport;
    NadeemTransport.addStop("Nazimabad no 2", "Driver A");
    NadeemTransport.addStop("Board Office", "Driver B");
    NadeemTransport.addStop("KDA chowrangi", "Driver C");
    NadeemTransport.addStop("Five Star", "Driver D");
    NadeemTransport.addStop("Nagan Chowrangi", "Driver E");
    Student x("Rayyan", 240993);
    NadeemTransport.RegisterStudent(&x);
    x.payFee();
    x.Activate();
    NadeemTransport.ProcessPayments(&x, 3);
    NadeemTransport.attendence(240993);
    Student y("Rayyan", 240993);
    if (x == y){
        cout<<"Same student detected"<<endl;
	}
    Person* p = &x;
    p->printInfo();
}
