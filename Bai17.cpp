#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<pair<long, long>> q;
    // dùng bfs -> chiều cao cây tăng dần, tìm ra số min trước
    // idea: duyệt bfs với cây nhị phân: O(2*L) với L = len({0,1})
    // mở rộng: On: cũng bfs như trên, nhưng visited chứa phần dư->nếu gặp phần dư có nghĩa 1 số ngắn hơn đã được xử lý->bắt đầu lại với nhánh đó

    q.push({1, 1 % n}); // số đầu tiên là 1
    vector<int> visited(n, 0);
    visited[1 % n] = 1;
    while (!q.empty())
    {
        pair<long, long> val = q.front();
        q.pop();
        long x1 = val.first * 10, x2 = val.first * 10 + 1;
        long r = val.second;
        if (r == 0)
        {
            cout << val.first << endl;
            break;
        }
        if (visited[x1 % n] == 0)
        {
            q.push({x1, x1 % n});
            visited[x1 % n] = 1;
        }
        if (visited[x2 % n] == 0)
        {
            q.push({x2, x2 % n});
            visited[x2 % n] = 1;
        }

        if (x2 >= 1111111112)
            break;
    }
    return 0;
}


