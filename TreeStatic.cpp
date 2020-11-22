#include "TreeStatic.h"
#include <iostream>
#include <ostream>
#include "Consts.h"

TreeStatic::TreeStatic()
{
	std::cout << TREE_NO_PARAM_CONSTRUCTOR_TEXT << std::endl;
}

TreeStatic::~TreeStatic()
{
	std::cout << TREE_DESTRUCTOR_TEXT << std::endl;
}

NodeStatic* TreeStatic::get_root()
{
	return &_root;
}

void TreeStatic::print_tree()
{
	_root.print_all_below();
}

bool TreeStatic::move_subtree(NodeStatic* parent_node, NodeStatic* new_child_node)
{
	NodeStatic saved_child(*new_child_node);
	
	NodeStatic* parent = new_child_node->get_parent();
	parent->remove_child(new_child_node);

	parent_node->add_child(&saved_child);
	return true;
}
