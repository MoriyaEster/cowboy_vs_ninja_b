#pragma once

#include "Ninja.hpp"

namespace ariel
{

    class YoungNinja : public Ninja
    {

    public:
        YoungNinja(std::string name, Point location);
        YoungNinja(const YoungNinja &other);
        ~YoungNinja();
        bool operator==(const YoungNinja &other) const;
    };
}