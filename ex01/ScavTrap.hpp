#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include <string>


class ScavTrap {
    public:
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& right);
        ~ScavTrap();
        ScavTrap&   operator=(const ScavTrap& right);
        void    setName(const std::string& name);
        const std::string&  getName() const;
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        int    rangedAttack(const std::string& target);
        int    meleeAttack(const std::string& target);
        void    challengeNewcomer();
    private:
        void    _scavTrapInit(const std::string& name);
        const unsigned int _attCost;
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _maxHitPoints;
        unsigned int _enrgPoints;
        unsigned int _maxEnrgPoints;
        unsigned int _level;
        unsigned int _meleeAttDamage;
        unsigned int _rangAttDamage;
        unsigned int _armorDamageReduce;
};

#endif