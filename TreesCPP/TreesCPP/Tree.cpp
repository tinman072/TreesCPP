#include <string>
#include <iostream>
#include <stdlib.h>

#include "stdafx.h"
#include "Tree.h"

TreeNode* Tree::getRoot()
{
	return root;
}

void Tree::insertNode(string dataItem)
{
	TreeNode *node = new TreeNode();
	node->data = dataItem;
	node->left = NULL;
	node->right = NULL;

	if (root == NULL)
	{
		root = node;
		return;
	}

	int turnLeft = 0;

	TreeNode *current = root;
	TreeNode *previous = NULL;

	while (current != NULL)
	{
		previous = current;

		if (dataItem < current->data)
		{
			turnLeft = 1;
			current = current->left;
		}
		else
		{
			turnLeft = 0;
			current = current->right;
		}
	}

	if (turnLeft == 1)
		previous->left = node;
	else
		previous->right = node;
}

void Tree::deleteNode(string dataItem)
{
	TreeNode *parent = root;
	TreeNode *current = root;

	bool isLeftChild = false;

	if (root == NULL)
	{
		cout << "There are no nodes to delete" << endl;
		return;
	}

	while (current->data != dataItem)
	{
		parent = current;

		if (dataItem < current->data)
		{
			isLeftChild = true;
			current = current->left;
		}
		else
		{
			isLeftChild = false;
			current = current->right;
		}

		if (current == NULL)
		{
			cout << "The data to be deleted was not found" << endl;
			return;
		}
	}

	//If the node to be delete is a leaf
	if (current->left == NULL && current->right == NULL)
	{
		if (current == root)
			root = NULL;
		else if (isLeftChild)
			parent->left = NULL;
		else
			parent->right = NULL;

		return;
	}

		
	//Node to be deleted has one child but is root
	if (current == root && current->right == NULL)
	{
		root = root->left;
		current->left = NULL;
		return;
	}

	if (current == root && current->left == NULL)
	{
		root = root->right;
		current->right = NULL;
		return;
	}
	//*********************************************


	//Node to be deleted is not root but has one child
	if (current->right == NULL && isLeftChild)
	{
		parent->left = current->left;
		current->left = NULL;
		return;
	}
	else if (current->left == NULL && isLeftChild)
	{
		parent->left = current->right;
		current->right = NULL;
		return;
	}
	else if (current->right == NULL && !isLeftChild)
	{
		parent->right = current->left;
		current->left = NULL;
		return;
	}
	else if(current->left == NULL && !isLeftChild)
	{
		parent->right = current->right;
		current->right = NULL;
		return;
	}
	//************************************************

	//If the node to be deleted has two children
	if (!(current->left == NULL) && !(current->right == NULL))
	{
		string sdata = findMin(current->right);
		current->data = sdata;

		if (current->right->left == NULL && current->right->right == NULL)
		{
			current->right = NULL;
			return;
		}

		TreeNode* temproot = root;
		root = current->right;
		deleteNode(sdata);

		if (current == temproot)
		{
			temproot->right = root;
			root = temproot;
			return;
		}
		else
		{
			root = temproot;
			return;
		}
	}


	//To be Continued.....

}

//TreeNode* Tree::deleteNode(struct TreeNode *root, string key)
//{
//	// base case
//	if (root == NULL) return root;
//
//	// If the key to be deleted is smaller than the root's key,
//	// then it lies in left subtree
//	if (key < root->data)
//		root->left = deleteNode(root->left, key);
//
//	// If the key to be deleted is greater than the root's key,
//	// then it lies in right subtree
//	else if (key > root->data)
//		root->right = deleteNode(root->right, key);
//
//	// if key is same as root's key, then This is the node
//	// to be deleted
//	else
//	{
//		// node with only one child or no child
//		if (root->left == NULL)
//		{
//			struct TreeNode *temp = root->right;
//			delete(root);
//			return temp;
//		}
//		else if (root->right == NULL)
//		{
//			struct TreeNode *temp = root->left;
//			delete(root);
//			return temp;
//		}
//
//		// node with two children: Get the inorder successor (smallest
//		// in the right subtree)
//		struct TreeNode* temp = findSuccessor(root->right);
//
//		// Copy the inorder successor's content to this node
//		root->data = temp->data;
//
//		// Delete the inorder successor
//		root->right = deleteNode(root->right, temp->data);
//	}
//	return root;
//}

void Tree::inFixPrint(struct TreeNode *r)
{
	if (r == NULL)
		return;

	inFixPrint(r->left);
	cout << r->data << " ";
	inFixPrint(r->right);
}

void Tree::postFixPrint(struct TreeNode *r)
{
	if (r == NULL)
		return;

	postFixPrint(r->left);
	postFixPrint(r->right);
	cout << r->data << " ";

}

void Tree::preFixPrint(struct TreeNode *r)
{
	if (r == NULL)
		return;

	cout << r->data << " ";
	preFixPrint(r->left);
	preFixPrint(r->right);

}

int Tree::treeHeight(struct TreeNode *r)
{
	if (r == NULL)
		return 0;

	int leftHeight = treeHeight(r->left);
	int rightHeigt = treeHeight(r->right);

	if (leftHeight > rightHeigt)
		return leftHeight + 1;
	else
		return rightHeigt + 1;

}

int Tree::treeSize(struct TreeNode *r)
{
	if (r == NULL)
		return 0;

	int leftSize = treeSize(r->left);
	int rightSize = treeSize(r->right);

	return leftSize + rightSize + 1;
}

void Tree::mirror(struct TreeNode *r)
{
	if (r == NULL)
		return;

	mirror(r->left);
	mirror(r->right);

	TreeNode *temp;

	temp = r->left;
	r->left = r->right;
	r->right = temp;
}

string Tree::findMin(struct TreeNode *r)
{
	if (r->left == NULL)
		return r->data;
	else
		return findMin(r->left);
}

string Tree::findMax(struct TreeNode *r)
{
	if (r->right == NULL)
		return r->data;
	else
		return findMax(r->right);
}

//TreeNode* Tree::findSuccessor(struct TreeNode *r)
//{
//	if (r->left == NULL)
//		return r;
//	else
//		return findSuccessor(r->left);
//}

TreeNode* Tree::searchTree(string key, struct TreeNode *r)
{
	if (r == NULL)
		return NULL;

	else
	{
		if (r->data == key)
			return r;
		else
		{
			if (key < r->data)
				return searchTree(key, r->left);
			else
				return searchTree(key, r->right);
		}
	}
}