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

    void set_ (T X, T Y, T Z); // { x = X; y = Y; z = Z; }

    T    get_x (); // { return x; }
    T    get_y (); // { return y; }
    T    get_z (); // { return z; }

    T    module (); // { return sqrt(x*x + y*y + z*z); }

    void operator= (const V3D<T>& A) {
        x = A.x;
        y = A.y;
        z = A.z;
    }

    V3D<T>  operator+ (const V3D<T>& A);
    V3D<T>& operator+= (const V3D<T>& A);
    V3D<T>  operator- (const V3D<T>& A);
    V3D<T>& operator-= (const V3D<T>& A);

    template <typename N>
    V3D<T> operator* (N A);
    template <typename N>
    V3D<T> operator/ (N A);

    V3D<T> from_polar (const V3D<T>& A);
    V3D<T> normalize ();

    // template <class V> friend V3D<V> operator+ (const V3D<V>& A, const  V3D<V>& B);
    // template <class V> friend V3D<V>& operator+= (V3D<V>& A, const V3D<V>& B);
    // template <class V> friend V3D<V> operator- (const V3D<V>& A, const V3D<V>& B);
    // template <class V> friend V3D<V>& operator-= (V3D<V>& A, const V3D<V>& B);
    // template <class V> friend V3D<V> operator* (const V3D<V>& A, V B);
    // template <class V> friend V3D<V> operator/ (const V3D<V>& A, V B);

    // template <class V> friend V3D<V> from_polar(const V3D<V>& A);
    // template <class V> friend V3D<V> normalize(V3D<V>& A);
    template <typename V>
    friend V3D<V> mul (const V3D<>& A, const V3D<V>& B);
};

#endif