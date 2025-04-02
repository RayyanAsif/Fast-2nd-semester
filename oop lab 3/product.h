#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
using namespace std;
class Product{
	private:
		string productName; 
		float price; 
		int stock; 
		float discount;
	public:
		Product() : productName(" "),price(0),stock(0),discount(0) {}
		Product(string n,float p,int s,float d) : productName(n),price(p),stock(s),discount(d) {}
		void apply_discount(){
			price -= price * (discount/100);
		}
		void update_stock(){
			int temp;
			cout<<"Enter number of stock to reduce"<<endl;
			if(stock > 0 && stock >= temp){
				stock -= temp;
			}
			else{
				cout<<"Not enough stock available"<<endl;
			}
		}
		void display_product();	
};
#endif
