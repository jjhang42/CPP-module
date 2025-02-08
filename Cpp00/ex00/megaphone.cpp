#include <iostream> //<stdio.h>
#include <string>

#include <cctype>
// using namespace std;

int	main(int argc, char *argv[])
{
	// char *str;
	std::string				str;
	std::string::iterator	it;
	static std::string		error = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (argc != 1)
	{
		for (int idx = 1; idx < argc; idx++)
		{
			str = argv[idx];
			it = str.begin();
			for (; it != str.end(); it++)
				std::cout << static_cast<char>(std::toupper(*it));
				// std::cin >> str;
		}
	}
	else
		std::cout << error;
	std::cout << std::endl;
	// std::cout << "\n";
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	int	idx1;
// 	int	idx2;

// 	idx1 = 1;
// 	while (idx1 < argc)
// 	{
// 		idx2 = 0;
// 		while (argv[idx1][idx2] != '\0')
// 		{
// 			if (std::isupper(argv[idx1][idx2]) != true && \
// 				std::isalpha(argv[idx1][idx2]) == true)
// 				std::cout << (char)(argv[idx1][idx2] - 32);
// 			else
// 				std::cout << (char)argv[idx1][idx2];
// 			idx2++;
// 		}
// 		idx1++;
// 	}
// 	std::cout << '\n';
// 	return (0);
// }
