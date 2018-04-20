#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <vector>
using namespace std;

// Develop Class People in this header file. 
class People{
	string name;
	char s[4] = {'M','m','F','f'};
	char sex;
	unsigned int age; 
	unsigned int money;
	int power;
	int happy;
	People *dad;
	People *mom;
	vector<People *> baby;
	public:
	People *me;
	void operator+(int );
	int operator-(const People &);
	void operator>>( People &);
	People(string n="Unknow",char SEX='F',int a=69,People *d = NULL,People *m = NULL){
		int num=0;
		for(int i=0;i<4;i++){
			if( SEX != s[i]){ num++; }
		}
		if(num == 4){ sex = 'F'; }
		else{ sex = SEX; }
		
		name = n;
		
		if(a >= 0){ age = a; }
		else{ age = 69; }
		
		money = 0;
		power = 100;
		happy = 50;
		dad = d;
		mom = m;
	}
	
	void show(){
		string gender;
		cout <<"----------------------------------------"<<endl;
		cout <<"NAME: "<<name<<endl;
		if(sex=='M'){ gender = "ALE"; }
		else if(sex=='m'){ gender = "ALE"; sex='M';}
		else if(sex=='F'){ gender = "EMALE"; }
		else if(sex=='f'){ gender = "EMALE"; sex='F';}
		cout <<"GENDER: "<< sex <<gender <<endl;
		cout <<"AGE: "<<age<<" years"<<endl;
		cout <<"MONEY: "<<money<<" Baht"<<endl;
		cout <<"ENERGY: "<<power<<"%"<<endl;
		cout <<"HAPPINESS: "<<happy<<"%"<<endl;
		cout <<"----------------------------------------"<<endl;
	}
	
	void work(int hr){
		if(hr<=0 || hr>power){ }
		else {
			int money_less = money;
			money = money+( 30.0* (pow(happy,0.5) *(0.1*age+hr) ) );
			power = power-hr;
			if(happy > ( hr/(1+0.0001*money_less)) ){
				happy = happy-( hr/(1+0.0001*money_less) );
			}
			else{
				happy = 0;
			}
		}
	}
	
	void play(int hr){
		if(hr<=0 || hr>power || 10*age*hr > money){ }
		else{
			money = money-(10*age*hr);
			power = power-hr;
			happy = ( (100*hr)+(2*happy) ) / (hr+2);
		}
	}
	
	void rest(int hr){
		if(hr<=0 ){ }
		else{
			int x; int num=0;
			for(int i=0;i<hr;i++){ num++; }
			srand(time(0));
			x = ( rand()%num )+1;
			if(power+x > 100){ power = 100; }
			else{ power = power+x; }
			
			srand(time(0));
			int y = rand()%11;
			if(happy+y > 100){ happy = 100; }
			else{ happy = happy+y; }
		}
		
	}	

	
	void showFamily(){
		cout <<"----------------------------------------"<<endl;
		cout <<"NAME: "<<name<<endl;
		if(dad!=NULL){
			cout <<"FATHER: " << dad->name << endl;
		}
		if(mom!=NULL){
			cout <<"MOTHER: "<< mom->name <<endl;
		}
		if(baby.size() != 0){
			cout <<"CHILDREN: "<< baby[0]->name ;
			for(int i=1;i<baby.size();i++){
				cout  << ", "<< baby[i]->name ;
			}
			cout <<endl;
		}
		cout <<"----------------------------------------"<<endl;
	}
	
	/*void call_me(People *a){
		this->me = a;
		a->me = this;
	}*/
	
};

void People::operator+(int a){
		age += a; 
}

int People::operator-( const People &c){
		return age-c.age;
}

void People::operator>>( People &c){
	baby.push_back(&c);
	if(sex == 'M'|| sex == 'm'){  
		c.dad = this;
	}
	if(sex == 'F'|| sex == 'f'){  
		c.mom = this;
	}
}






