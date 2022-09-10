#include <iostream>
using namespace std;

// Hoang Gia Kiet
// Le Thien Hoa

// bai 1
int count(int a[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 3 == 0)
            res++;
    }
    return res;
}
// tot nhat: O(n)
// xau nhat: O(n)

// bai 2
int findElement(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 3 == 0)
            return i;
    }
    return -1;
}
// tot nhat: O(1)
// xau nhat: O(n)

// bai 3
void findCouple(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((a[i] + a[j]) % 3 == 0)
                cout << a[i] << " va " << a[j] << endl;
        }
    }
}
// tot nhat: O(n^2)
// xau nhat: O(n^2)

int main()
{
    int n = 7;
    int a[n] = {27, 1, 6, 2, 12, 7, 9};
    cout << "so phan tu chia het: " << count(a, n) << endl;
    cout << "vi tri phan tu dau tien chia het: " << findElement(a, n) << endl;
    findCouple(a, n);
    return 0;
}