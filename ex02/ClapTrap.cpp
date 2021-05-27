#include "ClapTrap.hpp"

void    ClapTrap::_init(const std::string &name) {
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_enrgPoints = 100;
    this->_maxEnrgPoints = 100;
    this->_level = 1;
    this->_name = name;
    this->_meleeAttDamage = 30;
    this->_rangAttDamage = 20;
    this->_armorDamageReduce = 5;
}

ClapTrap::ClapTrap() : _attCost(25) {
    this->_init("CLPTRP");
    std::cout << "<<Empty ClapTrap activated!>>" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _attCost(25) {
    this->_init(name);
    std::cout << "<<Constructed a \033[32;1m" << this->_name << "\033[0m ClapTrap.>>" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "<<Destroyed a \033[32;1m" << this->_name << "\033[0m ClapTrap.>>" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& right) : _attCost(25) {
    *this = right;
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