//
// Created by asaf7 on 5/9/2023.
//

#include "OldNinja.hpp"
namespace ariel {
        OldNinja::OldNinja(const string &name, const Point &location) : Ninja(name,location) {
            this->setHealthPoints(150);
            this->setSpeed(8);
        }
} // ariel