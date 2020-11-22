#pragma once
#include <vector>

class NodeStatic
{
public:
	NodeStatic();
	NodeStatic(const NodeStatic& other);
	NodeStatic(NodeStatic&& other);
	~NodeStatic();

	int get_children_number();
	int get_child_index(NodeStatic* node);

	void add_new_child();
	void print();
	void print_up();
	void print_all_below();
	void set_value(int new_val);
	void set_parent(NodeStatic* parent);
	void add_child(NodeStatic* node);
	void remove_child(NodeStatic* node);

	NodeStatic* get_child(int child_offset);
	NodeStatic* get_parent();

	NodeStatic& operator=(const NodeStatic& other);
	NodeStatic& operator=(NodeStatic&& other);
	
private:
	std::vector<NodeStatic> _children;
	NodeStatic* _parent_node;
	int _val;
};

