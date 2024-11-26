#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main(){

    string input = "123 45.67";
    stringstream ss;

    ss<<input;

    int number1;
    double number2;
    ss>>number1>>number2;
    cout<<"Number 1: "<<number1<<endl;
    cout<<"Number 2: "<<number2<<endl;

    ss.str(""); // Clear the stringstream
    // ss << "Hello";

    ss.str("Hello");
    cout << ss.str() << endl;
    string output = ss.str();
    cout<<"Output: "<<output<<endl;
}