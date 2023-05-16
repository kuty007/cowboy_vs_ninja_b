//
// Created by asaf7 on 5/9/2023.
//

#include "Character.hpp"
#include <cmath>

namespace ariel {

    bool Character::isAlive() const { return alive; }


    const Point &Character::getLocation() const { return location; }

    double Character::distance(Character const *other) {
        return this->location.distance(other->location);
    }

    void Character::hit(int damage) {
        if (damage < 0) {
            throw std::invalid_argument("damage cannot be negative");
        }
        this->health_points -= damage;
        if (this->health_points <= 0) {
            this->health_points = 0;
            this->alive = false;

        }
    }

    const std::string &Character::getName() const {
        return this->name;
    }

    Character::Character(const string &name, const Point &location, int health_points) : location(location),
                                                                                         health_points(health_points),
                                                                                         name(name) {
        this->alive = true;
        this->belong_to_team = false;

    }

    int Character::getHealthPoints() const { return this->health_points; }

    void Character::setHealthPoints(int healthPoints) { this->health_points = healthPoints; }

    void Character::setLocation(const Point &location) { this->location = location; }

    void Character::setBelongToTeam(bool belongToTeam) { this->belong_to_team = belongToTeam; }

    bool Character::getBelongToTeam() const { return this->belong_to_team; }

    Character *Character::getNearestCharacter(const vector<Character *> &characters) const {
        Character *nearestCharacter = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (auto character: characters) {
            if (!character->isAlive() || character == this) {
                continue;
            }
            double distance = character->distance(this);
            if (distance < minDistance) {
                minDistance = distance;
                nearestCharacter = character;
            }
        }

        return nearestCharacter;
    }

    void Character::setAlive(bool alive) { this->alive = alive; }

    bool Character::isCowboy() const {
        return is_cowboy;
    }

    void Character::setIsCowboy(bool isCowboy) {
        this->is_cowboy = isCowboy;

    }

} // ariel