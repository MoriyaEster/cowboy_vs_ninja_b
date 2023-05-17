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
        Point(double x, double y);
        Point();
        Point(const Point& other);
        ~Point();

        double distance(Point dest);

        double getX() const;
        double getY() const;

        void print() const;

        Point moveTowards(Point src, Point dst, double dis);

        bool operator==(const Point& other) const;
        Point& operator=(const Point& other);
    };
}