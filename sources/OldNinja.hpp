#pragma once

#include "Ninja.hpp"

namespace ariel
{

    class OldNinja : public Ninja
    {

    public:
        OldNinja(std::string name, Point location);
        OldNinja(const OldNinja &other);
        OldNinja(OldNinja &&other) noexcept;
        virtual ~OldNinja();

        OldNinja &operator=(const OldNinja &other);
        bool operator==(const OldNinja &other) const;
        OldNinja &operator=(OldNinja &&other) noexcept;
    };
}