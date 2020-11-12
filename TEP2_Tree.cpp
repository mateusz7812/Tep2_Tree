#include <iostream>

#include "NodeStatic.h"
#include "TreeStatic.h"

void node_print_test()
{
	NodeStatic node;
	node.set_value(1);

	node.add_new_child();
	node.get_child(0)->set_value(2);
	
	node.add_new_child();
	node.get_child(1)->set_value(3);

	std::cout << std::endl << "node print: ";
	node.print();

	std::cout << std::endl << "node print all below: ";
	node.print_all_below();

	std::cout << std::endl << "node child print up: ";
	node.get_child(1)->print_up();

	std::cout << std::endl << std::endl;
}

void node_add_child_test()
{
	NodeStatic root;
	std::cout << "root created" << std::endl << std::endl;
	
	root.add_new_child();
	root.get_child(0)->set_value(1);
	std::cout << "child added" << std::endl << std::endl;

	root.add_new_child();
	root.get_child(1)->set_value(2);
	std::cout << "child added" << std::endl << std::endl;

	
	root.get_child(0)->add_new_child();
	root.get_child(0)->get_child(0)->set_value(11);
	std::cout << "child added to first child" << std::endl << std::endl;

	root.get_child(0)->add_new_child();	
	root.get_child(0)->get_child(1)->set_value(12);
	std::cout << "child added to first child" << std::endl << std::endl;

	
	root.get_child(1)->add_new_child();
	root.get_child(1)->get_child(0)->set_value(21);
	std::cout << "child added to second child" << std::endl << std::endl;

	root.get_child(1)->add_new_child();
	root.get_child(1)->get_child(1)->set_value(22);
	std::cout << "child added to second child" << std::endl << std::endl;

	
	std::cout << "test print up from node 12:";
	root.get_child(0)->get_child(1)->print_up();

	std::cout << std::endl;
}

void tree_destructor_test()
{
	std::cout << std::endl << "Tree creating ..." << std::endl;
	TreeStatic tree;

	std::cout << std::endl << "Tree root value being set to 1..." << std::endl;
	tree.get_root()->set_value(1);
	
	std::cout << std::endl << "Tree destructing..." << std::endl;
}

void tree_test()
{
	TreeStatic tree;
	tree.get_root()->set_value(1);
	tree.get_root()->add_new_child();
	tree.get_root()->get_child(0)->set_value(2);

	std::cout << std::endl << "print tree: ";
	tree.print_tree();
	std::cout << std::endl;

}

int main()
{
	tree_destructor_test();
}
