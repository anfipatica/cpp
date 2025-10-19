/*
 * Name: Luna del Valle
 * File: ScavTrap.hpp
 * Created on: Thursday Jul 31, 2025 14:32:22 CEST
 */

#ifndef SCAVTRAP_HPP

#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
    public:
        ScavTrap ();
        ScavTrap (std::string _name);
		ScavTrap (const ScavTrap& other);

        virtual ~ScavTrap ();
		ScavTrap& operator=(const ScavTrap& rhs);

        void guardGate();
        void attack(const std::string& target);

    private:
		
};

#endif /* end of include guard SCAVTRAP_HPP */

