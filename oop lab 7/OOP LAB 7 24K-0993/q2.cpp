#include <iostream>
using namespace std;
class Matrix{
	private:
		int arr[2][2];
	public:
		Matrix(int a=0,int b=0,int c=0,int d=0){
			arr[0][0] = a;
			arr[0][1] = b;
			arr[1][0] = c;
			arr[1][1] = d;
		}
		Matrix operator+(const Matrix& x){
			Matrix y;
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					y.arr[i][j] = arr[i][j] + x.arr[i][j];
				}
			}
			return y;
		}
		void display(){
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					cout<<arr[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
};
int main(){
	Matrix x1(1,2,3,4);
	Matrix x2(5,6,7,8);
	cout<<"Matrix 1: "<<endl;
	x1.display();
	cout<<"Matrix 2: "<<endl;
	x2.display();
	cout<<"Sum: "<<endl;
	Matrix x3 = x1+x2;
	x3.display(); 
}
