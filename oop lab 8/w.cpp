#include <iostream>

using namespace std;

class A{

public:

A() { cout << "A()" << endl; }~A(){
	cout<<"a"<<endl;
}};
class B : public A{

public:

B() { cout << "B()" << endl; }~B(){
	cout<<"b"<<endl;
}}; // BY DEFAULT B() : A()

int main(){

B b;

return 0;

}
