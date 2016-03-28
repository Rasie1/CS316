#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    cout << "Welcome" << endl;
    Matrix<int> a(4, 4);
    a(1, 1) = 17;
    cout << a << endl;

    cout << "Resizing with default value:" << endl;
    a.resize(10, 10, 1000);
    cout << a << endl;

    cout << "Resizing into smaller matrix:" << endl;
    a.resize(8, 5);
    cout << a << endl;

    cout << "Getting a row:" << endl;
//    a.resize(6, 6, 1000);
//    cout << a << endl;

    cout << "Getting a column:" << endl;
//    a.resize(6, 6, 1000);
//    cout << a << endl;

    cout << "Copying to B" << endl;
//    auto b = a;
    Matrix<int> b(4, 4);
    b(1, 1) = 1;
    cout << b << endl;

    cout << "Inserting a row and a column" << endl;
    a.insertRow(3, 2);
    a.insertCol(2, 1);
    cout << a << endl;

    cout << "Deleting a row and a column" << endl;
    a.deleteRow(3);
    a.deleteCol(2);
    cout << a << endl;

    cout << "Displaying B" << endl;
    cout << b << endl;

    cout << "Swapping B and A" << endl;
    swap(a, b);


    cout << "Displaying A" << endl;
    cout << a << endl;
    cout << "Displaying B" << endl;
    cout << b << endl;

    return 0;
}
