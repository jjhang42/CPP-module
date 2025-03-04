#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1) {
		std::cerr << "Error: Enter the parameter!" << std::endl;
		return (1);
	}

	PmergeMe<std::vector<int> >	p;
	// PmergeMe< std::list<int> >	l;
	for (int i = 1; i < argc; i++) {
		p.push_back(std::atoi(argv[i]));
	}
	std::cout << "container: vector" << std::endl;
	p.DoMergeInsertionSort();

	return (0);
}