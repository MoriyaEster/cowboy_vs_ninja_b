#pragma once

#include "Ninja.hpp"

namespace ariel
{

    class YoungNinja : public Ninja
    {

    public:
        YoungNinja(std::string name, Point location);
        YoungNinja(const YoungNinja &other);
        YoungNinja(YoungNinja &&other) noexcept;
        ~YoungNinja();

        bool operator==(const YoungNinja &other) const;
        YoungNinja &operator=(const YoungNinja &other);
        YoungNinja &operator=(YoungNinja &&other) noexcept;
    };
}