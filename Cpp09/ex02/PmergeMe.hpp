#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>

template <class _Container = std::vector<int> >
class PmergeMe
{
	private:
		_Container	c;
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
		typedef _Container container_type;
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

		void		push_back(const value_type &value) {
			c.push_back(value);
		}

		size_t	getComparisonCount( void ) const {
			return (comparisonCount);
		};

	private:
		/* empliment method => low bound */
		iterator	LowBound( container_type &chain, int &value ) {
			iterator	begin = chain.begin();
			iterator	end = chain.end();
			iterator	it;

			size_t	cnt = 0;
			for ( ; begin != end; ++begin) {
				cnt++;
			}

			begin = chain.begin();
			int	step;
			while ( cnt > 0) {
					step = cnt / 2;
				if ( *begin < value ) {
					step--;
					it = ++begin;
				}
				else
					cnt = step;
			}
			return (it);
		}

		void	ShowStatus( container_type &c ) const {
			for (const_iterator it = c.begin(); it != c.end(); ++it) {
				std::clog << *it << " ";
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
			for ( ; i < c.size() / 2 ; i += 2 )
			{
				if (c[i] > c[i + 1]) {
					MainChain.push_back(c[i]);
					SubChain.push_back(c[i + 1]);
				}
				else if (c[i] <= c[i + 1]) {
					MainChain.push_back(c[i + 1]);
					SubChain.push_back(c[i]);
				}
			std::clog << "parameter: ";
			ShowStatus(temp);
			std::clog << std::endl;
			std::clog << "MainChain: ";
			ShowStatus(MainChain);
			std::clog << std::endl;
			std::clog << "SubChain : ";
			ShowStatus(SubChain);
			std::clog << std::endl;
			}
			if ( c.size() % 2 == 1)
				MainChain.push_back(c[c.size() - 1]);

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
			iterator it = LowBound(MainChain, SubChain[0]);
			MainChain.insert(it, SubChain[0]);
			return ( MainChain );
		}

	public:
		void	ShowStatus( void ) const {
			for (const_iterator	it = this->c.begin(); it != this->c.end(); ++it) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		}

		void	DoMergeInsertionSort( void ) {
			cnt = 0;
			std::cout << "before: ";
			ShowStatus();
			this->c = MergeInsertionSort(this->c);
			std::cout << "after: ";
			ShowStatus();
		}
};

#endif