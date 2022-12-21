#include "Harl.h"
#include <iostream>

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
	<< std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! "
				 "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for "
				 "years whereas you started working here since last month."
			  << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; ++i)
	{
		if (level == levels[i])
		{
			(this->*harl_complains[i])();
			break;
		}
	}
}

Harl::Harl()
{
	harl_complains[0] = &Harl::debug;
	harl_complains[1] = &Harl::info;
	harl_complains[2] = &Harl::warning;
	harl_complains[3] = &Harl::error;
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
}

void Harl::harlFilter(const std::string& level)
{
	int index = -1;
	for (int i = 0; i < 4; ++i)
	{
		if (level == levels[i])
		{
			index = i;
			break;
		}
	}
	switch (index)
	{
		case 0:
			std::cout << "[ " << levels[0] << " ]" << std::endl;
			(this->*harl_complains[0])();
			std::cout << std::endl;
		case 1:
			std::cout << "[ " << levels[1] << " ]" << std::endl;
			(this->*harl_complains[1])();
			std::cout << std::endl;
		case 2:
			std::cout << "[ " << levels[2] << " ]" << std::endl;
			(this->*harl_complains[2])();
			std::cout << std::endl;
		case 3:
			std::cout << "[ " << levels[3] << " ]" << std::endl;
			(this->*harl_complains[3])();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
