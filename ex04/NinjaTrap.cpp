#include "NinjaTrap.hpp"


NinjaTrap::NinjaTrap() : ClapTrap("NINJA") {
    this->_hitPoints = 60;
    this->_maxHitPoints = 60;
    this->_enrgPoints = 120;
    this->_maxEnrgPoints = 120;
    this->_meleeAttDamage = 60;
    this->_rangAttDamage = 5;
    this->_armorDamageReduce = 0;
    std::cout << "<<NinjaTrap was born!>>\n" << "悪に慈悲が被られることはない!" << std::endl;
}

NinjaTrap::NinjaTrap(const std::string& name) : ClapTrap(name) {
    this->_hitPoints = 60;
    this->_maxHitPoints = 60;
    this->_enrgPoints = 120;
    this->_maxEnrgPoints = 120;
    this->_meleeAttDamage = 60;
    this->_rangAttDamage = 5;
    this->_armorDamageReduce = 0;
    std::cout << "<<NinjaTrap was born!>>\n" 
    << "Only a ninja can stop a ninja." << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap& right) {
    *this = right;
}

NinjaTrap&  NinjaTrap::operator=(const NinjaTrap& right) {
    this->_hitPoints = right._hitPoints;
    this->_maxHitPoints = right._maxHitPoints;
    this->_enrgPoints = right._enrgPoints;
    this->_maxEnrgPoints = right._maxEnrgPoints;
    this->_meleeAttDamage = right._meleeAttDamage;
    this->_rangAttDamage = right._rangAttDamage;
    this->_armorDamageReduce = right._armorDamageReduce;
    this->_name = right._name;
    std::cout << "Made a clone of myself!" << std::endl;
    return *this;
}

NinjaTrap::~NinjaTrap() {
    std::cout << "<<NinjaTrap dies>>\nAll those moments will be lost in time, like tears in rain. Time to die." << std::endl;
}

void    NinjaTrap::ninjaShoeBox(ClapTrap& target) {
    std::cout << "I have an amazing partnership with my dear friend ClapTrap " << target.getName() << "!" << std::endl;
}

void    NinjaTrap::ninjaShoeBox(FragTrap& target) {
    std::cout << "Oh, good. For a moment there I thought we were in trouble. Glad to see you, FragTrap " << target.getName() << "!" << std::endl;
}

void    NinjaTrap::ninjaShoeBox(NinjaTrap& target) {
    std::cout << "I seem to have caught myself! Oh, it's just " << target.getName() << ".." << std::endl;
}

void    NinjaTrap::ninjaShoeBox(ScavTrap& target) {
    std::cout << "Hey, " << target.getName() << "! I've never been a fan of ScavTraps! *Ssssschhhhhhh*" << std::endl;
}

int    NinjaTrap::rangedAttack(const std::string& target) {
    if (this->_enrgPoints >= this->_attCost) {
        std::cout << "\033[32;1m<" << this->getName() << ">\033[0m attacks \033[31;1m<" << target << ">\033[0m from afar with a shuriken, causing " << this->_rangAttDamage << " points of damage!" << std::endl;
        this->_enrgPoints -= this->_attCost;
        return (this->_rangAttDamage);
    }
    std::cout << "\033[32;1m<" << this->getName() << ">\033[0m has not enough enery to attack" << std::endl;
    return 0;
}

int    NinjaTrap::meleeAttack(const std::string& target) {
    if (this->_enrgPoints >= this->_attCost) {
        std::cout << "\033[32;1m<" << this->getName() << ">\033[0m stabs \033[31;1m<" << target << ">\033[0m with a kunai, causing " << this->_meleeAttDamage << " points of damage!" << std::endl;
        this->_enrgPoints -= this->_attCost;
        return (this->_meleeAttDamage);
    }
    std::cout << "\033[32;1m<" << this->getName() << ">\033[0m has not enough enery to attack" << std::endl;
    return 0;
}