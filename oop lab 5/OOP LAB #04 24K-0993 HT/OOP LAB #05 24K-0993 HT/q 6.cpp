#include <iostream>
using namespace std;
class Product{
	private:
		static int count;
	public:
		Product(){
			count++;
		}
		static void display(){
			cout<<"Number of Products created: "<<count<<endl;
		}	
};
int Product::count=0;
int main(){
	Product x;
	Product y;
	Product z;
	Product::display();
}
