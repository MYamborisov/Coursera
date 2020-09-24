#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle : public Figure {
public:
    Triangle(int a, int b, int c) : _a(a), _b(b), _c(c) {}
    string Name() const override {
        return "TRIANGLE";
    }
    double Perimeter() const override {
        return static_cast<double>(_a + _b + _c);
    }
    double Area() const override {
        double p = static_cast<double>(_a + _b + _c) / 2;
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));
    }
private:
    const int _a, _b, _c;
};

class Rect : public Figure {
public:
    Rect(int w, int h) : width(w), height(h) {}
    string Name() const override {
        return "RECT";
    }
    double Perimeter() const override {
        return static_cast<double>(2 * (width + height));
    }
    double Area() const override {
        return static_cast<double>(width * height);
    }
private:
    const int width, height;
};

class Circle : public Figure {
public:
    Circle(int r) : radius(r) {}
    string Name() const override {
        return "CIRCLE";
    }
    double Perimeter() const override {
        return 2 * 3.14 * radius;
    }
    double Area() const override {
        return 3.14 * radius * radius;
    }
private:
    const int radius;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
    string type;
    shared_ptr<Figure> result;
    is >> type;
    if (type == "RECT") {
        int width, height;
        is >> width >> height;
        Rect rect(width, height);
        result = make_shared<Rect>(rect);
    } else if (type == "TRIANGLE") {
        int a, b, c;
        is >> a >> b >> c;
        Triangle tr(a, b, c);
        result = make_shared<Triangle>(tr);
    } else {
        int radius;
        is >> radius;
        Circle circ(radius);
        result = make_shared<Circle>(circ);
    }
    return result;
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}