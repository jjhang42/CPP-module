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
			max++;
			c.push_back(std::pair<int, int>(value, index));
		}

		void	push_back( std::pair<int, int>	&pair ) {
			c.push_back(pair);
		}

	private:
		void	consoleLog( std::string const &stage, container_type &Main, container_type &Sub ) {
			std::clog << stage << std::endl;
			std::clog << "[MAIN]" << std::endl;
			ShowStatus(Main);
			std::clog << "[SUB]" << std::endl;
			ShowStatus(Sub);
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
			for (const_iterator it = c.begin(); it != c.end(); ++it) {
				std::clog << it->first << " ";
			}
			std::clog << std::endl;
		}

		int	getSubIndex( int depth, int MainChainIdx ) {
			return ( MainChainIdx / static_cast<int>(std::pow(2, depth)));
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

		iterator	getIteratorInPair( container_type &MainChain, std::pair<int, int> &src ) {
			iterator	it = MainChain.begin();
			int			idx = src.second;
			for ( ; it != MainChain.end(); ++it ) {
				if (idx == it->second)
					return (it);
			}
			return (MainChain.end());
		}

		container_type	JacobsthalInsertionPhase( container_type &MainChain, container_type &SubChain ) {
			MainChain.insert(MainChain.begin(), *SubChain.begin());
			unsigned int	idx = 3;
			while ( idx < jacobsthalSequence.size() )
			{
				unsigned int	max = jacobsthalSequence[ idx ];
				unsigned int	min = jacobsthalSequence[ idx - 1 ];
				unsigned int	subsize = SubChain.size();
				if (max > subsize)
					max = subsize;
				while (max > min)
				{
					iterator	it = LowBound(MainChain.begin(),getIteratorInPair(MainChain, SubChain[max - 1]), SubChain[max - 1].first);
					MainChain.insert(it, SubChain[max - 1]);
					max--;
				}
				idx++;
			}
			return (MainChain);
		}

		container_type	setPairing( container_type &MainChain, container_type &SubChain ) {
			container_type	NewSubChain;
			for (iterator	it = MainChain.begin(); it != MainChain.end() ; ++it ) {
				for (iterator subit = SubChain.begin(); subit != SubChain.end(); ++subit ) {
					if ( subit->second == it->second ) {
						NewSubChain.push_back(*subit);
						SubChain.erase(subit);
						break ;
					}
				}
			}
			if (SubChain.size() != 0)
				NewSubChain.push_back(*SubChain.begin());
			return (NewSubChain);
		}

		container_type	recoverIndex( container_type &dst, container_type &src ) {
			for (iterator	dstit = dst.begin(); dstit != dst.end() ; ++dstit ) {
				for (iterator srcit = src.begin(); srcit != src.end(); ++srcit ) {
					if ( dstit->first == srcit->first ) {
						dstit->second = srcit->second;
						break ;
					}
				}
			}
			return (dst);
		}
		/* Merge Insertion Sort */
		container_type	MergeInsertionSort( container_type &c ) {
 			/* Escape Condition */
			if (c.size() <= 1)
			{
				std::clog << "escape from recursive!" << std::endl;
				return (c);
			}
			container_type	MainChain;
			container_type	SubChain;
			/* Divide */
			size_t	i = 0;
			while (i + 1 < c.size())
			{
				if (c[i].first > c[i + 1].first) {
					MainChain.push_back(std::pair<int, int>(c[i].first, i));
					SubChain.push_back(std::pair<int, int>(c[i + 1].first, i));
				}
				else {
					MainChain.push_back(std::pair<int, int>(c[i + 1].first, i));
					SubChain.push_back(std::pair<int, int>(c[i].first, i));
				}
				comparisonCnt++;
				i += 2;
			}
			if (i < c.size())
				SubChain.push_back(c[i]);
			MainChain = MergeInsertionSort( MainChain );
			consoleLog("merge result:", MainChain, SubChain);
			/* pairing */
			SubChain = setPairing( MainChain, SubChain );

			consoleLog("pairing", MainChain, SubChain);
			/* Insertion - binary Style */
			MainChain = JacobsthalInsertionPhase( MainChain, SubChain );
			MainChain = recoverIndex(MainChain, c);
			consoleLog("insertion result: ", MainChain, SubChain);

			return ( MainChain );
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