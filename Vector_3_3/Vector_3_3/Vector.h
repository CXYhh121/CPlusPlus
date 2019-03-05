#include <iostream>
#include <algorithm>
#include <assert.h>
#include <string>
using namespace std;

namespace CXY
{
	template <class T>
	class Vector
	{
	public:
		typedef T* iterator;//Vector迭代器的原生指针
		typedef const T* const_iterator;//const迭代器

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

		const_iterator cbegin() const
		{
			return _start;
		}
		const_iterator cend() const
		{
			return _finish;
		}
		
		//构造函数
		/*Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}*/
		Vector() = default;
		~Vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}


		//拷贝构造v2(v1)
		//Vector( Vector<T>& v)
		//{
		//	_start = new T[v.Capacity()];
		//	//memcpy(_start, v._start, sizeof(T)*v.Size());
		//	for (size_t i = 0; i < Size(); ++i)
		//	{
		//		_start[i] = v._start[i];
		//	}
		//	_finish = _start + v.Size();
		//	_endofstorage = _start + v.Capacity();
		//}

		//拷贝构造
		Vector(const Vector<int>& v)
			:_start(nullptr)
			,_finish(nullptr)
			, _endofstorage(nullptr)
		{
			Reserve(v.Capacity());

			iterator it = begin();
			const_iterator vit = v.cbegin();

			while (vit != v.cend())
			{
				*it++ = *vit++;
			}
			_finish = _start + v.Size();
			_endofstorage = _start + v.Capacity();

		}

		//赋值运算符= v1 = v2 = v3
		/*Vector<T>& operator=(const Vector<T>& v)
		{
			if (this != &v)
			{
				delete[] _start;
				_start = new T[sizeof(T)*v.Size()];
				memcpy(_start, v._start, sizeof(T)*v.Size());
				_finish = _start + v.Size();
				_endofstorage = _start + v.Capacity();
			}
			return *this;
		}*/

		//赋值运算符copy = v2;
		Vector<T>& operator=(Vector<T> v)
		{
			this->Swap(v);
			return *this;
		}

		void Swap(Vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}
		
		//往Vector中插入数据
		void PushBack(const T& x)
		{
			/*if (_finish == _endofstorage)
			{
				size_t newcapacity = Capacity() == 0 ? 2 : Capacity() * 2;
				Reserve(newcapacity);
			}

			*_finish = x;
			++_finish;*/
			Insert(end(), x);
		}

		void PopBack()
		{
			assert(Size() > 0);
			--_finish;
			//Erase(--end());
		}

		//在Vector中任意位置前插入一个数
		void Insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			size_t posindex = pos - _start;
			if (_finish == _endofstorage)
			{
				size_t newcapacity = Capacity() == 0 ? 2 : Capacity() * 2;
				Reserve(newcapacity);
				pos = _start + posindex;
			}

			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				--end;
			}

			*pos = x;
			++_finish;
		}
		//删除Vector任意位置中的数，并返回下一个位置
		//返回下一个位置是为了防止出现迭代器失效的问题
		iterator Erase(iterator pos)
		{
			iterator begin = pos;
			while (pos != _finish)
			{
				*pos = *(pos + 1);
					++pos;
			}
			--_finish;
			return begin;
		}

		//增容Capacity
		void Reserve(size_t n) 
		{
			if (n > Capacity())
			{
				size_t size = Size();
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, sizeof(T)*size);
					for (size_t i = 0; i < size; ++i)
					{
						tmp[i] = _start[i];
					}
				}
				_start = tmp;
				_finish = _start + size;
				_endofstorage = _start + n;
			}
		}

		//增加Size
		void Resize(size_t n, const T& value = T())
			//T()调用默认构造函数，给value赋缺省值
			//因为容器Vector内可以存放任意类型的数据，当类型将T替换时，就会调用对应类型的构造函数
			//C++中内置类型也有对应的构造函数(int() char())
		{
			//当n小于当前size时，将数据个数缩小到n
			if (n <= Size())
			{
				_finish = _start + n;
			}
			else
			{
				//当容量不够时增容
				if (n > Capacity())
					Reserve(n)

				while (_finish != _start + n)
				{
					*_finish = value;
					++_finish;
				}
			}
		}

		//访问Vector
		T& operator [](size_t pos)
		{
			assert(pos < Size());
			return _start[pos];
		}
		/*const T& operator[](size_t pos) const
		{
			assert(pos < Size());
			return _start[pos];
		}*/
		size_t Size() const
		{
			return _finish - _start;
		}
		size_t Capacity() const
		{
			return _endofstorage - _start;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;
			
	};

	void TestVector1()//测试构造函数，PushBack，PopBack，迭代器
	{
		Vector<int> v1;
		v1.PushBack(1);
		v1.PushBack(2);
		v1.PushBack(3);
		v1.PushBack(4);
		v1.PushBack(5);

		//Vector<int> v2(v1);

		v1.PopBack();

		for (size_t i = 0; i < v1.Size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		//Vector迭代器使用
		Vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		//范围for的使用
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		
	}

	void TestVector2()//测试拷贝构造，赋值运算符=，const迭代器
	{
		Vector<int> v2;
		v2.PushBack(1);
		v2.PushBack(2);
		v2.PushBack(3);
		v2.PushBack(4);
		v2.PushBack(5);
        
		//Vector<int> v3(v2);//调拷贝构造函数初始化v3
		
		//调赋值运算符=
		Vector<int> v3;
		 v3 = v2;

		 //调用const迭代器
		Vector<int>::const_iterator cit = v3.cbegin();
		while (cit != v3.cend())
		{
			cout << *cit << " ";
			++cit;
		}
		cout << endl;

	}

	void TestVector3()
	{
		Vector<int> v3;
		v3.PushBack(1);
		v3.PushBack(2);
		v3.PushBack(3);
		v3.PushBack(4);
		v3.PushBack(5);

		Vector<int>::iterator pos = find(v3.begin(), v3.end(), 3);

		for (size_t i = 0; i < v3.Size(); ++i)
		{
			cout << v3[i] << " ";
		}
		cout << endl;
		
		v3.Insert(pos, 30);//调用Insert
	   
		pos = find(v3.begin(), v3.end(), 4);
		Vector<int>::iterator ret = v3.Erase(pos);//调用Erase

		Vector<int>::const_iterator cit = v3.cbegin();
		while (cit != v3.cend())
		{
			cout << *cit << " ";
			++cit;
		}
		cout << endl;

		cout << "下一个位置的值：" << *ret << endl;

	}

	
}