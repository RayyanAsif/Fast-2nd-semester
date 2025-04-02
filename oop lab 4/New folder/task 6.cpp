#include <iostream>
using namespace std;
class SmartEnergyDevice{
	private:
		string deviceName;
		string deviceType;
		double powerRating;
		double hoursUsed;
	public:
		SmartEnergyDevice(string n,string t,double pr,double hu) : deviceName(n),deviceType(t),powerRating(pr),hoursUsed(hu){
			cout<<deviceName<<" is now active!"<<endl;
		}	
		~SmartEnergyDevice(){
			cout<<deviceName<<" is removed!"<<endl;
		}
		void useDevice(double h){
			hoursUsed += h;
		}
		double calculateEnergyConsumption(){
			double temp = (powerRating*hoursUsed)/1000;
			return temp;
		}
		void displayEnergyUsage(){
			cout<<"Device: "<<deviceName<<endl;
			cout<<"Type: "<<deviceType<<endl;
			cout<<"Power Rating in W: "<<powerRating<<endl;
			cout<<"Time Used in hours: "<<hoursUsed<<endl;
			cout<<"Total Energy Consumption in kWH: "<<calculateEnergyConsumption()<<endl;
		}
};
int main(){
	SmartEnergyDevice x("Smart_Heater","Heater",2000,5);
	SmartEnergyDevice y("Smart_AC","Air_conditioner",1500,8);
	x.displayEnergyUsage();
	y.displayEnergyUsage();
}

