#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <list>
# include <algorithm>
# include <cmath>

# define EMPTY -1

template <template <class, class> class _Container >
class PmergeMe
{
	private:
		typedef	_Container< std::pair<int, int>, std::allocator< std::pair<int, int> > >	container_type;
		container_type	c;
		std::vector<int>	jacobsthalSequence;
		int					comparisonCnt;
		int					max;
	protected:
	public:
		/* O.C.C.F. */
		PmergeMe() { comparisonCnt = 0; max = 0; }
		PmergeMe(const PmergeMe &copy) : c(copy.c) { comparisonCnt = copy.comparisonCnt; max = copy.max;}
		PmergeMe &operator=(const PmergeMe &copy) {
			if (this != &copy) {
				c = copy.c;
				comparisonCnt = copy.comparisonCnt;
				max = copy.max;
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
	public:
		/* Capacity */
		size_type	size() const { return c.size(); }

		/* Methods */
		iterator	insert(iterator pos, const value_type &value) {
			return c.insert(pos, value);
		}

		/* NO INDEX */
		void	push_back( const int &value ) {
			max++;
			c.push_back(std::pair<int, int>(value, EMPTY));
		}

		void	push_back( const int &value, const int &index ) {
			max = index + 1;
			c.push_back(std::pair<int, int>(value, index));
		}

		void	push_back( std::pair<int, int>	&pair ) {
			c.push_back(pair);
		}

	private:
		void	consoleLog( std::string const &stage, container_type &Chain ) {
			std::clog << stage << std::endl;
			std::clog << "[CHAIN]" << std::endl;
			ShowStatus(Chain);
		}

		/* impliment method => low bound */
		iterator	LowBound( iterator begin, iterator end, int const &value ) {
			while ( begin != end ) {
				iterator	mid = begin;
				std::advance( mid, std::distance(begin, end) / 2 );
				if ( mid->first < value ) {
					begin = mid + 1;
				}
				else {
					end = mid;
				}
				comparisonCnt++;
			}
			return (begin);
		}

		void	ShowStatus( container_type &c ) const {
			std::clog << "Main: ";
			for (const_iterator it = c.begin(); it != c.end(); ++it) {
				std::clog << it->first << " ";
			}
			std::clog << std::endl;
			std::clog << "_Sub: ";
			for (const_iterator it = c.begin(); it != c.end(); ++it) {
				std::clog << it->second << " ";
			}
			std::clog << std::endl;
		}

		int	getSubIndex( int depth, int MainChainIdx ) {
			return ( MainChainIdx / static_cast<int>(std::pow(2, depth)));
		}

		std::pair<int, int>	SplitPair( container_type &c, container_type &chain, int idx) {
			std::pair<int, int>	temp;

			temp.first = c[idx].second;
			temp.second = EMPTY;
			c[idx].second = EMPTY;
			int	num = c[idx].first;
			iterator	it = chain.begin();
			for (; it != chain.end(); ++it) {
				if (it->first == num) {
						it->second = EMPTY;
					break;
				}
			}
			if (it != chain.end() && it->first == EMPTY && it->second == EMPTY)
				chain.erase(it);
			return (temp);
		}

		unsigned int	getSize( iterator begin, iterator end ) {
			unsigned int	Csize = 0;
			while (begin != end) {
				if (begin->first != EMPTY)
					Csize++;
				if (begin->second != EMPTY)
					Csize++;
				++begin;
			}
			return (Csize);
		}

		container_type	JacobsthalInsertionPhase( container_type &c ) {
			container_type	Chain = c;
			std::pair<int, int>	temp;
			unsigned int	size = getSize(c.begin(), c.end());
			/*  pairing */
			temp = SplitPair(c, Chain, 0);
			Chain.insert(Chain.begin(), temp);
			consoleLog("++insertion++", Chain );

			unsigned int	idx = 3;
			unsigned int	curSize = 2;
			while ( idx < jacobsthalSequence.size() && curSize < size)
			{
				unsigned int	maxNum = jacobsthalSequence[idx];
				unsigned int	Csize = c.size();
				if (maxNum > Csize)
					maxNum = Csize;
				unsigned int	minNum = jacobsthalSequence[idx - 1];
				std::cout << "MAX: " << maxNum << std::endl;
				std::cout << "MIN: " << minNum << std::endl;
				while (maxNum > minNum)
				{
					temp = SplitPair(c, Chain, maxNum - 1);
					iterator it = LowBound(Chain.begin(), Chain.end(), temp.first);
					Chain.insert(it, temp);
					maxNum--;
					curSize++;
				}
				idx++;
			}
			return (Chain);
		}


		/* Merge Insertion Sort */
		container_type	MergeInsertionSort( container_type &c ) {
 			/* Escape Condition */
			if (c.size() <= 1)
			{
				std::clog << "escape from recursive!" << std::endl;
				return (c);
			}
			container_type	Chain;
			/* Divide */
			size_t	i = 0;
			while (i + 1 < c.size())
			{
				if (c[i].first > c[i + 1].first) {
					Chain.push_back(std::pair<int,int>(c[i].first, c[i + 1].first));
				}
				else {
					Chain.push_back(std::pair<int,int>(c[i + 1].first, c[i].first));
				}
				comparisonCnt++;
				i += 2;
			}
			if (i < c.size())
				Chain.push_back(std::pair<int,int>(EMPTY, c[i].first));
			Chain = MergeInsertionSort( Chain );
			/* Insertion - binary Style */
			consoleLog("divide result", Chain);
			consoleLog("divide result??", c);
			std::cout << std::endl;
			/* Do recursive */
			Chain = JacobsthalInsertionPhase( Chain );
			return ( Chain );
		}

		/* J_n = J_{n-1} + 2J_{n-2} */
		/* J_0 = 0                  */
		/* J_1 = 1                  */
		/* J_2 = 1                  */
		/* J_3 = 3                  */
		/* J_4 = 5                  */
		/* J_5 = 11                 */
		/* ...                      */
		void	makeJacobsthalSequence( void ) {
			jacobsthalSequence.push_back(0);
			jacobsthalSequence.push_back(1);
			unsigned int	idx = 2;
			while ( true ) {
				unsigned int	js = (jacobsthalSequence[idx - 1]) + (2 * jacobsthalSequence[idx - 2]);
				jacobsthalSequence.push_back(js);
				idx++;
				if (js >= c.size())
					break ;
			}
			std::vector<int>::iterator it	= jacobsthalSequence.begin();
			for ( ; it != jacobsthalSequence.end(); ++it)
			{
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		}

	public:
		void	ShowStatus( void ) const {
			for (const_iterator	it = this->c.begin(); it != this->c.end(); ++it) {
				std::cout << it->first << " ";
			}
			std::cout << std::endl;
		}

		void	DoMergeInsertionSort( void ) {
			makeJacobsthalSequence();
			std::cout << "before: ";
			ShowStatus();
			this->c = MergeInsertionSort( this->c );
			std::cout << "after: ";
			ShowStatus();
			std::cout << "Numbers: " << max << std::endl;
			std::cout << "Comparision Count: " << comparisonCnt << std::endl;
		}
};

#endif