#include "v3d.h"

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
template <typename N>
V3D<T> V3D<T>::operator* (N A) {
    return V3D<T> (this->x * Num, this->y * Num, this->z * Num);
}

// template<typename T>
// template<>
// V3D<T> V3D<T>::operator* <V3D<T>>(V3D<T> A)
// { return V3D<T>(this->y * A.z - this->z * A.y, - (this->x * A.z - this->z * A.x), this->x * A.y - this->y * A.x); }

template <typename T>
V3D<T> mul (const V3D<T>& A, const V3D<T>& B) {
    return V3D (A.y * B.z - A.z * B.y, -(A.x * B.z - A.z * B.x), A.x * B.y - A.y * B.x);
}

template <typename T>
template <typename N>
V3D<T> V3D<T>::operator/ (N Num) {
    return V3D<T> (this->x / Num, this->y / Num, this->z / Num);
}

template <typename T>
V3D<T> V3D<T>::from_polar (const V3D<T>& A) // a thetta fi
{
    return V3D<T> (A.x * sin (A.y) * cos (A.z), A.x * sin (A.y) * sin (A.z), A.x * cos (A.y));
}

template <typename T>
V3D<T> V3D<T>::normalize () {
    T length = this->module ();
    return length == 0 ? *this : *this / length;
}
