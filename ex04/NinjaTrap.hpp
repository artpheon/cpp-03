#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class   NinjaTrap : public ClapTrap {
    public:
        NinjaTrap();
        NinjaTrap(const std::string& name);
        NinjaTrap(const NinjaTrap& right);
        NinjaTrap&  operator=(const NinjaTrap& right);
        ~NinjaTrap();
        void    ninjaShoeBox(ClapTrap& target);
        void    ninjaShoeBox(FragTrap& target);
        void    ninjaShoeBox(NinjaTrap& target);
        void    ninjaShoeBox(ScavTrap& target);
    private:
        unsigned int _hitPoints;
        unsigned int _maxHitPoints;
        unsigned int _enrgPoints;
        unsigned int _maxEnrgPoints;
        std::string _name;
        unsigned int _meleeAttDamage;
        unsigned int _rangAttDamage;
        unsigned int _armorDamageReduce;
};

#endif