#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) 
{
    std::cout << "ClapTrap " << Name << " has been created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap" << Name << "has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (HitPoints > 0 && EnergyPoints > 0)
    {
        std::cout << "ClapTrap " << Name << " attacks " << target << " ,causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    }
    else if (EnergyPoints == 0)
        std::cout << "ClapTrap "<< Name << " has no energy to attck!" << std::endl;
    else if (HitPoints == 0)
        std::cout << "ClapTrap " << Name << " has no hit points and cannot attack!" << std::endl;    
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount == 0)
        std::cout << "ClapTrap " << Name << " was not damage" << std::endl;
    else if (HitPoints > 0)
    {
        if (amount >= static_cast<unsigned int>(HitPoints))
        {
            HitPoints = 0;
            std::cout << "ClapTrap " << Name << " has been destroyed!!" << std::endl;
        }
        else
        {
            HitPoints -= amount;
            std::cout << "ClapTrap " << amount << " takes " << amount
                << " points of damage! Remaining hit points: " << HitPoints << std::endl; 
        }
    }

    else if (HitPoints == 0)
         std::cout << "ClapTrap "<< Name << " is already destroyed!" << std::endl;
}

 void ClapTrap::beRepaired(unsigned int amount) 
 {
        if (HitPoints > 0 && EnergyPoints > 0) {
            HitPoints += amount;
            EnergyPoints--;
            std::cout << "ClapTrap " << Name << " repairs itself, restoring " << amount 
                      << " hit points! Total hit points: " << HitPoints << std::endl;
        } 
        else if (EnergyPoints == 0)
            std::cout << "ClapTrap " << Name << " has no energy to repair!" << std::endl;
        else if (HitPoints == 0)
            std::cout << "ClapTrap " << Name << " cannot repair because it's destroyed!" << std::endl;
    }