#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1) {
		std::cerr << "Error: Enter the parameter!" << std::endl;
		return (1);
	}

	PmergeMe<std::vector>	p;
	// PmergeMe< std::pair<int, int> >	l;
	for (int i = 1; i < argc; i++) {
		std::pair<int, int>	c = std::pair<int, int>(std::atoi(argv[i]), i);
		p.push_back(c);
	}
	std::cout << "container: vector" << std::endl;
	p.DoMergeInsertionSort();

	return (0);
}