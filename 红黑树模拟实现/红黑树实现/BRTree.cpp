#include <iostream>
using namespace std;

enum color{ RED, BLACK }; //�ڵ���ɫ

/////////////////////////////////////////////////////////
//������ڵ�
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
//�����������
template <class T>
struct RBTreeIterator{ 
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator Self;
	//����������ָ�����Ʋ���
	T& operator*(){
		return _node->_data;
	}
	T* operator->(){
		return &(operator*());
	}

	//ǰ��++
	Self& operator++(){
		Increment(); //ȡnode����һ���ڵ�
		return *this;
	}
	//����++
	Self operator++(int){
		Self it = *this;
		Increment();
		return it;
	}

	//ǰ��--
	Self& operator--(){
		Decremrnt(); //ȡnode��һ���ڵ�
		return *this;
	}
	//����--
	Self operator--(int){
		Self it(*this);
		Decrement();
		return it;
	}

	//�������Ƚ�
	bool operator!=(const Self& it){
		return _node != it->_node; //�Ƿ�ָ��ͬһ���ڵ�
	}
	bool operator==(const Self& it){
		return _node == it->_node;
	}

	//ȡ��һ���ڵ�
	void Increment(){ 
		//��һ���ڵ�Ϊ�ȸýڵ�����С�ڵ�
		//����������------�����������������·��ڵ�
		if (_node->right){
			while (_node->_left){
				_node = _node->_left;
			}
		}
		//������������
		Node* parent = _node->_parent;
	}

	//ȡ��һ���ڵ�
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
		//��С�ڵ�
	}

	iterator end(){

	}
private:
	Node* head;
};