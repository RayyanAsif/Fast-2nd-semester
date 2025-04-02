#include <iostream>
using namespace std;
class student{
	private:
		string name;
		int roll_no;
		float marks[5];
		float total;
		float percentage;
		char grade;
	public:
		void inputDetails(){
			cout<<"Enter your name"<<endl;
			cin>>name;
			cout<<"Enter your roll number"<<endl;
			cin>>roll_no;
			cout<<"Enter marks:"<<endl;
			for(int i=0;i<5;i++){
				cout<<"Subject "<<i+1<<endl;
				cin>>marks[i];
			}
		}
		void CalculateGrade(){
			for(int i=0;i<5;i++){
				total+=marks[i];
			}
			float temp;
			cout<<"Enter highest obtainable marks of all subjects"<<endl;
			cin>>temp;
			percentage = total/temp*100;
			if(percentage >= 90){
				grade = 'A';
			}
			else if(percentage >= 75 && percentage <= 89){
				grade = 'B';
			}
			else if(percentage >= 65 && percentage <= 74){
				grade = 'C';
			}
			else{
				grade = 'F';
			}
		}
		void DisplayReportCard(){
			cout<<"Name: "<<name<<endl;
			cout<<"Roll No: "<<roll_no<<endl;
			cout<<"Subject Marks:"<<endl;
			for(int i=0;i<5;i++){
				cout<<"Subject "<<i+1<<" "<<marks[i]<<endl;
			}
			cout<<"Total Marks: "<<total<<endl;
			cout<<"Percentage: "<<percentage<<endl;
			cout<<"Grade: "<<grade<<endl;
		}	
};
int main(){
	student x;
	x.inputDetails();
	x.CalculateGrade();
	x.DisplayReportCard();
	return 0;
}
