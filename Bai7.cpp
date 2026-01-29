#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int Bai7_Prefix(int n, vector<int> &a)
{
    vector<int> left(n), right(n);
    left[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], a[i]);
    }

    right[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], a[i]);
    }

    int water = 0;
    for (int i = 0; i < n; i++)
    {
        water += min(left[i], right[i]) - a[i];
    }
    return water;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << Bai7_Prefix(n, a) << endl;
    return 0;
}



// Stack
int Bai7_Stack(int n, vector<int> &a)
{
    stack<int> st;
    int water = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[i] > a[st.top()])
        {
            int mid = st.top();
            st.pop();
            if (st.empty())
                break;
            int right = st.top();
            int height = min(a[right], a[i]) - a[mid];
            int width = right - i - 1;
            water += height * width;
        }
        st.push(i);
    }
    return water;
}