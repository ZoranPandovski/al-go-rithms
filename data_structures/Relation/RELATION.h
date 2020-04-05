#include <iostream>
#include <vector>
using namespace std;

class RELATION
{

    vector<int> dovec;
    vector<char> domvect;
    vector<int> ravec;
    vector<char> ranvect;
    vector<int> refer;
    vector<char> referchar;
    vector<int> reference;
    vector<vector<int> > matrix;
    string relation;
    int i, j, u, v, matsize;
    int flag;

  public:
    string input();
    void domain(int);
    void range(int);
    void matrixnotation();
    void matrixintialisation();
    bool reflexive();
    bool symmetric();
    bool antisymmetric();
    bool transitive();
};

string RELATION::input()
{

    cout << "Enter the relation(Element of the realtion should be from the considered set):";
    getline(cin, relation);
    cin.ignore();
    return relation;
}

void RELATION::matrixintialisation()
{
    matsize = refer.size() + referchar.size();
    for (i = 0; i < matsize; i++)
    {
        vector<int> temp;
        for (j = 0; j < matsize; j++)
            temp.push_back(0);
        matrix.push_back(temp);
    }
}

void RELATION::matrixnotation()
{
    domain(0);
    range(0);
    for (i = 0; i < dovec.size(); i++)
        refer.push_back(dovec[i]);
    for (i = 0; i < domvect.size(); i++)
        referchar.push_back(domvect[i]);
    for (i = 0; i < ravec.size(); i++)
    {
        flag = 0;
        for (j = 0; j < refer.size(); j++)

        {
            if (ravec[i] == refer[j])
                break;
            else
                ++flag;
        }
        if (flag == refer.size())
            refer.push_back(ravec[i]);
    }

    for (i = 0; i < ranvect.size(); i++)
    {
        flag = 0;
        for (j = 0; j < referchar.size(); j++)

        {
            if (ranvect[i] == referchar[j])
                break;
            else
                ++flag;
        }
        if (flag == referchar.size())
            referchar.push_back(ranvect[i]);
    }

    for (i = 0; i < refer.size(); i++)
    {
        reference.push_back(refer[i]);
    }
    for (i = 0; i < referchar.size(); i++)
    {
        reference.push_back(referchar[i]);
    }
    cout << endl;

    matrixintialisation();

    for (i = 0; i < relation.length(); i++)
    {
        u = 0;
        v = 0;
        flag = 0;
        if (relation[i] == '(')
        {
            for (j = 0; j < reference.size(); j++)
            {
                if (isdigit(relation[i + 1]))
                {
                    if ((relation[i + 1] - '0') == reference[j])
                    {
                        ++flag;
                        u = j;
                        break;
                    }
                }
                else
                {
                    if (((int)(relation[i + 1])) == reference[j])
                    {
                        ++flag;
                        u = j;
                        break;
                    }
                }
            }
            i += 3;
            for (int k = 0; k < reference.size(); k++)
            {
                if (isdigit(relation[i]))
                {
                    if ((relation[i] - '0') == reference[k])
                    {
                        ++flag;
                        v = k;
                        break;
                    }
                }
                else
                {
                    if (((int)(relation[i])) == reference[k])
                    {
                        ++flag;
                        v = k;
                        break;
                    }
                }
            }
        }
        if (flag == 2)
            matrix[u][v] = 1;
    }

    cout << "  ";
    for (i = 0; i < refer.size(); i++)
        cout << refer[i] << " ";
    for (i = 0; i < referchar.size(); i++)
        cout << referchar[i] << " ";
    cout << endl;

    flag = 0;
    for (i = 0; i < matsize; i++)
    {
        if (i < refer.size())
        {
            cout << refer[i] << " ";
        }

        else
        {
            cout << referchar[flag] << " ";
            ++flag;
        }
        for (j = 0; j < matsize; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void RELATION::domain(int check)
{
    if (isdigit(relation[2]))
        dovec.push_back(relation[2] - '0');
    else
        domvect.push_back(relation[2]);

    for (i = 8; i < relation.length(); i += 6)
    {
        if (isdigit(relation[i]))
            dovec.push_back(relation[i] - '0');
        else
            domvect.push_back(relation[i]);
    }
    for (i = 0; i < dovec.size(); i++)
        for (j = i + 1; j < dovec.size(); j++)
        {
            if (dovec[i] == dovec[j])
            {
                dovec.erase(dovec.begin() + j);
                --j;
            }
        }
    for (i = 0; i < domvect.size(); i++)
        for (j = i + 1; j < domvect.size(); j++)
        {
            if (domvect[i] == domvect[j])
            {
                domvect.erase(domvect.begin() + j);
                --j;
            }
        }

    if (check == 1)
    {
        cout << "\ndomain: {";
        for (i = 0; i < dovec.size(); i++)
            cout << dovec[i] << ",";
        for (i = 0; i < domvect.size(); i++)
            cout << domvect[i] << ",";
        cout << "}";
    }
}

void RELATION::range(int check)
{
    if (isdigit(relation[4]))
        ravec.push_back(relation[4] - '0');
    else
        ranvect.push_back(relation[4]);

    for (i = 10; i < relation.length(); i += 6)
    {
        if (isdigit(relation[i]))
            ravec.push_back(relation[i] - '0');
        else
            ranvect.push_back(relation[i]);
    }
    for (i = 0; i < ravec.size(); i++)
        for (j = i + 1; j < ravec.size(); j++)
        {
            if (ravec[i] == ravec[j])
            {
                ravec.erase(ravec.begin() + j);
                --j;
            }
        }
    for (i = 0; i < ranvect.size(); i++)
        for (j = i + 1; j < ranvect.size(); j++)
        {
            if (ranvect[i] == ranvect[j])
            {
                ranvect.erase(ranvect.begin() + j);
                --j;
            }
        }

    if (check == 1)
    {
        cout << "\nrange: {";
        for (i = 0; i < ravec.size(); i++)
            cout << ravec[i] << ",";
        for (i = 0; i < ranvect.size(); i++)
            cout << ranvect[i] << ",";

        cout << "}";
    }
}

bool RELATION ::reflexive()
{
    flag = 0;
    for (i = 0, j = 0; i < matsize, j < matsize; i++, j++)
    {
        if (matrix[i][j] != 1)
            return false;
        ++flag;
    }

    if (flag == matsize)
        return true;
}

bool RELATION::symmetric()
{
    flag = 0;
    for (i = 0; i < matsize; i++)
    {
        for (j = 0; j < matsize; j++)
        {
            if (i != j)
            {
                if (matrix[i][j] != matrix[j][i])
                    return false;
                flag++;
            }
        }
    }
    if (flag == ((matsize * matsize) - matsize))
        return true;
}

bool RELATION::antisymmetric()
{
    for (i = 0, j = 0; i < matsize, j < matsize; i++, j++)
    {
        if (matrix[i][j] == 1)
            return true;
    }
    return false;
}

bool RELATION::transitive()
{
    int k;
    for (i = 0; i < matsize; i++)
    {
        for (j = 0; j < matsize; j++)
        {
            for (k = 0; k < matsize; k++)
            {
                if ((matrix[i][j] == 1) && (matrix[j][k] == 1))
                {
                    if (matrix[i][k] != 1)
                        return false;
                }
            }
        }
    }
    return true;
}
