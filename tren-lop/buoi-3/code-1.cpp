#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Book
{
    int ID;
    string title;
    float price;
    Book();
    Book(const int &_ID, const string &_title, const float &_price);
};

typedef Book Item;

struct Node
{
    Item data;
    Node *next;
    Node();
    Node(const Item &val);
};

class Books
{
private:
    Node *head;
    Node *tail;
    long size;

public:
    Books();
    ~Books();
    void add(const Item &val);
    Item findByIdBook(const int &_ID);
    vector<Book> findByTitleBook(const string &_title);
    vector<Book> findByHighestPrice();
    float averagePriceOfAll();
};

int main()
{
    Book b('1', "c++", 123);
    Books list;
    list.add(b);

    return 0;
}

Book::Book()
{
    ID = 0;
    title = "";
    price = 0;
}

Book::Book(const int &_ID, const string &_title, const float &_price)
{
    ID = _ID;
    title = _title;
    price = _price;
}

Node::Node() {}

Node::Node(const Item &val)
{
    data = val;
    next = NULL;
}

Books::Books()
{
    head = tail = NULL;
    size = 0;
}

Books::~Books() {}

void Books::add(const Item &val)
{
    Node *p = new Node(val);
    if (size == 0)
        head = tail = p;
    else
    {
        tail->next = p;
        tail = p;
    }
    size++;
}

Item Books::findByIdBook(const int &_ID)
{
    for (Node *t = head; t != NULL; t = t->next)
    {
        if (t->data.ID == _ID)
            return t->data;
    }
    return Item();
}

vector<Book> Books::findByTitleBook(const string &_title)
{
    vector<Book> res;
    for (Node *t = head; t != NULL; t = t->next)
    {
        if (t->data.title.compare(_title) == 0)
            res.push_back(t->data);
    }
    return res;
}

vector<Book> Books::findByHighestPrice()
{
    float highestPrice = 0;
    vector<Book> res;
    for (Node *t = head; t != NULL; t = t->next)
    {
        if (t->data.price > highestPrice)
            highestPrice = t->data.price;
    }
    for (Node *t = head; t != NULL; t = t->next)
    {
        if (t->data.price == highestPrice)
            res.push_back(t->data);
    }
    return res;
}

float Books::averagePriceOfAll()
{
    float averagePrice = 0;
    for (Node *t = head; t != NULL; t = t->next)
        averagePrice += t->data.price;
    return averagePrice / size;
}
