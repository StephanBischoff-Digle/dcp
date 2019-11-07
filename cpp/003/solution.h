#pragma once

#include <iostream>

#include <functional>
#include <memory>
#include <string>
#include <sstream>


struct Node {
    std::string val;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(std::string val, Node* left = nullptr, Node* right = nullptr)
        : val{val},
          left{left},
          right{right} {}

    void add_left(std::string val) {
        left = std::shared_ptr<Node>(new Node{val});
    }
    void add_right(std::string val) {
        right = std::shared_ptr<Node>(new Node{val});
    }
};


//     a
//  b     c
//
// a b # # c # #
std::string serialize(const Node& root) {
    std::function<std::string(const std::shared_ptr<Node>& sub)> recursive;
    recursive = [&recursive](const std::shared_ptr<Node>& sub) -> std::string {
        if (!sub) {
            return std::string{"#"};
        } else {
            std::stringstream ss;
            ss << sub->val << " "
               << recursive(sub->left) << " "
               << recursive(sub->right);
            return ss.str();
        }
    };

    std::stringstream ss;
    ss << root.val << " ";
    if (!root.left) {
        ss << "#";
    } else {
        ss << recursive(root.left);
    }

    if (!root.right) {
        ss << " #";
    } else {
        ss << " " << recursive(root.right);
    }

    return ss.str();
}
