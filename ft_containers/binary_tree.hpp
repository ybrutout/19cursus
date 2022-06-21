#ifndef BINARY_TREE
# define BINARY_TREE

# include <iostream>
# include "pair.hpp"

# include <functional>//a enlever
# include <memory> // je crois pas qu'il faut l'enlever a voir


namespace ft
{
	template <class key, class T>
	class Node
	{
		public:
			typedef		ft::pair<const key, T>		value_type;

			Node					*_parent;
			Node					*_left;
			Node					*_right;
			value_type				_key;

			/*Default constructor, Construct an empty node*/
			Node() : _parent(NULL), _left(NULL), _right(NULL)
			{}

			/*Construct a node which has a parent and a value, but no child.*/
			Node(Node *parent, value_type val) : _parent(parent), _left(NULL), _right(NULL), _key(val)
			{}

			/*Construct a top of the tree node.*/
			Node(value_type val) : _parent(NULL), _left(NULL), _right(NULL), _key(val)
			{}

			Node(key first, T second) : _parent(NULL), _left(NULL), _right(NULL)
			{
				value_type	tmp(first, second);
				this->_key = tmp;
			}

			~Node() {}

			Node&	operator=(const Node& rhs)
			{
				this->_parent = rhs._parent;
				this->_left = rhs._left;
				this->_right = rhs._right;
				this->_key = rhs._key;
			}
	};

	template <class key, class T>
	void printRBTRec(const std::string &prefix, const Node<key, T> *node, bool isLeft)
	{
		if (node != nullptr)
		{
			std::cout << prefix;

			std::cout << (isLeft ? "├──" : "└──");

			// print the value of the node
			std::cout << node->_key << std::endl;

			// enter the next tree level - left and right branch
			printRBTRec(prefix + (isLeft ? "│   " : "    "), node->_right, true);
			printRBTRec(prefix + (isLeft ? "│   " : "    "), node->_left, false);
		}
		else
		{
			std::cout << prefix;
			std::cout << (isLeft ? "├──" : "└──");
			std::cout << std::endl;
		}
	}

	//changer std::less
	template <class key, class T, class Compare = std::less<key>, class Alloc =  std::allocator<ft::pair<key, T> > >
	class Binary_Tree
	{
		public:
			typedef				key									key_type;
			typedef				T									mapped_type;
			typedef				pair<key_type, mapped_type>			value_type;
			typedef				Compare								key_compare;
			//value_compare see value_comp
			typedef				Alloc								allocator_type;
			typedef	typename	allocator_type::reference			reference;
			typedef typename	allocator_type::const_reference		const_reference;
			typedef typename	allocator_type::pointer				pointer;
			typedef typename	allocator_type::const_pointer		const_pointer;
			//iterator
			//const_iterator
			//reverse_iterator
			//const_reverse_iterator
			typedef				ptrdiff_t							difference_type;
			typedef				size_t								size_type;
			typedef				Node<key, T>						node;

		protected:
			allocator_type		_alloc;
			key_compare			_key_cmp;
			size_t				_size;
			node				*_root;

		public:

		Binary_Tree(): _size(0), _root(NULL) {}

		~Binary_Tree()
		{
			node	*tmp = this->_root;

			while (this->_size != 0)
			{
				if (tmp->_right)
					tmp = tmp->_right;
				else if (tmp->_left)
					tmp = tmp->_left;
				else
				{
					node	*bis = tmp;
					tmp = tmp->_parent;
					if (bis == tmp->_left)
						tmp->_left = NULL;
					else
						tmp->_right = NULL;
					delete bis;
					this->_size--;
				}
			}
		}

		void	insert(key_type ke, mapped_type value)
		{
			if (this->_size == 0)
			{
				node	*tmp = new node(ke, value);
				this->_root = tmp;
				this->_size++;
			}
			else
			{
				node *tmp = this->_root;
				while (1)
				{
					if (this->_key_cmp(ke, tmp->_key))
					{
						if (tmp->_left == NULL)
						{
							node	*nw = new node(ke, value);
							nw->_parent = tmp;
							this->_size++;
							tmp->_left = nw;
							break;
						}
						else
							tmp = tmp->_left;
					}
					else
					{
						if (tmp->_right == NULL)
						{
							node	*nw = new node(ke, value);
							nw->_parent = tmp;
							this->_size++;
							tmp->_right = nw;
							break;
						}
						else
							tmp = tmp->_right;
					}

				}
			}
		}

		void print(void) { printRBTRec("", this->_root, false); };
	};
};

#endif
