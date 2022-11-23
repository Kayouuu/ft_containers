/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:28:02 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/22 16:17:30 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "ft_containers.hpp"

namespace ft
{
	template <
		class Key,
		class T,
		class Compare = std::less<Key>, // TOCHECK if need to code std::less
		class Allocator = std::allocator<std::pair<const Key, T>>
	>
	class map
	{
		public:
			typedef Key										key_type;
			typedef	T										mapped_type;
			typedef	typename std::pair<const Key, T>		value_type;
			typedef	size_t									size_type;
			typedef	long int								difference_type;
			typedef	typename Compare						key_compare;
			typedef typename Allocator						allocator_type;
			typedef value_type&								reference;
			typedef	const value_type&						const_reference;
			typedef	typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			// typedef	BidirectionnalIterator				iterator; // TOCHECK
			// typedef	BidirectionnalIteral const			const_iterator; // TOCHECK
			typedef	ft::reverse_iterator<iterator>			reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			class value_compare; // TODO
		private:
			// TOFILL
		public:
			// Constructor
			map()
			{
				// TODO
			}

			explicit map(Compare const &comp, Allocator const &alloc = Allocator())
			{
				// TODO
			}

			template <class InputIt>
			map(InputIt first, InputIt last, Compare const &comp = Compare(), Allocator const &alloc = Allocator())
			{
				// TODO
			}

			map(map const &other)
			{
				// TODO
			}
			
			map	&operator=(map const &other)
			{
				// TODO
			}

			// Destructor
			~map()
			{
				// TODO
			}

			// Get_allocator
			allocator_type	get_allocator() const
			{
				// TODO
			}

			// Element access
			T	&at(Key const &key)
			{
				// TODO
			}

			T const	&at(Key const &key) const
			{
				// TODO
			}

			T	&operator[](Key const &key)
			{
				// TODO
			}
			
			// Iterators
			iterator	begin()
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
			bool	empty() const
			{
				// TODO
			}

			size_type	size() const
			{
				// TODO
			}

			size_type	max_size() const
			{
				// TODO
			}

			// Modifiers
			void	clear()
			{
				// TODO
			}

			ft::pair<iterator, bool>	insert(value_type const &value)
			{
				// TODO
			}

			iterator	insert(iterator pos, value_type const &value)
			{
				// TODO
			}

			template<class InputIt>
			void	insert(InputIt first, InputIt last)
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

			size_type	erase(Key const &key)
			{
				// TODO
			}
			
			void	swap(map &other)
			{
				// TODO
			}

			// Lookup
			size_type	count(Key const &key) const
			{
				// TODO
			}

			iterator	find(Key const &key)
			{
				// TODO
			}

			const_iterator	find(Key const &key) const
			{
				// TODO
			}
			
			std::pair<iterator, iterator>	equal_range(Key const &key)
			{
				// TODO
			}
			
			std::pair<const_iterator, const_iterator>	equal_range(Key const &key) const
			{
				// TODO
			}
			
			iterator	lower_bound(Key const &key)
			{
				// TODO
			}

			const_iterator	lower_bound(Key const &key) const
			{
				// TODO
			}
			
			iterator	upper_bound(Key const &key)
			{
				// TODO
			}

			const_iterator	upper_bound(Key const &key) const
			{
				// TODO
			}
			
			// Observers
			key_compare	key_comp() const
			{
				// TODO
			}

			ft::map::value_compare	value_comp() const
			{
				// TODO
			}
	};
	
	//	TODO Add friend functions (operator==, etc... + )
}
#endif