#include <iostream>
using namespace std;
class Vehicle{
	protected:
		int vehicleId;
		static int activeDelivery;
		int speed;
		int capacity;
		double EnergyEfficiency;
	public:
		Vehicle(int v,int s,int c,double e):vehicleId(v),speed(s),capacity(c),EnergyEfficiency(e) {
			activeDelivery++;
		}
		virtual void calculateRoute(string dest) =0;
		virtual double deliveryTime() = 0;
		virtual void command(string s,int pId){
			cout<<"Vehicle | Status: "<<s<<" | ID: "<<pId<<endl;
		}
		virtual void command(string s,int pId,string u){
			cout<<"Vehicle | Status: "<<s<<" | ID: "<<pId<<" | Urgency: "<<u<<endl;
		}
		friend bool resolveConflict(Vehicle &v1, Vehicle &v2);
		bool operator==(const Vehicle& x){
			return (capacity == x.capacity) && (speed == x.speed) && (EnergyEfficiency == x.EnergyEfficiency);
		}
};
int Vehicle::activeDelivery = 0;
class RamzanDrone: public Vehicle{
	public:
		RamzanDrone(int v):Vehicle(v,125,10,0.8) {}
		void calculateRoute(string dest) override{
			cout<<"Ramzan Drone | "<<"Route calculated for: "<<dest<<endl;		
		}
		double deliveryTime(){
			return 9.5;
		}
		virtual void command(string s,int pId){
			cout<<"Ramzan Drone | High-speed drone delivery | Status: "<<s<<" | ID: "<<pId<<endl;
		}
		virtual void command(string s,int pId,string u){
			cout<<"Ramzan Drone | Urgent delivery | Status: "<<s<<" | ID: "<<pId<<" | Urgency: "<<u<<" | Arriving in: "<<deliveryTime()<<"min"<<endl;
		}
};
class RamzanTimeShip: public Vehicle{
	public:
		RamzanTimeShip(int v):Vehicle(v,70,50,0.9) {}
		void calculateRoute(string dest) override{
			cout<<"Ramzan Time Ship | "<<"Route calculated for: "<<dest<<endl;		
		}
		double deliveryTime(){
			return 5.0;
		}
		virtual void command(string s,int pId){
			cout<<"Ramzan Time Ship | Time shiping Delivery | Status: "<<s<<" | ID: "<<pId<<endl;
		}
		virtual void command(string s,int pId,string u){
			cout<<"Ramzan Time Ship | Urgent delivery | Status: "<<s<<" | ID: "<<pId<<" | Urgency: "<<u<<" | Arriving in: "<<deliveryTime()<<"min"<<endl;
		}
};
class RamzanHyperPod: public Vehicle{
	public:
		RamzanHyperPod(int v):Vehicle(v,175,100,0.7) {}
		void calculateRoute(string dest) override{
			cout<<"Ramzan Hyper Pod | "<<"Route calculated for: "<<dest<<endl;		
		}
		double deliveryTime(){
			return 14.0;
		}
		virtual void command(string s,int pId){
			cout<<"Ramzan Hyper Pod | Bulk transport delivery | Status: "<<s<<" | ID: "<<pId<<endl;
		}
		virtual void command(string s,int pId,string u){
			cout<<"Ramzan Hyper Pod | Urgent delivery | Status: "<<s<<" | ID: "<<pId<<" | Urgency: "<<u<<" | Arriving in: "<<deliveryTime()<<"min"<<endl;
		}
};
bool resolveConflict(Vehicle &v1, Vehicle &v2){
	if(v1 == v2){
		cout<<"Both are same Vehicle"<<endl;
	}
	else if(v1.EnergyEfficiency > v2.EnergyEfficiency){
		cout<<"Vehicle 1 choosen due to higher Energy Efficiency"<<endl;
	}
	else{
		cout<<"Vehicle 2 choosen due to higher Energy Efficiency"<<endl;
	}
}
int main(){
	RamzanDrone d(101);
	RamzanTimeShip s(102);
	RamzanHyperPod p(103);
	d.command("Arrive at the KHI DC",10002);
	s.command("Arrive at the Aiport Customs",10003,"Monday");
	p.command("Delivered",10004);
	d.calculateRoute("Karachi");
    s.calculateRoute("Karachi");
    p.calculateRoute("Peshawar");
	resolveConflict(d,s);
}
