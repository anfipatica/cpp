/*
 * Name: Luna del Valle
 * File: DiamondTrap.hpp
 * Created on: Monday Aug 04, 2025 19:01:48 CEST
 */

#ifndef DIAMONDTRAP_HPP

#define DIAMONDTRAP_HPP

#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
    public:
        DiamondTrap ();
        DiamondTrap (std::string _name);
		DiamondTrap (const DiamondTrap& other);
        virtual ~DiamondTrap ();
		DiamondTrap& operator=(const DiamondTrap& rhs);

        using ScavTrap::attack;
        void whoAmI();
    private:
        using FragTrap::hit_points;
        using ScavTrap::energy_points;
        using FragTrap::attack_damage;
	    std::string name;	
};

#endif /* end of include guard DIAMONDTRAP_HPP */

