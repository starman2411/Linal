//
// Created by nikit on 22.03.2020.
//

#ifndef LINAL_POINT3D_H
#define LINAL_POINT3D_H
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;


template <typename T>
class Point3D {
private:
    T x,y,z;
public:
    Point3D(T x=0, T y=0){
        this->x=x;
        this->y=y;
        this->z=z;
    }
    void set_X(T x){
        this->x=x;
    }
    void set_Y(T y){
        this->y=y;
    }
    void set_Z(T z){
        this->z=z;
    }
    T get_X()const{
        return(this->x);
    }
    T get_Y()const{
        return(this->y);
    }
    T get_Z()const{
        return(this->z);
    }

};







#endif //LINAL_POINT3D_H
