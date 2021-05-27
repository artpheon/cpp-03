#include "FragTrap.hpp"

int main() {
    srand(time(0));
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


    return 0;
}