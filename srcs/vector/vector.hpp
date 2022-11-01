#ifndef VECTOR_HPP
# define VECTOR_HPP

// TOFIX Not needed at the end
#include <stdexcept>
#include <memory>
#include "iterator.hpp"

namespace	ft
{
	template<
		class T,
		class Allocator = std::allocator<T>
	>
	class vector
	{
	
		// Iterator
		class	RandomAccessIterator;
		class	ConstRandomAccessIterator;
		class	ReverseRandomAccessIterator;
		class	ConstReverseRandomAccessIterator;

		private:

			// Member types
			typedef T									value_type;
			typedef	Allocator							allocator_type;
			typedef	size_t								size_type;
			typedef	ptrdiff_t							difference_type;
			// TODO Need to check if these two below are working correctly
			typedef	value_type&							reference;
			typedef	const value_type&					const_reference;
			typedef	typename Allocator::pointer			pointer;
			typedef	typename Allocator::const_pointer	const_pointer;
			typedef	typename ft::vector<T, Allocator>::RandomAccessIterator				iterator;
			typedef	typename ft::vector<T, Allocator>::ConstRandomAccessIterator		const_iterator;
			typedef	typename ft::vector<T, Allocator>::ReverseRandomAccessIterator		reverse_iterator;
			typedef	typename ft::vector<T, Allocator>::ConstReverseRandomAccessIterator	const_reverse_iterator;

			Allocator	_alloc;
			T			*_arr;
			size_t		_size;
			size_t		_capacity;
		public:
			vector() 
			{
				// TOCHECK
				this->_size = 0;
				this->_capacity = 0;
			}

			vector(vector const &copy)
			{
				if (*this != copy)
					*this = copy;
			}

			vector	&operator=(vector const &copy)
			{
				// TODO Deep copy, do at the end
				return (*this);
			}

			explicit vector(const allocator_type& alloc)
			{
				// TOCHECK ~Need to check if it's enough
				this->_alloc = alloc;
			}

			explicit vector(size_type count, const T& value = T(), const allocator_type& alloc = Allocator())
			{
				// TODO
			}

			template<class InputIt>
			vector(InputIt first, InputIt last, const allocator_type& alloc = Allocator())
			{
				// TODO
			}

			// Destructor
			~vector()
			{
				// TODO
			}

			// Assign
			void assign(size_type count, const T& value)
			{
				// TODO
			}

			template<class InputIt>
			void assign(InputIt first, InputIt last)
			{
				// TODO
			}

			// Get_allocator
			allocator_type get_allocator() const
			{
				// TOCHECK Need to check if it's correct
				return (this->_alloc);
			}

			// Element access
			reference	at(size_type pos)
			{
				// TOFIX Use self-made out_of_range exception with right msg
				if (!(pos < this->_size))
					throw	std::out_of_range("out of range");
				return (this->_arr[pos]);
			}

			const_reference	at(size_type pos) const
			{
				// TOFIX Use self-made out_of_range exception with right msg
				if (!(pos < this->_size))
					throw	std::out_of_range("out of range");
				return (this->_arr[pos]);
			}

			reference	&operator[](size_type pos) { return (this->_arr[pos]); }

			const_reference	&operator[](size_type pos) const;

			reference	front()
			{
				// TOCHECK
				// if (this->empty())
				// 	return ();
				return (this->_arr[0]);
			}

			const_reference	front() const
			{
				// TOCHECK
				// if (this->empty())
				// 	return ();
				return (this->_arr[0]);
			}

			reference	back()
			{
				// TOCHECK
				// if (this->empty())
				// 	return ();
				return (this->_arr[this->_size - 1]);
			}

			const_reference	back() const
			{
				// TOCHECK
				// if (this->empty())
				// 	return ();
				return (this->_arr[this->_size - 1]);
			}

			T	*data()
			{
				// TOCHECK
				if (this->_size == 0)
					return (NULL);
				return (this->_arr);
			}

			const T	*data() const
			{
				// TOCHECK
				if (this->_size == 0)
					return (NULL);
				return (this->_arr);
			}

			// Iterators
			iterator		begin()
			{
				// TODO
			}

			const_iterator	begin() const
			{
				// TODO
			}

			iterator	end()
			{
				// TODO
			}

			const_iterator	end() const
			{
				// TODO
			}

			reverse_iterator	rbegin()
			{
				// TODO
			}

			const_reverse_iterator	rbegin() const
			{
				// TODO
			}

			reverse_iterator	rend()
			{
				// TODO
			}

			const_reverse_iterator	rend() const
			{
				// TODO
			}

			// Capacity
			bool		empty() const
			{
				if (this->begin() == this->end())
					return (true);
				return (false);
			}

			size_type	size() const { return (this->size); }

			size_type	max_size() const { return (this->_alloc.max_size()); }

			void	reserve(size_type new_cap)
			{
				// TODO
			}

			size_type	capacity() const { return (this->_capacity); }

			// Modifiers
			void		clear()
			{
				// TODO
			}

			iterator	insert(const_iterator pos, const T &value)
			{
				// TODO
			}

			iterator	insert(const_iterator pos, size_type count, const T& value)
			{
				// TODO
			}

			template<class InputIt>
			iterator	insert(const_iterator pos, InputIt first, InputIt last)
			{
				// TODO
			}

			iterator	erase(iterator pos)
			{
				// TODO
			}

			iterator	erase(iterator first, iterator last)
			{
				// TODO
			}

			void		push_back(const T& value)
			{
				// TODO
			}

			void		pop_back()
			{
				// TODO
			}

			void		resize(size_type count, T value = T())
			{
				// TODO
			}

			void		swap(vector &other)
			{
				// TODO
			}

			// Friend functions

			friend void swap(std::vector<T, Allocator>& lhs, std::vector<T, Allocator>& rhs);

			friend bool operator==(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

			friend bool operator!=(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

			friend bool operator<(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

			friend bool operator<=(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

			friend bool operator>(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

			friend bool operator>=(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);
	};

	// TODO swap must be used like this : ft::swap()
	template<class T, class Allocator>
	void swap(std::vector<T, Allocator>& lhs, std::vector<T, Allocator>& rhs);

	template< class T, class Allocator>
	bool operator==(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

	template< class T, class Allocator>
	bool operator!=(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

	template< class T, class Allocator>
	bool operator<(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

	template< class T, class Allocator>
	bool operator<=(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

	template< class T, class Allocator>
	bool operator>(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

	template< class T, class Allocator>
	bool operator>=(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);
}
#endif