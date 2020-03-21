# Linal
 This assembly is a set of geometric tools(Point(2D,3D),Vector(2D,3D),Matrix(2x2,3x3)) that make it easier to work with geometry.
## Point 2D

public:
    Point2D(T x=0, T y=0){
        this->x=x;
        this->y=y;
'set_X(T x)' 
    void set_Y(T y){
        this->y=y;
    }
    T get_X()const{
        return(this->x);
    }
    T get_Y()const{
        return(this->y);
    }
    void rotate(double angle, Point2D<T> axis = (0,0) ){
        double degree=angle*3.14159265/180;
        T new_x=cos(degree)*(this->x - axis.get_X())+sin(degree)*(this->y - axis.get_Y())+axis.get_X();
        T new_y=cos(degree)*(this->y - axis.get_Y())-sin(degree)*(this->x - axis.get_X())+axis.get_Y();
        if (abs(new_x)<0.000001) {new_x=0;}
        if (abs(new_y)<0.000001) {new_y=0;}
        this->x=new_x;
        this->y=new_y;
    }
};
