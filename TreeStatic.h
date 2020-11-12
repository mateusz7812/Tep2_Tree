#pragma once
#include "NodeStatic.h"

class TreeStatic
{
public:
	TreeStatic();
	~TreeStatic();

	NodeStatic* get_root();
	void print_tree();

private:
	NodeStatic _root;
};

