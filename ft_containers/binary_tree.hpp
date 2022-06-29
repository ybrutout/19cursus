#ifndef BINARY_TREE
# define BINARY_TREE

# include <iostream>
# include "pair.hpp"
# include "tree_iterator.hpp"

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
			Node(Node *parent, value_type val) : parent(parent), left(NULL), right(NULL), value(val)
			{}

			/*Construct a top of the tree node.*/
			Node(value_type val) : parent(NULL), left(NULL), right(NULL), value(val)
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
			typedef				Alloc								allocator_type;
			typedef	typename	allocator_type::reference			reference;
			typedef typename	allocator_type::const_reference		const_reference;
			typedef typename	allocator_type::pointer				pointer;
			typedef typename	allocator_type::const_pointer						const_pointer;
			typedef typename	ft::tree_iterator<Node<key_type, mapped_type> >		iterator;
			//const_iterator
			//reverse_iterator
			//const_reverse_iterator
			typedef				ptrdiff_t							difference_type;
			typedef				size_t								size_type;
			typedef				Node<key, T>						node;

		protected:

			node				*_more_last;
			allocator_type		_alloc;
			key_compare			_key_cmp;
			size_t				_size;
			node				*_root;

		public:

		//fonction pour implémenter le dernier node apres le dernier. Voir si il faut pas mettre se truc en privé
		//si il y a plusieurs constructeur il furda l'utiliser dans chaque constructeur.
		node		*just_more_last()
		{
			node *tmp = new node;
			return tmp;
		}


		/*Default constructor*/
		Binary_Tree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _size(0), _root(NULL), _key_cmp(comp), _alloc(alloc)
		{
			this->_more_last = just_more_last();
		}

		//ajouter l'insert the range
		// template <class IteratorTree>
		// Binary_Tree(IteratorTree first, IteratorTree last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		// : _size(0), _root(NULL), _key_cmp(comp), _alloc(alloc)
		// {
		// 	IteratorTree	tmp = first;
		// 	while (tmp != last)
		// 	{
		// 		this->_size++;
		// 		tmp++;
		// 	}
		// 	std::cout << "size == " << this->_size << std::endl;
		// }

		~Binary_Tree()
		{
			node	*tmp = this->_root;

			while (this->_size != 0)
			{
				if (tmp->right && tmp->right != this->_more_last)
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
			delete this->_more_last;
		}

		private:
		// void	recursive_for_discover(node *rhs, node* last)
		// {

		// 	if (rhs.left)
		// 		recursive_for_discover(rhs.left, last);
		// 	if (rhs.right && rhs.right != last)
		// 		recursive_for_discover(rhs.right, last);
		// }

		public:

		//ca va pas 
		Binary_Tree& operator=(Binary_Tree& rhs)
		{
			this->clear();
			this->_alloc = rhs._alloc;
			this->_key_cmp = rhs._key_cmp;
			this->_more_last = just_more_last();
			// recursive_for_discover(rhs._root, rhs._more_last);
			node *tmp = this->_root;
			while (tmp->right)
				tmp = tmp->right;
			tmp->right = this->_more_last;
			this->_more_last = tmp;
			return *this;
		}

		/*Return an iterator on the smallest node(pair)*/
		iterator	begin()
		{
			node	*tmp = this->_root;

			while (1)
			{
				if (tmp->left)
					tmp = tmp->left;
				else
					return tmp;
			}
			return tmp;
		}

		iterator	end()
		{
			return this->_more_last;
		}

		//pas sure que ce soit utile
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			InputIterator tmp = first;
			size_type distance = 0;
			while (tmp != last)
			{
				++tmp;
				distance++;
			}
			for (size_type i = 0; i < distance; i++, first++)
				insert(first._node->value);
		}

		void	insert(value_type val)
		{
			if (this->_size == 0)
			{
				node	*tmp = new node(val);
				this->_root = tmp;
				this->_size++;
				this->_root->right = this->_more_last;
			}
			else
			{
				node *tmp = this->_root;
				while (1)
				{
					if (this->_key_cmp(val._first, tmp->value._first))
					{
						if (tmp->left == NULL)
						{
							node	*nw = new node(val);
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
						if (!this->_key_cmp(tmp->value._first, val._first))
							return ;
						if (tmp->right == NULL || tmp->right == this->_more_last)
						{
							node	*nw = new node(val);
							nw->parent = tmp;
							this->_size++;
							if (tmp->right == this->_more_last)
							{
								nw->right = this->_more_last;
								this->_more_last->parent = nw;
							}
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
		//renvoi une pair qui contient le node a supprimé et un int qui permet de savoir de quel cote est il pour le node parent.
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

		public:
		size_type		erase(const key_type& k)
		{
			node	*tmp = this->_root;
			int		i = 0;

			pair<node *, int> pr = find_the_object_to_erase(tmp, k);
			i = pr._second;
			tmp = pr._first;
			if (tmp->right == NULL && tmp->left == NULL)
			{
				if (i == 1)
					tmp->parent->left = NULL;
				else if (i == 2)
					tmp->parent->right = NULL;
			}
			else if (tmp->right == this->_more_last)
			{
				if (tmp->parent)
				{
					tmp->parent->right = this->_more_last;
					this->_more_last = tmp->parent;
				}
				else
				{
					node *bis = tmp->left;
					this->_root = tmp->left;
					tmp->left->parent = NULL;
					while (bis->right)
						bis = bis->right;
					bis->right = this->_more_last;
					this->_more_last->parent = bis;
				}
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
					else
					{
						if (i == 1)
							tmp->parent->left = tmp->left;
						if (i == 2)
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
					else
					{
						if (i == 1)
							tmp->parent->left = tmp->right;
						if (i == 2)
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
						tmp->parent->left = bis;
					else if (i == 2)
						tmp->parent->right = bis;
					else if (i == 0)
						this->_root = bis;
					bis->left = tmp->left;
					bis->right = tmp->right;
					bis->parent->right = NULL;
					bis->parent = tmp->parent;
					bis->right->parent = bis;
					bis->left->parent = bis;
				}
			}
			delete tmp;
			this->_size--;
			return 1;
		}


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
			this->_more_last->parent = NULL;
		}

	};
};

#endif
