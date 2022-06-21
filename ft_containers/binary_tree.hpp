#ifndef BINARY_TREE
# define BINARY_TREE

# include <iostream>

namespace ft
{
	template <typename T>
	class Binary_Tree
	{
		protected:
			class Node
			{
				public:
					Node			*_parent;
					Node			*_left;
					Node			*_right;
					value_type		_value;

					/*Default constructor, Construct an empty node*/
					Node() : _parent(NULL), _left(NULL), _right(NULL)
					{}

					/*Construct a node which has a parent and a value, but no child.*/
					Node(Node *parent, value_type val) : _parent(parent), _left(NULL), _right(NULL), _value(val)
					{}

					/*Construct a top of the tree node.*/
					Node(value_type val) : _parent(NULL), _left(NULL), _right(NULL), _value(val)
					{}

					//copy constructor

					//operator=

					~Node() {}

					//assigner un node à left ou a right voir si utile.
			};

		public:
			typedef			T			value_type;
			typedef			T*			pointer;
			typedef			const T*	const_pointer;
			typedef			T&			reference;
			typedef			const T&	const_reference;
			typedef			size_t		size_type;

		protected:
			Node	*_tree;

		public:

		/*Default constructor. An empty tree*/
		Binary_Tree() : _tree(NULL) {}

		/*Constructor with a first value*/
		Binary_Tree(value_type val)
		{ this->_tree = Node(val); }

		/*Copy constructor*/
		// Binary_Tree(Binary_Tree cpy)
		// {
		// }



	};
};

#endif
