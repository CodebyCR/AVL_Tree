//
// Created by Christoph Rohde on 03.10.22.
//

#pragma once
#include <iostream>
#include <queue>

template <typename T>
class AVL_Tree {

private:

    struct Node
    {
        T data;
        Node* left;
        Node* right;
        int height;
    };

    Node* root;


    auto insert(Node* node, T data) -> Node*
    {
        if (node == nullptr)
        {
            node = new Node;
            node->data = data;
            node->left = nullptr;
            node->right = nullptr;
            node->height = 1;
            return node;
        }

        if (data < node->data){
            node->left = insert(node->left, data);
        }
        else if (data > node->data){
            node->right = insert(node->right, data);
        }
        else{
            return node;
        }

        node->height = std::max(height(node->left), height(node->right)) + 1;

        int balance = this->balance(node);

        if (balance > 1 && data < node->left->data) {
            return rotateRight(node);
        }
        if (balance < -1 && data > node->right->data) {
            return rotateLeft(node);
        }
        if (balance > 1 && data > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && data < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    auto height(Node* node) -> int
    {
        if (node == nullptr){
            return 0;
        }
        return node->height;
    }

    auto balance(Node* node) -> int
    {
        if (node == nullptr){
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    auto rotateRight(Node* node) -> Node*
    {
        Node* left = node->left;
        Node* right = left->right;

        left->right = node;
        node->left = right;

        node->height = std::max(height(node->left), height(node->right)) + 1;
        left->height = std::max(height(left->left), height(left->right)) + 1;

        return left;
    }

     auto rotateLeft(Node* node) -> Node*
    {
        Node* right = node->right;
        Node* left = right->left;

        right->left = node;
        node->right = left;

        node->height = std::max(height(node->left), height(node->right)) + 1;
        right->height = std::max(height(right->left), height(right->right)) + 1;

        return right;
    }


public:
    
    AVL_Tree()
    {
        root = nullptr;
    }

    ~AVL_Tree() = default;

    auto add(T data) -> void
    {
        root = insert(root, data);
    }

    auto getInOrder() -> std::vector<T>
    {
        std::vector<T> inOrder;
        inOrderTraversal(root, inOrder);
        return inOrder;
    }

    auto inOrderTraversal(Node* node, std::vector<T> &inOrder) -> void
    {
        if (node == nullptr){
            return;
        }
        inOrderTraversal(node->left, inOrder);
        inOrder.push_back(node->data);
        inOrderTraversal(node->right, inOrder);
    }

    auto getPreOrder() -> std::vector<T>
    {
        std::vector<T> preOrder;
        preOrderTraversal(root, preOrder);
        return preOrder;
    }

    auto preOrderTraversal(Node* node, std::vector<T> &preOrder) -> void
    {
        if (node == nullptr){
            return;
        }
        preOrder.push_back(node->data);
        preOrderTraversal(node->left, preOrder);
        preOrderTraversal(node->right, preOrder);
    }

    auto getPostOrder() -> std::vector<T>
    {
        std::vector<T> postOrder;
        postOrderTraversal(root, postOrder);
        return postOrder;
    }

    auto postOrderTraversal(Node* node, std::vector<T>& postOrder) -> void
    {
        if (node == nullptr){
            return;
        }
        postOrderTraversal(node->left, postOrder);
        postOrderTraversal(node->right, postOrder);
        postOrder.push_back(node->data);
    }

    auto getLevelOrder() -> std::vector<T>
    {
        std::vector<T> levelOrder;
        levelOrderTraversal(root, levelOrder);
        return levelOrder;
    }

    auto levelOrderTraversal(Node* node, std::vector<T>& levelOrder) -> void
    {
        if (node == nullptr){
            return;
        }
        std::queue<Node*> current_queue;
        current_queue.push(node);
        while (!current_queue.empty())
        {
            Node* current = current_queue.front();
            current_queue.pop();
            levelOrder.push_back(current->data);
            if (current->left != nullptr){
                current_queue.push(current->left);
            }
            if (current->right != nullptr){
                current_queue.push(current->right);
            }
        }
    }

    auto print() -> void
    {
        for (auto i : getInOrder()){
            std::cout << i << " ";
        }
    }

};