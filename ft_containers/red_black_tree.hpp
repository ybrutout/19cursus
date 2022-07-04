#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <iostream>
# include "pair.hpp"

namespace ft
{
	//Par définition j'ai mis la couleur du node à rouge dès le départ puisque à chaque insertion(sauf la première) le node est d'abord mis en rouge.
	template <class key, class T>
	class Node
	{
		public:
			typedef		ft::pair<key, T>		value_type;

			Node					*parent;
			Node					*left;
			Node					*right;
			value_type				value;
			bool					color;//true == noir et false == rouge

			/*Default constructor, Construct an empty node*/
			Node() : parent(NULL), left(NULL), right(NULL), color(false)
			{}

			/*Construct a node which has a parent and a value, but no child.*/
			//pas sure que ce soit utile, a voir
			Node(Node *parent, value_type val) : parent(parent), left(NULL), right(NULL), value(val), color(false)
			{}

			/*Construct a top of the tree node.*/
			Node(value_type val) : parent(NULL), left(NULL), right(NULL), value(val), color(false)
			{}

			//pas sure que ce soit utile a voir
			Node(key first, T second) : parent(NULL), left(NULL), right(NULL), color(false)
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
				this->color = rhs->color;
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
			if (node->color)
				std::cout << node->value.first << std::endl;
			else
				std::cout << "\033[31m" << node->value.first << "\033[0m" << std::endl;

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

	template <class key, class T, class Compare = std::less<key>, class Alloc =  std::allocator<ft::pair<key, T> > >
	class RBTree
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
			//typedef typename	ft::tree_iterator<Node<key_type, mapped_type> >		iterator;
			//const_iterator
			//reverse_iterator
			//const_reverse_iterator
			typedef				ptrdiff_t							difference_type;
			typedef				size_t								size_type;
			typedef				Node<key, T>						node;

		protected:

			node				*_end;
			allocator_type		_alloc;
			key_compare			_key_cmp;
			size_t				_size;
			node				*_root;

		private:
			node		*just_the_end()
			{
				node *tmp = new node;
				return tmp;
			}

		public:
			/*Default constructor*/
			RBTree(const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _key_cmp(comp), _size(0), _root(NULL)
			{
				_end = just_the_end();
				_end->color = true;
			}

			//Copie Constructor

			//Constructeur de range (pas sure d'en avoir besoin directement dans le redblack tree)

			/*Deconstructor*/
			~RBTree()
			{
				node *tmp = this->_root;

				while (this->_size != 0)
				{
					if (tmp->right && tmp->right != this->_end)
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
				delete this->_end;
			}
		private:
			void	its_empty(value_type val)
			{
				this->_root = new node(val);
				this->_size++;
				this->_root->right = this->_end;
				this->_root->color = true;
			}

			node	*where_is_the_insert(value_type val)
			{
				node	*tmp = this->_root;
				while (1)
				{
					//Si la clé est plus petite que lq clé de tmp
					if (this->_key_cmp(val.first, tmp->value.first))
					{
						if (tmp->left)
							tmp = tmp->left;
						else
						{
							node	*nw = new node(val);
							tmp->left = nw;
							nw->parent = tmp;
							tmp = tmp->left; // a chaque fois que je break il faut que tmp soit égal à la dernière node inséré.Z
							break;
						}
					}
					else
					{
						//faire la gestion de si on veut insérer une valeur qui existe déjà.
						if (!this->_key_cmp(tmp->value.first, val.first))
							return NULL;
						if (tmp->right && tmp->right != this->_end)
							tmp = tmp->right;
						else
						{
							node *nw = new node(val);
							if (tmp->right)
							{
								nw->right = this->_end;
								this->_end->parent = nw;
							}
							tmp->right = nw;
							nw->parent = tmp;
							tmp = tmp->right;
							break;
						}
					}
				}
				return tmp;
			}

			void	rotation_left(node *x, node *y, node *p) // on reçoit celui qui va descendre(x) celui qui va monter(y) et le parent de base.
			{
				if (!p)
					this->_root = y;
				else if (x == p->left)
					p->left = y;
				else
					p->right = y;
				y->parent = p;
				x->right = y->left;
				if (x->right)
					x->right->parent = x;
				y->left = x;
				x->parent = y;
			}

			void	rotation_right(node *x, node *y, node *p)// on reçoit celui qui va monter(x) celui qui va descendre(y) et le parent de base.
			{
				if (!p)
					this->_root = x;
				else if (y == p->left)
					p->left = x;
				else
					p->right = x;
				x->parent = p;
				y->left = x->right;
				if (y->left)
					y->left->parent = y;
				x->right = y;
				y->parent = x;
			}

			void	re_color(node *x)
			{
				if (x->color == true)
					x->color = false;
				else
					x->color = true;
			}

			void	p_red_and_u_red(node *u, node *p, node *g)
			{
				re_color(u);
				re_color(g);
				re_color(p);
				if (g == this->_root)
					re_color(g);

			}

			void	g_right_p_right(node *p, node *g)
			{
				rotation_left(g, p, g->parent);
				re_color(g);
				re_color(p);
			}

			void	g_right_p_left(node *p)
			{
				rotation_right(p->left, p, p->parent);
				g_right_p_right(p->parent, p->parent->parent);
			}

			void	g_left_p_left(node *p)
			{
				rotation_right(p, p->parent, p->parent->parent);
				re_color(p);
				re_color(p->right);
			}

			void	g_left_p_right(node *p)
			{
				rotation_left(p, p->right, p->parent);
				rotation_right(p->parent, p->parent->parent, p->parent->parent->parent);
				re_color(p->parent);
				re_color(p->parent->right);
			}

		public:
		//Le probleme c'est que j'ai des réatcions en chaine et donc mon changement doit se faire dans un while et donc mon tmp ne soit pas chercher
		//qu'est qui doit etre insérer mais il doit chercher ou est l'erreur.

		//Voir si on peut juste faire 'implementation donne.
			void	insert(value_type val)
			{
				node	*tmp;
				node	*p;
				node	*g;
				if (this->_size == 0)
					return its_empty(val);
				tmp = where_is_the_insert(val);
				if (!tmp)
					return ;//gestion de quand on veut insérer une valeur qui existe déjà
				p = tmp->parent;
				if (p->color == false)
				{
					g = p->parent;
					if (g->right == p && g->left && g->left->color == false)
						p_red_and_u_red(g->left, p, g);
					else if (g->left == p && g->right &&g->right->color == false)
						p_red_and_u_red(g->right, p, g);
					else if (g->right == p)
					{
						if (p->right && p->right == tmp)
							g_right_p_right(p, g);
						else if (p->left && p->left == tmp)
							g_right_p_left(p);

					}
					else if (g->left == p)
					{
						if (p->left && p->left == tmp)
							g_left_p_left(p);
						else if (p->right && p->right == tmp)
							g_left_p_right(p);
					}
				}
			}

			//fonction pour imprimé.
			void print(void) { printRBTRec("", this->_root, false); };


	};
};

#endif
