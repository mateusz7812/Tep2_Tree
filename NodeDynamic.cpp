#include "NodeDynamic.h"
#include <iostream>
#include "Consts.h"

NodeDynamic::NodeDynamic()
{
	_val = 0;
	_parent_node = NULL;
	std::cout << NODE_NO_PARAM_CONSTRUCTOR_TEXT << std::endl;
}

NodeDynamic::NodeDynamic(const NodeDynamic& other)
{
	_parent_node = other._parent_node;
	_val = other._val;
	_children = other._children;
	std::cout << NODE_COPY_CONSTRUCTOR_TEXT << " val:" << _val << std::endl;
}

NodeDynamic::NodeDynamic(NodeDynamic&& other)
{
	_parent_node = other._parent_node;
	other._parent_node = NULL;
	_val = other._val;
	other._val = 0;
	_children = move(other._children);
	other._children.clear();
	std::cout << NODE_MOVE_CONSTRUCTOR_TEXT << " val:" << _val << std::endl;
}

NodeDynamic::~NodeDynamic()
{
	std::cout << NODE_DESTRUCTOR_TEXT << " val:" << _val << std::endl;

	for (int i = 0; i < _children.size(); i++)
	{
		delete _children[i];
	}

	_children.clear();
}

void NodeDynamic::set_value(int new_val)
{
	_val = new_val;
}

int NodeDynamic::get_children_number()
{
	return _children.size();
}

int NodeDynamic::get_child_index(NodeDynamic* node)
{
	for (int i = 0; i < static_cast<int>(_children.size()); i++)
	{
		if (_children[i] == node)
		{
			return i;
		}
	}
	return -1;
}

int NodeDynamic::hash_code()
{
	return _val;
}

int NodeDynamic::get_value()
{
	return _val;
}

void NodeDynamic::set_parent(NodeDynamic* node)
{
	_parent_node = node;
}

void NodeDynamic::add_new_child()
{
	NodeDynamic* child = new NodeDynamic();
	child->set_parent(this);
	_children.push_back(child);
}

NodeDynamic* NodeDynamic::get_child(int child_offset)
{
	return _children[child_offset];
}

void NodeDynamic::print()
{
	std::cout << " " << _val;
}

void NodeDynamic::print_all_below()
{
	print();
	for (int i = 0; i < static_cast<int>(_children.size()); i++)
	{
		_children[i]->print_all_below();
	}
}

NodeDynamic& NodeDynamic::operator=(const NodeDynamic& other)
{
	if (this != &other)
	{
		_parent_node = other._parent_node;
		_val = other._val;
		_children = other._children;
	}
	return *this;
}

NodeDynamic& NodeDynamic::operator=(NodeDynamic&& other)
{
	_parent_node = other._parent_node;
	other._parent_node = NULL;
	_val = other._val;
	other._val = 0;
	_children = move(other._children);
	other._children.clear();
	return *this;
}

void NodeDynamic::add_child(NodeDynamic* node)
{
	_children.push_back(node);
	node->set_parent(this);
}

NodeDynamic* NodeDynamic::get_parent()
{
	return _parent_node;
}

void NodeDynamic::remove_child(NodeDynamic* node)
{
	node->set_parent(NULL);
	_children.erase(_children.begin() + get_child_index(node));
}
