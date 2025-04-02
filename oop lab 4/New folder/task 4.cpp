#include <iostream>
using namespace std;
class Car{
	private:
		string name;
		double capacity;
		double consumption_rate;
		double driven;
	public:
		Car(string n,double c,double c_r,double d) : name(n),capacity(c),consumption_rate(c_r),driven(d){
			cout<<"Car Added"<<endl;
		}
		~Car(){
			cout<<"Car tracking removed"<<endl;
		}
		void drive(double dist){
			driven += dist;
			int temp = dist/100 * consumption_rate;
			if(temp>capacity){
				cout<<"Not enough fuel available"<<endl;
			}
			else{
				capacity -= temp;
			}
		}
		void refuel(double fuel){
			capacity += fuel;
			cout<<"Fuel Added"<<endl;
		}
		void displayCarStatus(){
			cout<<"Name: "<<name<<endl;
			cout<<"Remaining fuel: "<<capacity<<endl;
			cout<<"Fuel Consumption per 100 km in litres: "<<consumption_rate<<endl;
			cout<<"Distance driven in km: "<<driven<<endl;
		}
};
int main(){
	Car x("Suzuki_WagonR",35,5,0);
	x.refuel(10);
	x.drive(200);
	x.displayCarStatus();
}
