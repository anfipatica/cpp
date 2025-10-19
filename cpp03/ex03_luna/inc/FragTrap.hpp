/*
 * Name: Luna del Valle
 * File: FragTrap.hpp
 * Created on: Thursday Jul 31, 2025 14:32:22 CEST
 */

#ifndef FRAGTRAP_HPP

#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap{
    public:
        FragTrap ();
        FragTrap (std::string _name);
		FragTrap (const FragTrap& other);

        virtual ~FragTrap ();
		FragTrap& operator=(const FragTrap& rhs);

        void highFivesGuys();

    private:
		
};

#endif /* end of include guard SCAVTRAP_HPP */

