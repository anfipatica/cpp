/*
 * Name: Luna del Valle
 * File: FragTrap.cpp
 * Created on: Wednesday Jul 30, 2025 14:41:30 CEST
 */

#include <iostream>
#include <climits>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/* Default constructor */
FragTrap::FragTrap(): ClapTrap() {
    std::cout<<"FragTrap default constructor called"<<std::endl;
    this->name = "default";
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

/* Named constructor */
FragTrap::FragTrap(std::string _name): ClapTrap() {
    std::cout<<"FragTrap named constructor called ("<<_name<<")"<<std::endl;
    this->name = _name;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

/* Copy constructor */
FragTrap::FragTrap(const FragTrap& source): ClapTrap() {
    std::cout<<"FragTrap copy constructor called"<<std::endl;

    *this = source;
}

/* Copy assignment operator */
FragTrap& FragTrap::operator=(const FragTrap& rhs) {
    std::cout<<"FragTrap copy assignment operator called"<<std::endl;

    this->name = rhs.name;
    this->hit_points = rhs.hit_points;
    this->energy_points = rhs.energy_points;
    this->attack_damage = rhs.attack_damage;
    return (*this);
}

/* Default destructor */
FragTrap::~FragTrap() {
    std::cout<<"FragTrap destructor called"<<std::endl;
}

void FragTrap::highFivesGuys() {
    
    std::cout<<"FragTrap "<<this->name<<" asks for a high five!"<<std::endl;

}
