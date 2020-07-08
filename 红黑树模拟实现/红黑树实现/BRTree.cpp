#include <iostream>
using namespace std;

enum color{ RED, BLACK }; //½ÚµãÑÕÉ«

struct RBTreeNode
{
	RBTreeNode* _left;
	RBTreeNode* _right;
	RBTreeNode* _parent;
	color _color;
	int _data;

	RBTreeNode(int data,color color=RED)
		; _left(nullptr), _right(nullptr), _parent(nullptr), _data(data), _color(color)
	{ }

};
