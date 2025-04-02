#include <iostream>
using namespace std;
class Complex{
	private:
		int real;
		int imaginary;
	public:
		Complex(int r,int i): real(r),imaginary(i) {}
		Complex operator+(const Complex& x){
			return Complex(real+x.real,imaginary+x.imaginary);
		}	
		Complex operator*(const Complex& x){
			return Complex(real*x.real,imaginary*x.imaginary);
		}
		void display(){
			cout<<" "<<real<<" + "<<imaginary<<"i"<<endl;
		}
};
int main(){
	Complex c1(3,10);
	Complex c2(4,-5);
	Complex c3=c1+c2;
	cout<<"Sum:";
	c3.display();
	Complex c4=c1*c2;
	cout<<"Product:";
	c4.display();
}
