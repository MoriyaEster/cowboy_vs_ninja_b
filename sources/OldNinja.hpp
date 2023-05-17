#pragma once

#include "Ninja.hpp"

namespace ariel
{

    class OldNinja : public Ninja
    {

    public:
        OldNinja(std::string name, Point location);
        OldNinja(const OldNinja& other); // copy constructor
        ~OldNinja(); // destructor

        bool operator==(const OldNinja& other) const; // operator== override
    };
}