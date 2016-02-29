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
    a.resize(6, 6, 1000);
    cout << a << endl;
    return 0;
}
