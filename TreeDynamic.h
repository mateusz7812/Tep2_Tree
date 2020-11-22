#pragma once
#include "NodeDynamic.h"

class TreeDynamic
{
public:
	TreeDynamic();
	~TreeDynamic();
	
	void print_tree();
	int count_nodes(int value);
	bool move_subtree(NodeDynamic* parent_node, NodeDynamic* new_child_node);
	NodeDynamic* get_root();

private:
	NodeDynamic* _root;
};