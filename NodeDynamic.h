#pragma once
#include <vector>


class NodeDynamic
{
public:
	NodeDynamic();
	NodeDynamic(const NodeDynamic& other);
	NodeDynamic(NodeDynamic&& other);
	~NodeDynamic();
	
	int get_children_number();
	int get_child_index(NodeDynamic* node);
	int hash_code();
	int get_value();

	void add_new_child();
	void print();
	void print_all_below();
	void set_value(int new_val);
	void set_parent(NodeDynamic* node);
	void add_child(NodeDynamic* node);
	void remove_child(NodeDynamic* node);

	NodeDynamic* get_parent();
	NodeDynamic* get_child(int child_offset);

	NodeDynamic& operator=(const NodeDynamic& other);
	NodeDynamic& operator=(NodeDynamic&& other);

private:
	std::vector<NodeDynamic*>  _children;
	NodeDynamic* _parent_node;
	int _val;
};
