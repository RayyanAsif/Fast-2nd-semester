#include <iostream>
using namespace std;
int reverse(int array[],int st,int en){
	while(st<en){
		int temp = array[st];
		array[st] = array[en];
		array[en] = temp;
		st++;
		en--;
	}
}
int rotate(int array[],int n,int k){
	reverse(array,0,n-1);
	reverse(array,0,k-1);
	reverse(array,k,n-1);
}
int main(){
	int array[5] = {1,2,3,4,5};
	int k;
	cout<<"How many elements to rotate"<<endl;
	cin>>k;
	k = k%5;
	rotate(array,5,k);
	for(int i=0;i<5;i++){
		cout<<array[i]<<"\t";
	}
}
