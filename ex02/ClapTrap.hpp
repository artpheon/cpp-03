#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

class ClapTrap {
    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& right);
        ~ClapTrap();
        ClapTrap&   operator=(ClapTrap const &right);
        void    setName(const std::string& name);
        const std::string&  getName() const;
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        int    rangedAttack(const std::string& target);
        int    meleeAttack(const std::string& target);
    protected:
        void    _init(const std::string& name);
        unsigned int _hitPoints;
        unsigned int _maxHitPoints;
        unsigned int _enrgPoints;
        unsigned int _maxEnrgPoints;
        unsigned int _level;
        std::string _name;
        unsigned int _meleeAttDamage;
        unsigned int _rangAttDamage;
        const unsigned int _attCost;
        unsigned int _armorDamageReduce;
};

#endif