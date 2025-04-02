#include <iostream>
#include "library.h"
using namespace std;
void book::displayBookDetail(){
			cout<<"Title: "<< title <<endl;
			cout<<"Author: "<< author <<endl;
			cout<<"ISBN: "<< ISBN <<endl;
			cout<<"Available: "<< isAvailable <<endl;
		}
void book::updateAvailability(){
			isAvailable = !isAvailable;
		}
int main(){
	book library[max_b];
	int count=0;
	int choice;
	do{
		int temp;
		cout<<"Press 1, to add a new book"<<endl;
		cout<<"Press 2, to display books details"<<endl;
		cout<<"Press 3, to search a book"<<endl;
		cout<<"Press 4, to update book availablity"<<endl;
		cout<<"Press 5, to end the program"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				library[count].addBook(library,count);
				break;
			case 2:
				if(count == 0){
					cout<<"No book available"<<endl;
				}	
				else{
					for(int i=0;i<count;i++){
						library[i].displayBookDetail();
						cout<<""<<endl;
					}
				}
				break;
			case 3:
				cout<<"Enter the ISBN of the book to search"<<endl;
				cin>>temp;
				library[0].searchBook(library,count,temp);
				break;
			case 4:
				cout<<"Enter ISBN to update availability:";
                cin>>temp;
                for(int i = 0; i < count; i++){
                    if(library[i].ISBN == temp){
                        library[i].updateAvailability();
                    }
                }
                break;
			case 5:
				cout<<"Thank You!"<<endl;
				break;
			default:
				cout<<"Invalid choice"<<endl;				
		}
	}while(choice !=5);
	return 0;
}
