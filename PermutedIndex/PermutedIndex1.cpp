#include"Header.h"

vector<string>split(const string& s)                      //splits the sentence and stores in a vector
{
	vector<string> ret;
	string::size_type i = 0, j = 0;
	while (i != s.size())
	{
		while (i != s.size() && isspace(s[i]))
			i++;
		j = i;
		while (j != s.size() && !isspace(s[j]))
			j++;
		if (i != j)
		{
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}

	return ret;
}


string rotate(vector<string>& v)                                   //rotates the sentence about a specific word
{
	string str;
	for (vector<string>::size_type i = 0; i != v.size() - 1; i++)
	{
		vector<string>::size_type j = i + 1;
		{
			v[i] = v[i] + " " + v[j];
			v[j] = v[i].substr(0, v[i].find(" "));
			v[i] = v[i].erase(0, v[j].size() + 1);
		}
	}
	
	for (vector<string>::const_iterator k = v.begin(); k != v.end(); k++)
	{
		str = str + " " + *k;
	}
	return str;
}


bool compare(string& x, string& y)                   //compare which word come in dictionary
{
	return  (x < y);
}

vector<string>::size_type port(const vector<string>& ret, const vector<string>& v)      
{
	for (vector<string>::size_type i = 0; i != ret.size(); i++)
	{
		if (v[0] == ret[i])
		{
			return i;
			break;
		}


	}
}
bool dare(vector<string>::size_type& x, vector<string>::size_type& y)       
{
	return x < y;
}

string paint1(vector<string>& v)
{
	string str;
	
	for (vector<string>::const_iterator i = v.begin(); i != v.end(); i++)
		str += " " + *i;
	return str;
}

vector<string>::size_type cmp(vector<string>& v, vector<string>& v1)           //compare two sentences
{
	for (vector<string>::size_type i = 0; i != v.size() - 1; i++)
	{
		auto c = v[i].compare(v1[0]);
		if (c == 0)
			return i;
		else continue;
	}
}


vector<string> unrotate1(vector<string>& s, vector<string>& v)                  //unrotate
{
	vector<string>  s1;
	string str2;
	vector<string>::size_type t = cmp(v, s);
	for (vector<string>::size_type i = 0; i != v.size(); i++)
	{
		if (i < t)
			str2 += " " + v[i];
	}

	s1.push_back(str2);
	return s1;
}

vector<string> unrotate2(vector<string>& s, vector<string>& v)
{
	vector<string>  s2;
	string  str3;
	vector<string>::size_type t = cmp(v, s);
	for (vector<string>::size_type i = 0; i != v.size(); i++)
	{
		if (i >= t)
			str3 += " " + v[i];
	}

	s2.push_back(str3);
	return s2;
}

string nsplit(vector<string>& v)
{
	string str;
	for (vector<string>::const_iterator i = v.begin(); i != v.end(); i++)
		str += " " + *i;
	return str;
}






string::size_type long_str(vector<string>& v)
{
	string::size_type str = 0;
	for (vector<string>::size_type i = 0; i != v.size(); i++)
	{
		str = max(str, v[i].size());
	}
	return str;
}

vector<string>v_cat(vector<string>& x, vector<string>& y)                      //vertical concatenation
{
	vector<string> arr;
	typedef vector<string>::iterator iter;
	arr = x;
	for ( iter i = y.begin(); i != y.end(); i++)
		arr.push_back(*i);
	return arr;
}

vector<string>h_cat(vector<string>& arr1, vector<string>& arr2)                    //horizontal concatenation
{
	vector<string> arr;
	string::size_type l_str = long_str(arr2);
	string::size_type l_str1 = long_str(arr1);
	vector<string>::size_type i = 0, j = 0;
	while (i != arr1.size() || j != arr2.size())
	{
		string s, s1;
		if (i != arr1.size())
			s = arr1[i++];
		vector<string>::size_type t = s.size();
		if (l_str1 != t)
		{
			s1 = string(l_str1 - t, ' ') + s;
		}
		else
			s1 = string(l_str1 + 5, ' ') + s;
		s1 += string(5, ' ');

		if (j != arr2.size())
			s1 += arr2[j++];

		arr.push_back(s1);
	}
	return arr;
}
