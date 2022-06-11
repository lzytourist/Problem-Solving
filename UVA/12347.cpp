#include <iostream>

using namespace std;

template<class T>
struct Node {
    T val;
    Node *left, *right;

    Node() = default;

    explicit Node(T _val) : val(_val) {
        left = right = nullptr;
    }
};

template<class T>
class BST {
    Node<T> *root;

    void deleteNodes(Node<T> *u) {
        if (u == nullptr) {
            return;
        }

        deleteNodes(u->left);
        deleteNodes(u->right);

        delete u;
    }

    void traverse(Node<T> *u) {
        if (u == nullptr) {
            return;
        }

        traverse(u->left);
        traverse(u->right);

        cout << u->val << "\n";
    }

public:
    BST() {
        root = nullptr;
    }

    ~BST();

    void insert(T n);

    void posOrderTraverse() {
        traverse(root);
    }
};

template<class T>
BST<T>::~BST() {
    deleteNodes(root);
}

template<class T>
void BST<T>::insert(T n) {
    if (root == nullptr) {
        root = new Node<T>(n);
    } else {
        Node<T> *head = root, *prev = nullptr;
        bool leftNode = true;

        while (head != nullptr) {
            prev = head;
            if (head->val < n) {
                head = head->right;
                leftNode = false;
            } else {
                head = head->left;
                leftNode = true;
            }
        }

        head = new Node<T>(n);
        if (leftNode) {
            prev->left = head;
        } else {
            prev->right = head;
        }
    }
}

int main() {
    BST<int> bst;
    int n;

    while (cin >> n) {
        bst.insert(n);
    }

    bst.posOrderTraverse();

    return 0;
}
