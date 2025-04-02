#include <iostream>
using namespace std;
class Patient{
	private:
		string name;
		int age;
		string medical_condition;
	public:
		Patient(string n,int a,string m) : name(n),age(a),medical_condition(m) {}
		void display(){
			cout<<"Name: "<<name<<",Age: "<<age<<",Medical Condition: "<<medical_condition<<endl;
		}	
};
class Hospital{
	private:
		Patient* x[10];
		int count;
	public:
		Hospital() : count(0) {}
		void add_patient(Patient* y){
			x[count] = y;
			count++;
		}
		void display_patient(){
			cout<<"Hospital Patient Record"<<endl;
			for(int i=0;i<count;i++){
				x[i]->display();
			}
		}
};
int main(){
	Hospital x;
	Patient a1("Alice",30,"Flu");
	Patient a2("Bob",45,"Diabetes");
	Patient a3("Charlie",50,"High Blood Pressure");
	x.add_patient(&a1);
	x.add_patient(&a2);
	x.add_patient(&a3);
	x.display_patient();
}
