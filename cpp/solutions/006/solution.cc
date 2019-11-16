#include "solution.h"

xor_linked_list::xor_linked_list() : memory_(3), size_{0} {}

void xor_linked_list::add(std::int32_t value) {
    if (size_ == 0) {
        memory_[0] = {0, value};
        size_++;
        return;
    }

    // resize internam memory if necessary
    if (size_ == memory_.size() - 1) {
        memory_.resize(2 * size_);
    }

    // find last
    std::size_t idx = 0;
    std::size_t prev = 0;
    std::size_t next;
    while ((next = memory_[idx].nxp ^ prev) != 0) {
        prev = idx;
        idx = next;
    }

    // "allocate memory"
    memory_[idx + 1] = {idx ^ 0, value};
    memory_[idx].nxp = prev ^ (idx + 1);
    size_++;
}

std::optional<std::int32_t> xor_linked_list::get(std::size_t target) {
    if (target >= size_) {
        return {};
    }

    if (target == 0) {
        return memory_[0].value;
    }

    std::size_t idx = 0;
    std::size_t prev = 0;
    std::size_t next;
    while ((next = memory_[idx].nxp ^ prev) != 0) {
        prev = idx;
        idx = next;
        if (idx == target) {
            return {memory_[idx].value};
        }
    }

    return {};
}
