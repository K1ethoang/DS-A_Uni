// Hoang Gia Kiet
// 6251071049
// CNTT - K62
#include <iostream>
#include <algorithm>
using namespace std;

#define item int

struct Node
{
    item data;
    Node *next;

    Node()
    {
        data = -1;
        next = NULL;
    }

    Node(const item &value)
    {
        data = value;
        next = NULL;
    }
};

class SList
{
private:
    Node *head;
    Node *tail;
    long size;

public:
    SList();
    ~SList();
    void themTruoc(const item &value);
    void themSau(const item &value);
    void xoaDau();
    void xoaCuoi();
    void nhapDS(const long &_size);                                  // 1
    void nhapDSDenSo0();                                             // 2
    void xuatDS();                                                   // 3
    float tinhTrungBinhCong();                                       // 4
    long soPhanTuTrongDS();                                          // 5
    void chenYvaoSauX(const item &valueOfY, const item &valueOfX);   // 6
    void chenYvaoTruocX(const item &valueOfY, const item &valueOfX); // 7
    item giaTriCuaNutK(const long &viTri);                           // 8
    item phanTuNhoNhat();                                            // 9
    void xoaMotPhanTuCoKhoaX(const item &valueOfX);                  // 10
    void xoaTatCaPhanTuCoKhoaX(const item &valueOfX);                // 11
    bool kiemTraDayTang();                                           // 12
    void sapXepTangDan();                                            // 13
};

int main()
{
    SList list;
    cout << "\n\t\tCau 1" << endl;
    int n;
    cout << "\nNhap so luong phan tu can nhap: ";
    cin >> n;
    list.nhapDS(n);
    list.xuatDS();

    cout << "\n\t\tCau 2" << endl;
    list.nhapDSDenSo0();
    list.xuatDS();

    cout << "\n\t\tCau 3" << endl;
    list.xuatDS();

    cout << "\n\t\tCau 4" << endl;
    cout << "\nTBC: " << list.tinhTrungBinhCong() << endl;

    cout << "\n\t\tCau 5" << endl;
    cout << "\nSo phan tu trong ds: " << list.soPhanTuTrongDS() << endl;

    cout << "\n\t\tCau 6 : chen Y vao sau X" << endl;
    item x, y;
    cout << "\nNhap gia tri Y: ";
    cin >> y;
    cout << "\nNhap gia tri X: ";
    cin >> x;
    list.chenYvaoSauX(y, x);
    cout << endl;
    list.xuatDS();

    cout << "\n\t\tCau 7 : chen Y vao truoc X" << endl;
    cout << "\nNhap gia tri Y: ";
    cin >> y;
    cout << "\nNhap gia tri X: ";
    cin >> x;
    list.chenYvaoTruocX(y, x);
    cout << endl;
    list.xuatDS();

    cout << "\n\t\tCau 8" << endl;
    int k;
    cout << "\nNhap nut K: ";
    cin >> k;
    if (list.giaTriCuaNutK(k) == -1)
        cout << "\nKhong co gia tri cua nut K";
    else
        cout << "\nGia tri cua nut " << k << ": " << list.giaTriCuaNutK(k);

    cout << "\n\t\tCau 9" << endl;
    if (list.phanTuNhoNhat() == -1)
        cout << "\nKhong co phan tu nho nhat";
    else
        cout << "\nPhan tu nho nhat: " << list.phanTuNhoNhat();

    cout << "\n\t\tCau 10" << endl;
    cout << "\nNhap khoa x de xoa 1 phan tu: ";
    cin >> x;
    list.xoaMotPhanTuCoKhoaX(x);
    cout << endl;
    list.xuatDS();

    cout
        << "\n\t\tCau 11" << endl;
    cout << "\nNhap khoa x de xoa tat ca phan tu: ";
    cin >> x;
    list.xoaTatCaPhanTuCoKhoaX(x);
    cout << endl;
    list.xuatDS();

    cout
        << "\n\t\tCau 12" << endl;
    if (list.kiemTraDayTang())
        cout << "\nDay la day tang";
    else
        cout << "\nDay khong phai day tang";

    cout << "\n\t\tCau 13: sap xep tang dan";
    list.sapXepTangDan();
    cout << endl;
    list.xuatDS();
}

SList::SList()
{
    head = tail = NULL;
    size = 0;
}

SList::~SList()
{
    Node *temp;
    while (size != 0)
    {
        temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

void SList::themTruoc(const item &value)
{
    Node *n = new Node(value);
    if (size == 0)
        head = tail = n;
    else
    {
        n->next = head;
        head = n;
    }
    size++;
}

void SList::themSau(const item &value)
{
    Node *n = new Node(value);
    if (size == 0)
        head = tail = n;
    else
    {
        tail->next = n;
        tail = n;
    }
    size++;
}

void SList::xoaDau()
{
    if (size == 0)
        return;
    else
    {
        Node *temp = head;
        if (size == 1)
            head = tail = NULL;
        else
            head = head->next;
        delete temp;
        size--;
    }
}

void SList::xoaCuoi()
{
    if (size == 0)
        return;
    {
        for (Node *t = head; t != NULL; t = t->next)
        {
            if (t->next == tail)
            {
                delete tail;
                t->next = NULL;
                tail = t;
                size--;
                return;
            }
        }
    }
}

void SList::nhapDS(const long &_size) // 1
{
    for (int i = 0; i < _size; i++)
    {
        item x;
        cout << "\nNhap phan tu " << i + 1 << ": ";
        cin >> x;
        themSau(x);
    }
}

void SList::nhapDSDenSo0() // 2
{
    for (int i = 0;; i++)
    {
        item x;
        cout << "\nNhap phan tu " << i + 1 << ": ";
        cin >> x;
        if (x == 0)
            break;
        themSau(x);
    }
}
void SList::xuatDS() // 3
{
    for (Node *t = head; t != NULL; t = t->next)
    {
        cout << t->data << " ";
    }
}

float SList::tinhTrungBinhCong() // 4
{
    float sum = 0;
    for (Node *t = head; t != NULL; t = t->next)
    {
        sum += t->data;
    }
    return sum / size;
}

long SList::soPhanTuTrongDS() // 5
{
    return size;
}

void SList::chenYvaoSauX(const item &valueOfY, const item &valueOfX) // 6
{
    if (size == 0)
        return;
    else if (size == 1 && head->data == valueOfX)
        themSau(valueOfY);
    else
    {
        for (Node *t = head; t != NULL; t = t->next)
        {
            if (t->data == valueOfX)
            {
                Node *n = new Node(valueOfY);
                n->next = t->next;
                t->next = n;
                size++;
            }
        }
    }
}

void SList::chenYvaoTruocX(const item &valueOfY, const item &valueOfX) // 7
{
    if (size == 0)
        return;
    else if (size == 1 && head->data == valueOfX)
        themTruoc(valueOfY);
    else
    {
        if (head->data == valueOfX)
            themTruoc(valueOfY);
        Node *prevN = new Node();
        for (Node *t = head->next; t != NULL; t = t->next)
        {
            if (t->data == valueOfX)
            {
                Node *n = new Node(valueOfY);
                n->next = t;
                prevN->next = n;
            }
            prevN = t;
        }
    }
}

item SList::giaTriCuaNutK(const long &viTri) // 8
{
    long count = 0;
    for (Node *t = head; t != NULL; t = t->next)
    {
        if (count == viTri)
            return t->data;
        count++;
    }
    return -1;
}

item SList::phanTuNhoNhat() // 9
{
    if (size == 0)
        return -1;
    item result = head->data;
    for (Node *t = head->next; t != NULL; t = t->next)
    {
        if (result > t->data)
            result = t->data;
    }
    return result;
}

void SList::xoaMotPhanTuCoKhoaX(const item &valueOfX) // 10
{
    if (size == 0)
        return;
    else if (head->data == valueOfX)
        xoaDau();
    else
    {
        Node *prevN = new Node();
        for (Node *t = head; t != NULL; t = t->next)
        {
            if (t->data == valueOfX)
            {
                Node *del = t;
                prevN->next = t->next;
                delete del;
                size--;
                break;
            }
            prevN = t;
        }
    }
}

void SList::xoaTatCaPhanTuCoKhoaX(const item &valueOfX) // 11
{
    if (size == 0)
        return;
    else
    {
        Node *prevN = new Node();
        for (Node *t = head; t != NULL; t = t->next)
        {
            if (t->data == valueOfX)
            {
                Node *del = t;
                prevN->next = t->next;
                delete del;
                size--;
                t = prevN;
            }
            prevN = t;
        }
    }
}

bool SList::kiemTraDayTang() // 12
{
    for (Node *t = head; t != tail; t = t->next)
    {
        if (t->data > t->next->data)
            return false;
    }
    return true;
}

void SList::sapXepTangDan() // 13
{
    if (size == 0)
        return;
    for (Node *i = head; i != tail; i = i->next)
    {
        Node *minIndex = i;
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (minIndex->data > j->data)
                minIndex = j;
        }
        if (minIndex != i)
            swap(i->data, minIndex->data);
    }
}