#include <assert.h>
#include <iostream>
template
	<typename T>
class Vector
{
private:
	int sz; // the number of elements in this Vector
	T * buf; // the base of the array of Ts you must allocate
public:
	Vector(int n) // Vector v1(10); -- create a 10 element Vector
		: sz(n),buf(new T[n])
	{
	}
	Vector(std::initializer_list<T> L) // Vector v1{T1, T2, T3};
		: buf(new T[sz]),sz(L.size())
	{
		int i = 0;
		for(auto it = std::begin(L); it != std::end(L); ++it)
		{
			buf[i] = *it;
			++i;
		}
	}
	~Vector() // destructor called automatically when a Vector dies
	{
		delete [] buf;
	}
	Vector(const Vector & v) // Vector v2(v1);
		: buf(new T[sz]), sz(v.sz)
	{
		for(int i = 0; i < sz; ++i)
		{
			buf[i] = v.buf[i];
		}
	}
	int size()  // v1.size() returns 10 for v1 example above
	{
		return sz;
	}
	T & operator [](const int i) // T x = V[i];
	{
		if(i < 0 || i > (sz-1))
		{
			std::cerr << "Index is out of bounds in operator []. Returning buf[0]." << std::endl;
			return buf[0];
		} 
		return buf[i];
	}
	T operator * (const Vector & v) const // T x = V1 * V2
	{	
		int size = sz;
		T total = 0;
		if(sz != v.sz)
		{
			std::cerr << "v.sz is not the same size as sz." << std::endl;
			if(sz > v.sz)
				size = v.sz;
			else
				size = sz;
		}
		for(int i = 0; i < size; ++i)
		{
			total += (buf[i] * v.buf[i]);
		}
		return total;
	}
	Vector operator + (const Vector & v) const // V1 = V1 + V2
	{
		Vector v1(sz);
		int size = sz;
		if(sz != v.sz)
		{
			std::cerr << "v.sz is not the same size as sz." << std::endl;
			if(sz > v.sz)
				size = v.sz;
		}
		for(int i = 0; i < size; ++i)
		{
			v1.buf[i] = buf[i] + v.buf[i];
		}
		return v1;
	}
	const Vector & operator = (const Vector & v) //V1 = V2
	{
		delete [] buf;
		sz = v.sz;
		buf = new T[sz];
		for(int i = 0; i < sz; ++i)
		{
			buf[i] = v.buf[i];
		}
	}
	bool operator == (const Vector & v) const // if (V1 == V2)...
	{
		if(sz != v.sz)
			return false;
		else
		{
			for(int i = 0; i < sz; ++i)
			{
				if(buf[i] != v.buf[i])
					return false;
			}
		}
		return true;
	}
	bool operator != (const Vector & v) const // if (V1 != V2)...
	{
		if(sz != v.sz)
			return true;
		else
		{
			for(int i = 0; i < sz; ++i)
			{
				if(buf[i] != v.buf[i])
					return true;
			}
		}
		return false;
	}
	friend Vector operator * (const int n, const Vector & v) // V1 = 20 * V2; -- each element of V1 will be element of V2 * 20
	{
		Vector<T> v1(v.sz);
		for(int i = 0; i < v1.sz; ++i)
		{
			v1.buf[i] = (v.buf[i] * n);
		}
		return v1;
	}
	friend Vector operator + (const int n, const Vector & v) // V1 = 20 + V2; -- each element of V1 will be element of V2 + 20
	{
		Vector<T> v1(v.sz);
		for(int i = 0; i < v1.sz; ++i)
		{
			v1.buf[i] = (v.buf[i] + n);
		}
		return v1;
	}
	friend std::ostream& operator << (std::ostream & o, const Vector & v) // cout << V2; == prints the vector in format(v0,v1,v2,...,vn)
	{
		o << "{";
		for(int i = 0; i < v.sz; ++i)
		{
			if(i != (v.sz - 1))
				o << v.buf[i] << ", ";
			else
				o << v.buf[i] << "}";
		}
		return o;
	}
};