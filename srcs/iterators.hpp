/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:32:41 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/03 16:34:43 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

namespace ft
{
	template <class T>
	struct iterator_traits
	{
		typedef typename T::value_type            value_type;
		typedef typename T::difference_type       difference_type;
		typedef typename T::iterator_category     iterator_category;
		typedef typename T::pointer               pointer;
		typedef typename T::reference             reference;
	};
	template <class T>
	struct iterator_traits<T*>
	{
		typedef T                          value_type;
		typedef ptrdiff_t                  difference_type; // TOCHECK
		typedef std::random_access_iterator_tag iterator_category; // TOCHECK Mandatory to use the std tag, otherwise STL algorithms wouldn't work 
		typedef T*                         pointer;
		typedef T&                         reference;
	};
	template< class T >
	struct iterator_traits<const T*>
	{
		typedef T                          value_type;
		typedef ptrdiff_t                  difference_type; // TOCHECK
		typedef std::random_access_iterator_tag iterator_category; // TOCHECK Mandatory to use the std tag, otherwise STL algorithms wouldn't work
		typedef T*                         pointer;
		typedef T&                         reference;
	};
	
	template< class Iter >
	class reverse_iterator
	{
		private:
			Iter	it;
		public:
			// Member types
			typedef Iter    iterator_type;
			typedef ft::iterator_traits<Iter>::iterator_category    iterator_category;
			typedef ft::iterator_traits<Iter>::value_type           value_type;
			typedef ft:iterator_traits<Iter>::difference_type      	difference_type;
			typedef ft::iterator_traits<Iter>::pointer				pointer;
			typedef	ft::iterator_traits<Iter>::reference			reference;

			// Constructors
			reverse_iterator(); // TODO
			explicit	reverse_iterator(iterator_type x); // TODO
			template<class U>
			reverse_iterator(reverse_iterator<U> const &other) { *this = copy; }
			template<class U>
			reverse_iterator	&operator=(reverse_iterator<U> const &other); // TODO
			~reverse_iterator() { }
			
			iterator_type	base() const;
			
	}
}

#endif