#include <iostream>
using namespace std;

enum color{ RED, BLACK }; //节点颜色

/////////////////////////////////////////////////////////
//红黑树节点
template <class T>
struct RBTreeNode
{
	RBTreeNode* _left;
	RBTreeNode* _right;
	RBTreeNode* _parent;
	color _color;
	int _data;

	RBTreeNode(const T& data=T(),color color=RED)
		; _left(nullptr), _right(nullptr), _parent(nullptr), _data(data), _color(color)
	{ }

};
/////////////////////////////////////////////////////////
//红黑树迭代器
template <class T>
struct RBTreeIterator{ 
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator Self;
	//迭代器具有指针类似操作
	T& operator*(){
		return _node->_data;
	}
	T* operator->(){
		return &(operator*());
	}

	//前置++
	Self& operator++(){
		Increment(); //取node的下一个节点
		return *this;
	}
	//后置++
	Self operator++(int){
		Self it = *this;
		Increment();
		return it;
	}

	//前置--
	Self& operator--(){
		Decremrnt(); //取node上一个节点
		return *this;
	}
	//后置--
	Self operator--(int){
		Self it(*this);
		Decrement();
		return it;
	}

	//迭代器比较
	bool operator!=(const Self& it){
		return _node != it->_node; //是否指向同一个节点
	}
	bool operator==(const Self& it){
		return _node == it->_node;
	}

	//取下一个节点
	void Increment(){ 
		//下一个节点为比该节点大的最小节点
		//右子树存在------是其右子树的最左下方节点
		if (_node->right){
			while (_node->_left){
				_node = _node->_left;
			}
		}
		//右子树不存在
		Node* parent = _node->_parent;
	}

	//取上一个节点
	void Decrement(){

	}

private:
	Node* _node;
};

template <class T>
class RBTree{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T> iterator;

	iterator begin(){
		//最小节点
	}

	iterator end(){

	}
private:
	Node* head;
};