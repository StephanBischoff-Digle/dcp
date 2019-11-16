#pragma once

#include <functional>

auto cons(int a, int b) {
    return [a, b](std::function<int(int, int)> f) { return f(a, b); };
}

int car(std::function<int(std::function<int(int, int)>)> p) {
    return p([](int a, int) { return a; });
}

int cdr(std::function<int(std::function<int(int, int)>)> p) {
    return p([](int, int b) { return b; });
}
