#include "SuperTrap.hpp"

SuperTrap::SuperTrap() : NinjaTrap()
{
    this->_enrgPoints = 120;
    this->_maxEnrgPoints = 120;
    this->_meleeAttDamage = 60;
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_rangAttDamage = 20;
    this->_armorDamageReduce = 5;
    this->_name = "Supertrap";
    std::cout << "<<Supertrap created>>" << std::endl;
}

SuperTrap::SuperTrap(const std::string& name) : NinjaTrap()
{
    this->_enrgPoints = 120;
    this->_maxEnrgPoints = 120;
    this->_meleeAttDamage = 60;
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_rangAttDamage = 20;
    this->_armorDamageReduce = 5;
    this->_name = name;
    std::cout << "<<Supertrap created>>" << std::endl;
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

void    SuperTrap::setName(const std::string& name) {
    this->_name = name;
}

const std::string&  SuperTrap::getName() const {
    return this->_name;
}