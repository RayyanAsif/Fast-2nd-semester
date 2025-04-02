#include "product.h"
#include <iostream>
using namespace std;
void Product::display_product(){
	cout<<"Product Name: "<<productName<<endl;
	cout<<"Price: "<<price<<endl;
	cout<<"Discount: "<<discount<<endl;
	cout<<"Stock Available: "<<stock<<endl;
}
int main(){
	Product x("Cadbury",500,100,50);
	x.apply_discount();
	x.update_stock();
	x.display_product();
	return 0;
}
