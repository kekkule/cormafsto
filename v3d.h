// Bad logic, because we have lot's of frend functions (and repeating elements)
// In function from_polar we use x, y, z - later make a, thetta, fi for correct math logic
#ifndef V3D_GUARD
#define V3D_GUARD

#include <iostream>
#include <math.h>

using namespace std;

template <typename T>
class V3D {
private:
    T x, y, z;

public:
    V3D<T> ()
        : x (0)
        , y (0)
        , z (0) { }
    V3D<T> (T x, T y, T z)
        : x (x)
        , y (y)
        , z (z) { }
    V3D<T> (const V3D<T>& A)
        : x (A.x)
        , y (A.y)
        , z (A.z) { }
    ~V3D<T> () { }

    void set_ (T X, T Y, T Z);

    T    get_x (); 
    T    get_y (); 
    T    get_z (); 

    T    module (); 

    template <typename N>
    void operator= (const V3D<N>& A);

    template <typename N>
    V3D<T>  operator+ (const V3D<N>& A);

    template <typename N>
    V3D<T>& operator+= (const V3D<N>& A);

    template <typename N>
    V3D<T>  operator- (const V3D<N>& A);

    template <typename N>
    V3D<T>& operator-= (const V3D<N>& A);

    template <typename N>
    V3D<T> operator* (V3D<N> A);

    template <typename N>
    V3D<T> operator* (N A);

    template <typename N>
    V3D<T> operator/ (N A);

    template <typename N>
    V3D<T> from_polar (const V3D<N>& A);

    V3D<T> from_polar (T r, T thetta, T fi);

    V3D<T> normalize ();

    template <typename N>
    friend V3D<T> mul (const V3D<T>& A, const V3D<N>& B);
};

#endif //V3D_GUARD