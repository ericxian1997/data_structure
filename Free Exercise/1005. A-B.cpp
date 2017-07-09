#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> A;
        vector<int> B;

        vector<int> D;
        int n, m;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            A.push_back(temp);
        }
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            int temp;
            cin >> temp;
            B.push_back(temp);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for(int i = 0; i < n; i++)
        {
            bool found = false;
            for(int j = 0; j < m && B[j] <= A[i]; j++)
            {
                if(B[j] == A[i])
                {
                    found = true;
                    break;
                }
            }
            if(!found)
            {
                D.push_back(A[i]);
            }
        }

        vector<int>::iterator iter = unique(D.begin(), D.end());
        D.erase(iter, D.end());
        // delete the repetitive value

        for(int i = 0; i < D.size(); i++)
        {
            cout << D[i];
            if(i != D.size()-1)  cout << " ";
        }
        cout << endl;
    }
}
