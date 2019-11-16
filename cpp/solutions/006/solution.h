#pragma once

#include <cstdint>
#include <iostream>
#include <optional>
#include <vector>

struct xor_node {
    std::size_t nxp;
    std::int32_t value;

    friend std::ostream& operator<<(std::ostream& out, const xor_node& o) {
        out << "{nxp: " << o.nxp << ", value: " << o.value << "}";
        return out;
    }
};

class xor_linked_list {
public:
    xor_linked_list();

    void add(std::int32_t value);
    std::optional<std::int32_t> get(std::size_t index);
    std::size_t size() {
        return size_;
    }

    friend std::ostream& operator<<(std::ostream& out,
                                    const xor_linked_list& o) {
        out << "[\n";
        std::size_t idx = 0;
        for (const auto& n : o.memory_) {
            out << idx << "\t" << n << "\n";
            idx++;
        }
        out << "]";
        return out;
    }

private:
    std::vector<xor_node> memory_;
    std::size_t size_;
};
