#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Book
{
    string code;
    string name;
    float price;
    int numberOfSold;
    float sum;

    Book();
    Book(const Book &data);
    Book(const string &code, const string &name, const float &price, const int &numberOfSold);
    void inputBook();
    void outputBook();
};

struct Node
{
    Book data;
    Node *next;

    Node();
    Node(const Book &_data);
};

class Books
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    Books();
    ~Books();
    void insertLast(const Book &_data);
    void deleteFirst();
    void deleteLast();
    void deleteNode(Node *pos);
    void inputList();
    void display();
    int countNumberOfBookHaveSumLargest();
    void sortDescendingBySum();
    void deleteBooksHaveSumLargest();
    void displayBooksHaveSumUnder5000orNumberOfSoldUnder500();
};

int main()
{
    Books books;
    books.inputList();
    cout << "\n\t\tSO SACH VUA NHAP\n";
    books.display();

    cout << "\n\tSo luong sach co doanh thu cao: " << books.countNumberOfBookHaveSumLargest() << endl;
    cout << "\n\tSau khi sap xep giam dan theo tong thu\n"
         << endl;
    books.sortDescendingBySum();
    books.display();

    cout << "\n\tXoa cac cuon sach co tong thu cao\n"
         << endl;
    books.deleteBooksHaveSumLargest();
    books.display();

    cout << "\n\tCac cuon sach co tong thu duoi 5000 hoac so luong ban duoi 500\n"
         << endl;
    books.displayBooksHaveSumUnder5000orNumberOfSoldUnder500();

    return 0;
}

// Book
Book::Book()
{
    code = "EMPTY";
    name = "EMPTY";
    price = 0;
    numberOfSold = 0;
    sum = 0;
}

Book::Book(const Book &data)
    : code(data.code), name(data.name), price(data.price), numberOfSold(data.numberOfSold), sum(data.price * data.numberOfSold) {}

Book::Book(const string &code, const string &name, const float &price, const int &numberOfSold)
    : code(code), name(name), price(price), numberOfSold(numberOfSold), sum(price * numberOfSold) {}

void Book::inputBook()
{
    cout << "\nNhap ma sach: ";
    fflush(stdin);
    getline(cin, code);
    cout << "\nNhap ten sach: ";
    getline(cin, name);
    cout << "\nNhap gia sach: ";
    cin >> price;
    cout << "\nNhap so luong sach da ban: ";
    cin >> numberOfSold;
    sum = price * numberOfSold;
}

void Book::outputBook()
{
    cout << left << setw(10) << code << " | " << setw(15) << name << " | " << setw(20) << price << " | " << setw(20) << numberOfSold << " | " << setw(20) << size_t(sum) << endl;
}

// Node
Node::Node()
    : next(NULL)
{
}

Node::Node(const Book &_data)
    : data(_data), next(NULL) {}

// Books
Books::Books()
    : head(NULL), tail(NULL), size(0) {}

Books::~Books()
{
    Node *t;
    while (head != NULL)
    {
        t = head;
        head = head->next;
        size--;
        delete t;
    }
}

void Books::insertLast(const Book &_data)
{
    Node *n = new Node(_data);
    if (size == 0)
        head = tail = n;
    else
    {
        tail->next = n;
        tail = n;
    }
    size++;
}

void Books::deleteFirst()
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

void Books::deleteNode(Node *pos)
{
    if (size == 0)
        return;
    else if (pos == head)
        deleteFirst();
    else if (pos == tail)
        deleteLast();
    else
    {
        Node *prevN = new Node();
        for (Node *t = head; t != NULL; t = t->next)
        {
            if (t == pos)
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

void Books::deleteLast()
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

void Books::inputList()
{
    int n;
    do
    {
        cout << "\nNhap so luong sach: ";
        cin >> n;
        if (n <= 0 || n > 100)
            cout << "\n\t(!) So luong khong hop le (!)" << endl;
    } while (n <= 0 || n > 100);

    for (int i = 0; i < n; i++)
    {
        cout << "\n\tNHAP SACH " << i + 1 << endl;
        Book book;
        book.inputBook();
        insertLast(book);
    }
}

void Books::display()
{
    cout << left << setw(10) << "Ma sach"
         << " | " << setw(15) << "Ten sach"
         << " | " << setw(20) << "Gia ban (USD)"
         << " | " << setw(20) << "So luong da ban"
         << " | " << setw(20) << "Tong thu (USD)" << endl;
    for (Node *t = head; t != NULL; t = t->next)
        t->data.outputBook();
    cout << endl;
}
int Books::countNumberOfBookHaveSumLargest()
{
    const int sumLargest = 10000;
    int count = 0;
    for (Node *t = head; t != NULL; t = t->next)
    {
        if (t->data.sum > sumLargest)
            count++;
    }
    return count;
}

void Books::sortDescendingBySum()
{
    for (Node *i = head; i != tail; i = i->next)
    {
        Node *maxIndex = i;
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (j->data.sum > maxIndex->data.sum)
                maxIndex = j;
        }
        if (maxIndex != i)
            swap(i->data, maxIndex->data);
    }
}

void Books::deleteBooksHaveSumLargest()
{
    const int sumLargest = 10000;
    for (Node *t = head; t != NULL; t = t->next)
    {
        if (t->data.sum > sumLargest)
            deleteNode(t);
    }
}

void Books::displayBooksHaveSumUnder5000orNumberOfSoldUnder500()
{
    const int maxSum = 5000, maxSold = 500;
    cout << left << setw(10) << "Ma sach"
         << " | " << setw(15) << "Ten sach"
         << " | " << setw(20) << "Gia ban (USD)"
         << " | " << setw(20) << "So luong da ban"
         << " | " << setw(20) << "Tong thu (USD)" << endl;
    for (Node *t = head; t != NULL; t = t->next)
    {
        if (t->data.sum < maxSum || t->data.numberOfSold < maxSold)
            t->data.outputBook();
    }
    cout << endl;
}