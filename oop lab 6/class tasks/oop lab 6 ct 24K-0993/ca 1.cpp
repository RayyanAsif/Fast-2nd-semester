#include <iostream>
using namespace std;
class base{
public:
    int i,b;
    base(int i,int b){
        this->i = i;
        this->b = b;
    }
};
class derived : public base{
public:
    derived(int i, int b) : base(1, b) {}

    void showData() {
        cout<< "i = "<<i<<endl<< "b = "<<b;
    }
};
int main(){
    derived d1(4, 5);
    d1.showData();
    return 0;
}
