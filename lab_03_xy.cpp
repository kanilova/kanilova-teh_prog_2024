#include <iostream>
#include <cmath>

class Point {

public:
    double x, y;

    Point(double x, double y) : x(x), y(y) {}
    virtual ~Point() {}

    virtual void draw() {
        std::cout << "Point at (" << x << ", " << y << ")" << std::endl;
    }

    void erase() {
        std::cout << "Erasing point..." << std::endl;
    }

    void move(double dx, double dy) {
        x += dx;
        y += dy;
        std::cout << "Moving point to (" << x << ", " << y << ")" << std::endl;
    }

    void rotate(double angle) {
        double new_x = x * cos(angle) - y * sin(angle);
        double new_y = x * sin(angle) + y * cos(angle);
        x = new_x;
        y = new_y;
        std::cout << "Rotating point..." << std::endl;
    }

    virtual double distanceTo(Point& other) {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx*dx + dy*dy);
    }
};

class Shape {
public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void rotate(double angle) = 0;
};

class Line : public Shape {
protected:
    Point start, end;

public:
    Line(const Point& start, const Point& end) : start(start), end(end) {}

    void draw() override {
        std::cout << "Drawing line from (" << start.x << ", " << start.y << ") to ("
                  << end.x << ", " << end.y << ")" << std::endl;
    }

    void erase() override {
        std::cout << "Erasing line..." << std::endl;
    }

    void move(double dx, double dy) override {
        start.move(dx, dy);
        end.move(dx, dy);
        std::cout << "Moving line..." << std::endl;
    }

    void rotate(double angle) override {
        start.rotate(angle);
        end.rotate(angle);
        std::cout << "Rotating line..." << std::endl;
    }
};

class Quadrilateral : public Shape {
public:
    
};

class Square : public Quadrilateral, public Point {
protected:
    double side;

public:
    Square(double x, double y, double side) : Point(x, y), side(side) {}

    void draw() override {
        std::cout << "Drawing square at (" << x << ", " << y << ") with side length " << side << std::endl;
    }

    void erase() override {
        std::cout << "Erasing square..." << std::endl;
    }

    void move(double dx, double dy) override {
        x += dx;
        y += dy;
        std::cout << "Moving square to (" << x << ", " << y << ")" << std::endl;
    }

    void rotate(double angle) override {
         
    
        double s = x + side - side * cos(angle * M_PI / 180)*
         x - side * sin(angle * M_PI / 180);
    
    }

   
};
class rhombus : public Quadrilateral, public Point {
protected:
    double side;

public:
    rhombus(double x, double y, double side) : Point(x, y), side(side) {}

    void draw() override {
        std::cout << "Drawing rhombus at (" << x << ", " << y << ") with side length " << side << std::endl;
    }

    void erase() override {
        std::cout << "Erasing rhombus..." << std::endl;
    }

    void move(double dx, double dy) override {
        x += dx;
        y += dy;
        std::cout << "Moving rhombus to (" << x << ", " << y << ")" << std::endl;
    }

    void rotate(double angle) override {
         
    
        double s = x + side - side * cos(angle * M_PI / 180)*
         x - side * sin(angle * M_PI / 180);
    
    }

   
};


class rechandle : public Quadrilateral, public Point {
protected:
    double side;

public:
    rechandle(double x, double y, double side) : Point(x, y), side(side) {}

    void draw() override {
        std::cout << "Drawing rechandle at (" << x << ", " << y << ") with side length " << side << std::endl;
    }

    void erase() override {
        std::cout << "Erasing rechandle..." << std::endl;
    }

    void move(double dx, double dy) override {
        x += dx;
        y += dy;
        std::cout << "Moving rechandle to (" << x << ", " << y << ")" << std::endl;
    }

    void rotate(double angle) override {
        double s = x + side - side * cos(angle * M_PI / 180)*
         x - side * sin(angle * M_PI / 180);
        
    }

    
};
class  parallerodram : public Quadrilateral, public Point {
protected:
    double side;

public:
    parallerodram(double x, double y, double side) : Point(x, y), side(side) {}

    void draw() override {
        std::cout << "Drawing parallerodram at (" << x << ", " << y << ") with side length " << side << std::endl;
    }

    void erase() override {
        x=0;//
        y=0;
        std::cout << "Erasing parallerodram..." << std::endl;
    }

    void move(double dx, double dy) override {
        x += dx;
        y += dy;
        std::cout << "Moving parallerodram to (" << x << ", " << y << ")" << std::endl;
    }

    void rotate(double angle) override {
    
        double s = x + side - side * cos(angle * M_PI / 180)*
         x - side * sin(angle * M_PI / 180);
    
    }

    
};


// Пример использования классов
int main() {
    Point p1(0, 0);
    Point p2(3, 4);

    p1.draw();
    p2.draw();

    Line l(p1, p2);
    l.draw();
    
    Square Squ(2,3,6);
    Squ.draw();
    Squ.erase();
    Squ.move(2,4);
    Squ.rotate(30);
    
    
    rhombus Romb(2,3,6);
    Romb.draw();
    Romb.erase();
    Romb.move(2,4);
    Romb.rotate(30);
    
    rechandle Prim(4,5,6);
    Prim.draw();
    Prim.erase();
    Prim.move(3,4);
    Prim.rotate(60);
    
    parallerodram Parll(4,5,6);
    Parll.draw();
    Parll.erase();
    Parll.move(3,4);
    Parll.rotate(60);
    
    

   
    return 0;
}