#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1) {
		std::cerr << "Error: Enter the parameter!" << std::endl;
		return (1);
	}

	PmergeMe<std::vector>	p;
	PmergeMe<std::list>		l;
	int	idx = 0;
	int	cnt = 1;
	while (cnt < argc)
	{
		l.push_back(std::atoi(argv[cnt]), idx);
		p.push_back(std::atoi(argv[cnt]), idx);
		cnt++;
		if (cnt < argc)
		{
			l.push_back(std::atoi(argv[cnt]), idx);
			p.push_back(std::atoi(argv[cnt]), idx);
			cnt++;
		}
		idx++;
	}
	std::string	str;
	str = p.DoMergeInsertionSort(true, "std::vector<int>");
	std::cout << str;
	str = l.DoMergeInsertionSort(false, "std::list<int>");
	std::cout << str;
	return (0);
}