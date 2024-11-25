#include "ClapTrap.hpp"

int main()
{
    ClapTrap claptrap1("Bob");

    claptrap1.attack("Target1");
    claptrap1.takeDamage(5);
    claptrap1.beRepaired(3);
    claptrap1.takeDamage(8);
}