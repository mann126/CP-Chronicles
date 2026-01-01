#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        int count_left = 0, count_right = 0; // count_leftt = ( , count_right = )
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '_' && count_left <= count_right)
            {
                count_left++;
                s[i] = '(';
            }
            else if (s[i] == '_' && count_right < count_left)
            {
                count_right++;
                s[i] = ')';
            }
            else if (s[i] == '(')
            {
                count_left++;
            }
            else if (s[i] == ')')
            {
                count_right++;
            }
        }

        vector<int> left;
        vector<int> right;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                left.push_back(i + 1);
            }
            else
            {
                right.push_back(i + 1);
            }
        }

        long long int sum = 0;
        for (int i = 0; i < left.size(); i++)
        {
            sum += (right[i] - left[i]);
        }
        cout << sum << endl;
    }

    return 0;
}