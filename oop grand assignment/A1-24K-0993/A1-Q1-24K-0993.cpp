#include <iostream>
using namespace std;
class Skill{
public:
    int sID;
    string sName;
    string desc;
    void showSkillDetails(){
        cout<<"Skill ID: "<<sID<<" | Skill Name: "<<sName<<" | Description: "<<desc<<endl;
    }
    void updateSkillDescription(string newD){
        desc = newD;
    }
};
class Sport{
public:
    int sportID;
    string name;
    string desc;
    void showSportDetails(){
        cout <<"Sport ID: "<<sportID<<" | Name: "<<name<<" | Description: "<<desc<<endl;
    }
};
class Student{
public:
    int studentID;
    string name;
    int age;
    string sportsInterest;
    string mentorAssigned;
    Student(int id,string n,int a,string i){
    	studentID = id;
    	name = n;
    	age = a;
    	sportsInterest = i;
    	mentorAssigned = "Unknown";
	}
    void registerForMentorship(string m){
        mentorAssigned = m;
    }
    void viewMentorDetails(){
        cout<<"Mentor Assigned: "<<mentorAssigned<<endl;
    }
    void updateSportsInterest(string newS){
        sportsInterest = newS;
    }
};
class Mentor{
public:
    int mentorID;
    string name;
    string sportsExpertise;
    int maxLearners;
    int currentLearners = 0;
    Mentor(int m,string n,string e,int x){
    	mentorID = m;
    	name = n;
    	sportsExpertise = e;
    	maxLearners = x;
	}
    void assignLearner(Student &s){
        if(currentLearners<maxLearners){
            s.registerForMentorship(name);
            currentLearners++;
            cout<<s.name<<" has been assigned to mentor "<<name<<endl;
        }else{
            cout<<"Mentor "<<name<<" has reached maximum capacity."<<endl;
        }
    }
    void removeLearner(Student &s){
        if (s.mentorAssigned == name){
            s.mentorAssigned = "None";
            currentLearners--;
            cout<<s.name<<" has been removed from mentorship under "<<name<<endl;
        }else{
            cout<<"This student is not assigned to this mentor."<<endl;
        }
    }
};
int main(){
    Mentor m1(1,"Ali","Tennis",3);
    Student s1(101,"Saad",20,"Tennis");
    Student s2(102,"Ahmed",21,"Tennis");
    m1.assignLearner(s1);
    s1.viewMentorDetails();
    m1.assignLearner(s2);
    s2.viewMentorDetails();
    m1.removeLearner(s1);
    s1.viewMentorDetails();
    return 0;
}

