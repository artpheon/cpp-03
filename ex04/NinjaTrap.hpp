#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class   NinjaTrap : virtual public ClapTrap {
    public:
        NinjaTrap();
        NinjaTrap(const std::string& name);
        NinjaTrap(const NinjaTrap& right);
        NinjaTrap&  operator=(const NinjaTrap& right);
        virtual ~NinjaTrap();
        virtual void    setName(const std::string& name);
        virtual const std::string&  getName() const;
        void    ninjaShoeBox(ClapTrap& target);
        void    ninjaShoeBox(FragTrap& target);
        void    ninjaShoeBox(NinjaTrap& target);
        void    ninjaShoeBox(ScavTrap& target);
        virtual int     rangedAttack(const std::string& target);
        virtual int     meleeAttack(const std::string& target);
};

#endif