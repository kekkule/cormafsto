#include "v3d.h"
#include <iostream>

using namespace std;

int main () {
    V3D<double> A, B, C;
    A.set_ (0.1, 0.2, 0.3);
    B.set_ (10.1, 1.2, 1.3);
    // B = A.normalize();

    C = mul (A, B);
    cout << C.get_x () << " " << C.get_y () << " " << C.get_z () << endl;
    cout << B.module () << endl;
    return 0;
}
