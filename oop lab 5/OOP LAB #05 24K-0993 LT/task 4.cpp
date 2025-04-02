#include <iostream>
using namespace std;
class warehouse{
	private:
		string location;
		int stock;
	public:
		warehouse(string l,int s) : location(l),stock(s) {}		
		void display(){
			cout<<"Warehouse at "<<location<<" | Capacity: "<<stock<<endl;
		}
};
class delivery_service{
	private:
		string service_id;
		warehouse* starting;
		warehouse* destination;
	public:
		delivery_service(string s,warehouse* y,warehouse* t) : service_id(s),starting(y),destination(t) {}
		void update_destination(warehouse* x){
			destination = x;
		}
		void status(){
			cout<<"Delivery Service: "<<service_id<<endl;
			cout<<"Starting: ";
			starting->display();
			cout<<"Current Destination: ";
			destination->display();
		}	
};
int main(){
	warehouse x("Karachi",1500),y("Islamabad",3000),z("Rawalpindi",500);
	delivery_service a("DS-1001",&x,&y);
	cout<<"Initial Status: "<<endl;
	a.status();
	a.update_destination(&z);
	cout<<"After Updating Status:"<<endl;
	a.status();
}
