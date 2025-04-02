#include <iostream>
using namespace std;
struct Student{
	string Name;
	int Roll_Num;
	int year;
	float Grades[5];
};
int main(){
	Student* x = new Student[5];
	for(int i=0;i<5;i++){
		cout<<"Enter your Name: "<<endl;
		cin>>x[i].Name;
		cout<<"Enter your roll number: "<<endl;
		cin>>x[i].Roll_Num;
		cout<<"Enter year of admission: "<<endl;
		cin>>x[i].year;
		cout<<"Enter grade of your Subjects: "<<endl;
		for(int j=0;j<5;j++){
			cin>>x[i].Grades[j];
		}
	}
	float total[5];
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			total[i] += x[i].Grades[j];
		}
	}
	for(int i=0;i<5;i++){
		cout<<"Name: "<<x[i].Name<<endl;
		cout<<"Roll_num: "<<x[i].Roll_Num<<endl;
		cout<<"Year: "<<x[i].year<<endl;
		cout<<"Total marks: "<<total[i]<<endl;
	}
	int highest=0,highest_index;
	for(int i=0;i<5;i++){
			if(total[i]>highest){
				highest = total[i];
				highest_index = i;
			}
		}
	cout<<"Highest marks: Student "<<highest_index<<endl;
}
