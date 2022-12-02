#pragma once
#include <iostream>

namespace trees {

	template<typename T>
	struct TreeNode {
		T data;
		TreeNode* parent = nullptr;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;

		TreeNode(T data) : data(data) {}
	};

	template<typename T>
	class BinarySearchTree {
		TreeNode<T>* root = nullptr;

	public:
		TreeNode<T> head() {
			return *root;
		}



		/// <summary>
		/// get element reference by data
		/// </summary>
		/// <param name="data">value to search</param>
		/// <returns>found item | nullptr</returns>
		TreeNode<T>* search(T data) {
			TreeNode<T>* cursor = this->root;

			while (cursor != nullptr) {
				if (data > cursor->data)
					cursor = cursor->right;
				else if (data < cursor->data)
					cursor = cursor->left;
				else 
					return cursor;
			}

			return nullptr;
		}



		/// <summary>
		/// insert element with value
		/// </summary>
		/// <param name="data">value to insert</param>
		/// <returns>inserted element</returns>
		TreeNode<T>* insert(T data) {
			// insert in head
			if (this->root == nullptr) {
				return this->root = new TreeNode<T>(data);
			}


			// start moving ...
			TreeNode<T>* cursor = this->root;

			while (cursor != nullptr) {
				// equal element found
				if (cursor->data == data) {
					return cursor;
				}

				// moving ...
				else if (data > cursor->data) {
					// if it the last rigth
					if (cursor->right == nullptr) {
						TreeNode<T>* newElement = new TreeNode<T>(data);
						cursor->right = newElement;
						return newElement->parent = cursor->right;
					}

					cursor = cursor->right;
				}
				else if (data < cursor->data) {
					// if it the last left
					if (cursor->left == nullptr) {
						TreeNode<T>* newElement = new TreeNode<T>(data);
						cursor->left = newElement;
						return newElement->parent = cursor->left;
					}

					cursor = cursor->left;
				}
			}
		}



		/// <summary>
		/// remove element by value
		/// </summary>
		/// <param name="data">value to delete</param>
		void remove(T data) {
			// if tree is empty
			if (this->root == nullptr)
				return;

			// find node to delete
			TreeNode<T>* found = this->search(data);

			// if the node doesn't contain any child
			if (found->left == nullptr && found->right == nullptr) {
				if (found->data > found->parent->data)
					found->parent->right = nullptr;
				else
					found->parent->left = nullptr;

				delete found;
			}

			// if the node contains one child
			else if (found->left == nullptr || found->right == nullptr) {
				// found item is left
				if (found->parent->data > found->data) {

					found->parent->left = found->left != nullptr
						? found->left	// if left child is not empty
						: found->right;	// if right child is not empty
				}

				// found item is right
				else if (found->parent->data > found->data) {

					found->parent->right = found->left != nullptr
						? found->left	// if left child is not empty
						: found->right;	// if right child is not empty
				}
				delete found;
			}

			// if the node contains left and rigth
			else if (found->left != nullptr && found->right != nullptr) {
				// find right's min element for replace
				TreeNode<T>* toReplace = this->min(found->right);

				// replace values
				swap(found->data, toReplace->data);

				// delete node which was replaced with recursion calling
				remove(toReplace->data);
			}
		}



		/// <summary>
		/// print all nodes from min to max
		/// </summary>
		/// <param name="head">root item for print</param>
		void print(TreeNode<T>* head) {
			if (head != nullptr) {
				// recursive left node moving ...
				print(head->left);

				std::cout << head->data << std::endl;

				// recursive rigth branch moving ...
				print(head->right);
			}
		}



		/// <summary>
		/// get min element
		/// </summary>
		/// <param name="head">root item for search</param>
		/// <throws>
		/// code value: -1
		/// if head is null
		/// <throws>
		/// <returns>min value in tree</returns>
		T min(TreeNode<T>* head) {
			if (head == nullptr)
				throw -1;

			// moving to the leftest node ...
			TreeNode<T>* cursor = head;

			while (cursor->left != nullptr)
				cursor = cursor->left;

			return cursor->data;
		} 



		/// <summary>
		/// get max element
		/// </summary>
		/// <param name="head">root item for search</param>
		/// <throws>
		/// code value: -1
		/// if head is null
		/// <throws>
		/// <returns>max value in tree</returns>
		T max(TreeNode<T>* head) {
			if (head == nullptr)
				throw - 1;

			// moving to the leftest node ...
			TreeNode<T>* cursor = head;

			while (cursor->right != nullptr)
				cursor = cursor->right;

			return cursor->data;
		}
	};

}