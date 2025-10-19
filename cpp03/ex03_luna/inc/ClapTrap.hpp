/*
 * Name: Luna del Valle
 * File: ClapTrap.hpp
 * Created on: Wednesday Jul 30, 2025 14:33:48 CEST
 */

#ifndef CLAPTRAP_HPP

#define CLAPTRAP_HPP


class ClapTrap {
    public:
        ClapTrap ();
        ClapTrap (std::string _name);
		ClapTrap (const ClapTrap& other);

        virtual ~ClapTrap ();
		ClapTrap& operator=(const ClapTrap& rhs);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void info(void) const;

    protected:
	    std::string name;	
        unsigned int hit_points;
        unsigned int energy_points;
        unsigned int attack_damage;
};

#endif /* end of include guard CLAPTRAP_HPP */

