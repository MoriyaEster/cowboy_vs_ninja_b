#include "Point.hpp"

namespace ariel
{

    using namespace std;

    Point::Point(double x, double y)
    {
        _x = x;
        _y = y;
    }

    Point::Point()
    {
        _x = 0.0;
        _y = 0.0;
    }

    Point::Point(const Point& other)
    {
        _x = other.getX();
        _y = other.getY();
    }

    Point::~Point()
    {
        // Destructor code goes here (if needed)
    }

    double Point::distance(Point dest)
    {
        double dx = dest.getX() - _x;
        double dy = dest.getY() - _y;
        return std::sqrt(dx * dx + dy * dy);
    }

    double Point::getX() const
    {
        return this->_x;
    }

    double Point::getY() const
    {
        return this->_y;
    }

    void Point::print() const
    {
        cout << "(" << _x << "," << _y << ")" << endl;
    }

    Point Point::moveTowards(Point src, Point dst, double dis)
    {
        return src;
    }

    bool Point::operator==(const Point& other) const
    {
        return (_x == other.getX() && _y == other.getY());
    }

    Point& Point::operator=(const Point& other)
    {
        if (this != &other)
        {
            _x = other._x;
            _y = other._y;
        }
        return *this;
    }
}