#include "Zombie.hpp"

int	main(void)
{
	/* stack Zombie */
	Zombie yeoshin("yeoshin");
	yeoshin.announce();

	/* heap Zombie */
	Zombie *inryu = newZombie("inryu");
	inryu->announce();
	delete inryu;

	/* stack zombie */
	randomChump("hyochoi");

	return (0);
}

