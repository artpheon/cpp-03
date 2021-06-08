#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>
# include <string>
# include <ctime>

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& right);
        ~FragTrap();
        FragTrap&   operator=(FragTrap const &right);
        int     vaulthunter_dot_exe(const std::string& target);
        int     freezeAttack(const std::string& target);
        int     dumbAttack(const std::string& target);
        int     cringeAttack(const std::string& target);
    private:
        typedef int    (FragTrap::*_attackFPtr)(const std::string&);
        _attackFPtr  _attacks[3];
        unsigned int _frzAttDamage;
        unsigned int _dumbAttDamage;
        unsigned int _cringAttDamage;
};

#endif