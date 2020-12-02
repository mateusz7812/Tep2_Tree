#pragma once
#include <vector>
#include <iostream>
#include "Consts.h"

template<typename T>
class NodeDynamic
{
public:
	NodeDynamic();
	NodeDynamic(const NodeDynamic<T>& other);
	NodeDynamic(NodeDynamic<T>&& other);
	~NodeDynamic();

	int get_children_number();
	int get_child_index(NodeDynamic<T>* node);
	
	T get_value();

	void add_new_child();
	void print();
	void print_all_below();
	void set_value(T new_val);
	void set_parent(NodeDynamic<T>* node);
	void add_child(NodeDynamic<T>* node);
	void remove_child(NodeDynamic<T>* node);

	NodeDynamic* get_parent();
	NodeDynamic* get_child(int child_offset);

	NodeDynamic<T>& operator=(const NodeDynamic<T>& other);
	NodeDynamic<T>& operator=(NodeDynamic<T>&& other);

private:
	std::vector<NodeDynamic<T>*>  _children;
	NodeDynamic<T>* _parent_node;
	T _val;
};


template<typename T>
NodeDynamic<T>::NodeDynamic()
{
	_val = NULL;
	_parent_node = NULL;
	std::cout << NODE_NO_PARAM_CONSTRUCTOR_TEXT << std::endl;
}

template<typename T>
NodeDynamic<T>::NodeDynamic(const NodeDynamic<T>& other)
{
	_parent_node = other._parent_node;
	_val = other._val;
	_children = other._children;
	std::cout << NODE_COPY_CONSTRUCTOR_TEXT << " ";
	print();
	std::cout << std::endl;
}

template<typename T>
NodeDynamic<T>::NodeDynamic(NodeDynamic<T>&& other)
{
	_parent_node = other._parent_node;
	other._parent_node = NULL;
	_val = other._val;
	other._val = 0;
	_children = move(other._children);
	other._children.clear();
	std::cout << NODE_MOVE_CONSTRUCTOR_TEXT << " ";
	print();
	std::cout << std::endl;
}

template<typename T>
NodeDynamic<T>::~NodeDynamic()
{
	try
	{
		std::cout << NODE_DESTRUCTOR_TEXT << " ";
		print();
		std::cout << std::endl;
	}
	catch (...)
	{
	}

	for (int i = 0; i < static_cast<int>(_children.size()); i++)
	{
		delete _children[i];
	}

	_children.clear();
}

template<typename T>
void NodeDynamic<T>::set_value(T new_val)
{
	_val = new_val;
}

template<typename T>
int NodeDynamic<T>::get_children_number()
{
	return _children.size();
}

template<typename T>
int NodeDynamic<T>::get_child_index(NodeDynamic<T>* node)
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

template<typename T>
T NodeDynamic<T>::get_value()
{
	return _val;
}

template<typename T>
void NodeDynamic<T>::set_parent(NodeDynamic<T>* node)
{
	_parent_node = node;
}

template<typename T>
void NodeDynamic<T>::add_new_child()
{
	NodeDynamic<T>* child = new NodeDynamic<T>();
	child->set_parent(this);
	_children.push_back(child);
}

template<typename T>
NodeDynamic<T>* NodeDynamic<T>::get_child(int child_offset)
{
	return _children[child_offset];
}

template<typename T>
void NodeDynamic<T>::print()
{
	std::cout << " " << _val;
}

template <typename T>
void NodeDynamic<T>::print_all_below()
{
	print();
	for (int i = 0; i < static_cast<int>(_children.size()); i++)
	{
		_children[i]->print_all_below();
	}
}

template <typename T>
NodeDynamic<T>& NodeDynamic<T>::operator=(const NodeDynamic<T>& other)
{
	if (this != &other)
	{
		_parent_node = other._parent_node;
		_val = other._val;
		_children = other._children;
	}
	return *this;
}

template <typename T>
NodeDynamic<T>& NodeDynamic<T>::operator=(NodeDynamic<T>&& other)
{
	_parent_node = other._parent_node;
	other._parent_node = NULL;
	_val = other._val;
	other._val = 0;
	_children = move(other._children);
	other._children.clear();
	return *this;
}


template <typename T>
void NodeDynamic<T>::add_child(NodeDynamic<T>* node)
{
	_children.push_back(node);
	node->set_parent(this);
}

template <typename T>
NodeDynamic<T>* NodeDynamic<T>::get_parent()
{
	return _parent_node;
}

template <typename T>
void NodeDynamic<T>::remove_child(NodeDynamic<T>* node)
{
	node->set_parent(NULL);
	_children.erase(_children.begin() + get_child_index(node));
}
