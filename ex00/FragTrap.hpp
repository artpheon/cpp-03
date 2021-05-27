#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include <string>
# include <ctime>

class FragTrap {
public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& right);
    ~FragTrap();
    FragTrap&   operator=(FragTrap const &right);
    void    setName(const std::string& name);
    const std::string&  getName() const;
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
    int vaulthunter_dot_exe(const std::string& target);
private:
    void    _fragTrapInit(const std::string& name);
    typedef int    (FragTrap::*_attackFPtr)(const std::string&);
    int    _rangedAttack(const std::string& target);
    int    _meleeAttack(const std::string& target);
    int    _freezeAttack(const std::string& target);
    int    _dumbAttack(const std::string& target);
    int    _cringeAttack(const std::string& target);
    const unsigned int _attCost;
    _attackFPtr  _attacks[5];
    unsigned int _hitPoints;
    unsigned int _maxHitPoints;
    unsigned int _enrgPoints;
    unsigned int _maxEnrgPoints;
    unsigned int _level;
    std::string _name;
    unsigned int _meleeAttDamage;
    unsigned int _rangAttDamage;
    unsigned int _frzAttDamage;
    unsigned int _dumbAttDamage;
    unsigned int _cringAttDamage;
    unsigned int _armorDamageReduce;
};

#endif