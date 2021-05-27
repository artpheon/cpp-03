#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>
# include <string>


class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& right);
        ~ScavTrap();
        ScavTrap&   operator=(const ScavTrap& right);

        void    challengeNewcomer();
    private:
        std::string _name;
        unsigned int _enrgPoints;
        unsigned int _maxEnrgPoints;
        unsigned int _meleeAttDamage;
        unsigned int _rangAttDamage;
        unsigned int _armorDamageReduce;
};

#endif