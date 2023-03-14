#include "v3d.h"
#include <iostream>

using namespace std;

int main () {
    V3D<double> A(0.1, 0.2, 0.3);
    V3D<double> B(10.1, 1.2, 1.3);

    V3D<double> C = mul (A, B);
    
    cout << C.get_x () << " " << C.get_y () << " " << C.get_z () << endl;
    cout << B.module () << endl;
    return 0;
}
