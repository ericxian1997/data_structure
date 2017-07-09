#include<iostream>
#include<string>
using namespace std;

int N_to_demical(string a)
{

}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        if(a.size() < b.size())
        {
            string temp;
            temp = a;
            a = b;
            b = temp;
        }
        int maxsize = (a.size() > b.size()) ? a.size() : b.size();
        int c = 0;
        for(int i = a.size()-1, j = b.size()-1; i >= -1; i--)
        {
            if(i == -1)
            {
                if(c == 1) a = '1' + a;
                break;
            }

            int num_a, num_b;
            if(a[i] <= '9') num_a = int(a[i] - '0');
            else num_a = int(a[i] - 'A') + 10;


            if(j >= 0)
            {if(b[j] <= '9') num_b = int(b[j] - '0');
            else num_b = int(b[j] - 'A') + 10;
            }
            else num_b = 0;

            if(num_a + num_b + c >= n) { num_a = (num_a + num_b + c) - n; c = 1;}
            else {num_a = (num_a + num_b + c); c = 0;}


            if(num_a <= 9) a[i] = '0' + num_a;
            else a[i] = 'A' + (num_a - 10);
            j--;
        }
        cout << a << endl;
    }
}
