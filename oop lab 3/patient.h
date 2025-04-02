#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <iostream>
const int max_b = 100;
using namespace std;
class patient{
	public:
		string name;
		int age;
		string disease;
		int room_no;
		patient(): name(""),age(0),disease(""),room_no(-1) {}
		patient(string n,int a,string d,int r): name(n),age(a),disease(d),room_no(r) {}	
		void add_patient(patient arr[],int& count){
			if(count >= max_b){
				cout<<"No room available for the patient"<<endl;
				return;
			}
			patient temp;
			cout<<"Enter the name of the patient"<<endl;
			cin>>temp.name;
			cout<<"Enter the age of the patient"<<endl;
			cin>>temp.age;
			cout<<"Enter the disease of the patient"<<endl;
			cin>>temp.disease;
			cout<<"Enter room no of the patient"<<endl;
			cin>>temp.room_no;
			arr[count] = temp;
			cout<<"Patient added successfully"<<endl;
			count++;
		}
		void update_details(){
			cout<<"Enter the name of the patient"<<endl;
			cin>>name;
			cout<<"Enter the age of the patient"<<endl;
			cin>>age;
			cout<<"Enter the disease of the patient"<<endl;
			cin>>disease;
			cout<<"Enter room no of the patient"<<endl;
			cin>>room_no;
			cout<<"Record updated successfully"<<endl;
		}
		void display_details();
};
#endif
