#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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

int main() {

    fragTrapDemonstrate();
    std::cout << std::endl;


    ScavTrap scav("bob");
    scav.challengeNewcomer();
    scav.beRepaired(10);
    scav.takeDamage(10);
    scav.rangedAttack("another trap");
    scav.meleeAttack("you");
    scav.challengeNewcomer();
    scav.challengeNewcomer();



    return 0;
}