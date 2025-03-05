#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>

# define PAIR std::pair<int, int>

template <template <class, class> class _Container >
class PmergeMe
{
	private:
		typedef	_Container< std::pair<int, int>, std::allocator< std::pair<int, int > > >	container_type;
		container_type	c;
		size_t		comparisonCount;
		int	cnt;

		public:
		/* O.C.C.F. */
		PmergeMe() { comparisonCount = 0; }
		PmergeMe(const PmergeMe &copy) : c(copy.c) { comparisonCount = copy.comparisonCount; }
		PmergeMe &operator=(const PmergeMe &copy) {
			if (this != &copy) {
				c = copy.c;
				comparisonCount = copy.comparisonCount;
			}
			return (*this);
		}
		~PmergeMe() {}

		/* Container type */
		typedef typename container_type::value_type value_type;
		typedef typename container_type::size_type size_type;
		typedef typename container_type::reference reference;
		typedef typename container_type::const_reference const_reference;

		/* Iterator */
		typedef typename container_type::iterator iterator;
		typedef typename container_type::const_iterator const_iterator;
		typedef typename container_type::reverse_iterator reverse_iterator;
		typedef typename container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() { return c.begin(); }
		const_iterator begin() const { return c.begin(); }
		iterator end() { return c.end(); }
		const_iterator end() const { return c.end(); }
		reverse_iterator rbegin() { return c.rbegin(); }
		const_reverse_iterator rbegin() const { return c.rbegin(); }
		reverse_iterator rend() { return c.rend(); }
		const_reverse_iterator rend() const { return c.rend(); }

		/* Capacity */
		size_type	size() const { return c.size(); }

		/* Methods */
		iterator	insert(iterator pos, const value_type &value) {
			return c.insert(pos, value);
		}

		void		push_back(const int &value1, const int &value2 ) {
			c.push_back(PAIR(value1, value2));
		}

		void	push_back(std::pair<int, int> &value) {
			c.push_back(value);
		}

		size_t	getComparisonCount( void ) const {
			return (comparisonCount);
		};

	private:
		void	consoleLog( std::string const &stage, container_type &MainChain, container_type &SubChain ) {
			std::clog << stage << std::endl;
			std::clog << std::endl;
			std::clog << "MainChain: ";
			ShowStatus(MainChain);
			std::clog << std::endl;
			std::clog << "SubChain : ";
			ShowStatus(SubChain);
			std::clog << std::endl;
		}

		/* empliment method => low bound */
		iterator	LowBound( container_type &chain, int &value ) {
			iterator	begin = chain.begin();
			iterator	end = chain.end();

			begin = chain.begin();
			while ( begin != end ) {
				iterator	mid = begin;
				std::advance( mid, std::distance(begin, end) / 2 );
				if ( *mid < value ) {
					begin = mid;
					++begin;
				}
				else {
					end = mid;
				}
			}
			return (begin);
		}

		void	ShowStatus( container_type &c ) const {
			for (const_iterator it = c.begin(); it != c.end(); ++it) {
				std::clog << it->first << " ";
			}
		}

		/* Merge Insertion Sort */
		container_type	MergeInsertionSort( container_type &c ) {
			container_type	MainChain;
			container_type	SubChain;

			std::clog << std::endl << "cnt: " << cnt++ << std::endl;
			if (c.size() <= 1)
			{
				std::clog << "escape from recursive!" << std::endl;
				return (c);
			}
			/* Merge style */
			std::clog << "divide started" << std::endl;
			container_type	temp = c;
			size_t	i = 0;
			while ( i + 1 < c.size() )
			{
				if (c[i] > c[i + 1]) {
					MainChain.push_back(PAIR(c[i].first, c[i].second));
					SubChain.push_back(PAIR(c[i + 1].first, c[i].second));
				}
				else if (c[i] <= c[i + 1]) {
					MainChain.push_back(PAIR(c[i + 1].first, c[i].second));
					SubChain.push_back(PAIR(c[i].first, c[i].second));
				}
				i += 2;
			}
			std::cout << "i : " << i << std::endl;
			if ( i < c.size() )
				MainChain.push_back(PAIR(c[i].first, c[i].second));

			consoleLog( "Result: Divide Two Containers", MainChain, SubChain );
			/* pair to mapping */


			consoleLog( "Result: Rearrange pair", MainChain, SubChain );
			/* Do recursive */
			MainChain = MergeInsertionSort( MainChain );

			/* Do Chain Split results */
			std::clog << "Divide Done: " << std::endl;
			std::clog << "MainChain: ";
			ShowStatus(MainChain);
			std::clog << std::endl;
			std::clog << "SubChain : ";
			ShowStatus(SubChain);
			std::clog << std::endl;
			/* Insertion - binary Style */

			return ( MainChain );
		}

	public:
		void	ShowStatus( void ) const {
			for (const_iterator	it = this->c.begin(); it != this->c.end(); ++it) {
				std::cout << it->first << " ";
			}
			std::cout << std::endl;
		}

		void	DoMergeInsertionSort( void ) {
			std::cout << "before: ";
			ShowStatus();
			this->c = MergeInsertionSort(this->c);
			std::cout << "after: ";
			ShowStatus();
		}
};

#endif