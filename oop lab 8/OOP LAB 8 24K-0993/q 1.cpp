#include <iostream>
using namespace std;
class Rectangle{
	private:
		int length;
		int width;
	public:
		Rectangle(int l,int w):length(l),width(w) {}
		friend class AreaCalculator;	
};
class AreaCalculator{
	public:
		static int calculateArea(Rectangle& x){
			return x.length * x.width;
		}
};
int main(){
    Rectangle r(10,5);
    int area = AreaCalculator::calculateArea(r);
    cout << "Area of Rectangle: " << area << endl;
    return 0;
}

