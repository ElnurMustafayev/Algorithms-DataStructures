#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    // BST: Binary Search Trees
    {
        trees::BinarySearchTree<int> tree = trees::BinarySearchTree<int>();

        auto* head1 = tree.insert(6);
        tree.insert(9);
        tree.insert(3);
        tree.insert(1);
        tree.insert(11);
        tree.insert(2);

        tree.print(tree.search(3));
        tree.print(head1);

        trees::TreeNode<int> head2 = tree.head();

        std::cout << "Min: " << tree.min(&head2) << std::endl;
        std::cout << "Max: " << tree.max(&head2) << std::endl;
    }
}