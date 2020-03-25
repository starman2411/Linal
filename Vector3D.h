//
// Created by nikit on 22.03.2020.
//

#ifndef LINAL_VECTOR3D_H
#define LINAL_VECTOR3D_H
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
template <typename T>
class Vector3D{
private:
    T x,y,z;
public:
    Vector3D(T x,T y,T z){
        this->x=x;
        this->y=y;
        this->z=z;
    }
    void set_x(T x){
        this->x=x;
    }
    void set_y(T y){
        this->y=y;
    }
    void set_z(T z){
        this->z=z;
    }
    T get_x() const{
        return(x);
    }
    T get_y() const{
        return(y);
    }
    T get_z() const{
        return(z);
    }
    double length()const{
        return(sqrt(x*x+y*y+z*z));
    }
    double get_angle(const Vector3D<T> vec)const{
        return ((180/3.14159265)*acos((x*vec.get_x()+y*vec.get_y()+z*vec.get_z())/this->length()/vec.length()));
    }
    double scalar(const Vector3D<T> vec)const{
        return(x*vec.get_x()+y*vec.get_y()+z*vec.get_z());
    }

    Vector3D<T> operator *(const Vector3D<T> vec){
        return(y*vec.get_z()-z*vec.get_y(),-(x*vec.get_y()-z*vec.get_x()),x*vec.get_y()-y*vec.get_x());
    }
    Vector3D<T> operator *(const double a){
        return(Vector2D<T>(x*a,y*a,z*a));
    }
    Vector3D<T> operator /(const double a){
        return(Vector2D<T>(x/a,y/a,z/a));
    }

    Vector3D<T> operator +(const Vector3D<T> vec){
        return Vector2D<T>(x+vec.get_x(),y+vec.get_y(),z+vec.get_z());
    }
    Vector3D<T> operator -(const Vector3D<T> vec){
        return Vector2D<T>(x-vec.get_x(),y-vec.get_y(),z-vec.get_z());
    }
    bool operator ==(const Vector3D<T> vec){
        return((x==vec.get_x())&&(y==vec.get_y())&&(z==vec.get_z()));
    }
    bool operator !=(const Vector3D<T> vec){
        return((x!=vec.get_x())||(y!=vec.get_y())||(z!=vec.get_z()));
    }
    bool operator >(const Vector3D<T> vec){
        return((this->length() > vec.length()));
    }
    bool operator <(const Vector3D<T> vec){
        return((this->length() < vec.length()));
    }
};

template <typename T>
Vector3D<T> operator *(const double a, const Vector3D<T> vec){
    return Vector3D<T> (vec.get_x()*a,vec.get_y()*a,vec.get_z()*a);
}


template <typename T>
ostream& operator<<(std::ostream& os,const Vector3D<T>& vec){
    os<<"{"<<vec.get_x()<<" , "<<vec.get_y()<<" , "<<vec.get_z()<<"}";
    return(os);
};

template <typename T>
istream& operator>>(std::istream &is, Vector3D<T>& vec){
    T x,y,z;
    is>>x>>y>>z;
    vec.set_x(x);
    vec.set_y(y);
    vec.set_z(z);
    return(is);
};


#endif //LINAL_VECTOR3D_H
