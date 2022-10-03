#include <iostream>
#include "AVL_Tree.hpp"

int main() {

    AVL_Tree<std::string> tree;
    tree.add("10");
    tree.add("20");
    tree.add("0");
    tree.add("4001");
    tree.add("4002");
    tree.add("25");
    tree.add("30");

    tree.print();


    return 0;
}
