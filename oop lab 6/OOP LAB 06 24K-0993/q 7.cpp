#include <iostream>
using namespace std;
class Device{
	protected:
		string deviceName;
		string powerStatus;
	public:
		Device(string d):deviceName(d),powerStatus("Off") {}	
};
class SmartLight:virtual public Device{
	public:
		SmartLight():Device("Smart Light") {}
		void turnOn(){
			powerStatus = "On";
			cout<<"Smart Light is ON with adjustable brightness."<<endl;
		}
		void turnOff(){
			powerStatus = "Off";
			cout<<"Smart Light is now OFF."<<endl;
		}
};
class SmartFan:virtual public Device{
	public:
		SmartFan():Device("Smart Fan") {}
		void turnOn(){
			powerStatus = "On";
			cout<<"Smart Fan is ON at medium speed."<<endl;
		}
		void turnOff(){
			powerStatus = "Off";
			cout<<"Smart Fan is now OFF."<<endl;
		}
};
class SmartRoom:public SmartFan,public SmartLight{
	public:
		SmartRoom():Device("Smart Room"),SmartLight(),SmartFan() {}
		void Activate(){
			SmartFan::turnOn();
			SmartLight::turnOn();
			cout<<"Smart Room is now fully activated!"<<endl;
		}
		void Deactivate(){
			SmartFan::turnOff();
			SmartLight::turnOff();
			cout<<"Smart Room is now fully deactivated!"<<endl;
		}
};
int main(){
	SmartRoom r;
	r.Activate();
	r.Deactivate();
	return 0;
}

