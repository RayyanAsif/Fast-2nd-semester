#include <iostream>
using namespace std;
class BusStop{
private:
    string Driver;
    string stopName;
public:
    BusStop(string d, string s) : Driver(d), stopName(s) {}
    string get_Driver(){ 
		return Driver; 
		}
    string get_stopName(){ 
		return stopName; 
		}
};
class Student{
private:
    string name;
    int id;
    BusStop* stop;
    bool FeePaid;
    bool cardActive;
public:
    Student(string n, int i) : name(n), id(i), FeePaid(false), stop(NULL), cardActive(false) {}
    void payFee(){ 
		FeePaid = true; 
		}
    void Activate(){
        if (FeePaid){
            cardActive = true;
        }
    }
    void TapCard(){
        if (cardActive && FeePaid){
            cout<<name<<" attendance marked"<<endl;
        }else{
            cout<<name<<" cannot mark attendance"<<endl;
        }
    }
    void assign(BusStop* x){ 
		stop = x; 
		}
    string get_name(){ 
		return name; 
		}
    int get_id(){
		return id; 
		}
};

class TransportSystem{
private:
    Student* x[50];
    BusStop* y[6];
    int scount=0,bcount=0;
public:
    void RegisterStudent(Student* z) {
        if(scount < 50){
            x[scount++]=z;
            cout<<z->get_name()<<" Registered Successfully"<<endl;
        }else{
            cout<<"Seats full, can't register"<<endl;
        }
    }
    void addStop(string stop, string driver){
        if(bcount < 6){
            y[bcount++] = new BusStop(driver,stop);
        }else{
            cout<< "Stop limit reached!"<<endl;
        }
    }
    void ProcessPayments(int id,int stop){
        if(stop>=bcount||stop<0){
            cout<<"Invalid Stop"<<endl;
            return;
        }
        for(int i=0;i<scount;i++){
            if (x[i]->get_id()==id){
                x[i]->assign(y[stop]);
                cout<<"Bus stop assigned to "<<x[i]->get_name()<<endl;
                return;
            }
        }
        cout<<"Student not found"<<endl;
    }

    void attendence(int id){
        for (int i=0;i<scount;i++) {
            if (x[i]->get_id()==id) {
                x[i]->TapCard();
                return;
            }
        }
        cout << "Student not found" << endl;
    }

    ~TransportSystem(){
        for (int i=0;i<bcount;i++) {
            delete y[i];
        }
    }
};
int main(){
    TransportSystem NadeemTransport;
    NadeemTransport.addStop("Nazimabad no 2","Driver A");
    NadeemTransport.addStop("Board Office","Driver B");
    NadeemTransport.addStop("KDA chowrangi","Driver C");
    NadeemTransport.addStop("Five Star","Driver D");
    NadeemTransport.addStop("Nagan Chowrangi","Driver E");
    Student x("Rayyan",240993);
    NadeemTransport.RegisterStudent(&x);
    x.payFee();
    x.Activate();
    NadeemTransport.ProcessPayments(240993, 3);
    NadeemTransport.attendence(240993);
}

