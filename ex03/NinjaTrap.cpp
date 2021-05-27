#include "NinjaTrap.hpp"


NinjaTrap::NinjaTrap() : _name("NINJA") {
    this->_hitPoints = 60;
    this->_maxHitPoints = 60;
    this->_enrgPoints = 120;
    this->_maxEnrgPoints = 120;
    this->_meleeAttDamage = 60;
    this->_rangAttDamage = 5;
    this->_armorDamageReduce = 0;
    std::cout << "<<NinjaTrap was born!>>\n" << "悪に慈悲が被られることはない!" << std::endl;
}

NinjaTrap::NinjaTrap(const std::string& name) : _name(name) {
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