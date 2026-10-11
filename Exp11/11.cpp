#include <iostream>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

Node* createNode(char ch, int freq) {
    Node* node = new Node;
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void sortNodes(Node* nodes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nodes[j]->freq > nodes[j + 1]->freq) {
                Node* temp = nodes[j];
                nodes[j] = nodes[j + 1];
                nodes[j + 1] = temp;
            }
        }
    }
}

void printCodes(Node* root, string code) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cin >> n;

    Node* nodes[100];

    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cin >> ch >> freq;
        nodes[i] = createNode(ch, freq);
    }

    while (n > 1) {
        sortNodes(nodes, n);

        Node* left = nodes[0];
        Node* right = nodes[1];

        Node* parent = createNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        for (int i = 2; i < n; i++)
            nodes[i - 2] = nodes[i];

        nodes[n - 2] = parent;
        n--;
    }

    printCodes(nodes[0], "");
    return 0;
}