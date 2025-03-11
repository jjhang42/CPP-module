#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1) {
		std::cerr << "Error: Enter the parameter!" << std::endl;
		return (1);
	}

	PmergeMe<std::vector>	p;
	// PmergeMe< std::pair<int, int> >	l;
	/* binary */
	// for (int idx = 1; idx < argc; idx++) {
	// 	p.push_back(std::atoi(argv[idx]), idx - 1);
	// }
	/* js */
	for (int idx = 1; idx < argc; idx++)
	{
		p.push_back(std::atoi(argv[idx]));
	}
	std::cout << "container: vector" << std::endl;
	p.DoMergeInsertionSort();

	return (0);
}