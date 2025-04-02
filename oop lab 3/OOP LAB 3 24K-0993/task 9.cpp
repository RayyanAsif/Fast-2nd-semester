#include "patient.h"
#include <iostream>
using namespace std;
void patient::display_details(){
			cout<<"Name: "<<name<<endl;
			cout<<"Age: "<<age<<endl;
			cout<<"Disease: "<<disease<<endl;
			cout<<"Room number: "<<room_no<<endl;
		}
int main(){
	patient arr[max_b];
	int count=0;
	int choice;
	do{
		cout<<"Press 1, to add a new patient"<<endl;
		cout<<"Press 2, to display patients details"<<endl;
		cout<<"Press 3, to update patient details"<<endl;
		cout<<"Press 4, to end the program"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				arr[count].add_patient(arr,count);
				count++;
				break;
			case 2:
				if(count==0){
					cout<<"No patient to display"<<endl;
					break;
				}
				for(int i=0;i<count;i++){
					arr[i].display_details();
				}	
				break;
			case 3:
				{
				string temp;
				cout<<"Enter name of the patient to update:";
                cin>>temp;
                for(int i=0;i<count; i++){
                    if(arr[i].name == temp){
                        arr[i].update_details();
                        break;
                    }
                }
          	}
          	break;
			case 4:
				cout<<"Thank you!"<<endl;
				break;
			default:
				cout<<"Invalid choice"<<endl;			
		}
	}while(choice != 4);
}
