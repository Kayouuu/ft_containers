/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:28:02 by psaulnie          #+#    #+#             */
/*   Updated: 2022/12/02 16:06:07 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "ft_containers.hpp"
#include "iterators.hpp"
#include "tree.hpp"

namespace ft
{
	template <
		class Key,
		class T,
		class Compare = std::less<Key>, // TOCHECK if need to code std::less
		class Allocator = std::allocator< ft::pair<const Key, T> >
	>
	class map
	{
		public:
			typedef Key										key_type;
			typedef	T										mapped_type;
			typedef	typename ft::pair< Key, T>				value_type; // TOFIX hould have const Key template parameter 
			typedef	size_t									size_type;
			typedef	long int								difference_type;
			typedef Compare									key_compare;
			typedef Allocator								allocator_type;
			typedef value_type&								reference;
			typedef	const value_type&						const_reference;
			typedef	typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef	RBTreeIterator<Key, T, s_tree<Key, T>, map>			iterator;
			typedef	const RBTreeIterator<Key, T, s_tree<Key, T>, map>	const_iterator;
			typedef	ft::reverse_iterator<iterator>			reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			class value_compare; // TODO
		private:
			// TOCHECK maybe a _capacity var ?
			RedBlackTree<Key, T>	_tree;
			size_type				_size;
			allocator_type			_alloc;
			
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
				s_tree<Key, T>	*node = _tree.search(key);
				if (node == NULL)
					throw std::out_of_range("map");
				return (node->data.second);
			}
			T const	&at(Key const &key) const
			{
				s_tree<Key, T>	*node = _tree.search(key);
				if (node == NULL)
					throw std::out_of_range("map");
				return (node->data.second);
			}

			T	&operator[](Key const &key)
			{
				// TOCHECK
				s_tree<Key, T> *tmp = _tree.search(key);
				if (tmp == NULL)
					return (_tree.insert(ft::make_pair<Key, T>(key, T())).data.second);
				return (tmp->data.second);
			}
			
			// Iterators
			iterator	begin() { return (iterator(_tree.minimum(_tree.root))); }

			const_iterator	begin() const { return (const_iterator(_tree.minimum(_tree.root))); }

			iterator	end()
			{
				// TODO
				iterator it(_tree.maximum(_tree.root, true));
				return (it);
			}

			const_iterator	end() const
			{
				// TODO
				const_iterator it(_tree.maximum(_tree.root, true));
				return (it);
			}

			reverse_iterator	rbegin() { return (reverse_iterator(begin())); }
			const_reverse_iterator	rbegin() const { return (const_reverse_iterator(begin())); }
			reverse_iterator	rend() { return (reverse_iterator(end())); }
			const_reverse_iterator	rend() const { return (const_reverse_iterator(begin())); }

			// Capacity
			bool	empty() const { return (this->_size == 0); }
			size_type	size() const { return (this->_size); }

			size_type	max_size() const { return (this->_alloc.max_size()); }

			// Modifiers
			void	clear()
			{
				// TODO
			}

			ft::pair<iterator, bool>	insert(value_type const &value)
			{
				// TOCHECK returned value (seems now good)
				bool	inserted = false;
				s_tree<Key, T> node = _tree.insert(value);
				iterator it(&node);
				this->_size++;
				if ((*it))
					inserted = true;
				return (ft::pair<iterator, bool>(it, inserted));
			}

			iterator insert(iterator pos, const value_type& value)
			{
				// TOCHECK returned value (seems now good)
				(void)pos;
				bool	inserted = false;
				s_tree<Key, T> node = _tree.insert(value);
				iterator it(&node);
				this->_size++;
				if ((*it))
					inserted = true;
				return (ft::pair<iterator, bool>(it, inserted));
			}

			template<class InputIt>
			void	insert(InputIt first, InputIt last)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			void	erase(iterator pos)
			{
				_tree.erase((*pos).first);
				this->size--;
			}

			void	erase(iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first);
					first++;
				}
			}

			size_type	erase(Key const &key)
			{
				// TODO
			}
			
			void	swap(map &other)
			{
				std::swap(this->_alloc, other._alloc);
				std::swap(this->_size, other._size);
				std::swap(this->_tree, other._tree);
			}

			// Lookup
			size_type	count(Key const &key) const
			{
				// TODO
			}

			iterator	find(Key const &key)
			{
				s_tree<Key, T> *tmp = _tree.search(key);
				if (tmp == NULL)
					return (end());
				return (it(tmp));
			}

			const_iterator	find(Key const &key) const
			{
				s_tree<Key, T> *tmp = _tree.search(key);
				if (tmp == NULL)
					return (end());
				return (it(tmp));
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

			map::value_compare	value_comp() const
			{
				// TODO
			}
	};
	
	//	TODO Add friend functions (operator==, etc... + )
	template<class Key, class T, class Compare, class Alloc>
	void swap(std::map<Key,T,Compare,Alloc>& lhs, std::map<Key,T,Compare,Alloc>& rhs) { lhs.swap(rhs); }
}
#endif