#include "NodeStatic.h"

#include "Consts.h"

NodeStatic::NodeStatic()
{
	_val = 0;
	_parent_node = NULL;
	std::cout << NODE_NOPARAM_CONSTRUCTOR_TEXT << std::endl;
}

NodeStatic::NodeStatic(const NodeStatic& other)
{
	_parent_node = other._parent_node;
	_val = other._val;
	_children = other._children;
	std::cout << NODE_COPY_CONSTRUCTOR_TEXT << " val:" << _val << std::endl;
}

NodeStatic::NodeStatic(NodeStatic&& other)
{	
	_parent_node = other._parent_node;
	other._parent_node = NULL;
	_val = other._val;
	other._val = 0;
	_children = move(other._children);
	other._children.clear();
	std::cout << NODE_MOVE_CONSTRUCTOR_TEXT << " val:" << _val << std::endl;
}

NodeStatic::~NodeStatic()
{
	std::cout << NODE_DESTRUCTOR_TEXT << " val:" << _val <<std::endl;
	_children.clear();
}

void NodeStatic::set_value(int new_val)
{
	_val = new_val;
}

int NodeStatic::get_children_number()
{
	return(_children.size());
}

void NodeStatic::set_parent(NodeStatic* parent)
{
	_parent_node = parent;
}

void NodeStatic::add_new_child()
{
	NodeStatic child;
	child.set_parent(this);
	_children.push_back(child);
}

NodeStatic* NodeStatic::get_child(int child_offset)
{
	if (child_offset < 0 || child_offset >= (int)_children.size())
		return NULL;
	return &_children.at(child_offset);
}

void NodeStatic::print()
{
	std::cout << " " << _val;
}

void NodeStatic::print_up()
{
	print();
	if (_parent_node != NULL) 
		_parent_node->print_up();
}

void NodeStatic::print_all_below()
{
	print();
	for (int i = 0; i < (int)_children.size(); i++)
	{
		_children[i].print_all_below();
	}
}

NodeStatic& NodeStatic::operator=(const NodeStatic& other)
{
	_parent_node = other._parent_node;
	_val = other._val;
	_children = other._children;
	return *this;
}

NodeStatic& NodeStatic::operator=(NodeStatic&& other)
{
	_parent_node = other._parent_node;
	other._parent_node = NULL;
	_val = other._val;
	other._val = 0;
	_children = move(other._children);
	other._children.clear();
	return *this;
}
