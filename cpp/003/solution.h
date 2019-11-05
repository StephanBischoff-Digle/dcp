#pragma once

#include <memory>
#include <string>


struct Node {
    std::string val;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
};


std::string serialize() {
    return std::string{""};
}

Node deserialize(const std::string s) {
    Node ret;
    ret.val = std::string{s};
    ret.left = nullptr;
    ret.right = nullptr;
    return ret;
}
