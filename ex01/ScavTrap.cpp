#include "ScavTrap.hpp"

void    ScavTrap::_scavTrapInit(const std::string& name) {
    srand(time(0));
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_enrgPoints = 50;
    this->_maxEnrgPoints = 50;
    this->_level = 1;
    this->_name = name;
    this->_meleeAttDamage = 20;
    this->_rangAttDamage = 15;
    this->_armorDamageReduce = 3;
}

ScavTrap::ScavTrap() : _attCost(25) {
    this->_scavTrapInit("N/A");
    std::cout << "<<Unnamed ScavTrap constructed: Let me teach you the ways of magic!>>" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : _attCost(25) {
    this->_scavTrapInit(name);
    std::cout << "<<Constructed a \033[32;1m" << this->_name << "\033[0m ScavTrap: Hey, best friend! Sooooo... how are things?>>" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "<<Destroyed a \033[32;1m" << this->_name << "\033[0m ScavTrap: Good thing I don't have a soul! Ugh..>>" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& right) : _attCost(25) {
    *this = right;
}

ScavTrap&   ScavTrap::operator=(ScavTrap const &right) {
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

void    ScavTrap::setName(const std::string& name) {
    this->_name = name;
}

const std::string&  ScavTrap::getName() const {
    return this->_name;
}

int    ScavTrap::rangedAttack(const std::string& target) {
    if (this->_enrgPoints >= this->_attCost) {
        std::cout << "ScavTrap \033[32;1m<" << this->getName() << ">\033[0m attacks \033[31;1m<" << target << ">\033[0m at range, causing " << this->_rangAttDamage << " points of damage!" << std::endl;
        this->_enrgPoints -= this->_attCost;
        return (this->_rangAttDamage);
    }
    std::cout << "\033[32;1m<" << this->getName() << ">\033[0m has not enough enery to attack" << std::endl;
    return 0;
}

int    ScavTrap::meleeAttack(const std::string& target) {
    if (this->_enrgPoints >= this->_attCost) {
        std::cout << "ScavTrap \033[32;1m<" << this->getName() << ">\033[0m attacks \033[31;1m<" << target << ">\033[0m in close combat, causing " << this->_meleeAttDamage << " points of damage!" << std::endl;
        this->_enrgPoints -= this->_attCost;
        return (this->_meleeAttDamage);
    }
    std::cout << "\033[32;1m<" << this->getName() << ">\033[0m has not enough enery to attack" << std::endl;
    return 0;
}

void    ScavTrap::takeDamage(unsigned int amount) {
    if (amount > 0) {
        if (amount > (this->_hitPoints + this->_armorDamageReduce))
            this->_hitPoints = 0;
        else
            this->_hitPoints = this->_hitPoints + this->_armorDamageReduce - amount;
        std::cout << "ScavTrap \033[32;1m<" << this->getName() << ">\033[0m takes reduced " << (amount - this->_armorDamageReduce) << " points of damage" << std::endl;
    }
}

void    ScavTrap::beRepaired(unsigned int amount) {
    if (amount + this->_hitPoints > this->_maxHitPoints)
        this->_hitPoints = this->_maxHitPoints;
    else
        this->_hitPoints += amount;
    std::cout << "ScavTrap \033[32;1m<" << this->getName() << ">\033[0m gets repaired by " << amount << " points" << std::endl;
}

void    ScavTrap::challengeNewcomer() {
    const static std::string challenges[5] = {
        "Get married and have kids.",
        "Stop discussing dragons and unicorns at work.",
        "Become black!",
        "Hack into Bank of America.",
        "Stay home and do NOTHING."
    };
    std::cout << "ScavTrap \033[32;1m<" << this->getName() << ">\033[0m found a new challenge for you: " << challenges[rand() % 5] << std::endl;
}