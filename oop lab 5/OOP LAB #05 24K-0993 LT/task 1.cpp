#include <iostream>
using namespace std;
class Music_Session{
	private:
		string name;
		string artist;
		int duration;
		static int played;
	public:
		Music_Session(string n,string a,int d) : name(n),artist(a),duration(d) {}
		void play(){
			cout<<"Playing: "<<name<<" by "<<artist<<" ["<<duration<<" sec]"<<endl;
			played++;
		}
		static void total_played(){
			cout<<"Total songs played: "<<played<<endl;
		}
};
int Music_Session::played = 0;
int main(){
	Music_Session x("Shape of You","Ed Sheeran",210);
	Music_Session y("Blinding Lights","The Weeknd",200);
	Music_Session z("After Hours","The Weeknd",200);
	x.play();
	y.play();
	z.play();
	Music_Session::total_played();
}
