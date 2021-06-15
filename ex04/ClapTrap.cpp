#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
_attCost(25),
_hitPoints(100),
_maxHitPoints(100),
_enrgPoints(100),
_maxEnrgPoints(100),
_level(1),
_name("CLPTRP"),
_meleeAttDamage(30),
_rangAttDamage(20),
_armorDamageReduce(5)
{
    std::cout << "<<Empty ClapTrap activated!>>" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :
_attCost(25),
_hitPoints(100),
_maxHitPoints(100),
_enrgPoints(100),
_maxEnrgPoints(100),
_level(1),
_name(name),
_meleeAttDamage(30),
_rangAttDamage(20),
_armorDamageReduce(5)
{
    std::cout << "<<Constructed a ClapTrap>>" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "<<Destroyed a ClapTrap>>" << std::endl;
}

ClapTrap&   ClapTrap::operator=(ClapTrap const &right) {
    this->_hitPoints = right._hitPoints;
    this->_maxHitPoints = right._maxHitPoints;
    this->_enrgPoints = right._enrgPoints;
    this->_maxEnrgPoints = right._maxEnrgPoints;
    this->_level = right._level;
    this->_name = right._name;
    this->_meleeAttDamage = right._meleeAttDamage;
    this->_rangAttDamage = right._rangAttDamage;
    this->_armorDamageReduce = right._armorDamageReduce;
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap& right) {
    *this = right;
}

void    ClapTrap::setName(const std::string& name) {
    this->_name = name;
}

const std::string&  ClapTrap::getName() const {
    return this->_name;
}

int    ClapTrap::rangedAttack(const std::string& target) {
    if (this->_enrgPoints >= this->_attCost) {
        std::cout << "\033[32;1m<" << this->getName() << ">\033[0m attacks \033[31;1m<" << target << ">\033[0m at range, causing " << this->_rangAttDamage << " points of damage!" << std::endl;
        this->_enrgPoints -= this->_attCost;
        return (this->_rangAttDamage);
    }
    std::cout << "\033[32;1m<" << this->getName() << ">\033[0m has not enough enery to attack" << std::endl;
    return 0;
}

int    ClapTrap::meleeAttack(const std::string& target) {
    if (this->_enrgPoints >= this->_attCost) {
        std::cout << "\033[32;1m<" << this->getName() << ">\033[0m attacks \033[31;1m<" << target << ">\033[0m in close combat, causing " << this->_meleeAttDamage << " points of damage!" << std::endl;
        this->_enrgPoints -= this->_attCost;
        return (this->_meleeAttDamage);
    }
    std::cout << "\033[32;1m<" << this->getName() << ">\033[0m has not enough enery to attack" << std::endl;
    return 0;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (amount > 0) {
        if (amount > (this->_hitPoints + this->_armorDamageReduce))
            this->_hitPoints = 0;
        else
            this->_hitPoints = this->_hitPoints + this->_armorDamageReduce - amount;
        std::cout << "\033[32;1m<" << this->getName() << ">\033[0m takes reduced " << (amount - this->_armorDamageReduce) << " points of damage" << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (amount + this->_hitPoints > this->_maxHitPoints)
        this->_hitPoints = this->_maxHitPoints;
    else
        this->_hitPoints += amount;
    std::cout << "\033[32;1m<" << this->getName() << ">\033[0m gets repaired by " << amount << " points" << std::endl;
}