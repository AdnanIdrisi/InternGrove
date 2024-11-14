#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    if(num1>num2){
    	cout << "The maximun of " << num1 << " and " << num2 << " is " << num1;
	}
	else{
		cout << "The maximun of " << num1 << " and " << num2 << " is " << num2;
	}
    return 0;
}

