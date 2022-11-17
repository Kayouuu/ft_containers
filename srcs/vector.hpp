/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:11:25 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/17 17:36:39 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <stdexcept>
#include <memory>
#include "iterators.hpp"
#include "ft_containers.hpp"

namespace	ft
{
	template<
		class T,
		class Allocator = std::allocator<T>
	>
	class vector
	{
		public:
			// Iterators
			typedef ft::RandomAccessIterator<T, vector>				iterator;
			typedef	ft::RandomAccessIterator<const T, vector>		const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			// Member types
			typedef T									value_type;
			typedef	Allocator							allocator_type;
			typedef	size_t								size_type;
			typedef	long int							difference_type;
			typedef	value_type&							reference;
			typedef	const value_type&					const_reference;
			typedef	typename Allocator::pointer			pointer;
			typedef	typename Allocator::const_pointer	const_pointer;
		private:


			Allocator	_alloc;
			T			*_arr;
			size_t		_size;
			size_t		_capacity;

			void		realloc(size_type new_capacity)
			{
				// if (new_capacity <)
				// if (_capacity == 0 && new_capacity )
				// 	new_capacity = 1;
				if (new_capacity <= this->_capacity * 2)
					new_capacity = this->_capacity * 2;
				T	*new_arr = this->_alloc.allocate(new_capacity);
				if (this->_arr != NULL)
				{
					for (size_t i = 0; i < this->_capacity; i++)
						new_arr[i] = this->_arr[i];
					this->_alloc.deallocate(this->_arr, this->_capacity);
				}
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

			vector(vector const &copy) { *this = copy; }

			vector	&operator=(vector const &copy)
			{
				size_type	i = 0;
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
				// TOCHECK ~Need to check if it's enough / Possibly need to allocate a capacity
				this->_alloc = alloc;
				this->_size = 0;
				this->_capacity = 0;
			}

			explicit vector(size_type count, const T& value = T(), const allocator_type& alloc = Allocator())
			{
				this->_alloc = alloc;
				this->_size = 0;
				this->_capacity = 0;
				this->assign(count, value);
			}

			template<class InputIt>
			vector(InputIt first, InputIt last, const allocator_type& alloc = Allocator(), typename ft::enable_if< !ft::is_integral< InputIt >::value >::type* = 0 )
			{
				// TOCHECK
				InputIt	copy = first;
				int		i = 0;

				while (copy != last)
				{
					i++;
					++copy;
				}
				this->_alloc = alloc;
				this->_size = i;
				this->_capacity = i;
				this->_arr = this->_alloc.allocate(i);
				i = 0;
				while (first != last)
				{
					this->_arr[i] = T(*first);
					++first;
					i++;
				}
			}

			// Destructor
			~vector()
			{
				// TOCHECK ~Need to check if it's enough
				// this->clear() ?
				if (this->_capacity > 0)
					this->_alloc.deallocate(this->_arr, this->_capacity);
			}

			// Assign
			void assign(size_type count, const T& value)
			{
				if (this->_capacity > 0)
					this->_alloc.deallocate(this->_arr, this->_capacity);
				this->_arr = this->_alloc.allocate(count);
				this->_size = count;
				if (this->_capacity < this->_size)
					this->_capacity = count;
				for (size_t i = 0; i < count; i++)
					this->_alloc.construct(&this->_arr[i], value);
			}

			template<class InputIt>
			void assign(InputIt first, typename ft::enable_if< !ft::is_integral< InputIt >::value, InputIt>::type last)
			{
				// TOFIX with ft::distance
				// InputIt tmp = first;
				int	i = ft::distance(first, last);
				int	j = 0;
				if (this->_capacity > 0)
					this->_alloc.deallocate(this->_arr, this->_capacity);
				this->_capacity = 0;
				// while (tmp != last)
				// {
				// 	i++;
				// 	tmp++;
				// }
				this->_arr = this->_alloc.allocate(i);
				while (j != i)
				{
					this->_arr[this->_capacity] = T(*first);
					this->_capacity++;
					first++;
					j++;
				}
				this->_size = this->_capacity;
			}

			// Get_allocator
			allocator_type get_allocator() const
			{
				return (this->_alloc);
			}

			// Element access
			reference	at(size_type pos)
			{
				if (!(pos < this->_size))
					throw	std::out_of_range("out of range");
				return (this->_arr[pos]);
			}

			const_reference	at(size_type pos) const
			{
				if (!(pos < this->_size))
					throw	std::out_of_range("out of range");
				return (this->_arr[pos]);
			}

			reference	&operator[](size_type pos) { return (this->_arr[pos]); }
			const_reference	&operator[](size_type pos) const { return (this->_arr[pos]); }

			reference	front() { return (this->_arr[0]); }
			const_reference	front() const { return (this->_arr[0]); }
			reference	back() { return (this->_arr[this->_size - 1]); }
			const_reference	back() const { return (this->_arr[this->_size - 1]); }

			T	*data()
			{
				if (this->_size == 0)
					return (NULL);
				return (this->_arr);
			}

			const T	*data() const
			{
				if (this->_size == 0)
					return (NULL);
				return (this->_arr);
			}

			// Iterators
			iterator		begin() { return (iterator(this->_arr)); }
			const_iterator	begin() const { return (const_iterator(this->_arr)); }
			iterator		end() { return (iterator(begin() + size())); }
			const_iterator	end() const { return (const_iterator(begin() + size())); }

			reverse_iterator	rbegin() { return (reverse_iterator(end())); }
			const_reverse_iterator	rbegin() const { return(const_reverse_iterator(end())); }
			reverse_iterator	rend() { return (reverse_iterator(begin())); }
			const_reverse_iterator	rend() const { return(const_reverse_iterator(begin())); }

			// Capacity
			bool		empty() const { return (this->begin() == this->end()); }
			size_type	size() const { return (this->_size); }
			size_type	capacity() const { return (this->_capacity); }
			size_type	max_size() const { return (this->_alloc.max_size()); }

			void	reserve(size_type new_cap)
			{
				if (new_cap > max_size())
					throw std::length_error("Length error");
				if (new_cap < this->_capacity)
					return	;
				T	*new_arr = this->_alloc.allocate(new_cap);
				if (this->_arr != NULL)
				{
					for (size_t i = 0; i < this->_capacity; i++)
						new_arr[i] = this->_arr[i];
					this->_alloc.deallocate(this->_arr, this->_capacity);
				}
				this->_arr = new_arr;
				this->_capacity = new_cap;
			}


			// Modifiers
			void		clear()
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_arr[i]);
				this->_size = 0;
			}

			iterator	insert(const_iterator pos, const T &value)
			{
				vector<T, Allocator>::iterator it = this->begin();
				vector<T, Allocator>::iterator right_it;
				int		new_capacity;
				int 	i = 0;

				if (_size + 1 > _capacity)
					new_capacity = _capacity + 1;
				else
					new_capacity = _capacity;
				if (pos == this->end())
				{
					this->push_back(value);
					return (this->end() - 1);
				}
				if (this->_size == this->_capacity && this->_capacity + 1 <= this->_capacity * 2)
					new_capacity = this->_capacity * 2;
				
				T	*new_arr = this->_alloc.allocate(new_capacity);

				while (it != pos)
				{
					new_arr[i] = *it;
					i++;
					++it;
				}
				new_arr[i] = value;
				right_it = iterator(&new_arr[i]);
				i++;
				while (it != this->end())
				{
					new_arr[i] = *it;
					++it;
					i++;
				}
				this->_alloc.deallocate(this->_arr, this->_capacity);
				this->_arr = new_arr;
				this->_size += 1;
				this->_capacity = new_capacity;
				return (right_it);
			}

			iterator	insert(const_iterator pos, size_type count, const T& value)
			{
				vector<T, Allocator>::iterator it = this->begin();
				int	right_pos;
				int	new_capacity;
				int i = 0;
				
				if (_size + count > _capacity)
					new_capacity = this->_capacity + count;
				else
					new_capacity = _capacity;
				if (pos == this->end())
				{
					for (size_t j = 0; j < count; j++)
						this->push_back(value);
					return (this->begin());
				}
				if (this->_size == this->_capacity && this->_capacity + count <= this->_capacity * 2)
					new_capacity = this->_capacity * 2;
				
				T	*new_arr = this->_alloc.allocate(new_capacity);

				while (it != pos)
				{
					new_arr[i] = *it;
					i++;
					++it;
				}
				right_pos = i;
				for (size_t j = 0; j < count; j++)
				{
					new_arr[i] = value;
					i++;
				}
				while (it != this->end())
				{
					new_arr[i] = *it;
					++it;
					i++;
				}
				this->_alloc.deallocate(this->_arr, this->_capacity);
				this->_arr = new_arr;
				this->_size += count;
				this->_capacity = new_capacity;
				return (vector<T, Allocator>::iterator(&new_arr[right_pos]));
			}

			template<class InputIt>
			iterator	insert(const_iterator pos, InputIt first, typename ft::enable_if< !ft::is_integral< InputIt >::value, InputIt>::type last)
			{
				iterator	it = this->begin();
				InputIt	copy = first;
				int			right_pos;
				int			new_capacity = this->_capacity;
				int			new_size = 0;

				while (copy != last)
				{
					new_capacity++;
					copy++;
				}
				int i = 0;
				if (new_capacity <= (int)this->_capacity * 2)
					new_capacity = this->_capacity * 2;
				
				T	*new_arr = this->_alloc.allocate(new_capacity);

				while (it != pos)
				{
					new_arr[i] = *it;
					i++;
					it++;
				}
				right_pos = i;
				while (first != last)
				{
					new_arr[i] = *first;
					first++;
					i++;
					new_size++;
				}
				while (it != this->end())
				{
					new_arr[i] = *it;
					++it;
					i++;
				}
				if (this->_size != 0)
					this->_alloc.deallocate(this->_arr, this->_capacity);
				this->_arr = new_arr;
				this->_size += new_size;
				this->_capacity = new_capacity;
				return (iterator(&_arr[right_pos]));
			}

			iterator	erase(iterator pos)
			{
				// TOCHECK
				iterator	it = this->begin();
				iterator	returned = this->begin();
				int			i = 0;

				while (it != pos)
				{
					it++;
					returned++;
					i++;
				}
				it++;
				this->_alloc.destroy(&*pos);
				while (it != this->end())
				{
					this->_arr[i] = this->_arr[i + 1];
					i++;
					it++;
				}
				this->_size--;
				return (returned);
			}

			iterator	erase(iterator first, iterator last)
			{
				// TOCHECK
				iterator	returned = first;
				bool		n = false;

				if (first == last)
					return (last);
				if (last == this->end())
					n = true;
				while (first != last)
				{
					returned = this->erase(returned);
					++first;
				}
				if (n)
					return (this->end());
				return (returned);
			}

			void		push_back(const T& value)
			{
				if (_capacity == 0)
				{
					_capacity = 1;
					_arr = _alloc.allocate(1);
				}
				else if (this->_size == this->_capacity)
					this->realloc(this->_capacity + 1);
				this->_alloc.construct(this->_arr + this->_size, value);
				this->_size++;
			}

			void		pop_back()
			{
				this->_size--;
				this->_alloc.destroy(this->_arr + this->_size);
			}

			void		resize(size_type count, T value = T())
			{
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
				std::swap(this->_arr, other._arr);
				std::swap(this->_alloc, other._alloc);
				std::swap(this->_size, other._size);
				std::swap(this->_capacity, other._capacity);
			}

			// Friend functions
			template< class U, class Alloc>
			friend bool operator==(const vector<U, Alloc>& lhs, const vector<U, Alloc>& rhs);
			template< class U, class Alloc>
			friend bool operator<(const vector<U, Alloc>& lhs, const vector<U, Alloc>& rhs);
	};

	template<class T, class Allocator>
	void swap(vector<T, Allocator>& lhs, vector<T, Allocator>& rhs) { lhs.swap(rhs); }

	template< class T, class Allocator>
	bool operator==(vector<T, Allocator> const &lhs, vector<T, Allocator> const &rhs) { return (lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin())); }
	template< class T, class Allocator>
	bool operator<(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) { return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
	template< class T, class Allocator>
	bool operator!=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) { return (!(lhs == rhs)); }
	template< class T, class Allocator>
	bool operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) { return ((lhs < rhs) || (lhs == rhs)); }
	template< class T, class Allocator>
	bool operator>(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) { return (rhs < lhs); }
	template< class T, class Allocator>
	bool operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) { return (!(lhs < rhs) || (lhs == rhs)); }
	
}

#endif
