#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP

template<class T>
class LinearList{
	private:
		unsigned int capacity_;
		T *buffer_;
        unsigned int size_;
	public:
	LinearList();
	LinearList(const int& MaxListSize);
	LinearList(const int& isize, const T& ival);
	~LinearList();
	void push_back(const T& item);
	bool empty();
	unsigned int size();
	unsigned int capacity();
	void fill(const T& item);
	void resize(const int& n);
	int find(T& x);
	void print();
	void erase(const T&  item);
	void erase_pos(const int&  k);
	void  insert(const int& k, T& x);
	inline T& at(const int& k);
	inline T& operator[](const int& i);		

	};
		template<class T>
		LinearList<T>::LinearList()
		{
				buffer_=new T[1];
				size_=0;
				capacity_=1e6+1;
		}

		template<class T>
		LinearList<T>::LinearList(const int& MaxListSize)
		{
				buffer_=new T[MaxListSize];
				size_=0;
				capacity_=1e6+1;
		}
		template<class T>
		LinearList<T>::LinearList(const int& isize, const T& ival)
		{
				buffer_=new T[isize];
				size_=0;
				capacity_=1e6+1;
				fill(ival);
		}

		template<class T>
		LinearList<T>::~LinearList()
		{
			//delete buffer_;
		}

		template<class T>
		inline T& LinearList<T>::at(const int& k)
		{
			return buffer_[k];	
		}    

		template<class T>
		inline T& LinearList<T>::operator[](const int& i)
		{
			return buffer_[i];
		} 
		
		template<class T>
		void LinearList<T>::push_back(const T& item)
		{
			insert(size_,item);
		}   

		template<class T>
		bool LinearList<T>::empty()
		{
			if(size_==0) return true;
			else return false;
		}

		template<class T>
		unsigned int LinearList<T>::size()
		{
			return size_;
		}

		template<class T>
		unsigned int LinearList<T>::capacity()
		{
			return capacity_;
		}

		template<class T>
		void LinearList<T>::fill(const T& item)
		{
			for(int i=0;i<size_;i++)
			{
				buffer_[i]=item;
			}
		}

		 template<class T>
		 void LinearList<T>::resize(const int& n)
		 {

			if(n > capacity_)
			{
				cout<<"n > capacity_\n";
				return ;
			}
			if(size_ == 0)
			{
				buffer_ = new T[n];
			}
			else
			{
				T *temp = new T[n];
				for(int i=0;i<size_;i++)
					temp[i] = buffer_[i];
				delete[] buffer_;
				buffer_ = temp;
			}
			size_ = n;
		 }

		 template<class T>
		int LinearList<T>::find(T& x)
		{
			
			for(int i=0;i<size_;i++)
			{
				if(buffer_[i]==x) {return i+1;}
			}
			return 0;
		}

		template<class T>
		void LinearList<T>::print()
		{
			cout<<endl;
			for(int i=0;i<size_;i++)
			{
				cout<<buffer_[i]<<endl;
			}

		}

		template<class T>
		void LinearList<T>::erase(const T&  item)
		{

				for(int i=0;i<size_;i++)
					{
					if(buffer_[i]==item) {erase_pos(i+1);}
					}
				
		}
		template<class T>
		void LinearList<T>::erase_pos(const int&  k)
		{

				for(int i=k;i<size_;i++)
					{
					buffer_[i-1]=buffer_[i];
					}
				size_--;
		}

		template<class T>
		void LinearList<T>::insert(const int& k, T& x)
		{
			if(size_==0) 
			{
			*buffer_=x;size_=1;
			return;
			}
			
			else 
				{   	
					for(int i=size_-1;i>=k;i--)
					{

						buffer_[i+1]=buffer_[i];
					}
					buffer_[k]=x;

					size_++;
					return;
				}
		}


#endif
