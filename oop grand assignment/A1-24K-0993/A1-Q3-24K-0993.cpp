#include <iostream>
using namespace std;
class Vehicle{
	private:
		string model;
		int rentalPrice;
		string type;
	public:
		Vehicle(string m,int r,string t) : model(m),rentalPrice(r),type(t) {}
		void displayInfo(){
			cout<<"Model: "<<model<<" | Rental Price per day: "<<rentalPrice<<" | Type: "<<type<<endl;
		}
		string getType(){
			return type;
		}
};
class User{
	private:
		string name;
		int age;
		string licenseType;
		string contactInfo;
		int id;
		Vehicle* x;
	public:
		User(string n, int a, string l, string c, int i) : name(n), age(a), licenseType(l), contactInfo(c), id(i), x(NULL) {}
		void update(){ 
			cout<<"Enter the updated name:"<<endl;
			cin>>name;
			cout<<"Enter the updated age:"<<endl;
			cin>>age;
			cout<<"Enter the updated license type:"<<endl;
			cin>>licenseType;
			cout<<"Enter the updated contact info:"<<endl;
			cin>>contactInfo;
			cout<<"Enter the updated id:"<<endl;
			cin>>id;
		}	
		void isEligiable(Vehicle* z){
			if(z->getType()==licenseType){
				x = z;
			}
			else{
				cout<<"You can't rent this car"<<endl;
			}
		}
		void show_details(){
			cout<<"Name: "<<name<<" | Age: "<<age<<" | License Type: "<<licenseType<<" | Contact info: "<<contactInfo<<" | ID: "<<id<<endl;
			if(x){
				x->displayInfo();
			}
			else{
				cout<<"No Vehicle Registered"<<endl;
			}
		}
};
int main(){
	Vehicle* a[3];
	a[0] = new Vehicle("Ferrari LaFerrari", 30000, "intermediate");
    a[1] = new Vehicle("Koenisegg Agera", 50000, "full");
    a[2] = new Vehicle("Lamborghini Gallardo", 30000, "intermediate");
    cout<<"Car Rental System"<<endl;
    a[0]->displayInfo();
    a[1]->displayInfo();
    a[1]->displayInfo();
	User u1("Rayyan", 25, "Full", "rayyanasif811@gmail.com", 1);
	while(1){
		int c;
		cout<<"1.Update your details:"<<endl;
		cout<<"2.Rent a Vehicle:"<<endl;
		cout<<"3.Display your detail:"<<endl;
		cout<<"4.To end the program:"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>c;
		switch(c){
			case 1:
				u1.update();
				break;
			case 2:
				int c;
				cout<<"Enter the coice of the vehicle you want to rent"<<endl;
				cin>>c;
				u1.isEligiable(a[c-1]);
				break;
			case 3:
				u1.show_details();
			case 4:
				return 0;
			default:
				cout<<"Invalid choice"<<endl;				
		}
	}
}

