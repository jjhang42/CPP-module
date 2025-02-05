#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template < typename T, class _Container = std::deque<T> >
class MutantStack : public std::stack<T, _Container>
{
	private:
		int	*arr;
	public:
		/* O.C.C.F. */
		MutantStack( void );
		MutantStack( MutantStack const &copy );
		MutantStack	&operator=( MutantStack const &copy );
		~MutantStack( void );

		/* MEMBER Type */
		typedef	_Container									container_type;
		typedef	typename container_type::value_type			value_type;
		typedef typename container_type::size_type			size_type;
		typedef typename container_type::reference			reference;
		typedef typename container_type::const_reference	const_reference;

	protected:
	public:
		/* Member Functions */
		// reference		top( void );
		// const_reference	top( void ) const;

		// /* Capacity */
		// bool			empty( void ) const;
		// size_type		size( void ) const;

		// /* modifiers */
		// void			push( const value_type& value );
		// // void			push( value_type&& value ); // since c++ 11
		// void			pop( void );

	public:
		/* iterator */
		typedef	typename		container_type::iterator				iterator;
		typedef	typename		container_type::const_iterator			const_iterator;
		typedef	typename		container_type::reverse_iterator		reverse_iterator;
		typedef	typename		container_type::const_reverse_iterator	const_reverse_iterator;

		iterator				begin( void );
		const_iterator			begin( void ) const;
		iterator				end( void );
		const_iterator			end( void ) const;
		reverse_iterator		rbegin( void );
		const_reverse_iterator	rbegin( void ) const;
		reverse_iterator		rend( void );
		const_reverse_iterator	rend( void ) const;
};

# include "MutantStack.tpp"

#endif