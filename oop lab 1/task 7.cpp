#include <iostream>
#include <string>
using namespace std;
int main(){
	char array[100];
	char temp_upper[100],temp_nospace[100];
	int vcount=0,x=0,z=0;
	cout<<"Enter a string"<<endl;
	fgets(array,sizeof(array),stdin);
	for(int i=0;array[i] !='\0';i++){
		char t = array[i];
		if(t >='a' && t <= 'z'){
			t = t - 32;
		}
		temp_upper[x] = t;
		x++;
	}
	for(int i=0;temp_upper[i] != '\0';i++){
		if(temp_upper[i] == 'A' || temp_upper[i] == 'E' || temp_upper[i] == 'I' || temp_upper[i] == 'O' || temp_upper[i] == 'U'){
			vcount++;
		}
	}
	for(int i=0;array[i] != '\0';i++){
		char c = array[i];
		if(c != ' '){
			temp_nospace[z]=c;
			z++;
		}
	}
	temp_nospace[z] ='\0';
	temp_upper[x] = '\0';
	cout<<"UPPER CASE: "<<temp_upper<<endl;
	cout<<"Vowel count: "<<vcount<<endl;
	cout<<"No space: "<<temp_nospace<<endl;
	return 0;
}
