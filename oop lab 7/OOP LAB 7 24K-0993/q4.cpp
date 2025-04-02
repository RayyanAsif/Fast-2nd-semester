#include <iostream>
using namespace std;
class Animal{
	public:
		virtual void makeSound(){
			cout<<"Kuch bolo"<<endl;
		}
};
class Dog:public Animal{
	public:
		void makeSound() override{
			cout<<"Dog:Woof!"<<endl;		
		}
};
class Cat:public Animal{
	public:
		void makeSound() override{
			cout<<"Cat:Meow!"<<endl;		
		}
};
int main(){
	Animal *a1;
	Animal *a2;
	Dog d;
	Cat c;
	a1 = &d;
	a2 = &c;
	a1->makeSound();
	a2->makeSound();
}
