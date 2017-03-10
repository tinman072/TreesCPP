#pragma once

#include <string>
#include <iostream>
#include <stdlib.h>

#include "TreeNode.h"

using namespace std;

struct Tree
{

private:
	TreeNode *root = NULL;
	//TreeNode* findSuccessor(struct TreeNode *r);

	
public:
	TreeNode* getRoot();
	
	void insertNode(string dataItem);
	void deleteNode(string dataItem);
	//TreeNode* deleteNode(struct TreeNode *r, string key);

	string findMin(struct TreeNode *r);
	string findMax(struct TreeNode *r);
	TreeNode* searchTree(string key, struct TreeNode *r);

	void mirror(struct TreeNode *r);

	void inFixPrint(struct TreeNode *r);
	void preFixPrint(struct TreeNode *r);
	void postFixPrint(struct TreeNode *r);

	int treeHeight(struct TreeNode *r);
	int treeSize(struct TreeNode *r);

	


};