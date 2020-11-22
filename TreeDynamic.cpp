#include "TreeDynamic.h"
#include <iostream>
#include "Consts.h"

TreeDynamic::TreeDynamic()
{
	std::cout << TREE_NO_PARAM_CONSTRUCTOR_TEXT << std::endl;
	_root = new NodeDynamic();
}

TreeDynamic::~TreeDynamic()
{
	std::cout << TREE_DESTRUCTOR_TEXT << std::endl;
	delete _root;
}

NodeDynamic* TreeDynamic::get_root()
{
	return _root;
}

void TreeDynamic::print_tree()
{
	_root->print_all_below();
}

int TreeDynamic::count_nodes(int value)
{
	int counter = 0;
	std::vector<NodeDynamic*>  nodes;
	std::vector<NodeDynamic*>  children;
	nodes.push_back(_root);

	while (!nodes.empty())
	{
		NodeDynamic* node = nodes[0];
		nodes.erase(nodes.begin());
		if (node->get_value() == value)
			counter++;

		for (int i = 0; i < node->get_children_number(); i++)
		{
			children.push_back(node->get_child(i));
		}

		if (nodes.empty())
		{
			nodes = children;
			children.clear();
		}
	}
	
	return counter;
}

bool TreeDynamic::move_subtree(NodeDynamic* parent_node, NodeDynamic* new_child_node)
{
	new_child_node->get_parent()->remove_child(new_child_node);

	parent_node->add_child(new_child_node);
	return true;
}
