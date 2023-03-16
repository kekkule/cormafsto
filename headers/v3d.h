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

    void    set_ (T X, T Y, T Z);

    T       get_x ();
    T       get_y ();
    T       get_z ();

    T       module ();

    void    operator= (const V3D<T>& A);

    V3D<T>  operator+ (const V3D<T>& A);
    V3D<T>& operator+= (const V3D<T>& A);

    V3D<T>  operator- (const V3D<T>& A);
    V3D<T>& operator-= (const V3D<T>& A);

    V3D<T>  operator* (V3D<T> A);
    V3D<T>  operator* (T A);

    V3D<T>  operator/ (T A);

    V3D<T>  from_polar (const V3D<T>& A);
    V3D<T>  from_polar (T r, T thetta, T fi);

    V3D<T>  normalize ();

    template <typename V>
    friend V3D<V> mul (const V3D<V>& A, const V3D<V>& B);
};

// Implementation
//{
template <typename T>
void V3D<T>::set_ (T X, T Y, T Z) {
    x = X;
    y = Y;
    z = Z;
}

template <typename T>
T V3D<T>::get_x () {
    return x;
}

template <typename T>
T V3D<T>::get_y () {
    return y;
}

template <typename T>
T V3D<T>::get_z () {
    return z;
}

template <typename T>
T V3D<T>::module () {
    return sqrt (x * x + y * y + z * z);
}

template <typename T>
void V3D<T>::operator= (const V3D<T>& A) {
    x = A.x;
    y = A.y;
    z = A.z;
}

template <typename T>
V3D<T> V3D<T>::operator+ (const V3D<T>& A) {
    return V3D<T> (this->x + A.x, this->y + A.y, this->z + A.z);
}

template <typename T>
V3D<T>& V3D<T>::operator+= (const V3D<T>& A) {
    this->x += A.x;
    this->y += A.y;
    this->z += A.z;
    return *this;
}

template <typename T>
V3D<T> V3D<T>::operator- (const V3D<T>& A) {
    return V3D<T> (this->x - A.x, this->y - A.y, this->z - A.z);
}

template <typename T>
V3D<T>& V3D<T>::operator-= (const V3D<T>& A) {
    this->x -= A.x;
    this->y -= A.y;
    this->z -= A.z;
    return *this;
}

template <typename T>
V3D<T> V3D<T>::operator* (T A) {
    return V3D<T> (this->x * A, this->y * A, this->z * A);
}

// template<typename T>
// template<>
// V3D<T> V3D<T>::operator* <V3D<T>>(V3D<T> A)
// { return V3D<T>(this->y * A.z - this->z * A.y, - (this->x * A.z - this->z * A.x), this->x * A.y - this->y * A.x); }

template <typename T>
V3D<T> V3D<T>::operator/ (T Num) {
    return V3D<T> (this->x / Num, this->y / Num, this->z / Num);
}

template <typename T>
V3D<T> V3D<T>::from_polar (const V3D<T>& A) // r thetta fi
{
    return V3D<T> (A.x * sin (A.y) * cos (A.z), A.x * sin (A.y) * sin (A.z), A.x * cos (A.y));
}

template <typename T>
V3D<T> V3D<T>::from_polar (T r, T thetta, T fi) {
    return V3D<T> (r * sin (thetta) * cos (fi), r * sin (thetta) * sin (fi), r * cos (thetta));
}

template <typename T>
V3D<T> V3D<T>::normalize () {
    T length = this->module ();
    return length == 0 ? *this : *this / length;
}

template <typename T>
V3D<T> mul (const V3D<T>& A, const V3D<T>& B) {
    return V3D (A.y * B.z - A.z * B.y, -(A.x * B.z - A.z * B.x), A.x * B.y - A.y * B.x);
}

//}

#endif // V3D_GUARD