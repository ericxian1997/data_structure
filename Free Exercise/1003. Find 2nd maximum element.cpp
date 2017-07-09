#include<iostream>
#include<vector>
using namespace std;

class Sequence
{
public:
    Sequence(const vector<int>& v):seq(v) { }
    friend int second_max(const Sequence& s)
    {
        int second = -1;
        int maximum = -1;
        for(int i = 0; i < s.seq.size(); i++)
        {
            if(s.seq[i] > maximum)
            {
                second = maximum;
                maximum = s.seq[i];
            }
            else if(s.seq[i] < maximum && s.seq[i] > second)
            {
                second = s.seq[i];
            }
        }
        if(maximum == second)  second = -1;
        return second;
    }
private:
    vector<int> seq;
};


int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    Sequence s(v);
    cout << second_max(s) << endl;;
    return 0;
}
