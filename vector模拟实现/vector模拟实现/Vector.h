#pragma once

#include<iostream>
using namespace std;

#include<assert.h>

namespace vec
{
	template <class T>
	class Vector
	{
	public:
		
		///////////////////////////////////////////////////////////////////////
		//����������

		//ȫȱʡ���캯��
		Vector()
			:start(nullptr), finish(nullptr), end_of_storage(nullptr){ }

		//n��ֵΪdata �Ĺ���
		Vector(int n, const T& data = T()){ //���ڶ�������û����dataȡĬ��ֵ
			start = new T[n]; //����n��T���͵Ŀռ䣬����start

			for (int i = 0; i < n; i++){
				start[i] = data; //��data���n��Ԫ��
			}
			finish = start + n;
			end_of_storage = finish;
		}
		//����
		/*Vector(size_t n, const T& data = T()){
			reserv(n);
			while (n--)
				push_back(data);
		}*/


		//���䷽ʽ�Ĺ���
		template<class Iterator> //���ֱ����iterator������������ô[frist,last)ֻ����vector�ĵ�������ֻ��ȡvector������
		Vector(Iterator frist, Iterator last) //��������������������ͨ�������frist/last������������Ӧ���룬frist/last�������������͵ĵ�����
		{
			size_t size = last - frist;
			start = new T[size];

			finish = start;
			while (frist != last){
				*finish++ = *frist++;
			}

			end_of_storage = finish;
		}

		//��������
		Vector(const Vector<T>& v){
			start = new T[v.size()];
			finish = start;

			for (size_t n = 0; n < v.size(); n++){
				*finish++ = v[n];
			}
			//����д��
			//auto it = v.begin();
			//while (it != v.end())
			//	*finish++ = *it++;

			end_of_storage = finish;
		}

		//��ֵ���������
		Vector<T>& operator=(const Vector<T>& v);

		//��������
		~Vector(){
			if (start){
				delete[] start;
			}
			start = finish = end_of_storage = nullptr;
		}

		///////////////////////////////////////////////////////////////////////
		//������
		typedef T* iterator;  //vector�µĵ���������ԭ��ָ��
		typedef const T* const_iterator;

		iterator begin(){ return start; }
		const_iterator begin()const { return start; } //const���Ͷ������

		iterator end(){ return finish; }
		const_iterator end()const { return finish; }


		///////////////////////////////////////////////////////////////////////
		//������ز���

		size_t size()const{ 
			return finish - start; //��Ϊvactor�ײ�ʹ��˳�����һ�������Ŀռ�
		}

		size_t capacity()const{
				return end_of_storage - start;
		}

		//�п�
		bool empty()const {
			return start == finish;
		}

		//����
		iterator reserve(int n){
			if (n > capacity()){
				size_t s = size();
				iterator newStart = new T[n];
				delete[] start;

				start = newStart;
				finish = start + s;
				end_of_storage = start + n;
			}
			return start;
		}

		//resize
		iterator resize(size_t n, const T& data = T()){
			if (n >size()){
				if (n > capacity()){ //��n>capacity,����
					reserve(n);
				}

				while (n--){
					*finish++ = data;
				}
			}
			else(n < size()){
				finish = start + n;
			}
			return start;
		}


		///////////////////////////////////////////////////////////////////////
		//access ���ʲ���
		T& operator[](size_t index){
			assert(index < size());
			return start[index];  // return *(start + index);
		}

		const T& operator[](size_t index)const{
			assert(index < size());
			return start[index]; // return *(start + index);
		}

		iterator find(T& data){
			iterator it = start;
			while (it != finish){
				if (*it = data)
					return it;
				++it;
			}
			return finish;
		}

		T& front()const { return *start; }
		T& back()const { return *(finish - 1); }


		///////////////////////////////////////////////////////////////////////
		//modify �޸Ĳ���
		void push_back(const T& data){ insert(end(), data); }
		void pop_back(){ erase(finish-1); }

		void swap( Vector<T>& v ){
			swap(start, v.begin());
			swap(finish, v.end());
			swap(end_of_storage, v.end_of_storage);
		}

		//posλ�ò���
		iterator insert(iterator pos, const T& data){
			if (pos<start || pos>finish){ //posλ�ò��Ϸ�
				return start;
			}

			if (finish == end_of_storage){
				reserve((capacity()+1) * 2);//����ֱ��д��capacity*2 ,������vectorֱ�Ӳ��룬���޷�����
			}
			iterator it = finish;
			while (it != pos)
				*it = *(--it);
			*it = data;
			finish++;

			return start;
		}

		//posλ��ɾ��,���ر�ɾ��Ԫ�ص���һ��λ��
		iterator erase(iterator pos){
			if (pos<start || pos>=finish){ //posλ�ò��Ϸ�
				return finish;
			}
			auto cur = pos;
			while (cur + 1 != finish){
				*cur++ = *cur + 1;
			}
			finish--;
			return pos;
		}

		//���
		void clear(){
			finish = start;
		}


	private:
		iterator start; //�ռ���ʼλ��
		iterator finish; //���һ��Ԫ�ص���һ��
		iterator end_of_storage;  //�ռ�ĩβ


	};
}