#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

class ClapTrap {
    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& right);
        virtual ~ClapTrap();
        ClapTrap&   operator=(ClapTrap const &right);
        virtual void    setName(const std::string& name);
        virtual const std::string&  getName() const;
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        virtual int     rangedAttack(const std::string& target);
        virtual int     meleeAttack(const std::string& target);

    protected:
        unsigned int    _attCost;
        unsigned int    _hitPoints;
        unsigned int    _maxHitPoints;
        unsigned int    _enrgPoints;
        unsigned int    _maxEnrgPoints;
        unsigned int    _level;
        std::string     _name;
        unsigned int    _meleeAttDamage;
        unsigned int    _rangAttDamage;
        unsigned int    _armorDamageReduce;
};

#endif