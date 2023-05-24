//
// Created by asaf7 on 5/9/2023.
//

#include "Cowboy.hpp"

using namespace std;

namespace ariel {

/**
 * reload the ammo of the cowboy to 6
 */
    void Cowboy::reload() {
        if (!this->isAlive()) {
            throw std::runtime_error("Character is dead c");;
        }
        this->ammo = 6;

    }
/**
 * constructor
 * @param name
 * @param location
 */
    Cowboy::Cowboy(const std::string &name, const Point &location) : Character(name, location, 110) {
        this->setAlive(true);
        this->ammo = 6;
        this->setIsCowboy(true);
    }
/**
 * shoot the enemy if cowboy has ammo reload if not
 * @param enemy
 */
    void Cowboy::shoot(Character *enemy) {
        if (this == enemy) {
            throw std::runtime_error("Character cannot attack itself");
        }
        if (!this->isAlive()) {
            throw std::runtime_error("Character is dead");;
        }
        if (!enemy->isAlive()) {
            throw std::runtime_error("enemy is dead");;

        }
        if (this->ammo > 0) {
            this->ammo--;
            enemy->setHealthPoints(enemy->getHealthPoints() - 10);
            if (enemy->getHealthPoints() <= 0) {
                enemy->setHealthPoints(0);
                enemy->setAlive(false);
            }
        } else {
            cout << "no ammo" << endl;
            this->reload();
        }
    }
/**
 * print the cowboy
 * @return string that represent the cowboy
 */
    string Cowboy::print() const {
        if (this->isAlive()) {
            return "(C)" + this->getName() + " " + to_string(this->getHealthPoints()) + " " +
                   this->getLocation().print();;
        } else {
            return "(C)" + this->getName() + " " + this->getLocation().print();;
        }

    }


/**
 * attack the enemy using shoot or reload
 * @param other
 */
    void Cowboy::attack(Character *other) {
        shoot(other);

    }
/**
 * check if the cowboy has ammo
 * @return  true if he has ammo false otherwise
 */
    bool Cowboy::hasboolets() const {
        return this->ammo > 0;
    }

}
// ariel