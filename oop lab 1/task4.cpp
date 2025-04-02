#include <iostream>
using namespace std;
int main(){
	int array[7] = {1,3,2,5,3,7,6};
	cout<<"Peak identified at ";
	for(int i=0;i<7;i++){
		if(i==0){
			if(array[i]>array[i+1]){
				cout<<array[i];
			}
		}
		else if(i==6){
			if(array[i]>array[i-1]){
				cout<<array[i]<<"\t";
			}
		}
		else{
			if(array[i]>array[i+1] && array[i]>array[i-1]){
				cout<<array[i]<<"\t";
			}
		}
	}
	return 0;
}
