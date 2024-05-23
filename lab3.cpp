#include <iostream>
#include <cmath>

// Базовый абстрактный класс "Точка"
class Point {
protected:
    double x, y;

public:
    Point(double x, double y) : x(x), y(y) {}
    virtual void display() const = 0;
    virtual void move(double dx, double dy) {
        x += dx;
        y += dy;
    }
    virtual void rotate(double angle) {
        double newX = x * cos(angle) - y * sin(angle);
        double newY = x * sin(angle) + y * cos(angle);
        x = newX;
        y = newY;
    }
};

// Класс "Линия"
class Line : public Point {
private:
    double length;

public:
    Line(double x1, double y1, double x2, double y2) : Point((x1 + x2) / 2, (y1 + y2) / 2), length(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))) {}
    void display() const override {
        std::cout << "Линия: (" << x << ", " << y << "), длина: " << length << std::endl;
    }
};

// Класс "Квадрат"
class Square : public Point {
private:
    double side;

public:
    Square(double x, double y, double side) : Point(x, y), side(side) {}
    void display() const override {
        std::cout << "Квадрат: (" << x << ", " << y << "), сторона: " << side << std::endl;
    }
};

// Класс "Ромб"
class Rhombus : public Point {
private:
    double diagonal1, diagonal2;

public:
    Rhombus(double x, double y, double d1, double d2) : Point(x, y), diagonal1(d1), diagonal2(d2) {}
    void display() const override {
        std::cout << "Ромб: (" << x << ", " << y << "), диагонали: " << diagonal1 << ", " << diagonal2 << std::endl;
    }
};

// Класс "Прямоугольник"
class Rectangle : public Point {
private:
    double width, height;

public:
    Rectangle(double x, double y, double w, double h) : Point(x, y), width(w), height(h) {}
    void display() const override {
        std::cout << "Прямоугольник: (" << x << ", " << y << "), ширина: " << width << ", высота: " << height << std::endl;
    }
};

// Класс "Параллелограмм"
class Parallelogram : public Point {
private:
    double base, height;

public:
    Parallelogram(double x, double y, double b, double h) : Point(x, y), base(b), height(h) {}
    void display() const override {
        std::cout << "Параллелограмм: (" << x << ", " << y << "), основание: " << base << ", высота: " << height << std::endl;
    }
};

int main() {
    // Создание объектов геометрических фигур
    Line line(0, 0, 5, 5);
    Square square(2, 2, 4);
    Rhombus rhombus(3, 3, 6, 4);
    Rectangle rectangle(4, 4, 6, 4);
    Parallelogram parallelogram(5, 5, 6, 4);

    // Демонстрация методов
    std::cout << "До перемещения и поворота:" << std::endl;
    line.display();
    square.display();
    rhombus.display();
    rectangle.display();
    parallelogram.display();

    std::cout << "\nПосле перемещения и поворота:" << std::endl;
    line.move(2, 2);
    line.rotate(M_PI / 4);
    square.move(1, 1);
    square.rotate(M_PI / 2);
    rhombus.move(-1, -1);
    rhombus.rotate(M_PI / 6);
    rectangle.move(2, 2);
    rectangle.rotate(M_PI / 3);
    parallelogram.move(1, 1);
    parallelogram.rotate(M_PI / 4);

    line.display();
    square.display();
    rhombus.display();
    rectangle.display();
    parallelogram.display();

    return 0;
}
