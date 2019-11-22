#pragma once

#include <cstdint>
#include <functional>
#include <memory>
#include <tuple>

template <typename T>
class btree {
public:
    btree(T value, btree<T>* left = nullptr, btree<T>* right = nullptr) :
        left{left}, right{right}, value{value} {}


    std::size_t n_unival_subtrees() const {
        std::function<std::tuple<bool, T, std::size_t>(const btree<T>&)> recursive_unival_subtree;
        recursive_unival_subtree = 
            [&recursive_unival_subtree](const btree<T>& tree) -> std::tuple<bool, T, std::size_t> {
            // leaf condition; leafs are always universal value trees
            if (!tree.left && !tree.right) {
                return {true, tree.value, 1};
            }

            bool is_unival = true;
            std::size_t unival_subs = 0;
            if (tree.left) {
                auto [child_unival, val, n_unival_sub] = recursive_unival_subtree(*tree.left);
                is_unival = (child_unival && val == tree.value);
                unival_subs += n_unival_sub; 
            }
            if (tree.right) {
                auto [child_unival, val, n_unival_sub] = recursive_unival_subtree(*tree.right);
                is_unival = (child_unival && is_unival && val == tree.value);
                unival_subs += n_unival_sub; 
            }

            return {is_unival, tree.value, is_unival ? unival_subs + 1 : unival_subs};
        };

        auto [a, b, ret] = recursive_unival_subtree(*this);

        return ret;
    }

    std::shared_ptr<btree<T>> left;
    std::shared_ptr<btree<T>> right;
    T value; 
};


void init() {}
