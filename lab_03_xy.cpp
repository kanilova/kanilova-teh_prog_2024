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
    
    void print_info() {
        std::cout << "Point coordinates: (" << x << ", " << y << ")" << std::endl;
    }
};

class Shape {
public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void rotate(double angle) = 0;
    virtual void print_info() = 0;
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
    
    void print_info() override {
        std::cout << "Line coordinates: " << std::endl;
        start.print_info();
        end.print_info();
    }
};

class Quadrilateral : public Shape {
public:
    virtual ~Quadrilateral() {}
    virtual void print_info() = 0;
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
        double new_x = x * cos(angle) - y * sin(angle);
        double new_y = x * sin(angle) + y * cos(angle);
        x = new_x;
        y = new_y;
        std::cout << "Rotating square..." << std::endl;
    }
    
    void print_info() override {
        std::cout << "Square coordinates: (" << x << ", " << y << ")" << std::endl;
        std::cout << "Side length: " << side << std::endl;
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
        double new_x = x * cos(angle) - y * sin(angle);
        double new_y = x * sin(angle) + y * cos(angle);
        x = new_x;
        y = new_y;
        std::cout << "Rotating rhombus..." << std::endl;
    }
    
    void print_info() override {
        std::cout << "Rhombus coordinates: (" << x << ", " << y << ")" << std::endl;
        std::cout << "Side length: " << side << std::endl;
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
        double new_x = x * cos(angle) - y * sin(angle);
        double new_y = x * sin(angle) + y * cos(angle);
        x = new_x;
        y = new_y;
        std::cout << "Rotating rechandle..." << std::endl;
    }
    
    void print_info() override {
        std::cout << "Rechandle coordinates: (" << x << ", " << y << ")" << std::endl;
        std::cout << "Side length: " << side << std::endl;
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
        double new_x = x * cos(angle) - y * sin(angle);
        double new_y = x * sin(angle) + y * cos(angle);
        x = new_x;
        y = new_y;
        std::cout << "Rotating parallerodram..." << std::endl;
    }
    
    void print_info() override {
        std::cout << "Parallerodram coordinates: (" << x << ", " << y << ")" << std::endl;
        std::cout << "Side length: " << side << std::endl;
    }
};

// ?????? ????????????? ???????
int main() {
    Point p1(0, 0);
    Point p2(3, 4);

    p1.draw();
    p2.draw();
    std::cout << std::endl;
    
    Line l(p1, p2);
    l.draw();
    std::cout << std::endl;
  
    Square Squ(2,3,6);
    Squ.draw();
    Squ.move(2,4);
    Squ.rotate(30);
    Squ.print_info();
    Squ.erase();
    std::cout << std::endl;

    
    rhombus Romb(2,3,6);
    Romb.draw();
    Romb.move(2,4);
    Romb.rotate(30);
    Romb.print_info();
    Romb.erase();
    std::cout << std::endl;

    rechandle Prim(4,5,6);
    Prim.draw();
    Prim.move(3,4);
    Prim.rotate(60);
    Prim.print_info();
    Prim.erase();
    std::cout << std::endl;

    parallerodram Parll(4,5,6);
    Parll.draw();
    Parll.move(3,4);
    Parll.rotate(60);
    Parll.print_info();
    Parll.erase();
    std::cout << std::endl;

    return 0;
}

