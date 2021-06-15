#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap  {
	public:
		using	FragTrap::rangedAttack;
		using	NinjaTrap::meleeAttack;
		SuperTrap();
		SuperTrap(const std::string& name);
		~SuperTrap();
		SuperTrap(const SuperTrap&);
		SuperTrap&	operator=(const SuperTrap&);
		virtual void    setName(const std::string& name);
        virtual const std::string&  getName() const;
};

#endif