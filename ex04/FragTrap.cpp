#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FRG-TRP") {
    this->_attacks[0] = &FragTrap::freezeAttack;
    this->_attacks[1] = &FragTrap::dumbAttack;
    this->_attacks[2] = &FragTrap::cringeAttack;
    std::cout << "<<Constructed an empty FragTrap>>" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    this->_attacks[0] = &FragTrap::freezeAttack;
    this->_attacks[1] = &FragTrap::dumbAttack;
    this->_attacks[2] = &FragTrap::cringeAttack;
    std::cout << "<<Constructed a FragTrap>>" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "<<Destroyed a FragTrap>>" << std::endl;
}

FragTrap::FragTrap(const FragTrap& right) {
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
    this->_attacks[0] = &FragTrap::freezeAttack;
    this->_attacks[1] = &FragTrap::dumbAttack;
    this->_attacks[2] = &FragTrap::cringeAttack;
    return *this;
}

int    FragTrap::freezeAttack(const std::string& target) {
    if (this->_enrgPoints >= this->_attCost) {
        std::cout << "FR4G-TP \033[32;1m<" << this->getName() << ">\033[0m freezes \033[31;1m<" << target << ">\033[0m, causing " << this->_frzAttDamage << " points of damage!" << std::endl;
        this->_enrgPoints -= this->_attCost;
        return (this->_frzAttDamage);
    }
    std::cout << "\033[32;1m<" << this->getName() << ">\033[0m has not enough enery to attack" << std::endl;
    return 0;
}

int    FragTrap::dumbAttack(const std::string& target) {
    if (this->_enrgPoints >= this->_attCost) {
        std::cout << "FR4G-TP \033[32;1m<" << this->getName() << ">\033[0m shouts:\"Hey, watch out!\", and plants a bomb. \033[32;1m<" << this->getName() << ">\033[0m and \033[31;1m<" << target << ">\033[0m both get " << this->_dumbAttDamage << " points of damage!" << std::endl;
        this->_enrgPoints -= this->_attCost;
        this->takeDamage(this->_dumbAttDamage);
        return this->_dumbAttDamage;
    }
    std::cout << "\033[32;1m<" << this->getName() << ">\033[0m has not enough enery to attack" << std::endl;
    return 0;
}

int    FragTrap::cringeAttack(const std::string& target) {
    if (this->_enrgPoints >= this->_attCost) {
        std::cout << "FR4G-TP \033[32;1m<" << this->getName() << ">\033[0m says \033[31;1m<" << target << ">\033[0m is a cringe, causing it to get " << this->_cringAttDamage << " points of damage!" << std::endl;
        this->_enrgPoints -= this->_attCost;
        return this->_cringAttDamage;
    }
    std::cout << "\033[32;1m<" << this->getName() << ">\033[0m has not enough enery to attack" << std::endl;
    return 0;
}

int    FragTrap::vaulthunter_dot_exe(const std::string& target) {

    return (this->*_attacks[rand() % 5])(target);
}
