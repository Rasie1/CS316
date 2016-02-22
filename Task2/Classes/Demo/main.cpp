#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    cout << "Welcome" << endl;
    Matrix<int> a(4, 4);
    a(1, 1) = 17;
    cout << a(1, 1) << endl;
    return 0;
}
