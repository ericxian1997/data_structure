#include<vector>
#include <string>
#include <iostream>

using namespace std;

class Dictionary{
private:
    vector<string> eng;
    vector<string> chn;
public:
    void put(const string & english, const string & chinese)
    {
        eng.push_back(english);
        chn.push_back(chinese);
    }
    string get(const string & english)
    {
        for(int i = 0; i < eng.size(); i++)
        {
            if(eng[i] == english)
            {
                return chn[i];
            }
        }
        return "[not found]";
    }
};

int main()
{
    Dictionary dictionary;

 // initialize dictionary
    while (true)
    {
        string english;
        cin >> english;
        if (english == "end") break;
        string chinese;
        cin >> chinese;
        dictionary.put(english, chinese);
    }


 // lookup dictionary
    while (true)
    {
        string english;
        cin >> english;
        if (english == "end") break;
        cout << dictionary.get(english) << endl;
    }
}
