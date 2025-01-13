#ifndef DATA_HPP
# define DATA_HPP

class Data
{
	private:
		int	value;
	protected:
	public:
		Data( void );
		Data( Data const &Data );
		~Data( void );
		Data &operator=( Data const &Data );
		void	setValue( int val );
		int	getValue( void ) const;
};

#endif