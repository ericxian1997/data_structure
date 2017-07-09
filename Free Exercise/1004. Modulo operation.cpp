#include<vector>

class Mod {
public:
    virtual int productMod(const vector<int>&) = 0;
};


class Mod9999:public Mod
{
public:
    int productMod(const vector<int>& v)
    {
        long long product = 1;
        for(int i = 0; i < v.size(); i++)
        {
            product *= v[i];
            if(product > 9999)
            {
                product = product % 9999;
            }
        }
        return product;
    }
};

