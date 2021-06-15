#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

void fragTrapDemonstrate() {
int damage;
    {
        FragTrap frag1("psycho");
        FragTrap frag2("rapist");
        damage = frag1.vaulthunter_dot_exe(frag2.getName());
        frag2.takeDamage(damage);
        damage = frag2.vaulthunter_dot_exe(frag1.getName());
        frag1.takeDamage(damage);
    }
    std::cout << std::endl;
    {
        FragTrap frag1("Lilith");
        FragTrap frag2("Hunter");
        damage = frag1.vaulthunter_dot_exe(frag2.getName());
        frag2.takeDamage(damage);
        damage = frag2.vaulthunter_dot_exe(frag1.getName());
        frag1.takeDamage(damage);
        damage = frag1.vaulthunter_dot_exe(frag2.getName());
        frag2.takeDamage(damage);
        damage = frag2.vaulthunter_dot_exe(frag1.getName());
        frag1.takeDamage(damage);
        damage = frag1.vaulthunter_dot_exe(frag2.getName());
        frag2.takeDamage(damage);
        damage = frag2.vaulthunter_dot_exe(frag1.getName());
        frag1.takeDamage(damage);
        damage = frag1.vaulthunter_dot_exe(frag2.getName());
        frag2.takeDamage(damage);
        damage = frag2.vaulthunter_dot_exe(frag1.getName());
        frag1.takeDamage(damage);
        damage = frag1.vaulthunter_dot_exe(frag2.getName());
        frag2.takeDamage(damage);
        damage = frag2.vaulthunter_dot_exe(frag1.getName());
        frag1.takeDamage(damage);
        damage = frag1.vaulthunter_dot_exe(frag2.getName());
        frag2.takeDamage(damage);
        damage = frag2.vaulthunter_dot_exe(frag1.getName());
        frag1.takeDamage(damage);
    }
}

void    scavDemonstrate() {
    ScavTrap scav("bob");
    scav.challengeNewcomer();
    scav.beRepaired(10);
    scav.takeDamage(10);
    scav.rangedAttack("another trap");
    scav.meleeAttack("you");
    scav.challengeNewcomer();
    scav.challengeNewcomer();
}
int main() {

{
    std::cout << "____________Constructors______________" << std::endl;
    std::cout << "_______SuperTrap:" << std::endl;
    SuperTrap trap = SuperTrap("newSupertrap");
    std::cout << "_______NinjaTrap:" << std::endl;
    NinjaTrap nin = NinjaTrap("ninjaaa");
    std::cout << "_______FragTrap:" << std::endl;
    FragTrap    frag("newbie");
    std::cout << "_____________Action___________________" << std::endl;
    trap.ninjaShoeBox(nin);
    trap.ninjaShoeBox(frag);
    trap.meleeAttack(nin.getName());
    trap.rangedAttack(frag.getName());
    std::cout << "_____________Destructors_______________" << std::endl;
}
    std::cout << "\n" << std::endl;
    ClapTrap *ptr = new SuperTrap("superTRAP");
    delete ptr;
    return 0;
}