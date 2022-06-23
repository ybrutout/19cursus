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

		private:
		//private fonction to erase
		pair<node *, int>		find_the_object_to_erase(node	*tmp, const key_type& k)
		{
			int i = 0;
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
					return make_pair(tmp, 0);
			}
			return make_pair(tmp, i);
		}

		//private fonction to erase a do the changement between all the node before the erase of the object
		// void	erase_if_one_child(int i, )
		// {}



		public:
		size_type		erase(const key_type& k)
		{
			node	*tmp = this->_root;
			int		i = 0;

			pair<node *, int> pr = find_the_object_to_erase(tmp, k);
			i = pr._second;
			tmp = pr._first;
			if (i == 0)
				return 0;
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
						tmp->left->parent = NULL;
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
						tmp->right->parent = NULL;
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
						bis->right->parent = bis;
						bis->left->parent = bis;
					}
					else if (i == 2)
					{
						tmp->parent->right = bis;
						bis->left = tmp->left;
						bis->right = tmp->right;
						bis->parent->right = NULL;
						bis->parent = tmp->parent;
						bis->right->parent = bis;
						bis->left->parent = bis;
					}
					else if (i == 0)
					{
						this->_root = bis;
						bis->left = tmp->left;
						bis->right = tmp->right;
						bis->parent->right = NULL;
						bis->parent = tmp->parent;
						bis->left->parent = bis;
						bis->right->parent = bis;
					}
				}
			}
			delete tmp;
			this->_size--;
			return 1;
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{}

		void	clear()
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
			this->_root = NULL;
		}

	};
};

#endif
