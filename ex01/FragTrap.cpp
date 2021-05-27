#include "FragTrap.hpp"

void    FragTrap::_fragTrapInit(const std::string& name) {
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_enrgPoints = 100;
    this->_maxEnrgPoints = 100;
    this->_level = 1;
    this->_name = name;
    this->_meleeAttDamage = 30;
    this->_rangAttDamage = 20;
    this->_frzAttDamage = 10;
    this->_dumbAttDamage = 25;
    this->_cringAttDamage = 100;
    this->_armorDamageReduce = 5;
    this->_attacks[0] = &FragTrap::_meleeAttack;
    this->_attacks[1] = &FragTrap::_rangedAttack;
    this->_attacks[2] = &FragTrap::_freezeAttack;
    this->_attacks[3] = &FragTrap::_dumbAttack;
    this->_attacks[4] = &FragTrap::_cringeAttack;
}

FragTrap::FragTrap() : _attCost(25) {
    this->_fragTrapInit("N/A");
    std::cout << "<<Constructed an empty FragTrap.>>" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : _attCost(25) {
    this->_fragTrapInit(name);
    std::cout << "<<Constructed a \033[32;1m" << this->_name << "\033[0m FragTrap.>>" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "<<Destroyed a \033[32;1m" << this->_name << "\033[0m FragTrap.>>" << std::endl;
}

FragTrap::FragTrap(const FragTrap& right) : _attCost(25) {
    *this = right;
}

FragTrap&   FragTrap::operator=(FragTrap const &right) {
    this->_hitPoints = right._hitPoints;
    this->_maxHitPoints = right._maxHitPoints;
    this->_enrgPoints = right._enrgPoints;
    this->_maxEnrgPoints = right._maxEnrgPoints;
    this->_level = right._level;
    this->_name = right._name;
    this->_meleeAttDamage = right._meleeAttDamage;
    this->_rangAttDamage = right._rangAttDamage;
    this->_frzAttDamage = right._frzAttDamage;
    this->_dumbAttDamage = right._dumbAttDamage;
    this->_cringAttDamage = right._cringAttDamage;
    this->_armorDamageReduce = right._armorDamageReduce;
    this->_attacks[0] = &FragTrap::_meleeAttack;
    this->_attacks[1] = &FragTrap::_rangedAttack;
    this->_attacks[2] = &FragTrap::_freezeAttack;
    this->_attacks[3] = &FragTrap::_dumbAttack;
    this->_attacks[4] = &FragTrap::_cringeAttack;
    return *this;
}

void    FragTrap::setName(const std::string& name) {
    this->_name = name;
}

const std::string&  FragTrap::getName() const {
    return this->_name;
}

int    FragTrap::_rangedAttack(const std::string& target) {
    if (this->_enrgPoints >= this->_attCost) {
        std::cout << "FR4G-TP \033[32;1m<" << this->getName() << ">\033[0m attacks \033[31;1m<" << target << ">\033[0m at range, causing " << this->_rangAttDamage << " points of damage!" << std::endl;
        this->_enrgPoints -= this->_attCost;
        return (this->_rangAttDamage);
    }
    std::cout << "\033[32;1m<" << this->getName() << ">\033[0m has not enough enery to attack" << std::endl;
    return 0;
}

int    FragTrap::_meleeAttack(const std::string& target) {
    if (this->_enrgPoints >= this->_attCost) {
        std::cout << "FR4G-TP \033[32;1m<" << this->getName() << ">\033[0m attacks \033[31;1m<" << target << ">\033[0m in close combat, causing " << this->_meleeAttDamage << " points of damage!" << std::endl;
        this->_enrgPoints -= this->_attCost;
        return (this->_meleeAttDamage);
    }
    std::cout << "\033[32;1m<" << this->getName() << ">\033[0m has not enough enery to attack" << std::endl;
    return 0;
}

int    FragTrap::_freezeAttack(const std::string& target) {
    if (this->_enrgPoints >= this->_attCost) {
        std::cout << "FR4G-TP \033[32;1m<" << this->getName() << ">\033[0m freezes \033[31;1m<" << target << ">\033[0m, causing " << this->_frzAttDamage << " points of damage!" << std::endl;
        this->_enrgPoints -= this->_attCost;
        return (this->_frzAttDamage);
    }
    std::cout << "\033[32;1m<" << this->getName() << ">\033[0m has not enough enery to attack" << std::endl;
    return 0;
}

int    FragTrap::_dumbAttack(const std::string& target) {
    if (this->_enrgPoints >= this->_attCost) {
        std::cout << "FR4G-TP \033[32;1m<" << this->getName() << ">\033[0m shouts:\"Hey, watch out!\", and plants a bomb. \033[32;1m<" << this->getName() << ">\033[0m and \033[31;1m<" << target << ">\033[0m both get " << this->_dumbAttDamage << " points of damage!" << std::endl;
        this->_enrgPoints -= this->_attCost;
        this->takeDamage(this->_dumbAttDamage);
        return this->_dumbAttDamage;
    }
    std::cout << "\033[32;1m<" << this->getName() << ">\033[0m has not enough enery to attack" << std::endl;
    return 0;
}

int    FragTrap::_cringeAttack(const std::string& target) {
    if (this->_enrgPoints >= this->_attCost) {
        std::cout << "FR4G-TP \033[32;1m<" << this->getName() << ">\033[0m says \033[31;1m<" << target << ">\033[0m is a cringe, causing it to get " << this->_cringAttDamage << " points of damage!" << std::endl;
        this->_enrgPoints -= this->_attCost;
        return this->_cringAttDamage;
    }
    std::cout << "\033[32;1m<" << this->getName() << ">\033[0m has not enough enery to attack" << std::endl;
    return 0;
}

void    FragTrap::takeDamage(unsigned int amount) {
    if (amount > 0) {
        if (amount > (this->_hitPoints + this->_armorDamageReduce))
            this->_hitPoints = 0;
        else
            this->_hitPoints = this->_hitPoints + this->_armorDamageReduce - amount;
        std::cout << "FR4G-TP \033[32;1m<" << this->getName() << ">\033[0m takes reduced " << (amount - this->_armorDamageReduce) << " points of damage" << std::endl;
    }
}

void    FragTrap::beRepaired(unsigned int amount) {
    if (amount + this->_hitPoints > this->_maxHitPoints)
        this->_hitPoints = this->_maxHitPoints;
    else
        this->_hitPoints += amount;
    std::cout << "FR4G-TP \033[32;1m<" << this->getName() << ">\033[0m gets repaired by " << amount << " points" << std::endl;
}

int    FragTrap::vaulthunter_dot_exe(const std::string& target) {

    return (this->*_attacks[rand() % 5])(target);
}
