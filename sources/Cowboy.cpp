//
// Created by asaf7 on 5/9/2023.
//

#include "Cowboy.hpp"

using namespace std;

namespace ariel {


    void Cowboy::reload() {
        if (!this->isAlive()) {
            throw std::runtime_error("Character is dead c");;
        }
        this->ammo = 6;

    }

    Cowboy::Cowboy(const std::string &name, const Point &location) : Character(name, location, 110) {
        this->setAlive(true);
        this->ammo = 6;
        this->setIsCowboy(true);
    }

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

    string Cowboy::print() const {
        if (this->isAlive()) {
            return "(C)" + this->getName() + " " + to_string(this->getHealthPoints()) + " " +
                   this->getLocation().print();;
        } else {
            return "(C)" + this->getName() + " " + this->getLocation().print();;
        }

    }

    int Cowboy::getAmmo() const {
        return this->ammo;
    }

    void Cowboy::attack(Character *other) {
        shoot(other);

    }

    bool Cowboy::hasboolets() const {
        return this->ammo > 0;
    }

}
// ariel