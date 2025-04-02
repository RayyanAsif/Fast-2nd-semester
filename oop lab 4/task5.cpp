#include <iostream>
using namespace std;
class Movie{
	private:
		string movieName;
		int availableSeats;
		double ticketPrice;
	public:
		Movie(string n,int seats,double price) : movieName(n),availableSeats(seats),ticketPrice(price){
			cout<<movieName<<" is available for booking"<<endl;
		}	
		~Movie(){
			cout<<movieName<<" booking closed"<<endl;
		}
		void bookTicket(int s){
			if(availableSeats < s){
				cout<<"Not enough seats available"<<endl;
			}
			else{
				availableSeats -= s;
				cout<<"Tickets booked"<<endl;
			}
		}
		void displayMovieInfo(){
			cout<<"Movie: "<<movieName<<endl;
			cout<<"Seats Available: "<<availableSeats<<endl;
			cout<<"Price: "<<ticketPrice<<endl;
		}
};
int main(){
	Movie x("Avengers",50,10);
	x.bookTicket(5);
	x.displayMovieInfo();
}
