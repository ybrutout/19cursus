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
			typedef		ft::pair<key, T>		value_type;

			Node					*parent;
			Node					*left;
			Node					*right;
			value_type				value;

			/*Default constructor, Construct an empty node*/
			Node() : parent(NULL), left(NULL), right(NULL)
			{}

			/*Construct a node which has a parent and a value, but no child.*/
			Node(Node *parent, value_type val) : parent(parent), left(NULL), right(NULL), key(val)
			{}

			/*Construct a top of the tree node.*/
			Node(value_type val) : parent(NULL), left(NULL), right(NULL), key(val)
			{}

			Node(key first, T second) : parent(NULL), left(NULL), right(NULL)
			{
				this->value._first = first;
				this->value._second = second;
			}

			~Node() {}

			Node&	operator=(const Node& rhs)
			{
				this->parent = rhs.parent;
				this->left = rhs.left;
				this->right = rhs.right;
				this->key = rhs.key;
			}
	};

	//fondtion pour afficher donc à enlever
	template <class key, class T>
	void printRBTRec(const std::string &prefix, const Node<key, T> *node, bool isLeft)
	{
		if (node != nullptr)
		{
			std::cout << prefix;

			std::cout << (isLeft ? "├──" : "└──");

			// print the value of the node
			std::cout << node->value._first << std::endl;

			// enter the next tree level - left and right branch
			printRBTRec(prefix + (isLeft ? "│   " : "    "), node->right, true);
			printRBTRec(prefix + (isLeft ? "│   " : "    "), node->left, false);
		}
		else
		{
			std::cout << prefix;
			std::cout << (isLeft ? "├──" : "└──");
			std::cout << std::endl;
		}
	}

	template < class T>
	struct less : public std::binary_function <T,T,bool>
	{
		bool operator()(const T& x, const T& y) const { return x < y; }
	};

	template <class key, class T, class Compare = ft::less<key>, class Alloc =  std::allocator<ft::pair<key, T> > >
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

		Binary_Tree(): _size(0), _root(NULL), _key_cmp(key_compare()) {}

		~Binary_Tree()
		{
			node	*tmp = this->_root;

			while (this->_size != 0)
			{
				if (tmp->right)
					tmp = tmp->right;
				else if (tmp->left)
					tmp = tmp->left;
				else
				{
					node	*bis = tmp;
					if (tmp->parent)
					{
						tmp = tmp->parent;
						if (bis == tmp->left)
							tmp->left = NULL;
						else
							tmp->right = NULL;
					}
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
					if (this->_key_cmp(ke, tmp->value._first))
					{
						if (tmp->left == NULL)
						{
							node	*nw = new node(ke, value);
							nw->parent = tmp;
							this->_size++;
							tmp->left = nw;
							break;
						}
						else
							tmp = tmp->left;
					}
					else
					{
						if (tmp->right == NULL)
						{
							node	*nw = new node(ke, value);
							nw->parent = tmp;
							this->_size++;
							tmp->right = nw;
							break;
						}
						else
							tmp = tmp->right;
					}

				}
			}
		}

		//fonction pour afficher
		void print(void) { printRBTRec("", this->_root, false); };

		pointer		search(const key& k)
		{
			node *tmp = this->_root;
			while (k != tmp->value._first)
			{
				if (k < tmp->value._first && tmp->left)
					tmp = tmp->left;
				else if (k > tmp->value._first && tmp->right)
					tmp = tmp->right;
				else
					return NULL;
			}
			return &(tmp->value);
		}

		size_type		erase(const key_type& k)
		{
			node	*tmp = this->_root;

			int		i = 0;
			while (k != tmp->value._first)
			{
				if (k < tmp->value._first && tmp->left)
				{
					tmp = tmp->left;
					i = 1;
				}
				else if (k > tmp->value._first && tmp->right)
				{
					tmp = tmp->right;
					i = 2;
				}
				else
					return 0;
			}
			if (tmp->right == NULL && tmp->left == NULL)
			{
				if (i == 1)
					tmp->parent->left = NULL;
				else if (i == 2)
					tmp->parent->right = NULL;
			}
			else
			{
				if (tmp->right == NULL && tmp->left)
				{
					if (i == 0)
					{
						this->_root = tmp->left;
						tmp->parent = NULL;
					}
					else if (i == 1)
					{
						tmp->parent->left = tmp->left;
						tmp->left->parent = tmp->parent;
					}
					else if (i == 2)
					{
						tmp->parent->right = tmp->left;
						tmp->left->parent = tmp->parent;
					}
				}
				else if (tmp->right && tmp->left == NULL)
				{
					if (i == 0)
					{
						this->_root = tmp->right;
						tmp->parent = NULL;
					}
					else if (i == 1)
					{
						tmp->parent->left = tmp->right;
						tmp->right->parent = tmp->parent;
					}
					else if (i == 2)
					{
						tmp->parent->right = tmp->right;
						tmp->right->parent = tmp->parent;
					}
				}
				else
				{

					node	*bis = tmp->left;
					while (bis->right)
						bis = bis->right;
					if (bis->left)
					{
						bis->left->parent = bis->parent;
						bis->parent->right = bis->left;
					}
					if (i == 1)
					{
						tmp->parent->left = bis;
						bis->left = tmp->left;
						bis->right = tmp->right;
						bis->parent->right = NULL;
						bis->parent = tmp->parent;
					}
					else if (i == 2)
					{
						tmp->parent->right = bis;
						bis->left = tmp->left;
						bis->right = tmp->right;
						bis->parent->right = NULL;
						bis->parent = tmp->parent;
					}
					else if (i == 0)
					{
						this->_root = bis;
						bis->left = tmp->left;
						bis->right = tmp->right;
						bis->parent->right = NULL;
						bis->parent = tmp->parent;
					}
				}
			}

			delete tmp;
			this->_size--;
			return 1;
		}
	};
};

#endif
