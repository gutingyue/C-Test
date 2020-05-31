#pragma once

#include <iostream>
using namespace std;

namespace lis{
/////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Node
	template<class T>
	struct ListNode{
	public:
		ListNode(const T& val= T())
			:_prev(nullptr)
			,_next(nullptr)
			,_val(val)
		{}

		ListNode<T>* _prev;
		ListNode<T>* _next;
		T _val;

	};




//////////////////////////////////////////////////////////////////////////////////////////////////////////
	//iterator
	template<class T>
	class ListIterator{
	public:
		ListIterator(ListNode<T>* pNode = nullptr)
			:_pNode(pNode)
		{}

		//////////////////////////////////////////////
		//迭代器相关操作
		T& operator*(){
			return _pNode->_val; // 返回节点中val的值
		}

		T* operator->(){
			return &(operator*()); //->返回it对象中_pNode指针,指向节点中val的地址
		}
		
		//前置++
		ListIterator& operator++(){
			_pNode = _pNode->_next;
			return _pNode;
		}

		//后置++
		ListIterator operator++(int){
			ListIterator temp = _pNode;
			_pNode = _pNode->_next;
			return temp;
		}

		//前置--
		ListIterator& operator--(){
			_pNode = _pNode->_prev;
			return *this;
		}

		//后置--
		ListIterator operator--(int){
			ListIterator temp = _pNode;
			_pNode = _pNode->_prev;
			return temp;
		}

		bool operator==(const ListIterator& it){
			return _pNode == it._pNode;
		}

		bool operator!=(const ListIterator& it){
			return _pNode != it._pNode;
		}

	
		ListNode<T>* _pNode; //ListIterator对象中包含一个指向链表节点的指针
	};




//////////////////////////////////////////////////////////////////////////////////////////////////////////
	//List
	template<class T>
	class List{
	public:
		typedef ListNode<T> Node;
		typedef ListIterator<T> iterator;
	public:
		////////////////////////////////////////////////////////////////////
		//构造函数
		List(){
			CreateHead();
		}
		
		List(size_t n,const T& val = T()){
			CreateHead();
			while (n-- > 0){
				push_back(val);
			}
		}

		//区间构造
		template<class Itorate>
		List(Itorate frist, Itorate last){
			CreateHead();
			while (frist != last){
				push_back(*frist++);
			}
		}

		//拷贝构造
		List( List<T>& L){ //const List<T>& L 需要传入const类型的迭代器
			CreateHead();
			auto it = L.begin();
			while (it != L.end()){
				push_back(*it++);
			}

		}

		//赋值运算符重载
		List<T>& operator=(const List<T>& L);

		//析构
		~List(){
			//删除有效节点
			erase(begin(), end());

			//删除头节点
			delete head;
			head = nullptr;
		}

		////////////////////////////////////////////////////////////////////
		//迭代器
		iterator begin(){
			return iterator(head->_next);
		}
		iterator end(){
			return iterator(head); //此处根据head生成匿名对象，并返回
		}

		////////////////////////////////////////////////////////////////////
		//容量相关操作
		size_t size()const{
			size_t count = 0;
			for (auto it = begin(); it != end(); it++)
				const++;

			return count;
		}

		bool empty()const{
			return head == head->_next;
		}

		List& resize(size_t newsize, const T& val = T()){
			size_t oldsize = size();
			if (oldsize > newsize)
			{
				size_t i = oldsize - newsize;
				while (i-- > 0){
					pop_back();
				}
			}
			else
			{
				for (; oldsize < newsize; oldsize++)
					push_back(val);
			}
			return *this;
		}

		////////////////////////////////////////////////////////////////////
		//访问操作
		T& front() { return head->_next; }
		T& back() { return  head->_prev; }

		////////////////////////////////////////////////////////////////////
		//修改操作
		void push_back(const T& val = T()){
			insert(end(), val);
		}

		void pop_back(){
			erase(--end());
		}

		void push_front(const T& val = T()){
			insert(begin(), val);
		}

		void pop_front(){
			erase(begin());
		}

		//任意位置插入
		iterator insert(iterator pos,const T& val){
			ListNode<T>* pNewNode = new Node(val);

			//拿到指向节点的指针
			ListNode<T>* pNode = pos._pNode;

			//先连接，再断开
			pNewNode->_next = pNode;
			pNewNode->_prev = pNode->_prev;
			pNewNode->_prev->_next = pNewNode;
			pNode->_prev = pNewNode;

			return iterator(pNewNode);
		}

		//任意位置删除
		iterator erase(iterator pos){
			ListNode<T>* pNode = pos._pNode;
			ListNode<T>* pRet = pNode->_next;//保存pos位置的下一个节点位置，作为返回值

			pNode->_prev->_next = pNode->_next;
			pNode->_next->_prev = pNode->_prev;

			delete pNode;

			return iterator(pRet);
		}

		iterator erase(iterator frist, iterator last){
			while (frist != last){
				frist = erase(frist);
			}
			return frist;
		}

		void clear();

		void swap(List<T>& L){
			std::swap(this->head, L.head);
		}

	private:
		//创建头节点(仅包含头节点的空链表）
		Node* CreateHead(){
			head = new Node;
			head->_next = head;
			head->_prev = head;

			return head;
		}

	private:
		Node* head;
	};


}