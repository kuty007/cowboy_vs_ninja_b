//
// Created by asaf7 on 5/9/2023.
//

#include "Ninja.hpp"

namespace ariel {

    void Ninja::move(const Character *other) {
        this->setLocation(this->getLocation().moveTowards(other->getLocation(), this->speed))  ;
    }

    void Ninja::slash(Character *other) {
        if (this == other) {
            throw std::runtime_error("Character cannot attack itself");
        }
        if (!this->isAlive() ) {
            throw std::runtime_error("Character is dead");;
        }
        if (!other->isAlive()){
            throw std::runtime_error("enemy is dead");;
        }
        if (this->distance(other) <= 1) {
            other->hit(40);
            if (other->getHealthPoints() <= 0) {
                other->setHealthPoints(0);
                other->setAlive(false);
            }
        }
    }




    string Ninja::print() const {
        if (this->isAlive()) {
            return "(N)" + this->getName() + " " + to_string(this->getHealthPoints()) + " " + this->getLocation().print();
        } else {
            return "(N)" + this->getName() + " " + this->getLocation().print();
        }
    }


    Ninja::Ninja(const string &name, const Point &location) : Character(name, location, 100) {
        this->setAlive(true);
        this->setIsCowboy(false);
    }

    void Ninja::attack(Character *other) {
        if (!this->isAlive() ) {
            throw std::runtime_error("Character is dead");;
        }
        if (!other->isAlive()){
            throw std::runtime_error("enemy is dead");;
        }
        if (this->distance(other) <= 1) {
            slash(other);
        } else {
            this->move(other);
        }
    }
    int Ninja::getSpeed() const {
        return speed;
    }

    void Ninja::setSpeed(int speed) {
        this->speed = speed;

    }
} // ariel