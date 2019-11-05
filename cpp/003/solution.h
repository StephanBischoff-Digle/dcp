#pragma once

#include <iostream>

#include <memory>
#include <string>


struct Node {
    std::string val;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    friend std::ostream& operator<<(std::ostream& out, const Node& v) {
        out << "[val: " << v.val << ", left: " << v.left << ", right: " << v.right << "]";
        return out;
    }
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
