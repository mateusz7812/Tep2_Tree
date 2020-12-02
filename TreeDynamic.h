#pragma once
#include <iostream>

#include "Consts.h"
#include "NodeDynamic.h"

template< typename T>
class TreeDynamic
{
public:
	TreeDynamic<T>();
	~TreeDynamic<T>();
	
	void print_tree();
	int count_nodes(T value);
	bool move_subtree(NodeDynamic<T>* parent_node, NodeDynamic<T>* new_child_node);
	NodeDynamic<T>* get_root();

private:
	NodeDynamic<T>* _root;
};


template<typename T>
TreeDynamic<T>::TreeDynamic()
{
	std::cout << TREE_NO_PARAM_CONSTRUCTOR_TEXT << std::endl;
	_root = new NodeDynamic<T>();
}

template<typename T>
TreeDynamic<T>::~TreeDynamic()
{
	std::cout << TREE_DESTRUCTOR_TEXT << std::endl;
	delete _root;
}

template<typename T>
NodeDynamic<T>* TreeDynamic<T>::get_root()
{
	return _root;
}

template<typename T>
void TreeDynamic<T>::print_tree()
{
	_root->print_all_below();
}

template<typename T>
int TreeDynamic<T>::count_nodes(T value)
{
	int counter = 0;
	std::vector<NodeDynamic<T>*>  nodes;
	std::vector<NodeDynamic<T>*>  children;
	nodes.push_back(_root);

	while (!nodes.empty())
	{
		NodeDynamic<T>* node = nodes[0];
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

template<typename T>
bool TreeDynamic<T>::move_subtree(NodeDynamic<T>* parent_node, NodeDynamic<T>* new_child_node)
{
	new_child_node->get_parent()->remove_child(new_child_node);

	parent_node->add_child(new_child_node);
	return true;
}
