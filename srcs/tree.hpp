/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:19:50 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/23 16:21:17 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

#include "ft_containers.hpp"

template <typename T>
typedef struct	s_tree
{
	std::string	key;
	T			data;
	s_tree		*parent;
	s_tree		*left;
	s_tree		*right;
	int			color; // either 0 => black or 1 => red
}				t_tree;

typedef t_tree	*Node;

template <typename T>
class RedBlackTree
{
	private:
		Node			root;
		Node			TNULL;
		std::allocator	alloc;
	private:
		void	left_rotation( /* TOFILL */)
		{
			// TODO
		}

		void	right_rotation( /* TOFILL */)
		{
			// TODO
		}

		void	recolor(Node node)
		{
			// TODO
		}

		void	fixInsert(Node node) // where node is the newly inserted node
		{
			// TODO
		}

		void	fixErase(Node node) //	need to determine what is node
		{
			// TODO	
		}

	public:
		RedBlackTree(std::allocator allocator) : alloc(allocator)
		{
			// TOCHECK
			TNULL = alloc.allocate(1);
			TNULL->color = 0;
			TNULL->parent = TNULL;
			TNULL->left = NULL;
			TNULL->right = NULL;
			TNULL->key = "";
			alloc.construct(TNULL->data);
		}
		
		~RedBlackTree()
		{
			// TODO
		}

		void	insert(std::string, T value)
		{
			// TODO
		}

		void	erase(std::string key)
		{
			// TODO
		}

		T const &search(std::string key)
		{
			// TODO
			// parcours en profondeur
		}
};

#endif