#pragma once

#include <iostream>

#include <functional>
#include <iterator>
#include <memory>
#include <string>
#include <sstream>
#include <vector>

#include "dbg.h"


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


Node deserialize(const std::string s) {
    std::istringstream is(s);
    std::vector<std::string> tokens{
        std::istream_iterator<std::string>(is),
        std::istream_iterator<std::string>()};

    dbg(tokens);

    std::size_t i = 0;
    std::function<Node *()> constructor;
    constructor = [&tokens, &constructor, &i]() -> Node * {
        i++;
        if (tokens[i] == "#") {
            return nullptr;
        } else {
            return new Node{tokens[i], constructor(), constructor()};
        }
    };

    return Node{tokens[0], constructor(), constructor()};
}
