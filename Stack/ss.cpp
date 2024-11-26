#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string input = "123 45.67";
    stringstream ss(input);

    int number1;
    double number2;

    ss >> number1 >> number2;

    cout << "Number 1: " << number1 << endl;
    cout << "Number 2: " << number2 << endl;

    ss.str(""); // Clear the stringstream;
    ss.str("12 12.67 Hello");
    // cout << ss.str() << endl;

    // ss << "Hello";

    // string output = ss.str(); // Get the string from the stringstream
    // cout << "Output: " << output << endl;

    string output;
    ss >> number1 >> number2 >> output;

    cout << "Number 1: " << number1 << endl;
    cout << "Number 2: " << number2 << endl;
    cout << "Output: " << output << endl;

    return 0;
}


// #include <iostream>
// #include <sstream>
// #include <string>

// using namespace std;

// int main() {
//     stringstream ss; // Create an empty stringstream

//     // Insert "apple" into the stringstream
//     ss << "hello, apple";
//     // Get the string from the stringstream
//     string output = ss.str();
//     cout << "Output: " << output << endl;

//     ss.str(""); // Clear the stringstream

//     ss << "hello, world!";
//     // Print the output
//     output = ss.str();
//     cout << "Output: " << output << endl;

//     return 0;
// }