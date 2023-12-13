#include <iostream>
#include "lab 1.h"
#include <random>
using namespace std;

int main(){
    int size_x, size_y;
    cout << "Enter the dimensions of the field" << endl;
    cout << "a: ";
    cin >> size_x;
    cout << "b: ";
    cin >> size_y;

    int choice;
    cout << "Choose an option:" << endl;
    cout << "1. Fill with random values" << endl;
    cout << "2. Fill with zeros" << endl;
    cout << "3. Fill with a specific symbol" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    char fillSymbol;
    if (choice == 3) {
        cout << "Enter the symbol to fill the square with: ";
        cin >> fillSymbol;
    }
    else {
        fillSymbol = '0';
    }

    Image<char> a(size_x, size_y, false, fillSymbol);

    double x1, y1;
    cout << "Enter the coordinates of the top-left point" << endl;
    cout << "x: ";
    cin >> x1;
    cout << "y: ";
    cin >> y1;

    double x2, y2;
    cout << "Enter the coordinates of the bottom-right point" << endl;
    cout << "x: ";
    cin >> x2;
    cout << "y: ";
    cin >> y2;
}
