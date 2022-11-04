#ifndef VECTOR_HPP
# define VECTOR_HPP

// TOFIX Not needed at the end
#include <stdexcept>

#include <memory>
#include "../iterators.hpp"

namespace	ft
{
	template<
		class T,
		class Allocator = std::allocator<T>
	>
	class vector
	{
	
		// Iterator
		class	RandomAccessIterator
		{
			public:
				// TODO Use ft::iterator_traits ?
				typedef T		value_type;
				typedef	T*		pointer;
				typedef	T&		reference;
				// TOFIX Use self-made types
				typedef std::ptrdiff_t	difference_type;
				typedef	std::random_access_iterator_tag	iterator_category;
				
				// Constructors
				RandomAccessIterator() { };
				RandomAccessIterator(pointer ptr) : _ptr(ptr) { };
				RandomAccessIterator(RandomAccessIterator const &copy) { *this = copy; };
				RandomAccessIterator	&operator=(RandomAccessIterator const &copy)
				{
					_ptr = copy._ptr;
					return (*this);
				};
				// Destructor
				~RandomAccessIterator() { };

				// Operator overload
				reference	operator*() const { return (*_ptr); }
				pointer		operator->() { return (_ptr); }
				RandomAccessIterator	&operator++() { _ptr++; return (*this); }
				RandomAccessIterator	operator++(int) { RandomAccessIterator tmp = *this; ++(*this); return (tmp); }
				RandomAccessIterator	&operator--() { _ptr--; return (*this); }
				RandomAccessIterator	operator--(int) { RandomAccessIterator tmp = *this; --(*this); return (tmp); }
				RandomAccessIterator	&operator+=(RandomAccessIterator const &rhs) { this->_ptr += rhs._ptr; return (*this); }
				RandomAccessIterator	&operator-=(RandomAccessIterator const &rhs) { this->_ptr -= rhs._ptr; return (*this); }
				RandomAccessIterator	&operator[](size_t pos) { return (this->_ptr[pos]); }
				friend bool	operator==(RandomAccessIterator const &a, RandomAccessIterator const &b) { return (a._ptr == b._ptr); }
				friend bool	operator!=(RandomAccessIterator const &a, RandomAccessIterator const &b) { return (a._ptr == b._ptr); }
				friend bool	operator>(RandomAccessIterator const &a, RandomAccessIterator const &b) { return (a._ptr > b._ptr); }
				friend bool	operator<(RandomAccessIterator const &a, RandomAccessIterator const &b) { return (a._ptr < b._ptr); }
				friend bool	operator>=(RandomAccessIterator const &a, RandomAccessIterator const &b) { return (a._ptr >= b._ptr); }
				friend bool	operator<=(RandomAccessIterator const &a, RandomAccessIterator const &b) { return (a._ptr <= b._ptr); }
				friend	RandomAccessIterator	operator+(RandomAccessIterator const &lhs, RandomAccessIterator const &rhs) { lhs += rhs; return (lhs); }
				friend	RandomAccessIterator	operator-(RandomAccessIterator const &lhs, RandomAccessIterator const &rhs) { lhs += rhs; return (lhs); }
			private:
				pointer	_ptr;
		};
		class	ReverseRandomAccessIterator;
		class	ConstReverseRandomAccessIterator;

		public:
			//Iterators
			typedef ft::vector<T, Allocator>::RandomAccessIterator			iterator;
			typedef	const ft::vector<T, Allocator>::RandomAccessIterator	const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		private:

			// Member types
			typedef T									value_type;
			typedef	Allocator							allocator_type;
			typedef	size_t								size_type;
			typedef	ptrdiff_t							difference_type; // TOCHECK
			typedef	value_type&							reference;
			typedef	const value_type&					const_reference;
			typedef	typename Allocator::pointer			pointer;
			typedef	typename Allocator::const_pointer	const_pointer;

			Allocator	_alloc;
			T			*_arr;
			size_t		_size;
			size_t		_capacity;

			void		realloc(size_type new_capacity)
			{
				if (new_capacity <= this->_capacity * 2)
					new_capacity = this->_capacity * 2;
				T	*new_arr = this->_alloc.allocate(new_capacity);
				for (int i = 0; i < this->_capacity; i++)
					new_arr[i] = this->_arr[i];
				this->_alloc.deallocate(this->_arr, this->_capacity);
				this->_arr = new_arr;
				this->_capacity = new_capacity;
			}
		public:
			vector() 
			{
				// TOCHECK
				this->_size = 0;
				this->_capacity = 0;
			}

			vector(vector const &copy)
			{
				*this = copy;
			}

			vector	&operator=(vector const &copy)
			{
				// TOCHECK
				int	i = 0;
				this->_alloc = copy._alloc;
				this->_size = copy._size;
				this->_capacity = copy._capacity;
				this->_arr = this->_alloc.allocate(this->_capacity);
				if (this->_size > 0)
				{
					while (i < this->_capacity)
					{
						this->_arr[i] = copy._arr[i];
						i++;
					}
				}
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
				// TOCHECK ~Need to check if it's enough
				if (this->_capacity > 0)
					this->_alloc.deallocate(this->_arr, this->_capacity);
			}

			// Assign
			void assign(size_type count, const T& value)
			{
				// TOCHECK ~Need to check if it's enough
				if (this->_capacity > 0)
					this->_alloc.deallocate(this->_arr, this->_capacity);
				this->_arr = this->_alloc.allocate(count);
				this->_size = count;
				this->_capacity = count;
				for (int i = 0; i < count; i++)
					this->_arr[i] = value;
			}

			template<class InputIt>
			void assign(InputIt first, InputIt last)
			{
				// TOCHECK ~Need to check if it's enough
				InputIt tmp = first;
				int	i = 0;
				int	j = 0;
				if (this->_capacity > 0)
					this->_alloc.deallocate(this->_arr, this->_capacity);
				this->_capacity = 0;
				while (tmp != last)
				{
					i++;
					tmp++;
				}
				this->_arr = this->_alloc.allocate(i);
				while (j != i)
				{
					this->_arr[this->_capacity] = *first;
					this->_capacity++;
					first++;
					j++;
				}
				this->_size = this->_capacity;
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

			const_reference	&operator[](size_type pos) const { return (this->_arr[pos]); }

			reference	front()
			{
				// TOCHECK
				return (this->_arr[0]);
			}

			const_reference	front() const
			{
				// TOCHECK
				return (this->_arr[0]);
			}

			reference	back()
			{
				// TOCHECK
				return (this->_arr[this->_size - 1]);
			}

			const_reference	back() const
			{
				// TOCHECK
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
				return (iterator(&this->_arr[0]));
			}

			const_iterator	begin() const
			{
				// TOCHECK
				return (const_iterator(&this->_arr[0]));
			}

			iterator	end()
			{
				return (iterator(&this->_arr[this->_size]));
			}

			const_iterator	end() const
			{
				return (const_iterator(&this->_arr[this->_size]));
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

			size_type	size() const { return (this->_size); }

			size_type	max_size() const { return (this->_alloc.max_size()); }

			void	reserve(size_type new_cap)
			{
				// TOCHECK
				// TODO self-made exceptions
				if (new_cap > max_size())
					throw std::length_error("Length error");
				if (new_cap < this->_capacity)
					return	;
				this->realloc(new_cap);
			}

			size_type	capacity() const { return (this->_capacity); }

			// Modifiers
			void		clear()
			{
				// TOFIX not working like the std version (accessing vector[0] after calling clear should SEGFAULT)
				for (int i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_arr[i]);
				this->_size = 0;
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
				// TOCHECK
				if (this->_size + 1 >= this->_capacity)
					this->realloc(this->_capacity + 1);
				this->_alloc.construct(this->_arr + this->_size, value);
				this->_size++;
			}

			void		pop_back()
			{
				// TOCHECK
				this->_alloc.destroy(this->_arr + this->_size);
				if (this->_size > 1)
					this->_size--;
			}

			void		resize(size_type count, T value = T())
			{
				// TOCHECK
				if (count > this->max_size())
					throw std::length_error("Length error");
				if (this->_size > count)
				{
					this->realloc(count);
					this->_size = count;
				}
				else if (this->_size < count)
				{
					this->realloc(count);
					while (this->_size != count)
					{
						this->_arr[this->_size] = value;
						this->_size++;
					}
				}
			}

			void		swap(vector &other)
			{
				// TOCHECK
				vector<T, Allocator>	tmp(other);

				other = *this;
				*this = tmp;
			}

			// Friend functions

			friend void swap(ft::vector<T, Allocator>& lhs, ft::vector<T, Allocator>& rhs);

			// TOCHECK when operator overloading are done if necessary or not
			// friend bool operator==(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs);

			// friend bool operator!=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs);

			// friend bool operator<(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs);

			// friend bool operator<=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs);

			// friend bool operator>(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs);

			// friend bool operator>=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs);
	};

	// TODO swap must be used like this : ft::swap()
	template<class T, class Allocator>
	void swap(ft::vector<T, Allocator>& lhs, ft::vector<T, Allocator>& rhs)
	{
		// TOCHECK
		vector<T, Allocator>	tmp(lhs);

		lhs = rhs;
		rhs = tmp;
	}

	template< class T, class Allocator>
	bool operator==(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
	{
		// TOFIX Doesn't enter in the while loop
		if (lhs.size() != rhs.size())
			return (false);
		int i = 0;
		typename ft::vector<T, Allocator>::iterator	begin_l = lhs.begin();
		typename ft::vector<T, Allocator>::iterator	begin_r = rhs.begin();
		typename ft::vector<T, Allocator>::iterator	end = lhs.end();
		std::cout << *begin_l << " " << *end << std::endl;
		while (begin_l != end)
		{
			if (*begin_l != *begin_r)
				return (false);
			begin_r++;
			begin_l++;
		}
		return (true);
	}

	template< class T, class Allocator>
	bool operator!=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
	{
		// TODO
	}

	template< class T, class Allocator>
	bool operator<(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
	{
		// TODO
	}
	
	template< class T, class Allocator>
	bool operator<=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
	{
		// TODO
	}
	
	template< class T, class Allocator>
	bool operator>(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
	{
		// TODO
	}
	
	template< class T, class Allocator>
	bool operator>=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
	{
		// TODO
	}
	
}
#endif