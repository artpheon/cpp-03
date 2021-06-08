#include "SuperTrap.hpp"

SuperTrap::SuperTrap() : FragTrap("SuperTrap")
{
    //this->_rangAttDamage = 20;
}

SuperTrap::SuperTrap(const std::string& name) : FragTrap(name) 
{
    
}

SuperTrap::~SuperTrap() {
    std::cout << "What have you done? I'll have to go..." << std::endl;
    std::cout << "<<SuperTrap dies>>" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap& right) {
    *this = right;
}

SuperTrap&	SuperTrap::operator=(const SuperTrap& right) {
    this->_hitPoints = right._hitPoints;
    this->_maxHitPoints = right._maxHitPoints;
    this->_enrgPoints = right._enrgPoints;
    this->_maxEnrgPoints = right._maxEnrgPoints;
    this->_meleeAttDamage = right._meleeAttDamage;
    this->_rangAttDamage = right._rangAttDamage;
    this->_armorDamageReduce = right._armorDamageReduce;
    this->_name = right._name;
    return *this;
}