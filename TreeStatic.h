#pragma once
#include "NodeStatic.h"

class TreeStatic
{
public:
	TreeStatic();
	~TreeStatic();

	NodeStatic* get_root();
	void print_tree();
	bool move_subtree(NodeStatic* parent_node, NodeStatic* new_child_node);

private:
	NodeStatic _root;
};

