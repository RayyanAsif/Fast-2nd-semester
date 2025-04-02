#include <iostream>
using namespace std;
struct speaker{
	string name;
	string topic;
	int time_slot;
};
int main(){
	speaker* x = new speaker[4];
	for(int i=0;i<4;i++){
		cout<<"Enter speaker name:"<<endl;
		cin>>x[i].name;
		cout<<"Enter the topic of the speaker"<<endl;
		cin>>x[i].topic;
		cout<<"Enter time slot of the speaker"<<endl;
		cin>>x[i].time_slot;
	}
	for(int i=0;i<4;i++){
		cout<<"Speaker: "<<x[i].name<<endl;
		cout<<"Time Slot: "<<x[i].time_slot<<endl;
		cout<<"Topic: "<<x[i].topic<<endl;
	}
	delete[] x;	
}
