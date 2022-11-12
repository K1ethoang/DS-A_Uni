// Hoang Gia Kiet
// 6251071049
// CNTT - K62

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

queue<bool> dec2bin(long dec)
{
    stack<bool> s;
    queue<bool> res;
    while (dec != 0)
    {
        s.push(dec % 2);
        dec /= 2;
    }
    while (s.size() != 0)
    {
        res.push(s.top());
        s.pop();
    }
    return res;
}

int main()
{
    long dec;
    cout << "\nNhap so o he thap phan de chuyen doi: ";
    cin >> dec;
    queue<bool> res = dec2bin(dec);
    while (res.size() != 0)
    {
        cout << res.front();
        res.pop();
    }
}