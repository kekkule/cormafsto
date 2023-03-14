#include "v3d.h"

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
template <typename N>
void V3D<T>::operator= (const V3D<N>& A) {
    x = A.x;
    y = A.y;
    z = A.z;
}

template <typename T>
template <typename N>
V3D<T> V3D<T>::operator+ (const V3D<N>& A) {
    return V3D<T> (this->x + A.x, this->y + A.y, this->z + A.z);
}

template <typename T>
template <typename N>
V3D<T>& V3D<T>::operator+= (const V3D<N>& A) {
    this->x += A.x;
    this->y += A.y;
    this->z += A.z;
    return *this;
}

template <typename T>
template <typename N>
V3D<T> V3D<T>::operator- (const V3D<N>& A) {
    return V3D<T> (this->x - A.x, this->y - A.y, this->z - A.z);
}

template <typename T>
template <typename N>
V3D<T>& V3D<T>::operator-= (const V3D<N>& A) {
    this->x -= A.x;
    this->y -= A.y;
    this->z -= A.z;
    return *this;
}

template <typename T>
template <typename N>
V3D<T> V3D<T>::operator* (N A) {
    return V3D<T> (this->x * Num, this->y * Num, this->z * Num);
}

// template<typename T>
// template<>
// V3D<T> V3D<T>::operator* <V3D<T>>(V3D<T> A)
// { return V3D<T>(this->y * A.z - this->z * A.y, - (this->x * A.z - this->z * A.x), this->x * A.y - this->y * A.x); }

template <typename T>
template <typename N>
V3D<T> V3D<T>::operator/ (N Num) {
    return V3D<T> (this->x / Num, this->y / Num, this->z / Num);
}

template <typename T>
template <typename N>
V3D<T> V3D<T>::from_polar (const V3D<N>& A) // r thetta fi
{
    return V3D<T> (A.x * sin (A.y) * cos (A.z), A.x * sin (A.y) * sin (A.z), A.x * cos (A.y));
}

template <typename T>
V3D<T> V3D<T>::from_polar (T r, T thetta, T fi) 
{
    return V3D<T> (r * sin (thetta) * cos (fi), r * sin (thetta) * sin (fi), r * cos (thetta));
}

template <typename T>
V3D<T> V3D<T>::normalize () {
    T length = this->module ();
    return length == 0 ? *this : *this / length;
}

template <typename T, typename N>
V3D<T> mul (const V3D<T>& A, const V3D<N>& B) {
    return V3D (A.y * B.z - A.z * B.y, -(A.x * B.z - A.z * B.x), A.x * B.y - A.y * B.x);
}