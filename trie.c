#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Trie node structure
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    // isEndOfWord is true if the node represents the end of a word
    bool isEndOfWord;
};

// Returns a new trie node (initialized to NULLs)
struct TrieNode *createNode(void) {
    struct TrieNode *pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    
    if (pNode) {
        pNode->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            pNode->children[i] = NULL;
        }
    }
    
    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, const char *key) {
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < strlen(key); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = createNode();

        pCrawl = pCrawl->children[index];
    }

    // Mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else false
bool search(struct TrieNode *root, const char *key) {
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < strlen(key); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main() {
    // Input keys (use only lower case a-z)
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    struct TrieNode *root = createNode();

    // Construct trie
    for (int i = 0; i < 8; i++)
        insert(root, keys[i]);

    // Search for different keys
    printf("%s --- %s\n", "the", search(root, "the") ? "Found" : "Not present");
    printf("%s --- %s\n", "these", search(root, "these") ? "Found" : "Not present");
    printf("%s --- %s\n", "their", search(root, "their") ? "Found" : "Not present");
    printf("%s --- %s\n", "th", search(root, "th") ? "Found" : "Not present");

    return 0;
}