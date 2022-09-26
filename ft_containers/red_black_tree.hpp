#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <iostream>
# include "pair.hpp"
# include "tree_iterator.hpp"

# define RED false
# define BLACK true

namespace ft
{
	//Par définition j'ai mis la couleur du node à rouge dès le départ puisque à chaque insertion(sauf la première) le node est d'abord mis en rouge.
	template <class key, class T>
	class Node
	{
		public:
			typedef			ft::pair<key, T>		value_type;
			typedef	const	ft::pair<key, T>		const_value_type;
			typedef			value_type&				value_type_ref;
			typedef	const	value_type&				const_value_type_ref;
			typedef			value_type*				value_type_ptr;
			typedef const	value_type*				const_value_type_ptr;

			Node					*end;
			Node					*parent;
			Node					*left;
			Node					*right;
			value_type				value;
			bool					color;//true == noir et RED == rouge

			/*Default constructor, Construct an empty node*/
			Node() : end(NULL), parent(NULL), left(NULL), right(NULL), color(RED)
			{}

			/*Construct a node which has a parent and a value, but no child.*/
			//pas sure que ce soit utile, a voir
			Node(Node *parent, value_type val) : parent(parent), left(NULL), right(NULL), value(val), color(RED)
			{}

			/*Construct a top of the tree node.*/
			Node(value_type val) : parent(NULL), left(NULL), right(NULL), value(val), color(RED)
			{}

			//pas sure que ce soit utile a voir
			Node(key first, T second) : parent(NULL), left(NULL), right(NULL), color(RED)
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
				this->value = rhs.value;
				this->color = rhs->color;
				this->end = rhs->end;
			}

			bool	is_leaf()
			{
				if (this->right == NULL && this->left == NULL)
					return 1;
				return 0;
			}
	};

	//fonction pour afficher donc à enlever
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
			printRBTRec(prefix + (isLeft ? "│   " : "    "), node->right, BLACK);
			printRBTRec(prefix + (isLeft ? "│   " : "    "), node->left, RED);
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
			typedef				key														key_type;
			typedef				T														mapped_type;
			typedef				pair<key_type, mapped_type>								value_type;
			typedef				Compare													key_compare;
			typedef				Alloc													allocator_type;
			typedef	typename	allocator_type::reference								reference;
			typedef typename	allocator_type::const_reference							const_reference;
			typedef typename	allocator_type::pointer									pointer;
			typedef typename	allocator_type::const_pointer							const_pointer;
			typedef typename	ft::tree_iterator<Node<key_type, mapped_type> >			iterator;
			typedef typename	ft::const_tree_iterator<Node<key_type, mapped_type> >	const_iterator;
			//reverse_iterator
			//const_reverse_iterator
			typedef				ptrdiff_t												difference_type;
			typedef				size_t													size_type;
			typedef				Node<key, T>											node;

		protected:

			node				*_end;
			allocator_type		_alloc;
			key_compare			_key_cmp;
			size_t				_size;
			node				*_root;

		private:
			/*Créer le noeud NULL*/
			void	this_is_end()
			{
				_end = new node;
				_end->color = BLACK;
				_end->left = NULL;
				_end->right = NULL;
				_end->parent = NULL;
				_end->end = this->_end;
			}

		public:
			/*Default constructor*/
			RBTree(const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _key_cmp(comp), _size(0), _root(NULL)
			{
				this_is_end();
			}

			/*TO DO : Copie Constructor*/
			RBTree(RBTree const &cpy) : _alloc(cpy._alloc), _key_cmp(cpy._key_cmp), _size(0), _root(NULL)
			{
				iterator	it(cpy.RBTMinVal());

				this_is_end();
				while (!it._node->is_leaf())
				{
					insert(it._node->value);
					it++;
				}
			}

			//Constructeur de range (pas sure d'en avoir besoin directement dans le redblack tree)

			/*Deconstructor*/
			~RBTree()
			{
				node *tmp = this->_root;

				while (this->_size != 0)
				{
					if (tmp->right && tmp->right != this->_end)
						tmp = tmp->right;
					else if (tmp->left && tmp->left != this->_end)
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
				this->_root->left = this->_end;
				this->_root->color = BLACK;
				this->_root->end = this->_end;
			}

			pair<iterator, bool>	where_is_the_value(value_type val)
			{
				node	*tmp = this->_root;
				pair<iterator, bool>	ret;

				while (1)
				{
					//Si la clé est plus petite que la clé de tmp
					if (this->_key_cmp(val.first, tmp->value.first))
					{
						if (tmp->left && tmp->left != this->_end)
							tmp = tmp->left;
						else
						{
							node *nw = new node(val);
							tmp->left = nw;
							nw->right = _end;
							nw->left = _end;
							nw->parent = tmp;
							nw->end = _end;
							tmp = tmp->left; // a chaque fois que je break il faut que tmp soit égal à la dernière node inséré.Z
							this->_size++;
							break;
						}
					}
					else
					{
						//faire la gestion de si on veut insérer une valeur qui existe déjà.
						if (!this->_key_cmp(tmp->value.first, val.first))
						{
							ret.first = tmp;
							ret.second = false;
							return ret;
						}
						if (tmp->right && tmp->right != this->_end)
						{
							tmp = tmp->right;
							// std::cout << "tmp right == " << tmp->right->value.first << std::endl;
						}
						else
						{
							node *nw = new node(val);
							tmp->right = nw;
							nw->right = _end;
							nw->left = _end;
							nw->parent = tmp;
							nw->end = _end;
							tmp = tmp->right;
							this->_size++;
							break;
						}
					}
				}
				ret.first = tmp;
				ret.second = true;
				return ret;
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
				if (x->color == BLACK)
					x->color = RED;
				else
					x->color = BLACK;
			}

			node	*p_red_and_u_red(node *u, node *p, node *g)
			{
				re_color(u);
				re_color(g);
				re_color(p);
				if (g == this->_root)
					re_color(g);
				return g;
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
			ft::pair<iterator, bool>	insert(value_type val)
			{
				ft::pair<iterator, bool>	ret;
				node		*tmp;
				node		*p;//parent
				node		*g;//grand-parent

				if (this->_size == 0)
				{
					its_empty(val);
					ret.first = this->_root;
					ret.second = true;
					return ret;
				}
				ret = where_is_the_value(val);
				if (!ret.second)
				{
					return ret;//gestion de quand on veut insérer une valeur qui existe déjà
				}
				tmp = ret.first._node;
				while (tmp->parent && tmp->parent->color == RED)
				{
					p = tmp->parent;
					g = p->parent;
					if (g->right == p && g->left && g->left->color == RED)
						tmp = p_red_and_u_red(g->left, p, g);
					else if (g->left == p && g->right &&g->right->color == RED)
						tmp = p_red_and_u_red(g->right, p, g);
					else if (g->right == p)
					{
						if (p->right && p->right == tmp)
							g_right_p_right(p, g);
						else if (p->left && p->left == tmp)
							g_right_p_left(p);
						tmp = tmp->parent;
					}
					else if (g->left == p)
					{
						if (p->left && p->left == tmp)
							g_left_p_left(p);
						else if (p->right && p->right == tmp)
							g_left_p_right(p);
						tmp = tmp->parent;
					}
				}
				return ret;
			}

		private:
		node	*find_the_value(key_type val)
		{
			node	*tmp = this->_root;

			while (tmp != this->_end && tmp->value.first != val)
			{
				if (this->_key_cmp(val, tmp->value.first))
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			return tmp;
		}

		void	replace_node(node *to_replace, node *replacor)
		{
			if(!to_replace->parent)
				this->_root = replacor;
			else if(to_replace->parent->right == to_replace)
				to_replace->parent->right = replacor;
			else if (to_replace->parent->left == to_replace)
				to_replace->parent->left = replacor;
			replacor->parent = to_replace->parent;
		}

		node	*FindMinval(node *tmp)
		{
			while (tmp->left != this->_end)
				tmp = tmp->left;
			return tmp;
		}

		node	*BST_delete(node *tmp)
		{
			bool	todelete_color = tmp->color;
			node	*x;
			node	*y;
			node	*todelete = tmp;

			if (todelete->left == this->_end)
			{
				x = todelete->right;
				replace_node(todelete, todelete->right);
			}
			else if (todelete->right == this->_end)
			{
				x = todelete->left;
				replace_node(todelete, todelete->left);
			}
			else
			{
				y = FindMinval(todelete->right);
				todelete_color = y->color;
				x = y->right;
				if (y->parent && y->parent == todelete)
					x->parent = y;
				else
				{
					replace_node(y, y->right);
					y->right = todelete->right;
					y->right->parent = y;
				}
				replace_node(todelete, y);
				y->left = todelete->left;
				y->left->parent = y;
				y->color = todelete->color;
			}
			delete todelete;
			this->_size--;
			if (todelete_color == BLACK)
				return x;
			return NULL;
		}

		node	*rebalanced_delete(node *tmp)
		{
			node	*x = tmp;
			node	*s;
			while (x != this->_root && x->color == BLACK)
			{
				if (x == x->parent->left)
				{
					s = x->parent->right;
					if (s->color == RED)
					{
						re_color(s);
						x->parent->color = RED;
						rotation_left(x->parent, x->parent->right, x->parent->parent);
						s = x->parent->right;
					}
					if (s->left->color == BLACK && s->right->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->right->color == BLACK)
						{
							s->left->color = BLACK;
							s->color = RED;
							rotation_right(s, s->parent, s->parent->parent);
							s = x->parent->right;
						}
						s->right->color = BLACK;
						s->color = x->parent->color;
						x->parent->color = BLACK;
						rotation_left(x->parent, x->parent->right, x->parent->parent);
						x = this->_root;
					}
				}
				else
				{
					s = x->parent->left;
					if (s->color == RED)
					{
						re_color(s);
						x->parent->color = RED;
						rotation_right(x->parent->left, x->parent, x->parent->parent);
						s = x->parent->left;
					}

					if (s->right->color == BLACK && s->left->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->left->color == BLACK)
						{
							s->right->color = BLACK;
							s->color = RED;
							rotation_left(s, s->parent, s->parent->parent);
							s = x->parent->left;
						}
						s->left->color = BLACK;
						s->color = x->parent->color;
						x->parent->color = BLACK;
						rotation_right(x->parent, x->parent->left, x->parent->parent);
						x = this->_root;
					}
				}
			}
			x->color = BLACK;
			return x;
		}

		public:
			size_type	to_delete(key_type val)
			{
				node	*tmp;
				node	*bis;

				tmp = find_the_value(val);
				if (tmp == this->_end)
					return 0;//gestion de quand l'object n'existe pas dans l'arbre
				bis = BST_delete(tmp);
				if (bis)
					bis = rebalanced_delete(bis);
				if (val == 4)
					exit(EXIT_SUCCESS);
				print();
				return 1;
			}

			node	*RBTMinVal() const
			{
				node *tmp = this->_root;

				while (tmp->left != this->_end)
					tmp = tmp->left;
				return tmp;
			}

			node	*RBTMaxVal()
			{
				node *tmp = this->_root;

				while (tmp->right != this->_end)
					tmp = tmp->right;
				return tmp;
			}

			//fonction pour imprimé.
			void print(void) { printRBTRec("", this->_root, RED); };

			//a enlever
			size_type	get_size() const
			{
				return this->_size;
			}

			node	*get_the_end() const
			{
				return this->_end;
			}

			allocator_type	get_alloc() const
			{
				return this->_alloc;
			}

			void	swap(RBTree *rhs)
			{
				node	*tmp_end = this->_end;
				node	*tmp_root = this->_root;
				allocator_type	tmp_alloc = this->_alloc;
				key_compare		tmp_compare = this->_key_cmp;
				size_t			tmp_size = this->_size;

				this->_end = rhs->_end;
				this->_root = rhs->_root;
				this->_alloc = rhs->_alloc;
				this->_key_cmp = rhs->_key_cmp;
				this->_size = rhs->_size;

				rhs->_end = tmp_end;
				rhs->_root = tmp_root;
				rhs->_alloc = tmp_alloc;
				rhs->_key_cmp = tmp_compare;
				rhs->_size = tmp_size;
			}

	};

	template < class T>
	struct less : public std::binary_function <T,T,bool>
	{
		bool operator()(const T& x, const T& y) const { return x < y; }
	};
};



#endif

