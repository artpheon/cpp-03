#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("SCV_TP") {
    this->_enrgPoints = 50;
    this->_maxEnrgPoints = 50;
    this->_meleeAttDamage = 20;
    this->_rangAttDamage = 15;
    this->_armorDamageReduce = 3;
    std::cout << "<<Unnamed ScavTrap constructed: Let me teach you the ways of magic!>>" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    this->_enrgPoints = 50;
    this->_maxEnrgPoints = 50;
    this->_meleeAttDamage = 20;
    this->_rangAttDamage = 15;
    this->_armorDamageReduce = 3;
    std::cout << "<<Constructed a \033[32;1m" << this->_name << "\033[0m ScavTrap: Hey, best friend! Sooooo... how are things?>>" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "<<Destroyed a \033[32;1m" << this->_name << "\033[0m ScavTrap: Good thing I don't have a soul! Ugh..>>" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& right) {
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