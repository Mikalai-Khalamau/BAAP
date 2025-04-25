#include <iostream>
#include <string>

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void add(int value) {
        if (!find(value)) {
            root = insert(root, value);
            std::cout << "DONE" << std::endl;
        } else {
            std::cout << "ALREADY" << std::endl;
        }
    }

    void search(int value) {
        if (find(value)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    void printTree() {
        print(root, 0);
    }

private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->key) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool find(int value) {
        return find(root, value);
    }

    bool find(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->key == value) {
            return true;
        }
        return value < node->key ? find(node->left, value) : find(node->right, value);
    }

    void print(TreeNode* node, int depth) {
        if (node != nullptr) {
            print(node->left, depth + 1);
            for (int i = 0; i < depth; ++i) {
                std::cout << ".";
            }
            std::cout << node->key << std::endl;
            print(node->right, depth + 1);
        }
    }
};

int main() {
    BinarySearchTree bst;
    std::string command;
    int value;

    while (std::cin >> command) {
        if (command == "ADD") {
            std::cin >> value;
            bst.add(value);
        } else if (command == "SEARCH") {
            std::cin >> value;
            bst.search(value);
        } else if (command == "PRINTTREE") {
            bst.printTree();
        }
    }

    return 0;
}