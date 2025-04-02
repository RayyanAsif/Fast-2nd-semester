#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
using namespace std;
const int max_b = 100;

class book{
	private:
		string title;
		string author;
		bool isAvailable;
	public:
		int ISBN;
		book() : title(""),author(""),ISBN(0),isAvailable(false) {}
		book(string t,string a,int i,bool avl=true) : title(t),author(a),ISBN(i),isAvailable(avl) {}
		void addBook(book library[],int& count){
			if(count >= max_b){
				cout<<"Can't add more book, storage full!"<<endl;
				return;
			}
			book x;
			cout<<"Enter title of the book"<<endl;
			cin>>x.title;
			cout<<"Enter author name"<<endl;
			cin>>x.author;
			cout<<"Enter ISBN number"<<endl;
			cin>>x.ISBN;
			library[count] = x;
			count++;
		}
		void displayBookDetail();
		void updateAvailability();
		void searchBook(book library[],int count,int s){
			for(int i=0;i<count;i++){
				if(library[i].ISBN == s){
					cout<<"File Found"<<endl;
					library[i].displayBookDetail();
					return;
				}
			}
			cout<<"File not found"<<endl;
		}
};
#endif


