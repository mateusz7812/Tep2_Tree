#pragma once
#include <cstddef>
#include <iostream>
#include <vector>

class NodeStatic
{
public:
	NodeStatic();
	NodeStatic(const NodeStatic& other);
	NodeStatic(NodeStatic&& other);
	~NodeStatic();
	void set_value(int new_val);
	int get_children_number();
	void set_parent(NodeStatic* parent);
	void add_new_child();
	NodeStatic* get_child(int child_offset);
	void print();
	void print_up();
	void print_all_below();
	NodeStatic& operator=(const NodeStatic& other);
	NodeStatic& operator=(NodeStatic&& other);
	
private:
	std::vector<NodeStatic> _children;
	NodeStatic* _parent_node;
	int _val{};
};