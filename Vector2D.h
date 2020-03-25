
#ifndef LINAL_VECTOR2D_H
#define LINAL_VECTOR2D_H
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
template <typename T>
class Vector2D{
private:
    T x,y;
public:
    Vector2D(T x,T y){
        this->x=x;
        this->y=y;
    }
    void set_x(T x){
        this->x=x;
    }
    void set_y(T y){
        this->y=y;
    }
    T get_x() const{
        return(x);
    }
    T get_y() const{
        return(y);
    }
    double length()const{
        return(sqrt(x*x+y*y));
    }
    double get_angle(const Vector2D<T> vec)const{
        return ((180/3.14159265)*acos((x*vec.get_x()+y*vec.get_y())/this->length()/vec.length()));
    }

    double operator *(const Vector2D<T> vec){
        return(x*vec.get_x()+y*vec.get_y());
    }
    Vector2D<T> operator *(const double a){
        return(Vector2D<T>(x*a,y*a));
    }
    Vector2D<T> operator /(const double a){
        return(Vector2D<T>(x/a,y/a));
    }

    Vector2D<T> operator +(const Vector2D<T> vec){
        return Vector2D<T>(x+vec.get_x(),y+vec.get_y());
    }
    Vector2D<T> operator -(const Vector2D<T> vec){
        return Vector2D<T>(x-vec.get_x(),y-vec.get_y());
    }
    bool operator ==(const Vector2D<T> vec){
        return((x==vec.get_x())&&(y==vec.get_y()));
    }
    bool operator !=(const Vector2D<T> vec){
        return((x!=vec.get_x())||(y!=vec.get_y()));
    }
    bool operator >(const Vector2D<T> vec){
        return((this->length() > vec.length()));
    }
    bool operator <(const Vector2D<T> vec){
        return((this->length() < vec.length()));
    }
};

template <typename T>
Vector2D<T> operator *(const double a, const Vector2D<T> vec){
    return Vector2D<T> (vec.get_x()*a,vec.get_y()*a);
}


template <typename T>
ostream& operator<<(std::ostream& os,const Vector2D<T>& vec){
    os<<"{"<<vec.get_x()<<" , "<<vec.get_y()<<"}";
    return(os);
};

template <typename T>
istream& operator>>(std::istream &is, Vector2D<T>& vec){
    is>>vec.set_x();
    is>>vec.set_y();
    return(is);
};

#endif //LINAL_VECTOR2D_H
