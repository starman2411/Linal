# Linal
 This assembly is a set of geometric tools(Point(2D,3D),Vector(2D,3D),Matrix(2x2,3x3)) that make it easier to work with geometry.
## Point2D
###### Шаблонизированный класс для работы с точками в двумерии

 `Point2D(T x=0, T y=0)` -конструктор принимает координаты x и y  
        
 `set_X(T x)` - задать x  
 
 `set_Y(T y)` - задать y  

 `get_X()` - получить x  
 
 `get_Y()` - получить y  

 `rotate(double angle, Point2D<T> axis = (0,0) )` - повернуть точку на угол `angle` вокруг точки `axis` (если `axis` не указана, поворот   осуществляется вокруг начала координат.  


## Point3D
###### Шаблонизированный класс для работы с точками в трёхмерии

 `Point3D(T x=0, T y=0, T z=0)` -конструктор принимает координаты x,y,z
        
 `set_X(T x)` - задать x  
 
 `set_Y(T y)` - задать y  
 
 `set_Z(T z)` - задать z  

 `T get_X()` - получить x  
 
 `T get_Y()` - получить y  
 
 `T get_Z()` - получить z  

## Vector2D
###### Шаблонизированный класс для работы с векторами в двумерии


`Vector2D(T x,T y)` - конструктор принимает две координаты x,y

`void set_x(T x)` -задать x

`void set_y(T y)` -задать y

`T get_x()` -получить x

`T get_y()` -получить y

`double length()` - возвращает длину вектора

`double get_angle(const Vector2D<T> vec)` - возвращает угол между векторами

Перегружены операторы:

* `double operator *(const Vector2D<T> vec)`  - скалярное произведение

* `Vector2D<T> operator *(const double a)`

* `Vector2D<T> operator /(const double a)`

* `Vector2D<T> operator +(const Vector2D<T> vec)`

* `Vector2D<T> operator -(const Vector2D<T> vec)`

* `bool operator ==(const Vector2D<T> vec)`

* `bool operator !=(const Vector2D<T> vec)`

* `bool operator >(const Vector2D<T> vec)`

* `bool operator <(const Vector2D<T> vec)`

* `Vector2D<T> operator *(const double a, const Vector2D<T> vec)`

* `ostream& operator<<(std::ostream& os,const Vector2D<T>& vec)`

* `istream& operator>>(std::istream &is, Vector2D<T>& vec)`


## Vector3D
###### Шаблонизированный класс для работы с векторами в трёхмерии


`Vector2D(T x,T y)` - конструктор принимает три координаты x,y,z

`void set_x(T x)` -задать x

`void set_y(T y)` -задать y

`void set_z(T z)` -задать z

`T get_x()` -получить x

`T get_y()` -получить y

`T get_z()` -получить z

`double length()` - возвращает длину вектора

`double get_angle(const Vector3D<T> vec)` - возвращает угол между векторами

`double scalar(const Vector3D<T> vec)` - возвращает резултат скалярного произведения

Перегружены операторы:

* `double operator *(const Vector3D<T> vec)` - векторное произведение

* `Vector3D<T> operator *(const double a)` 

* `Vector3D<T> operator /(const double a)`

* `Vector3D<T> operator +(const Vector3D<T> vec)`

* `Vector3D<T> operator -(const Vector3D<T> vec)`

* `bool operator ==(const Vector3D<T> vec)`

* `bool operator !=(const Vector3D<T> vec)`

* `bool operator >(const Vector3D<T> vec)`

* `bool operator <(const Vector3D<T> vec)`

* `Vector3D<T> operator *(const double a, const Vector3D<T> vec)`

* `ostream& operator<<(std::ostream& os,const Vector3D<T>& vec)`

* `istream& operator>>(std::istream &is, Vector3D<T>& vec)`


## Matrix2
###### Шаблонизированный класс для работы с матрицами 2x2


  `Matrix2(T a11=0,T a12=0,T a21=0,T a22=0)` - конструктор принимает на вход 4 элемента (построчно)

  `double det()` - возвращает детерминант
  
  `Matrix2<T> reverse()` - возвращает обратную матрицу (в случае невозможности операции выводит сообщение об ошибке и возвращает исходную матрицу)
  
  `Matrix2<T> transpose()` - транспонирует матрицу
  
  `void set_from_array(const T (&array)[4])` - задёт значения элементов из одномерного массива (построчно)
  
  `int rank()` - возвращает ранг матрицы
    
Перегружены операторы:    
* `Matrix2<T> operator +(const Matrix2<T> m)`

* `Matrix2<T> operator -(const Matrix2<T> m)`

* `Matrix2<T> operator *(const double k)`

* `Matrix2<T> operator *(const Matrix2<T> m)`

* `Matrix2<T> operator *(const double k,const Matrix2<T> m)`

* `istream& operator>>(std::istream &is, Matrix2<T>& m)`

* `ostream& operator<<(std::ostream& os,const Matrix2<T>& m)`



## Matrix3
###### Шаблонизированный класс для работы с матрицами 3x3


  `Matrix3(T a11 = 0, T a12 = 0, T a13 = 0, T a21 = 0, T a22 = 0, T a23 = 0, T a31 = 0, T a32 = 0, T a33 = 0)` - конструктор принимает на вход 9 элементов (построчно)

  `double det()` - возвращает детерминант
  
  `Matrix3<T> reverse()` - возвращает обратную матрицу (в случае невозможности операции выводит сообщение об ошибке и возвращает исходную матрицу)
  
  `Matrix3<T> transpose()` - транспонирует матрицу
  
  `void set_from_array(const T (&array)[9])` - задёт значения элементов из одномерного массива (построчно)
  
  `int rank()` - возвращает ранг матрицы
    
Перегружены операторы:    
* `Matrix3<T> operator +(const Matrix3<T> m)`

* `Matrix3<T> operator -(const Matrix3<T> m)`

* `Matrix3<T> operator *(const double k)`

* `Matrix3<T> operator *(const Matrix3<T> m)`

* `Matrix3<T> operator *(const double k,const Matrix3<T> m)`

* `istream& operator>>(std::istream &is, Matrix3<T>& m)`

* `ostream& operator<<(std::ostream& os,const Matrix3<T>& m)`


