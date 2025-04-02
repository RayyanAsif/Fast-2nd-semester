#include <iostream>
using namespace std;
class Product{
	protected:
		string name; 
		float price;
		string brand;
	public:
		Product(string n,float p,string b):name(n),price(p),brand(b) {}
		void display_general(){
			cout<<"=== General Product Details ==="<<"\nProduct Name: "<<name<<"\nBrand: "
			<<brand<<"\nPrice: $"<<price<<endl;
		}	
};
class ElectronicProduct: public Product{
	private:
		int warranty;
	public:
		ElectronicProduct(string n,float p,string b,int w): warranty(w),Product(n,p,b) {}
		void display_Product(){
			cout<<"\n=== Electronic Product Details ==="<<"\nProduct Name: "<<name<<"\nBrand: "
			<<brand<<"\nPrice: $"<<price<<"\nWarranty: "<<warranty<<" month"<<endl;
		}	
};
int main(){
	Product p("Backpack", 49.99, "Nike");
	ElectronicProduct e("Smartphone", 799.99, "Samsung", 24);
	p.display_general();
	e.display_Product();
	return 0;
}
