#include <iostream>
using namespace std;
class LibraryItems{
	protected:
		string title;
		string author;
	public:
		LibraryItems(string t,string a):title(t),author(a) {}	
};
class Book:public LibraryItems{
	private:
		string ISBN;
	public:
		Book(string t,string a,string i):LibraryItems(t,a),ISBN(i) {}
		void display_book(){
			cout<<"=== Book Details ==="<<"\nTitle: "<<title<<"\nAuthor: "<<author
			<<"\nISBN: "<<ISBN<<"\n"<<endl;
		}	
};
class Magazine:public LibraryItems{
	private:
		int issue_no;
	public:
		Magazine(string t,string a,int i):LibraryItems(t,a),issue_no(i) {}
		void display_Magazine(){
			cout<<"=== Book Details ==="<<"\nTitle: "<<title<<"\nAuthor: "<<author
			<<"\nIssue Number: "<<issue_no<<"\n"<<endl;
		}
};
int main(){
	Book b("The Great Gatsby","F. Scott Fitzgerald","978-0743273565");
	Magazine m("National Geographic","Multiple Authors",202);
	b.display_book();
	m.display_Magazine();
	return 0;
}
