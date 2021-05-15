#include<iostream>
#include <string>
#include <sstream>

using namespace std;

class geometricobject 
{ 
    //baseclass
    public:
    	double h;
    	double w;
    	int h2;
    	double bmf;
virtual void geo()
{
    cout << "Just a geometric object\n" << endl; 
} 
virtual void bmi()
{
	
}
virtual void happy()
{
	
}
};

class rectangle : public geometricobject

{
    //derived class
    public:
virtual void geo()
{
    cout << "I’m a rectangle\n" << endl;	
} 
virtual void bmi()
{
	
}
}; 

class bmicalc : public geometricobject { // derived class
public:
		
virtual void geo()
{
    
}

virtual void bmi(){
	cout << "Enter your height in inches: ";
    cin >> h;
    cin.ignore();
    cout <<"Enter your weight in pounds: ";
    cin >> w;
    cin.ignore();
    bmf = w/h/h*703;
    cout << "Your bmi is: " << bmf << "\n\n";	
}	
}; 

class happytest : public geometricobject { // derived class
public:
string hchoice = "";
string hchoice1 = "";
string hchoice2 = "";
string hchoice3 = "";
string final = "";
int happynum = 0;
virtual void geo()
{
    
}
virtual void bmi(){
} 

virtual void happy(){
	cout << "This is a test to measure your level of happiness according to your responses to certain questions.\n" << "Would you like to take the test? Y/N ";
	cin >> hchoice;
	cin.ignore();
	if (hchoice == "Y" || hchoice == "y"){
		cout << "Question #1: Have you slept for at least 7-8 hours previously? Y/N \n"; 
	}else{
		cout << "Exiting..." << endl;
		system("pause");
		exit(0);	
	}	
		cin >> hchoice1;
		cin.ignore();
	
	if (hchoice1 == "Y" || hchoice1 == "y"){
			happynum = happynum+1;
		}
	cout << "Did you eat a good breakfast?" << endl;
	cin >> hchoice2;
	cin.ignore();
	if (hchoice2 == "Y" || hchoice2 ==  "y"){	
			happynum = happynum+1;
	}else{
	}
		cout << "Is your room a mess?" << endl;
		cin >> hchoice3;
		if (hchoice3 == "N" || hchoice3 == "n"){	
		happynum = happynum+1;
	}
		if (happynum >= 3){
			final = "extremely "; 
		}
		if (happynum == 2){
			final = "moderately "; 
		}
		if (happynum <= 1){
			final = "completely un"; 
		}
		cout << "This is the end of the test." << endl;
		cout << "You are " << final << "happy.";
		if (final == "extremely "){
			cout << " Great!\n";
		}
		if (final == "moderately "){
			cout << " Not bad.\n";
		}
		if (final == "completely un"){
			cout << " Try doing something you enjoy.\n";
		}
}
};

class circle : public geometricobject { // derived class
public:
virtual void geo()
{
    cout << "I’m a circle\n" << endl;
}
virtual void bmi()
{	

}
};

int main(){ 

geometricobject *ptr; //pointer to base class
int which;
cout << "Enter 4 for BMI calculator, anything else to exit. ";
cin >> which;
cin.ignore();
if (which == 4){
	ptr = new bmicalc;
	ptr -> bmi(); //run-time binding
}else{
	cout << "Exiting..." << endl;
	system("pause");
	exit(0);
}

int which2;
cout << "Enter 1 for Geometricobject, 2 for Rectangle, or 3 for Circle: ";
cin >> which2;
cin.ignore();
if (which2 == 1){
	ptr = new geometricobject;
	ptr -> geo(); //run-time binding
}
if (which2 == 2){
	ptr = new rectangle;
	ptr -> geo(); //run-time binding
}
if (which2 == 3){
	ptr = new circle;
	ptr -> geo(); //run-time binding
}
if (which2 < 1 || which2 > 3){
	cout << "Enter 1-3 only." << endl;
	system("pause");
	exit(0);
}

ptr = new happytest;
ptr -> happy(); //run-time binding
delete ptr;
system("pause");
return 0;
}

