//
// Created by asaf7 on 5/9/2023.
//

#include "Ninja.hpp"

namespace ariel {
/**
 * move the ninja towards other character
 * @param other
 */
    void Ninja::move(const Character *other) {
        this->setLocation(this->getLocation().moveTowards(other->getLocation(), this->speed))  ;
    }
/**
 * slash the enemy if he is close enough
 * @param other
 */
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
                other->setAlive(false);
            }
        }
    }


/**
 * print the ninja
 * @return  string that represent the ninja
 */

    string Ninja::print() const {
        if (this->isAlive()) {
            return "(N)" + this->getName() + " " + to_string(this->getHealthPoints()) + " " + this->getLocation().print();
        } else {
            return "(N)" + this->getName() + " " + this->getLocation().print();
        }
    }

/**
 * constructor
 * @param name
 * @param location
 */
    Ninja::Ninja(const string &name, const Point &location) : Character(name, location, 100) {
        this->setAlive(true);
        this->setIsCowboy(false);
    }
/**
 * attack the enemy using slash or move
 * @param other
 */
    void Ninja::attack(Character *other) {
        if (this->distance(other) <= 1) {
            slash(other);
        } else {
            this->move(other);
        }
    }
/**
 * get the speed of the ninja
 * @return  int that represent the speed of the ninja
 */
    int Ninja::getSpeed() const {
        return speed;
    }
/**
 * set the speed of the ninja
 * @param speed
 */
    void Ninja::setSpeed(int speed) {
        this->speed = speed;

    }
} // ariel