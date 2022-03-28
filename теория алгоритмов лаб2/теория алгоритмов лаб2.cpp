#include <iostream>
#include <string>

const int ALPHABET_SIZE = 26;

struct Trie {
    struct Trie* children[ALPHABET_SIZE];

    bool isEndOfWord;
};

struct Trie *getNode(void) {
    struct Trie* pNode = new Trie;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pNode->children[i] = NULL;
    }

    return pNode;
}

void insert(struct Trie* root, std::string key) {
    struct Trie *pCrawl = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
}

bool search(struct Trie* root, std::string key) {
    struct Trie *pCrawl = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl->isEndOfWord);
}

bool isEmpty(Trie* root) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

Trie* remove(Trie* root, std::string key, int depth = 0) {
    if (!root)
        return NULL;

    if (depth == key.size()) {
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }

        return root;
    }

    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    if (isEmpty(root) && root->isEndOfWord == false) {
        delete(root);
        root = NULL;
    }

    return root;
}


int main()
{
    std::string keys[] = { "the", "a", "there", "answer", "any", "by", "bye", "their" };

    int n = sizeof(keys) / sizeof(keys[0]);

    struct Trie* root = getNode();

    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    search(root, "the") ? std::cout << "Yes\n" : std::cout << "No\n";

    search(root, "these") ? std::cout << "Yes\n" : std::cout << "No\n";

    remove(root, "the");

    search(root, "the") ? std::cout << "Yes\n" : std::cout << "No\n";

    return 0;
}
