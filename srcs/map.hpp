/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:28:02 by psaulnie          #+#    #+#             */
/*   Updated: 2022/12/19 14:54:01 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "tree.hpp"
#include "iterators.hpp"
#include "tree_iterator.hpp"
#include "comparison.hpp"
#include <functional>

namespace ft
{
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key 												key_type;
		typedef T 													mapped_type;
		typedef typename ft::pair<const Key, T> 					value_type;
		typedef size_t 												size_type;
		typedef long int 											difference_type;
		typedef Compare 											key_compare;
		typedef Allocator 											allocator_type;
		typedef value_type 											&reference;
		typedef const value_type 									&const_reference;
		typedef typename Allocator::pointer 						pointer;
		typedef typename Allocator::const_pointer 					const_pointer;
		typedef RBTreeIterator<value_type, s_tree<Key, T>, false>	iterator;
		typedef RBTreeIterator<value_type, s_tree<Key, T>, true>	const_iterator;
		typedef ft::reverse_iterator<iterator> 						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> 				const_reverse_iterator;

		class value_compare : std::binary_function<value_type, value_type, bool>
		{
			protected:
				Compare comp;
				value_compare(Compare c) : comp(c) {}

			public:
				bool operator()(value_type const &lhs, value_type const &rhs) const { return (comp(lhs.first, rhs.first)); }
			friend class map<Key, T, Compare, Allocator>;
			friend class RedBlackTree<Key, T, Allocator, Compare>;
		};

	private:
		RedBlackTree<Key, T, Allocator, Compare> _tree;
		size_type _size;
		allocator_type _alloc;

	public:
		// Constructor
		map() : _tree(value_compare(Compare())), _size(0) { }

		explicit map(Compare const &comp, Allocator const &alloc = Allocator()) : _tree(value_compare(comp))
		{
			_size = 0;
			_alloc = alloc;
		}

		template <class InputIt>
		map(InputIt first, InputIt last, Compare const &comp = Compare(), Allocator const &alloc = Allocator()) : _tree(value_compare(comp))
		{
			_size = 0;
			_alloc = alloc;
			while (first != last)
			{
				insert((*first));
				first++;
			}
		}

		map(map const &other) :  _tree(value_compare(other._tree.comp.comp)), _alloc(other._alloc)
		{
			insert(other.begin(), other.end());
		}

		map &operator=(map const &other)
		{
			if (_tree.TNULL)
				_tree.destroy_tnull();
			_alloc = other._alloc;
			_tree = RedBlackTree<Key, T, Allocator, Compare>(other._tree.comp.comp);
			insert(other.begin(), other.end());
			_size = other._size;
			return (*this);
		}

		// Destructor
		~map()
		{
			_tree.destroy_tree(_tree.getRoot());
			_tree.destroy_tnull();
		}

		// Get_allocator
		allocator_type get_allocator() const { return (this->_alloc); }

		// Element access
		T &at(Key const &key)
		{
			s_tree<Key, T> *node = _tree.search(key);
			if (node == NULL)
				throw std::out_of_range("map");
			return (node->data.second);
		}
		T const &at(Key const &key) const
		{
			s_tree<Key, T> *node = _tree.search(key);
			if (node == NULL)
				throw std::out_of_range("map");
			return (node->data.second);
		}

		T &operator[](Key const &key)
		{
			// TOCHECK
			s_tree<Key, T> *tmp = _tree.search(key);
			if (tmp == NULL)
			{
				_size++;
				return (_tree.insert(ft::make_pair<Key, T>(key, T()))->data.second);
			}
			return (tmp->data.second);
		}

		// Iterators
		iterator begin() { return (iterator(_tree.minimum(_tree.root), _tree.TNULL, _tree.maximum(_tree.root))); }

		const_iterator begin() const { return (const_iterator(_tree.minimum(_tree.root), _tree.TNULL, _tree.maximum(_tree.root))); }

		iterator end()
		{
			iterator it(_tree.maximum(_tree.root, true), _tree.TNULL, _tree.maximum(_tree.root));
			return (it);
		}

		const_iterator end() const
		{
			const_iterator it(_tree.maximum(_tree.root, true), _tree.TNULL, _tree.maximum(_tree.root));
			return (it);
		}

		reverse_iterator rbegin() { return (reverse_iterator(iterator(_tree.maximum(_tree.root, true), _tree.TNULL, _tree.maximum(_tree.root)))); }
		const_reverse_iterator rbegin() const { return (const_reverse_iterator(iterator(_tree.maximum(_tree.root, true), _tree.TNULL, _tree.maximum(_tree.root)))); }
		reverse_iterator rend() { return (reverse_iterator(iterator(_tree.minimum(_tree.root), _tree.TNULL, _tree.maximum(_tree.root)))); }
		const_reverse_iterator rend() const { return (const_reverse_iterator(iterator(_tree.minimum(_tree.root), _tree.TNULL, _tree.maximum(_tree.root)))); }

		// Capacity
		bool empty() const { return (this->_size == 0); }
		size_type size() const { return (this->_size); }

		size_type max_size() const { return (this->_alloc.max_size()); }

		// Modifiers
		void clear()
		{
			// TOCHECK
			iterator it = this->begin();
			while (*it != (*this->end()))
			{
				this->_tree.erase((*it).first);
				it = this->begin();
			}
			_size = 0;
		}

		ft::pair<iterator, bool> insert(value_type const &value)
		{
			// TOCHECK returned value (seems now good)
			bool inserted = false;
			s_tree<Key, T> *node = _tree.insert(ft::make_pair<Key, T>(value.first, value.second));
			iterator it;
			if (node)
			{
				it = iterator(node, _tree.TNULL, _tree.maximum(_tree.root));
				this->_size++;
				inserted = true;
			}
			else
				it = lower_bound(value.first);
			return (ft::pair<iterator, bool>(it, inserted));
		}

		iterator insert(iterator pos, const value_type &value)
		{
			// TOCHECK returned value (seems now good)
			(void)pos;
			s_tree<Key, T> *node = _tree.insert(value);
			iterator it(node, _tree.TNULL, _tree.maximum(_tree.root));
			if (node)
				this->_size++;
			return (it);
		}

		template <class InputIt>
		void insert(InputIt first, InputIt last)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		}

		void erase(iterator pos)
		{
			_tree.erase((*pos).first);
			this->_size--;
		}

		void erase(iterator first, iterator last)
		{
			iterator tmp;

			while (first != last)
			{
				tmp = first;
				++first;
				erase(tmp->first);
			}
		}

		size_type erase(Key const &key)
		{
			if (_tree.erase(key) == true)
			{
				this->_size--;
				return (1);
			}
			return (0);
		}

		void swap(map &other)
		{
			std::swap(this->_alloc, other._alloc);
			std::swap(this->_size, other._size);
			std::swap(this->_tree, other._tree);
		}

		// Lookup
		size_type count(Key const &key) const
		{
			// TOCHECK
			s_tree<Key, T> *node = _tree.search(key);
			return (node == NULL ? 0 : 1); // If nothing is found, return 0, else 1
		}

		iterator find(Key const &key)
		{
			s_tree<Key, T> *tmp = _tree.search(key);
			if (tmp == NULL)
				return (end());

			return (iterator(tmp, _tree.TNULL, _tree.maximum(_tree.root)));
		}

		const_iterator find(Key const &key) const
		{
			s_tree<Key, T> *tmp = _tree.search(key);
			if (tmp == NULL)
				return (end());
			return (const_iterator(tmp, _tree.TNULL, _tree.maximum(_tree.root)));
		}

		ft::pair<iterator, iterator> equal_range(Key const &key)
		{
			return (ft::make_pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
		}

		ft::pair<const_iterator, const_iterator> equal_range(Key const &key) const
		{
			return (ft::make_pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)));
		}

		iterator lower_bound(Key const &key)
		{
			// TODO
			s_tree<Key, T> *node = _tree.lower_bound(key);
			if (node == _tree.TNULL)
				return (end());
			return (iterator(node, _tree.TNULL, _tree.maximum(_tree.root)));
		}

		const_iterator lower_bound(Key const &key) const
		{
			// TODO
			s_tree<Key, T> *node = _tree.lower_bound(key);
			return (const_iterator(node, _tree.TNULL, _tree.maximum(_tree.root)));
		}

		iterator upper_bound(Key const &key)
		{
			s_tree<Key, T> *node = _tree.upper_bound(key);
			return (iterator(node, _tree.TNULL, _tree.maximum(_tree.root)));
		}

		const_iterator upper_bound(Key const &key) const
		{
			s_tree<Key, T> *node = _tree.upper_bound(key);
			if (node == _tree.TNULL)
				return (end());
			return (const_iterator(node, _tree.TNULL, _tree.maximum(_tree.root)));
		}

		// Observers
		key_compare key_comp() const { return (_tree.comp.comp); }

		map::value_compare value_comp() const { return (_tree.comp); } // TOCHECK

		friend 	bool operator==( const map& lhs, const map& rhs ) { return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }
		friend 	bool operator<( const map& lhs, const map& rhs ) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
		friend	bool operator!=( const map& lhs, const map& rhs ) { return (!(lhs == rhs)); }
		friend	bool operator<=( const map& lhs, const map& rhs ) { return ((lhs < rhs) || (lhs == rhs)); }
		friend	bool operator>( const map& lhs, const map& rhs ) { return (rhs < lhs); }
		friend	bool operator>=( const map& lhs, const map& rhs ) { return (!(lhs < rhs) || (lhs == rhs)); }
	};

	template <class Key, class T, class Compare, class Alloc>
	void swap(ft::map<Key, T, Compare, Alloc> &lhs, ft::map<Key, T, Compare, Alloc> &rhs) { lhs.swap(rhs); }
}
#endif