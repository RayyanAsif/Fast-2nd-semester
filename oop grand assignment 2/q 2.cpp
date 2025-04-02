#include <iostream>
using namespace std;
class Ghost{
	public:
		int scarelevel;
		string workerName;
		Ghost(string n):workerName(n){
			scarelevel = (workerName.length() % 10) + 1;
		}
		int get_level(){
			return scarelevel;
		}
		virtual void haunt() = 0;
		virtual Ghost* operator+(const Ghost& x) = 0;
		friend ostream& operator<<(ostream& o,const Ghost& x){
			o<<x.workerName<<" | Scare Level : "<<x.scarelevel<<endl;
			return o;
		}	
};
class Poltergeists:virtual public Ghost{
	public:
		Poltergeists(string n):Ghost(n) {}
		void haunt() override {
			cout<< workerName <<" | move object!"<<endl;
		}
		Ghost* operator+(const Ghost& x) override {
			Poltergeists* y= new Poltergeists(workerName + " & " + x.workerName);
			y->scarelevel = x.scarelevel + scarelevel;
			return y;
		}
};
class Banshees:virtual public Ghost{
	public:
		Banshees(string n):Ghost(n) {}
		void haunt() override {
			cout<< workerName <<" | scream Loudly!"<<endl;
		}
		Ghost* operator+(const Ghost& x) override {
			Banshees* y= new Banshees(workerName + " & " + x.workerName);
			y->scarelevel = x.scarelevel + scarelevel;
			return y;
		}
};
class ShadowGhosts:virtual public Ghost{
	public:
		ShadowGhosts(string n):Ghost(n) {}
		void haunt() override {
			cout<< workerName <<" | whisper creepily!"<<endl;
		}
		Ghost* operator+(const Ghost& x) override {
			ShadowGhosts* y= new ShadowGhosts(workerName + " & " + x.workerName);
			y->scarelevel = x.scarelevel + scarelevel;
			return y;
		}
};
class ShadowPoltergeist : public ShadowGhosts, public Poltergeists{
	public:
		ShadowPoltergeist(string n):ShadowGhosts(n),Poltergeists(n),Ghost(n) {}
		void haunt() override{
			ShadowGhosts::haunt();
			Poltergeists::haunt();		
		}
		Ghost* operator+(const Ghost& x) override {
			ShadowPoltergeist* y= new ShadowPoltergeist(workerName + " & " + x.workerName);
			y->scarelevel = x.scarelevel + scarelevel;
			return y;
		}
};
class HauntedHouse{
	protected:
		string name;
		Ghost* arr[5];
		int gcount;
	public:
		HauntedHouse(string n):name(n),gcount(0) {}
		void addGhost(Ghost* g){
			if(gcount < 5){
				arr[gcount++] = g; 
			}
		}
		void show(){
			for(int i=0;i<gcount;i++){
				cout<<*arr[i]<<endl;
			}
		}
		friend void visit(HauntedHouse& h,string n,int b);	
};
class Visitors{
	protected:
		string name;
		int bravery;
	public:
		Visitors(string n,int b):name(n),bravery(b) {}
		void React(int s){
			if(s < bravery - 2){
				cout<<name<<" | Laughs!"<<endl;
			}
			else if(s > bravery -2){
				cout<<name<<" | Scream!"<<endl;
			}
			else{
				cout<<name<<" | shaky voice!"<<endl;
			}
		}
		friend void visit(HauntedHouse& h,string n,int b);	
};
void visit(HauntedHouse& h,string n,int b){
	cout<<n<<" visiting "<<h.name<<endl;
	for(int i=0;i<3; i++){
        h.arr[i]->haunt();
        Visitors v(n,b);
        v.React(h.arr[i]->get_level());
    }
}
int main() {
    HauntedHouse h1("Spooky Mansion");
    h1.addGhost(new Poltergeists("John"));
    h1.addGhost(new Banshees("Anna"));
    h1.addGhost(new ShadowGhosts("Luke"));
    h1.show();
    visit(h1,"Alice",5);
    visit(h1,"Bob",9);
    visit(h1,"Charlie",2);
    return 0;
}

