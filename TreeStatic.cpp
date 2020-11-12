#include "TreeStatic.h"

#include "Consts.h"

TreeStatic::TreeStatic()
{
	std::cout << TREE_NOPARAM_CONSTRUCTOR_TEXT << std::endl;
}

TreeStatic::~TreeStatic()
{
	std::cout << TREE_DESTRUCTOR_TEXT << std::endl;
}

NodeStatic* TreeStatic::get_root()
{
	return &_root;
}

void TreeStatic::print_tree()
{
	_root.print_all_below();
}
