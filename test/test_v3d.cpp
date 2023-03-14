#include "v3d.h"
#include <iostream>

using namespace std;

int main () {
    V3D<double> A(1, 0, 0);
    V3D<double> B(0, 1, 0);

    V3D<double> C = mul<double> (A, B);
    
    cout << C.get_x () << " " << C.get_y () << " " << C.get_z () << endl;
    cout << B.module () << endl;
    return 0;
}
