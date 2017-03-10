// TreesCPP.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>

#include "Tree.h"

using namespace std;

int main()
{
	Tree t;
	t.insertNode("L");t.insertNode("E");t.insertNode("S");t.insertNode("B");t.insertNode("I");
	t.insertNode("A");t.insertNode("C");t.insertNode("H");t.insertNode("J");t.insertNode("P");
	t.insertNode("W");t.insertNode("N");t.insertNode("R");t.insertNode("T");t.insertNode("Z");

		
	//t.insertNode("f");
	//t.insertNode("a");
	//t.insertNode("h");
	//t.insertNode("e");
	//t.insertNode("b");
	//t.insertNode("c");
	//t.insertNode("d");
	//t.insertNode("i");

	t.inFixPrint(t.getRoot());
	cout << endl;

	t.deleteNode("E");
	//t.deleteNode("A");
	t.inFixPrint(t.getRoot());
	cout << endl;

    return 0;
}

