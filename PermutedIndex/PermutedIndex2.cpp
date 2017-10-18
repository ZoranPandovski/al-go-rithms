#include"Header.h"

int main()
{
	string a, f;
	cout << "ENTER A STRING ..... VOILA" << endl;
	getline(cin, a);                          //got a string stored in 'a'

	
	typedef vector<string>::const_iterator iter;         //synonyms
	typedef vector<string>::size_type vec_sy;
	
	vector<string> str_r;
	vector<string> ret, v1, vec_sx, vec_sn;
	vector<vec_sy> pose;                //position

	ret = split(a);            //split the sentence in words 



	v1 = ret;           //storing the arr so as to use in future


	str_r.push_back(ret[0]);            //pushing the first word

	                                    
	for (vec_sy it = 0; it != v1.size(); it++)                //to rotate the string 
	{
		f = rotate(v1);
		vec_sx.push_back(f);                                    //contain rotated string
	}
	cout << "\n";


	sort(ret.begin(), ret.end(), compare);                 //sort the sentences in alphabetic order
	
	
	for (iter i = vec_sx.begin(); i != vec_sx.end(); i++)
	{
		vec_sy pose1 = port(ret, split(*i));                   //split converted the vec_sx elements in vector 
		pose.push_back(pose1);                                    //store positions
	}



	

	vector<vec_sy> pose_t = pose;                                          //jumbled position stored in pose_t
	sort(pose.begin(), pose.end(), dare);



	for (vector<vec_sy>::iterator it1 = pose.begin(); it1 != pose.end(); it1++)
	{
		vector<string>::size_type c = 0;
		for (vector<vec_sy>::iterator it2 = pose_t.begin(); it2 != pose_t.end(); it2++)
		{

			if ((*it1) == (*it2))
			{
				vec_sn.push_back(paint1(split(vec_sx[c])));                 //stores the rotated string
				break;
			}
			else c++;

		}
	}

	//vec_sn contains the rotated strings
	vector<string> suz1, suz2;
	for (iter i = vec_sn.begin(); i != vec_sn.end(); i++)
	{
		suz1.push_back(nsplit(unrotate1(str_r, split(*i))));
		suz2.push_back(nsplit(unrotate2(str_r, split(*i))));
	}
	vector<string> m1, m2;
	for (iter i = suz1.begin(); i != suz1.end(); i++)
	{
		vector<string> m;
		m.push_back(*i);
		m1 = v_cat(m1, m);
	}
	for (iter i = suz2.begin(); i != suz2.end(); i++)
	{
		vector<string> m;
		m.push_back(*i);
		m2 = v_cat(m2, m);
	}

	vector<string> y = h_cat(m2, m1);                                 //horizontal concatenation
	for (iter i = y.begin(); i != y.end(); i++)
		cout << *i << endl;
	cout << "\n";

	return 0;
}