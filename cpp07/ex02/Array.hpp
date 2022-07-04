#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template< typename T >
class Array
{
	public:

		Array<T>() : _size(0), _tab(new T[0]) {}
		Array<T>(unsigned int n) : _size(n), _tab(new T[n]) {}
		Array<T>(Array<T> const & src ) {*this = src;}
		~Array<T>() { delete [] _tab; }

		Array<T> & operator=(Array<T> const & src) {
			this->_size = src._size;
			this->_tab = new T[src._size];
			for (int i = 0; i < src._size; i++)
				this->_tab[i] = src._tab[i];
			return *this;
		}

		T & operator[](unsigned int i) {
			if (i >= this->_size)
				throw BufferOverflowException();
			return this->_tab[i];
		}

		unsigned int size() const {return this->_size;}

		class BufferOverflowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return "Array buffer overflow!!!";
				}
		};

	private:

		unsigned int _size;

		T * _tab;
};

#endif