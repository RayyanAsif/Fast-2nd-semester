#include <iostream>
using namespace std;
class Runner{
	string name;
	float speed;
	static const float max_speed;
	public:
		Runner(string n,float s) : name(n),speed(s) {}
		void display(){
			cout<<"Runner: "<<name<<" | Speed: "<<speed<<" km\h "<<endl;
			if(speed>max_speed){
				cout<<"(Disquilified: Exceeded Speed Limit)"<<endl;
			}
		}
		static void max(){
			cout<<"Max Speed Limit for Marathon: "<<max_speed<<endl;
		}
};
const float Runner::max_speed=25;
int main(){
	Runner x("Rayyan Asif",25);
	Runner y("Usain Bolt",21);
	Runner z("Doreamon",26);
	Runner::max();
	x.display();
	y.display();
	z.display();
}

