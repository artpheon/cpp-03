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
	private:
		using	FragTrap::_rangAttDamage;
		using	FragTrap::_hitPoints;
		using	FragTrap::_maxHitPoints;
		using	FragTrap::_armorDamageReduce;
		using	NinjaTrap::_enrgPoints;
		using	NinjaTrap::_maxEnrgPoints;
		using	NinjaTrap::_meleeAttDamage;
};

#endif