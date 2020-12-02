#include <iostream>

#include "NodeStatic.h"
#include "TreeDynamic.h"
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

	tree.get_root()->add_new_child();
	tree.get_root()->get_child(1)->set_value(3);

	tree.get_root()->get_child(0)->add_new_child();
	tree.get_root()->get_child(0)->get_child(0)->set_value(4);

	tree.get_root()->get_child(0)->add_new_child();
	tree.get_root()->get_child(0)->get_child(1)->set_value(5);

	tree.get_root()->get_child(1)->add_new_child();
	tree.get_root()->get_child(1)->get_child(0)->set_value(6);

	tree.get_root()->get_child(1)->add_new_child();
	tree.get_root()->get_child(1)->get_child(1)->set_value(7);

	std::cout << std::endl << "print tree: ";
	tree.print_tree();
	std::cout << std::endl;

}


void dynamic_tree_test()
{
	TreeDynamic<int> tree;
	tree.get_root()->set_value(1);

	tree.get_root()->add_new_child();
	tree.get_root()->get_child(0)->set_value(2);

	tree.get_root()->add_new_child();
	tree.get_root()->get_child(1)->set_value(3);

	tree.get_root()->get_child(0)->add_new_child();
	tree.get_root()->get_child(0)->get_child(0)->set_value(4);

	tree.get_root()->get_child(0)->add_new_child();
	tree.get_root()->get_child(0)->get_child(1)->set_value(5);

	tree.get_root()->get_child(1)->add_new_child();
	tree.get_root()->get_child(1)->get_child(0)->set_value(6);

	tree.get_root()->get_child(1)->add_new_child();
	tree.get_root()->get_child(1)->get_child(1)->set_value(7);

	std::cout << std::endl << "print tree: ";
	tree.print_tree();
	std::cout << std::endl;

}

void test_dynamic_tree_move_subtree()
{
	TreeDynamic<int> tree1;

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(0)->set_value(1);

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(1)->set_value(2);

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(2)->set_value(3);

	tree1.get_root()->get_child(2)->add_new_child();
	tree1.get_root()->get_child(2)->get_child(0)->set_value(4);

	std::cout << std::endl << "first" << std::endl;
	tree1.print_tree();
	std::cout << std::endl;

	TreeDynamic<int> tree2;

	tree2.get_root()->set_value(50);

	tree2.get_root()->add_new_child();
	tree2.get_root()->get_child(0)->set_value(54);

	tree2.get_root()->get_child(0)->add_new_child();
	tree2.get_root()->get_child(0)->get_child(0)->set_value(56);

	tree2.get_root()->get_child(0)->get_child(0)->add_new_child();
	tree2.get_root()->get_child(0)->get_child(0)->get_child(0)->set_value(58);

	tree2.get_root()->get_child(0)->add_new_child();
	tree2.get_root()->get_child(0)->get_child(1)->set_value(57);

	tree2.get_root()->add_new_child();
	tree2.get_root()->get_child(1)->set_value(55);

	std::cout << std::endl << "second" << std::endl;
	tree2.print_tree();
	std::cout << std::endl;

	tree1.move_subtree(tree1.get_root()->get_child(2), tree2.get_root()->get_child(0));

	std::cout << std::endl << "first" << std::endl;
	tree1.print_tree();
	std::cout << std::endl;
	std::cout << std::endl << "second" << std::endl;
	tree2.print_tree();
	std::cout << std::endl;
	std::cout << std::endl;
}

void test_static_tree_move_subtree()
{
	TreeStatic tree1;

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(0)->set_value(1);

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(1)->set_value(2);

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(2)->set_value(3);

	tree1.get_root()->get_child(2)->add_new_child();
	tree1.get_root()->get_child(2)->get_child(0)->set_value(4);

	std::cout << std::endl << "first" << std::endl;
	tree1.print_tree();
	std::cout << std::endl;

	TreeStatic tree2;

	tree2.get_root()->set_value(50);

	tree2.get_root()->add_new_child();
	tree2.get_root()->get_child(0)->set_value(54);

	tree2.get_root()->get_child(0)->add_new_child();
	tree2.get_root()->get_child(0)->get_child(0)->set_value(56);

	tree2.get_root()->get_child(0)->get_child(0)->add_new_child();
	tree2.get_root()->get_child(0)->get_child(0)->get_child(0)->set_value(58);

	tree2.get_root()->get_child(0)->add_new_child();
	tree2.get_root()->get_child(0)->get_child(1)->set_value(57);

	tree2.get_root()->add_new_child();
	tree2.get_root()->get_child(1)->set_value(55);

	std::cout << std::endl << "second" << std::endl;
	tree2.print_tree();
	std::cout << std::endl;

	NodeStatic* parent = tree1.get_root()->get_child(2);
	NodeStatic* new_child = tree2.get_root()->get_child(0);
	tree1.move_subtree(parent, new_child);

	std::cout << std::endl << "first" << std::endl;
	tree1.print_tree();
	std::cout << std::endl << std::endl << "second" << std::endl;
	tree2.print_tree();
	std::cout << std::endl << std::endl;
}

void test_counting_nodes()
{
	TreeDynamic<int> tree1;

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(0)->set_value(1);

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(1)->set_value(2);

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(2)->set_value(3);

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(3)->set_value(4);

	tree1.get_root()->get_child(2)->add_new_child();
	tree1.get_root()->get_child(2)->get_child(0)->set_value(4);

	tree1.get_root()->get_child(2)->get_child(0)->add_new_child();
	tree1.get_root()->get_child(2)->get_child(0)->get_child(0)->set_value(4);

	std::cout << std::endl << "Tree:" << std::endl;
	tree1.print_tree();

	std::cout << std::endl << "Liczba węzłów o wartości 4: " << tree1.count_nodes(4) << std::endl << std::endl;
}

class Number
{
public:
	Number() :_val(0) {}
	Number(int val) : _val(val) {}
	friend std::ostream& operator<<(std::ostream& os, const Number& obj);
	friend bool operator==(const Number& first, const Number& second);
private:
	int _val;
};

std::ostream& operator<<(std::ostream& os, const Number& obj)
{
	os << "N" << obj._val;
	return os;
}

bool operator==(const Number& first, const Number& second)
{
	return first._val == second._val;
}

void test_template_dynamic_tree_move_subtree()
{

	TreeDynamic<Number> tree1;

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(0)->set_value(Number(1));

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(1)->set_value(Number(2));

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(2)->set_value(Number(3));

	tree1.get_root()->get_child(2)->add_new_child();
	tree1.get_root()->get_child(2)->get_child(0)->set_value(Number(4));

	std::cout << std::endl << "first" << std::endl;
	tree1.print_tree();
	std::cout << std::endl;

	TreeDynamic<Number> tree2;

	tree2.get_root()->set_value(Number(50));

	tree2.get_root()->add_new_child();
	tree2.get_root()->get_child(0)->set_value(Number(54));

	tree2.get_root()->get_child(0)->add_new_child();
	tree2.get_root()->get_child(0)->get_child(0)->set_value(Number(56));

	tree2.get_root()->get_child(0)->get_child(0)->add_new_child();
	tree2.get_root()->get_child(0)->get_child(0)->get_child(0)->set_value(Number(58));

	tree2.get_root()->get_child(0)->add_new_child();
	tree2.get_root()->get_child(0)->get_child(1)->set_value(Number(57));

	tree2.get_root()->add_new_child();
	tree2.get_root()->get_child(1)->set_value(Number(55));

	std::cout << std::endl << "second" << std::endl;
	tree2.print_tree();
	std::cout << std::endl;

	tree1.move_subtree(tree1.get_root()->get_child(2), tree2.get_root()->get_child(0));

	std::cout << std::endl << "first" << std::endl;
	tree1.print_tree();
	std::cout << std::endl;
	std::cout << std::endl << "second" << std::endl;
	tree2.print_tree();
	std::cout << std::endl;
	std::cout << std::endl;
}


void test_template_counting_nodes()
{
	TreeDynamic<Number> tree1;

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(0)->set_value(1);

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(1)->set_value(2);

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(2)->set_value(3);

	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(3)->set_value(4);

	tree1.get_root()->get_child(2)->add_new_child();
	tree1.get_root()->get_child(2)->get_child(0)->set_value(4);

	tree1.get_root()->get_child(2)->get_child(0)->add_new_child();
	tree1.get_root()->get_child(2)->get_child(0)->get_child(0)->set_value(4);

	std::cout << std::endl << "Tree:" << std::endl;
	tree1.print_tree();

	std::cout << std::endl << "Liczba węzłów o wartości 4: " << tree1.count_nodes(4) << std::endl << std::endl;
}

int main()
{
	test_template_counting_nodes();
}
