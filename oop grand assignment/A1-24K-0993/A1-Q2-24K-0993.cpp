#include <iostream>
using namespace std;
class Robot{
	private:
		string name;
		int hits;
	public:
		Robot(string n){
			name = n;
			hits = 0;
		}	
		void hitBall(int &ballX, int &ballY, const string &direction){
			hits++;
			if(direction=="up"){
				ballY++;
			}
			else if(direction=="down"){
				ballY--;
			}
			else if(direction=="left"){
				ballX--;
			}
			else if(direction=="right"){
				ballX++;
			}
			else{
				cout<<"Invalid Direction"<<endl;
			}
		}
		int get_hits(){
			return hits;
		}
		string get_name(){
			return name;
		}
};
class Ball{
	private:
		int x;
		int y;
	public:
		Ball(int x1,int y1){
			x=x1;
			y=y1;
		}
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}
		void move(int dx, int dy){
			x=dx;
			y=dy;
		}
		void display(){
			cout<<"Ball is currently at: ("<<x<<","<<y<<")"<<endl;
		}	
};
class Goal{
	public:
		static int x;
		static int y;
		static int isGoalReached(int ballX, int ballY){
			if(ballX==x && ballY==y){
				cout<<"Congratulation! Ball reached the goals"<<endl;
				return 1;
			}
			else{
				cout<<"Ball doesn't reach the goal"<<endl;
				return 0;
			}
		}
};
int Goal::x = 3;
int Goal::y = 3;
class Team{
	private:
		string name;
		Robot* x;
	public:
		Team(string n,Robot* c){
			name=n;
			x=c;
		}
		Robot* get_Player(){
			return x;
		}
		string get_name(){
			return name;
		}	
};
class Game{
	private:
		Team* one;
		Team* two;
		Ball x;
		Goal y;
	public:
		Game(Team* x1,Team* x2,int bx,int by) : x(bx,by),one(x1),two(x2) {}
		void play(Team* x1){
			Robot* r = x1->get_Player();
			cout<<x1->get_name()<<" is playing with "<<r->get_name()<<endl;
			int a = 0;
			int b = 0;
			x.move(a,b);
			while(!Goal::isGoalReached(x.getX(),x.getY())){
				x.display();
				string d;
				cout<<"Which direction to move up/down/left/right"<<endl;
				cin>>d;
				r->hitBall(a,b,d);
				x.move(a,b);
			}
			cout<<x1->get_name()<< " reached the goal in "<<r->get_hits()<<" hits!"<<endl;
		}
		void startGame(){
			cout<<"Game started:"<<endl;
			play(one);
			play(two);
			declareWinner();
		}
		void declareWinner(){
			int h1 = one->get_Player()->get_hits();
			int h2 = two->get_Player()->get_hits();
			if(h1<h2)
				cout<<one->get_name()<<" is the Winner!"<<endl;
			else if(h2<h1)
				cout<<two->get_name()<<" is the Winner!"<<endl;
			else{
				cout<<"Tie!"<<endl;
			}	
		} 
		
};
int main(){
	Robot r1("Rayyan");
    Robot r2("Rad");
    Team tA("Team A", &r1);
    Team tB("Team B", &r2);
    Game g(&tA, &tB, 0, 0);
    g.startGame();
}
