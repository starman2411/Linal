#ifndef LINAL_MATRIX2_H
#define LINAL_MATRIX2_H
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
template <typename T>
class Matrix2{
public:
    T a[2][2];

    Matrix2(T a11=0,T a12=0,T a21=0,T a22=0) {
        a[0][0] = a11;
        a[0][1] = a12;
        a[1][0] = a21;
        a[1][1] = a22;
    }
    Matrix2<T> operator +(const Matrix2<T> m){
        return Matrix2<T>(a[0][0]+m.a[0][0], a[0][1]+m.a[0][1],a[1][0]+m.a[1][0],a[1][1]+m.a[1][1]);
    }
    Matrix2<T> operator -(const Matrix2<T> m){
        return Matrix2(a[0][0]-m.a[0][0], a[0][1]-m.a[0][1],a[1][0]-m.a[1][0],a[1][1]-m.a[1][1]);
    }
    Matrix2<T> operator *(const double k){
        return Matrix2(a[0][0]*k, a[0][1]*k,a[1][0]*k,a[1][1]*k);
    }
    Matrix2<T> operator *(const Matrix2<T> m){
        return Matrix2<T>((a[0][0]*m.a[0][0]+a[0][1]*m.a[1][0]),(a[0][0]*m.a[0][1]+a[0][1]*m.a[1][1]),(a[1][0]*m.a[0][0]+a[1][1]*m.a[1][0]),(a[1][0]*m.a[0][1]+a[1][1]*m.a[1][1]));
    }
    double det(){
        return(a[0][0]*a[1][1]-a[0][1]*a[1][0]);
    }
    Matrix2<T> reverse(){
        if (abs(this->det())<0.000001){
            cout<<"ERROR: det=0";
            return(*this);
        }
        return Matrix2<T>(a[1][1]/this->det(),-a[0][1]/this->det(),-a[1][0]/this->det(),a[0][0]/this->det());
    }
    Matrix2<T> transpose(){
        return Matrix2<T>(a[1][1],a[1][0],a[0][1],a[0][0]);
    }
    void set_from_array(const T (&array)[4]){
        a[0][0] = array[0];
        a[0][1] = array[1];
        a[1][0] = array[2];
        a[1][1] = array[3];
    }
    int rank(){
        if (abs((a[0][0]/a[1][0])*a[1][1]-a[0][1])<0.000001) return(1);
        return(2);
    }

};
template <typename T>
Matrix2<T> operator *(const double k,const Matrix2<T> m){
    return Matrix2<T>(m.a[0][0]*k, m.a[0][1]*k,m.a[1][0]*k,m.a[1][1]*k);
}
template <typename T>
istream& operator>>(std::istream &is, Matrix2<T>& m){
    is>>m.a[0][0] ;
    is>>m.a[0][1] ;
    is>>m.a[1][0] ;
    is>>m.a[1][1] ;
    return(is);
};

template <typename T>
ostream& operator<<(std::ostream& os,const Matrix2<T>& m){
    os<<"{ {"<<m.a[0][0]<<" "<<m.a[0][1]<<"} , {"<<m.a[1][0]<<" "<<m.a[1][1]<<"} }";
    return(os);
};




#endif //LINAL_MATRIX2_H
