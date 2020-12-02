#include "NodeDynamic.h"
#include <iostream>
#include "Consts.h"
/*
template<typename T>
NodeDynamic<T>::NodeDynamic()
{
	_val = 0;
	_parent_node = NULL;
	std::cout << NODE_NO_PARAM_CONSTRUCTOR_TEXT << std::endl;
}

template<typename T>
NodeDynamic<T>::NodeDynamic(const NodeDynamic<T>& other)
{
	_parent_node = other._parent_node;
	_val = other._val;
	_children = other._children;
	std::cout << NODE_COPY_CONSTRUCTOR_TEXT << " val:" << _val << std::endl;
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
	std::cout << NODE_MOVE_CONSTRUCTOR_TEXT << " val:" << _val << std::endl;
}

template<typename T>
NodeDynamic<T>::~NodeDynamic()
{
	std::cout << NODE_DESTRUCTOR_TEXT << " val:" << _val << std::endl;

	for (int i = 0; i < _children.size(); i++)
	{
		delete _children[i];
	}

	_children.clear();
}

template<typename T>
void NodeDynamic<T>::set_value(int new_val)
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
*/