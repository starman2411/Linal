//
// Created by nikit on 21.03.2020.
//

#ifndef LINAL_MATRIX3_H
#define LINAL_MATRIX3_H
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
template <typename T>
class Matrix3 {
public:
    T a[3][3];

    Matrix3(T a11 = 0, T a12 = 0, T a13 = 0, T a21 = 0, T a22 = 0, T a23 = 0, T a31 = 0, T a32 = 0, T a33 = 0) {
        a[0][0] = a11;
        a[0][1] = a12;
        a[0][2] = a13;
        a[1][0] = a21;
        a[1][1] = a22;
        a[1][2] = a23;
        a[2][0] = a31;
        a[2][1] = a32;
        a[2][2] = a33;

    }

    Matrix3<T> operator+(const Matrix3<T> m) {
        T a11 = a[0][0] + m.a[0][0];
        T a12 = a[0][1] + m.a[0][1];
        T a13 = a[0][2] + m.a[0][2];
        T a21 = a[1][0] + m.a[1][0];
        T a22 = a[1][1] + m.a[1][1];
        T a23 = a[1][2] + m.a[1][2];
        T a31 = a[2][0] + m.a[2][0];
        T a32 = a[2][1] + m.a[2][1];
        T a33 = a[2][2] + m.a[2][2];
        return Matrix3<T>(a11, a12, a13, a21, a22, a23, a31, a32, a33);
    }

    Matrix3<T> operator-(const Matrix3<T> m) {
        T a11 = a[0][0] - m.a[0][0];
        T a12 = a[0][1] - m.a[0][1];
        T a13 = a[0][2] - m.a[0][2];
        T a21 = a[1][0] - m.a[1][0];
        T a22 = a[1][1] - m.a[1][1];
        T a23 = a[1][2] - m.a[1][2];
        T a31 = a[2][0] - m.a[2][0];
        T a32 = a[2][1] - m.a[2][1];
        T a33 = a[2][2] - m.a[2][2];
        return Matrix3<T>(a11, a12, a13, a21, a22, a23, a31, a32, a33);
    }

    Matrix3<T> operator*(const double k) {
        T a11 = a[0][0] * k;
        T a12 = a[0][1] * k;
        T a13 = a[0][2] * k;
        T a21 = a[1][0] * k;
        T a22 = a[1][1] * k;
        T a23 = a[1][2] * k;
        T a31 = a[2][0] * k;
        T a32 = a[2][1] * k;
        T a33 = a[2][2] * k;
        return Matrix3<T>(a11, a12, a13, a21, a22, a23, a31, a32, a33);
    }
    Matrix3<T> operator/(const double k) {
        T a11 = a[0][0] / k;
        T a12 = a[0][1] / k;
        T a13 = a[0][2] / k;
        T a21 = a[1][0] / k;
        T a22 = a[1][1] / k;
        T a23 = a[1][2] / k;
        T a31 = a[2][0] / k;
        T a32 = a[2][1] / k;
        T a33 = a[2][2] / k;
        return Matrix3<T>(a11, a12, a13, a21, a22, a23, a31, a32, a33);
    }

    Matrix3<T> operator*(const Matrix3<T> m) {
        T a11 = a[0][0] * m.a[0][0] + a[0][1] * m.a[1][0] + a[0][2] * m.a[2][0];
        T a12 = a[0][0] * m.a[0][1] + a[0][1] * m.a[1][1] + a[0][2] * m.a[2][1];
        T a13 = a[0][0] * m.a[0][2] + a[0][1] * m.a[1][2] + a[0][2] * m.a[2][2];
        T a21 = a[1][0] * m.a[0][0] + a[1][1] * m.a[1][0] + a[1][2] * m.a[2][0];
        T a22 = a[1][0] * m.a[0][1] + a[1][1] * m.a[1][1] + a[1][2] * m.a[2][1];
        T a23 = a[1][0] * m.a[0][2] + a[1][1] * m.a[1][2] + a[1][2] * m.a[2][2];
        T a31 = a[2][0] * m.a[0][0] + a[2][1] * m.a[1][0] + a[2][2] * m.a[2][0];
        T a32 = a[2][0] * m.a[0][1] + a[2][1] * m.a[1][1] + a[2][2] * m.a[2][1];
        T a33 = a[2][0] * m.a[0][2] + a[2][1] * m.a[1][2] + a[2][2] * m.a[2][2];
        return Matrix3<T>(a11, a12, a13, a21, a22, a23, a31, a32, a33);
    }

    double det() {
        return (a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * a[2][1] -
                a[0][2] * a[1][1] * a[2][0] - a[0][1] * a[1][0] * a[2][2] - a[0][0] * a[1][2] * a[2][1]);
    }

    Matrix3<T> reverse() {
        double d=this->det();
        if (abs(d)<0.000001){
            cout<<"ERROR: det = 0";
            return(*this);
        }
        T a11 = a[1][1] * a[2][2] - a[1][2] * a[2][1];cout<<"1: "<<a11<<endl;
        T a12 = -(a[1][0] * a[2][2] - a[1][2] * a[2][0]);cout<<"2: "<<a12<<endl;
        T a13 = a[1][0] * a[2][1] - a[1][1] * a[2][0];cout<<"3: "<<a13<<endl;
        T a21 = -(a[0][1] * a[2][2] - a[0][2] * a[2][1]);cout<<"4: "<<a21<<endl;
        T a22 = a[0][0] * a[2][2] - a[0][2] * a[2][0];cout<<"5: "<<a22<<endl;
        T a23 = -(a[0][0] * a[2][1] - a[0][1] * a[2][0]);cout<<"6: "<<a23<<endl;
        T a31 = a[0][1] * a[1][2] - a[0][2] * a[1][1];cout<<"7: "<<a31<<endl;
        T a32 = -(a[0][0] * a[1][2] - a[0][2] * a[1][0]);cout<<"8: "<<a32<<endl;
        T a33 = a[0][0] * a[1][1] - a[0][1] * a[1][0];cout<<"9: "<<a33<<endl;
        Matrix3<T> A(a11, a12, a13, a21, a22, a23, a31, a32, a33);
        A=A.transpose();
        d=1/d;
        return A*d;
    }

    Matrix3<T> transpose() {
        return Matrix3<T>(a[0][0], a[1][0], a[2][0], a[0][1], a[1][1], a[2][1], a[0][2], a[1][2], a[2][2]);
    }

    void set_from_array(const T (&array)[9]) {
        a[0][0] = array[0];
        a[0][1] = array[1];
        a[0][2] = array[2];
        a[1][0] = array[3];
        a[1][1] = array[4];
        a[1][2] = array[5];
        a[2][0] = array[6];
        a[2][1] = array[7];
        a[2][2] = array[8];
    }

    int rank() {
        int r = 3;
        if (abs((a[0][0] / a[1][0]) * a[1][1] - a[0][1]) < 0.000001) {
            if (abs((a[0][0] / a[1][0]) * a[1][2] - a[0][2]) < 0.000001) { r--; }
        }
        if (abs((a[1][0] / a[2][0]) * a[2][1] - a[1][1]) < 0.000001) {
            if (abs((a[1][0] / a[2][0]) * a[2][2] - a[1][2]) < 0.000001) { r--; }
        }
        if (abs((a[0][0] / a[2][0]) * a[2][1] - a[0][1]) < 0.000001) {
            if ((abs((a[0][0] / a[2][0]) * a[2][2] - a[0][2]) < 0.000001) && (r > 1)) { r--; }
        }

        return (r);
    }

};
        template<typename T>
        Matrix3<T> operator*(const double k, const Matrix3<T> m) {
            T a11 = m.a[0][0] * k;
            T a12 = m.a[0][1] * k;
            T a13 = m.a[0][2] * k;
            T a21 = m.a[1][0] * k;
            T a22 = m.a[1][1] * k;
            T a23 = m.a[1][2] * k;
            T a31 = m.a[2][0] * k;
            T a32 = m.a[2][1] * k;
            T a33 = m.a[2][2] * k;
            return Matrix3<T>(a11, a12, a13, a21, a22, a23, a31, a32, a33);
        }
        template<typename T>
        istream& operator>>(std::istream &is, Matrix3<T> &m) {
            is >> m.a[0][0];
            is >> m.a[0][1];
            is >> m.a[0][2];
            is >> m.a[1][0];
            is >> m.a[1][1];
            is >> m.a[1][2];
            is >> m.a[2][0];
            is >> m.a[2][1];
            is >> m.a[2][2];
            return (is);
        };

        template<typename T>
        ostream &operator<<(std::ostream &os, const Matrix3<T> &m) {
            os << "{ {" << m.a[0][0] << " " << m.a[0][1] << " " << m.a[0][2]<<
            "}, {" << m.a[1][0] << " " << m.a[1][1] << " " << m.a[1][2]<<
            "}, {" << m.a[2][0] << " " << m.a[2][1] << " " << m.a[2][2]<<
            "} }";
            return (os);
        };


#endif //LINAL_MATRIX3_H
