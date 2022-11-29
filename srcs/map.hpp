/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:28:02 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/29 11:54:55 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "ft_containers.hpp"
#include "tree.hpp"

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
			typedef	RBTreeIterator							iterator; // TOCHECK
			typedef	RBTreeIterator const					const_iterator; // TOCHECK
			typedef	ft::reverse_iterator<iterator>			reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			class value_compare; // TODO
		private:
			// TOCHECK maybe a _capacity var ?
			RedBlackTree<class Key, class T>	_tree;
			size_type							_size;
			allocator_type						_alloc;
			
		public:
			// Constructor
			map() // TOCHECK
			{
				_size = 0;
			}

			explicit map(Compare const &comp, Allocator const &alloc = Allocator())
			{
				// TODO assign comp to value_compare
				_size = 0;
				_alloc = alloc;
			}

			template <class InputIt>
			map(InputIt first, InputIt last, Compare const &comp = Compare(), Allocator const &alloc = Allocator())
			{
				// TODO assign comp to value_compare + add InputIt
				_alloc = alloc;
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
			allocator_type	get_allocator() const { return (this->_alloc); }

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
				s_tree *tmp = _tree.search(key);
				if (tmp == NULL)
				{
					_tree.insert(ft::make_pair<Key, T>(key, T())); // TOFIX make insert function returns the newly inserted value for better performance
					_tree.search(key);
				}
				return (tmp->data.second);
			}
			
			// Iterators
			iterator	begin() { return (RBTreeIterator<T>(_tree.minimum(_tree.root))); }

			const_iterator	begin() const { return (RBTreeIterator<T>(_tree.minimum(_tree.root))); }

			iterator	end()
			{
				// TODO
				return (RBTreeIterator<T>(++_tree.maximum(_tree.root)));
			}

			const_iterator	end() const
			{
				// TODO
				return (RBTreeIterator<T>(++_tree.maximum(_tree.root)));
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
				_tree.insert(value);
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