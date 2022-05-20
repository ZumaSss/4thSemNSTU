#include <iostream>
#include <list>
using namespace std;

class HashTable
{
    int capacity;
    list<int>* table;

public:
    HashTable(int V);
    void insertItem(string key, int data);
    void deleteItem(string key);

    int checkPrime(int n)
    {
        int i;
        if (n == 1 || n == 0)
        {
            return 0;
        }
        for (i = 2; i < n / 2; i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    int getPrime(int n)
    {
        if (n % 2 == 0)
        {
            n++;
        }
        while (!checkPrime(n))
        {
            n += 2;
        }
        return n;
    }

    int hashFunction(string key)
    {
        int size_key = size(key);
        int i_key = (char)key[0] * (char)key[0];

        for (int i = 1; i < size_key; ++i)  i_key = i_key / 10 % 10;

        return (i_key % capacity);
    }
    void displayHash();
};
HashTable::HashTable(int c)
{
    int size = getPrime(c);
    this->capacity = size;
    table = new list<int>[capacity];
}
void HashTable::insertItem(string key, int data)
{
    int index = hashFunction(key);
    table[index].push_back(data);
}

void HashTable::deleteItem(string key)
{
    int index = hashFunction(key);
    list<int>::iterator i = table[index].begin();

    table[index].erase(i);
}

void HashTable::displayHash()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "table[" << i << "]";
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

int main()
{
    string key[] = { "AB", "AC", "AD", "BB", "BC", "BD" };
    int data[] = { 1, 2, 3, 4, 5, 6 };
    int size = sizeof(key) / sizeof(key[0]);

    HashTable h(size);

    for (int i = 0; i < size; i++)
        h.insertItem(key[i], data[i]);

    h.deleteItem("AB");
    h.displayHash();
}