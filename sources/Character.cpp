//
// Created by asaf7 on 5/9/2023.
//

#include "Character.hpp"
#include <cmath>

namespace ariel {
/**
 *
 * @return true if the character is alive
 */
    bool Character::isAlive() const { return alive; }

/**
 * get the location of the character
 * @return  const reference to Point  that represent the location of the character
 */
    const Point& Character::getLocation() const { return location; }
/**
 * get the distance between two characters
 * @param other
 * @return double that represent the distance between two characters
 */
    double Character::distance(Character const *other) {
        return this->location.distance(other->location);
    }
/**
 * reduce the health points of the character by the damage
 * and if the health points is less than 0 the character is dead
 * @param damage
 */
    void Character::hit(int damage) {
        if (damage < 0) {
            throw std::invalid_argument("damage cannot be negative");
        }
        this->health_points -= damage;
        if (this->health_points <= 0) {
            this->alive = false;

        }
    }
    /**
     * get the name of the character
     * @return const reference to string that represent the name of the character
     */

    const std::string &Character::getName() const {
        return this->name;
    }
/**
 * constructor
 * @param name
 * @param location
 * @param health_points
 */
    Character::Character(const string &name, const Point &location, int health_points) : location(location),
                                                                                         health_points(health_points),name(name) {
        this->alive = true;
        this->belong_to_team = false;

    }
/**
 * get the health points of the character
 * @return int that represent the health points of the character
 */
    int Character::getHealthPoints() const { return this->health_points; }
/**
 * set the health points of the character
 * @param healthPoints
 */
    void Character::setHealthPoints(int healthPoints) { this->health_points = healthPoints; }
/**
 * set the location of the character
 * @param location
 */
    void Character::setLocation(const Point &location) { this->location = location; }
/**
 * set if the character belong to team
 * @param belongToTeam
 */
    void Character::setBelongToTeam(bool belongToTeam) { this->belong_to_team = belongToTeam; }
/**
 * get if the character belong to team
 * @return true if the character belong to team
 */
    bool Character::getBelongToTeam() const { return this->belong_to_team; }
/**
 * get the nearest character from the vector of characters
 * @param characters
 * @return *Character that represent the nearest character
 */
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
/**
 * set if the character is alive
 * @param alive
 */
    void Character::setAlive(bool alive) { this->alive = alive; }
/**
 * get if the character type is cowboy
 * @return true if the character type is cowboy false otherwise
 */
    bool Character::isCowboy() const {
        return is_cowboy;
    }
/**
 * set if the character type is cowboy
 * @param isCowboy
 */
    void Character::setIsCowboy(bool isCowboy) {
        this->is_cowboy = isCowboy;

    }

} // ariel