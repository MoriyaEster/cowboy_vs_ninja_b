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

    Point::Point(const Point &other)
    {
        _x = other.getX();
        _y = other.getY();
    }

    Point::Point(Point &&other) noexcept
        : _x(other.getX()), _y(other.getY())
    {
    }

    Point::~Point()
    {
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

    std::string Point::print()
    {
        std::ostringstream oss;
        oss << "(" << _x << "," << _y << ")";
        return oss.str();
    }

    Point Point::moveTowards(Point src, Point dst, double dis)
    {
        if (dis < 0)
        {
            throw std::invalid_argument("invalid distance");
        }
        double dx = dst.getX() - src.getX();
        double dy = dst.getY() - src.getY();
        double distance = std::sqrt(dx * dx + dy * dy);

        if (distance <= dis)
        {
            return dst;
        }

        double ratio = dis / distance;

        double newX = src.getX() + (dx * ratio);
        double newY = src.getY() + (dy * ratio);

        return Point(newX, newY);
    }

    bool Point::operator==(const Point &other) const
    {
        return (_x == other.getX() && _y == other.getY());
    }

    Point &Point::operator=(const Point &other)
    {
        if (this != &other)
        {
            _x = other._x;
            _y = other._y;
        }
        return *this;
    }

    Point &Point::operator=(Point &&other) noexcept
    {
        if (this != &other)
        {
            _x = other._x;
            _y = other._y;
        }
        return *this;
    }
}