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
		//��������ز���
		T& operator*(){
			return _pNode->_val; // ���ؽڵ���val��ֵ
		}

		T* operator->(){
			return &(operator*()); //->����it������_pNodeָ��,ָ��ڵ���val�ĵ�ַ
		}
		
		//ǰ��++
		ListIterator& operator++(){
			_pNode = _pNode->_next;
			return _pNode;
		}

		//����++
		ListIterator operator++(int){
			ListIterator temp = _pNode;
			_pNode = _pNode->_next;
			return temp;
		}

		//ǰ��--
		ListIterator& operator--(){
			_pNode = _pNode->_prev;
			return *this;
		}

		//����--
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

	
		ListNode<T>* _pNode; //ListIterator�����а���һ��ָ������ڵ��ָ��
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
		//���캯��
		List(){
			CreateHead();
		}
		
		List(size_t n,const T& val = T()){
			CreateHead();
			while (n-- > 0){
				push_back(val);
			}
		}

		//���乹��
		template<class Itorate>
		List(Itorate frist, Itorate last){
			CreateHead();
			while (frist != last){
				push_back(*frist++);
			}
		}

		//��������
		List( List<T>& L){ //const List<T>& L ��Ҫ����const���͵ĵ�����
			CreateHead();
			auto it = L.begin();
			while (it != L.end()){
				push_back(*it++);
			}

		}

		//��ֵ���������
		List<T>& operator=(const List<T>& L);

		//����
		~List(){
			//ɾ����Ч�ڵ�
			erase(begin(), end());

			//ɾ��ͷ�ڵ�
			delete head;
			head = nullptr;
		}

		////////////////////////////////////////////////////////////////////
		//������
		iterator begin(){
			return iterator(head->_next);
		}
		iterator end(){
			return iterator(head); //�˴�����head�����������󣬲�����
		}

		////////////////////////////////////////////////////////////////////
		//������ز���
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
		//���ʲ���
		T& front() { return head->_next; }
		T& back() { return  head->_prev; }

		////////////////////////////////////////////////////////////////////
		//�޸Ĳ���
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

		//����λ�ò���
		iterator insert(iterator pos,const T& val){
			ListNode<T>* pNewNode = new Node(val);

			//�õ�ָ��ڵ��ָ��
			ListNode<T>* pNode = pos._pNode;

			//�����ӣ��ٶϿ�
			pNewNode->_next = pNode;
			pNewNode->_prev = pNode->_prev;
			pNewNode->_prev->_next = pNewNode;
			pNode->_prev = pNewNode;

			return iterator(pNewNode);
		}

		//����λ��ɾ��
		iterator erase(iterator pos){
			ListNode<T>* pNode = pos._pNode;
			ListNode<T>* pRet = pNode->_next;//����posλ�õ���һ���ڵ�λ�ã���Ϊ����ֵ

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
		//����ͷ�ڵ�(������ͷ�ڵ�Ŀ�����
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