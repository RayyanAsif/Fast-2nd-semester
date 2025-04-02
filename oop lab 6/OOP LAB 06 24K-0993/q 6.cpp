#include <iostream>
using namespace std;
class Transport{
	protected:
		string vehicleType;
		int capacity;
	public:
		Transport(string v,int c):vehicleType(v),capacity(c) {}	
};
class RoadTransport:virtual public Transport{
	protected:
		string RoadType;
	public:
		RoadTransport(string v,int c,string t):Transport(v,c),RoadType(t) {}	
};
class AirTransport:virtual public Transport{
	protected:
		double altitude;
	public:
		AirTransport(string v,int c,double t):Transport(v,c),altitude(t) {}	
};
class HybridVehicle:public AirTransport,public RoadTransport{
	protected:
		float efficiency;
	public:
		HybridVehicle(string v,int c,double t,string g,float e):Transport(v,c),AirTransport(v,c,t)
		,RoadTransport(v,c,g),efficiency(e) {}
		void display(){
			cout<<"=== Hybrid Vehicle Details ==="<<"\nVehicle Type: "<<vehicleType<<"\nMax Capacity: "
			<<capacity<<" passengers"<<"\nRoad Type: "<<RoadType<<"\nMax Altitude: "
			<<altitude<<"\nFuel Efficiency: "<<efficiency<<" km/l"<<endl;
		}	
};
int main(){
	HybridVehicle x("Hybrid", 5, 10000, "SUV", 15.5);
	x.display();
	return 0;
}
