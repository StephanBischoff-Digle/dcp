#pragma once

#include <cstdint>
#include <string>

std::size_t recursive_decodings(const std::string message) {
    std::size_t n_decodes = 0;
    if (message.empty()) {
        n_decodes = 1;
    } else {
        if (message[0] != '0') {
            n_decodes += recursive_decodings(message.substr(1));
        }

        int val = std::stoi(message.substr(0,2));
        if (val <= 26 && val >= 10) {
            n_decodes += recursive_decodings(message.substr(2));
        }
    }

    return n_decodes;
}
