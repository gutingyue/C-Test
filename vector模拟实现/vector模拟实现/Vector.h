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
		//构造与析构

		//全缺省构造函数
		Vector()
			:start(nullptr), finish(nullptr), end_of_storage(nullptr){ }

		//n个值为data 的构造
		Vector(int n, const T& data = T()){ //若第二个参数没给，data取默认值
			start = new T[n]; //申请n个T类型的空间，交给start

			for (int i = 0; i < n; i++){
				start[i] = data; //用data填充n个元素
			}
			finish = start + n;
			end_of_storage = finish;
		}
		//简洁版
		/*Vector(size_t n, const T& data = T()){
			reserv(n);
			while (n--)
				push_back(data);
		}*/


		//区间方式的构造
		template<class Iterator> //如果直接用iterator做迭代器，那么[frist,last)只能是vector的迭代器，只能取vector的区间
		Vector(Iterator frist, Iterator last) //重新声明迭代器，可以通过传入的frist/last的类型生成相应代码，frist/last可以是任意类型的迭代器
		{
			size_t size = last - frist;
			start = new T[size];

			finish = start;
			while (frist != last){
				*finish++ = *frist++;
			}

			end_of_storage = finish;
		}

		//拷贝构造
		Vector(const Vector<T>& v){
			start = new T[v.size()];
			finish = start;

			for (size_t n = 0; n < v.size(); n++){
				*finish++ = v[n];
			}
			//或者写成
			//auto it = v.begin();
			//while (it != v.end())
			//	*finish++ = *it++;

			end_of_storage = finish;
		}

		//赋值运算符重载
		Vector<T>& operator=(const Vector<T>& v);

		//析构函数
		~Vector(){
			if (start){
				delete[] start;
			}
			start = finish = end_of_storage = nullptr;
		}

		///////////////////////////////////////////////////////////////////////
		//迭代器
		typedef T* iterator;  //vector下的迭代器就是原生指针
		typedef const T* const_iterator;

		iterator begin(){ return start; }
		const_iterator begin()const { return start; } //const类型对象调用

		iterator end(){ return finish; }
		const_iterator end()const { return finish; }


		///////////////////////////////////////////////////////////////////////
		//容量相关操作

		size_t size()const{ 
			return finish - start; //因为vactor底层使用顺序表，是一段连续的空间
		}

		size_t capacity()const{
				return end_of_storage - start;
		}

		//判空
		bool empty()const {
			return start == finish;
		}

		//扩容
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
				if (n > capacity()){ //若n>capacity,扩容
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
		//access 访问操作
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
		//modify 修改操作
		void push_back(const T& data){ insert(end(), data); }
		void pop_back(){ erase(finish-1); }

		void swap( Vector<T>& v ){
			swap(start, v.begin());
			swap(finish, v.end());
			swap(end_of_storage, v.end_of_storage);
		}

		//pos位置插入
		iterator insert(iterator pos, const T& data){
			if (pos<start || pos>finish){ //pos位置不合法
				return start;
			}

			if (finish == end_of_storage){
				reserve((capacity()+1) * 2);//不能直接写成capacity*2 ,若给空vector直接插入，就无法扩容
			}
			iterator it = finish;
			while (it != pos)
				*it = *(--it);
			*it = data;
			finish++;

			return start;
		}

		//pos位置删除,返回被删除元素的下一个位置
		iterator erase(iterator pos){
			if (pos<start || pos>=finish){ //pos位置不合法
				return finish;
			}
			auto cur = pos;
			while (cur + 1 != finish){
				*cur++ = *cur + 1;
			}
			finish--;
			return pos;
		}

		//清空
		void clear(){
			finish = start;
		}


	private:
		iterator start; //空间起始位置
		iterator finish; //最后一个元素的下一个
		iterator end_of_storage;  //空间末尾


	};
}