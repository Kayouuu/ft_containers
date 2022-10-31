#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>

template<
	class T,
	class Allocator = std::allocator<T>
>
class vector
{
	private:

		// Member types
		typedef typename T							value_type;
		typedef	typename Allocator					allocator_type;
		typedef	typename size_t						size_type;
		typedef	typename ptrdiff_t					difference_type;
		// TODO Need to check if these two below are working correctly
		typedef	typename value_type&				reference;
		typedef	typename const value_type&			const_reference;
		typedef	typename Allocator::pointer			pointer;
		typedef	typename Allocator::const_pointer	const_pointer;
		// TODO need to use self-coded iterator
		typedef	typename std::vector<T, Allocator>::iterator				iterator;
		typedef	typename std::vector<T, Allocator>::const_iterator			const_iterator;
		typedef	typename std::vector<T, Allocator>::reverse_iterator		reverse_iterator;
		typedef	typename std::vector<T, Allocator>::const_reverse_iterator	const_reverse_iterator;

		Allocator	_alloc;
		T			*_arr;
		size_t		_size;
		size_t		_capacity;
	public:
		vector();
		vector(vector const &copy);
		vector	&operator=(vector const &copy);
		explicit vector(const Allocator& alloc );
		explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator());
		template< class InputIt >
		vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );

		// Destructor
		~vector();

		// Assign
		void assign(size_type count, const T& value);
		template<class InputIt>
		void assign(InputIt first, InputIt last);

		// Get_allocator
		allocator_type get_allocator() const;

		// Element access
		reference		at( size_type pos );
		const_reference	at( size_type pos ) const;
		reference		operator[](size_type pos);
		const_reference	operator[](size_type pos) const;

		reference		front();
		const_reference	front() const;

		reference		back();
		const_reference	back() const;

		T		*data();
		const T	*data() const;
		
		// Iterators
		iterator		begin();
		const_iterator	begin() const;

		iterator		end();
		const_iterator	end() const;

		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;

		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		// Capacity
		bool		empty() const;
		size_type	size() const;
		size_type	max_size() const;
		void		reserve(size_type new_cap);
		size_type	capacity() const;

		// Modifiers
		void		clear();

		iterator	insert(const_iterator pos, const T &value);
		iterator	insert(const_iterator pos, size_type count, const T& value);
		template<class InputIt>
		iterator	insert(const_iterator pos, InputIt first, InputIt last);

		iterator	erase(iterator pos);
		iterator	erase(iterator first, iterator last);

		void		push_back(const T& value);
		void		pop_back();
		void		resize(size_type count, T value = T());
		void		swap(vector &other);

		// Friend functions

		template<class T, class Allocator>
		friend void swap(std::vector<T, Allocator>& lhs, std::vector<T, Allocator>& rhs);

		template< class T, class Allocator>
		friend bool operator==(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

		template< class T, class Allocator>
		friend bool operator!=(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

		template< class T, class Allocator>
		friend bool operator<(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

		template< class T, class Allocator>
		friend bool operator<=(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

		template< class T, class Allocator>
		friend bool operator>(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

		template< class T, class Allocator>
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

#endif