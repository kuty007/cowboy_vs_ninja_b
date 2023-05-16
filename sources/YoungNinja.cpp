//
// Created by asaf7 on 5/9/2023.
//

#include "YoungNinja.hpp"

namespace ariel {

    YoungNinja::YoungNinja(const string &name, const Point &location) : Ninja(
            name, location) {
        this->setHealthPoints(100);
        this->setSpeed(14);
    }
} // ariel