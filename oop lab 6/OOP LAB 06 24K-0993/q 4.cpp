#include <iostream>
using namespace std;
class Person{
	protected:
		string name;
		int age;
	public:
		Person(string n,int a):name(n),age(a) {}
};
class Doctor:public Person{
	protected:
		string specialization;
	public:
		Doctor(string n,int a,string s):Person(n,a),specialization(s) {}
};
class Surgeon:public Doctor{
	protected:
		int count;
	public:
		Surgeon(string n,int a,string s,int c):Doctor(n,a,s),count(c) {}
		void display_Surgeon(){
			cout<<"=== Surgeon Details ==="<<"\nName: "<<name<<"\nAge: "<<age<<"\nSpecialization: "<<
			specialization<<"\nSurgeries Performed: "<<count<<"\n"<<endl;
		}	
};
int main(){
	Surgeon s("Dr. John Smith",45,"Cardiac Surgery",250);
	s.display_Surgeon();
}
