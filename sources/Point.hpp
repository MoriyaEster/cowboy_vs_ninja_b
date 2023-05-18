#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <stdio.h>
#include <cmath>

namespace ariel
{

    class Point
    {
        double _x;
        double _y;

    public:
        Point(double _x_, double _y_);
        Point();
        Point(const Point &other);
        Point(Point &&other) noexcept;
        ~Point();

        double distance(Point dest);

        double getX() const;
        double getY() const;

        std::string print();

        static Point moveTowards(Point src, Point dst, double dis);

        bool operator==(const Point &other) const;
        Point &operator=(const Point &other);
        Point &operator=(Point &&other) noexcept;
    };
}