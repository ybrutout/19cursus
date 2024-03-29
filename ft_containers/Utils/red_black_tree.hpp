                                                                                                                                                                                                                             #ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "pair.hpp"
# include "../Iterator/tree_iterator.hpp"
# include "../Iterator/reverse_iterator.hpp"
# include <iostream>

# define RED false
# define BLACK true

namespace ft
{
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
			bool					color;

			/*Default constructor, Construct an empty node*/
			Node() : end(NULL), parent(NULL), left(NULL), right(NULL), color(RED)
			{}

			/*Construct a node which has a parent and a value, but no child.*/
			Node(Node *parent, value_type val) : parent(parent), left(NULL), right(NULL), value(val), color(RED)
			{}

			/*Construct a top of the tree node.*/
			Node(value_type val) : parent(NULL), left(NULL), right(NULL), value(val), color(RED)
			{}

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

	//Display Function just for vizualisation
	// template <class key, class T>
	// void printRBTRec(const std::string &prefix, const Node<key, T> *node, bool isLeft)
	// {
	// 	if (node != nullptr)
	// 	{
	// 		std::cout << prefix;
	// 		std::cout << (isLeft ? "├──" : "└──");
	// 		if (node->color)
	// 			std::cout << node->value.first << std::endl;
	// 		else
	// 		{
	// 			std::cout << "\033[31m" << node->value.first << "\033[0m" << std::endl;
	// 		}
	// 		printRBTRec(prefix + (isLeft ? "│   " : "    "), node->right, BLACK);
	// 		printRBTRec(prefix + (isLeft ? "│   " : "    "), node->left, RED);
	// 	}
	// 	else
	// 	{
	// 		std::cout << prefix;
	// 		std::cout << (isLeft ? "├──" : "└──");
	// 		std::cout << std::endl;
	// 	}
	// }

	template <class key, class T, class Compare = std::less<key>, class Alloc =  std::allocator<ft::pair<key, T> > >
	class RBTree
	{
		public:
			typedef				Node<key, T>													node;
			typedef				key																key_type;
			typedef				T																mapped_type;
			typedef				pair<key_type, mapped_type>										value_type;
			typedef				Compare															key_compare;
			typedef				typename Alloc::template rebind<node>::other					allocator_type;
			typedef	typename	allocator_type::reference										reference;
			typedef typename	allocator_type::const_reference									const_reference;
			typedef typename	allocator_type::pointer											pointer;
			typedef typename	allocator_type::const_pointer									const_pointer;
			typedef typename	ft::tree_iterator<Node<key_type, mapped_type> >					iterator;
			typedef typename	ft::const_tree_iterator<Node<key_type, mapped_type> >			const_iterator;
			typedef	typename	ft::reverse_iterator<iterator>									reverse_iterator;
			typedef	typename	ft::reverse_iterator<const_iterator>							const_reverse_iterator;
			typedef				ptrdiff_t														difference_type;
			typedef				size_t															size_type;

		protected:

			node				*_end;
			allocator_type		_alloc;
			key_compare			_key_cmp;
			size_t				_size;
			node				*_root;

		private:
			void	this_is_end()
			{
				_end = _alloc.allocate(1);
				_alloc.construct(_end, node());
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
						_alloc.destroy(bis);
						_alloc.deallocate(bis, 1);
						this->_size--;
					}
				}
				_alloc.destroy(_end);
				_alloc.deallocate(_end, 1);
			}
		private:
			void	its_empty(value_type val)
			{
				this->_root = _alloc.allocate(1);
				_alloc.construct(this->_root, node(val));
				this->_size++;
				this->_root->right = this->_end;
				this->_root->left = this->_end;
				this->_root->color = BLACK;
				this->_root->end = this->_end;
				this->_end->parent = this->_root;
			}

			pair<iterator, bool>	where_is_the_value(value_type val)
			{
				node	*tmp = this->_root;
				pair<iterator, bool>	ret;

				while (1)
				{
					if (this->_key_cmp(val.first, tmp->value.first))
					{
						if (tmp->left && tmp->left != this->_end)
							tmp = tmp->left;
						else
						{
							node *nw = _alloc.allocate(1);
							_alloc.construct(nw, node(val));
							tmp->left = nw;
							nw->right = _end;
							nw->left = _end;
							nw->parent = tmp;
							nw->end = _end;
							tmp = tmp->left;
							this->_size++;
							break;
						}
					}
					else
					{
						if (!this->_key_cmp(tmp->value.first, val.first))
						{
							ret.first = tmp;
							ret.second = false;
							return ret;
						}
						if (tmp->right && tmp->right != this->_end)
							tmp = tmp->right;
						else
						{
							node *nw = _alloc.allocate(1);
							_alloc.construct(nw, node(val));
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

			void	rotation_left(node *x, node *y, node *p)
			{
				if (!p)
					this->_root = y;
				else if (x == p->left)
					p->left = y;
				else
					p->right = y;
				y->parent = p;
				x->right = y->left;
				if (!x->right->is_leaf() )
					x->right->parent = x;
				y->left = x;
				x->parent = y;
			}

			void	rotation_right(node *x, node *y, node *p)
			{
				if (!p)
					this->_root = x;
				else if (y == p->left)
					p->left = x;
				else
					p->right = x;
				x->parent = p;
				y->left = x->right;
				if (!y->left->is_leaf())
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

		public:
			ft::pair<iterator, bool>	insert(value_type val)
			{
				ft::pair<iterator, bool>	ret;
				node		*tmp;
				node		*tmp_tmp;
				node		*u;

				if (this->_size == 0)
				{
					its_empty(val);
					ret.first = this->_root;
					ret.second = true;
					return ret;
				}
				ret = where_is_the_value(val);
				if (!ret.second)
					return ret;
				tmp = ret.first._node;
				while (tmp && tmp->parent && tmp->parent->color == RED)
				{
					if (tmp->parent->parent->right == tmp->parent)
					{
						u = tmp->parent->parent->left;
						if (u->color == RED)
						{
							u->color = BLACK;
							tmp->parent->color = BLACK;
							tmp->parent->parent->color = RED;
							tmp = tmp->parent->parent;
						}
						else 
						{
							if (tmp == tmp->parent->left)
							{
								tmp_tmp = tmp->parent;
								rotation_right(tmp, tmp->parent, tmp->parent->parent);
								tmp = tmp_tmp;
							}
							tmp->parent->color = BLACK;
							tmp->parent->parent->color = RED;
							rotation_left(tmp->parent->parent, tmp->parent->parent->right, tmp->parent->parent->parent);
						}
					}
					else
					{
						u = tmp->parent->parent->right;
						if (u->color == RED)
						{
							u->color = BLACK;
							tmp->parent->color = BLACK;
							tmp->parent->parent->color = RED;
							tmp = tmp->parent->parent;
						}
						else
						{
							if (tmp == tmp->parent->right)
							{
								tmp_tmp = tmp->parent;
								rotation_left(tmp->parent, tmp, tmp->parent->parent);
								tmp = tmp_tmp;							
							}
							tmp->parent->color = BLACK;
							tmp->parent->parent->color = RED;
							rotation_right(tmp->parent, tmp->parent->parent, tmp->parent->parent->parent);
						}
					}
					_root->color = BLACK;
				}
				return ret;
			}

			node	*find_the_value(key_type val)const
			{
				if (_size == 0)
					return _end;
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

		private:

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

		node	*FindMinval(node *tmp)const
		{

			while (tmp != _end && tmp->left != this->_end)
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
			_alloc.destroy(todelete);
			_alloc.deallocate(todelete, 1);
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
					if (s != _end && s->left->color == BLACK && s->right->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s != _end && s->right->color == BLACK)
						{
							s->left->color = BLACK;
							s->color = RED;
							rotation_right(s->left, s, s->parent);
							s = x->parent->right;
						}
						if (s != _end)
							s->color = x->parent->color;
						x->parent->color = BLACK;
						if (s != _end)
							s->right->color = BLACK;
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
					if (s != _end && s->right->color == BLACK && s->left->color == BLACK)
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
							rotation_left(s, s->right, s->parent);
							s = x->parent->left;
						}
						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->left->color = BLACK;
						rotation_right(x->parent->left, x->parent, x->parent->parent);
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
					return 0;
				bis = BST_delete(tmp);
				if (bis)
					bis = rebalanced_delete(bis);
				return 1;
			}

			node	*RBTMinVal() const
			{
				node *tmp = this->_root;

				while (tmp->left != this->_end)
					tmp = tmp->left;
				return tmp;
			}

			node	*RBTMaxVal() const
			{
				node *tmp = this->_root;

				while (tmp->right != this->_end)
					tmp = tmp->right;
				return tmp;
			}

			node	*LowerBound(key_type k)const
			{
				node 	*tmp = _root;
				node	*previous;

				while (tmp != _end)
				{
					previous = tmp;
					if (tmp->value.first == k)
						return tmp;
					else if (tmp->value.first > k)
						tmp = tmp->left;
					else
						tmp = tmp->right;
				}
				if (previous->value.first > k)
					return previous;
				else
				{
					if (previous == RBTMaxVal())
						return _end;
					while (previous->parent->right == previous)
						previous = previous->parent;
				}
				return previous->parent;
			}

			node	*upperBound(key_type k)const
			{
				node 	*tmp = _root;
				node	*previous;
				while (tmp != _end)
				{
					previous = tmp;
					if (tmp->value.first == k)
						break;
					else if (tmp->value.first > k)
						tmp = tmp->left;
					else
						tmp = tmp->right;
				}
				if (tmp != _end)
				{
					if (tmp->right != _end)
						return FindMinval(tmp->right);
					if (tmp == RBTMaxVal())
						return _end;
					while (tmp->parent && tmp == tmp->parent->right)
						tmp = tmp->parent;
					return tmp->parent;
				}
				else
				{
					if (previous == RBTMaxVal())
				 		return _end;
					if (previous == RBTMinVal())
						return RBTMinVal();
					while (tmp->parent && tmp == tmp->parent->right)
						tmp = tmp->parent;
					return tmp->parent;
				}
			}


			//Display function just to vizualisation
			// void print(void) const { printRBTRec("", this->_root, RED); };

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
				size_t			tmp_size = this->_size;

				this->_end = rhs->_end;
				this->_root = rhs->_root;
				this->_size = rhs->_size;

				rhs->_end = tmp_end;
				rhs->_root = tmp_root;
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

