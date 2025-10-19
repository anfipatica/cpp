/*
 * Name: Luna del Valle
 * File: ScavTrap.cpp
 * Created on: Wednesday Jul 30, 2025 14:41:30 CEST
 */

#include <iostream>
#include <climits>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/* Default constructor */
ScavTrap::ScavTrap(): ClapTrap() {
    std::cout<<"ScavTrap default constructor called"<<std::endl;
    this->name = "default";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

/* Named constructor */
ScavTrap::ScavTrap(std::string _name): ClapTrap(_name) {
    std::cout<<"ScavTrap named constructor called ("<<_name<<")"<<std::endl;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

/* Copy constructor */
ScavTrap::ScavTrap(const ScavTrap& source): ClapTrap() {
    std::cout<<"ScavTrap copy constructor called"<<std::endl;

    *this = source;
}

/* Copy assignment operator */
ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
    std::cout<<"ScavTrap copy assignment operator called"<<std::endl;

    this->name = rhs.name;
    this->hit_points = rhs.hit_points;
    this->energy_points = rhs.energy_points;
    this->attack_damage = rhs.attack_damage;
    return (*this);
}

/* Default destructor */
ScavTrap::~ScavTrap() {
    std::cout<<"ScavTrap destructor called"<<std::endl;
}

/* attack member function */
void ScavTrap::attack(const std::string& target) {

    if (this->energy_points <= 0) {
        std::cout<<"ScavTrap "<<this->name<<" tried to attack "<<target<<" but they were too tired."<<std::endl;
        return ;
    }

    if (this->hit_points <= 0) {
        std::cout<<"ScavTrap "<<this->name<<" tried to attack "<<target<<" but they were too damaged."<<std::endl;
        return ;
    }

    this->energy_points -= std::min(1u, this->energy_points); 
    std::cout<<"ScavTrap "<<this->name<<" attacks "<<target<<", causing "<<this->attack_damage<<" poins of damage!"<<std::endl;

}

void ScavTrap::guardGate() {
    
    std::cout<<"ScavTrap "<<this->name<<" is now in Gate keeper mode."<<std::endl;

}
