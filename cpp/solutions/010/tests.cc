#include "gtest/gtest.h"
#include "solution.h"

#include <iostream>


TEST(d010, scheduler_single) {
    stb::Scheduler<int, int> s;
    auto worker_a = [](const std::vector<int>& args) {return args[0];};

    s.add_job(2, {worker_a, {1, 2}});

    s.run();

    std::vector<int> r_vec {1};
    ASSERT_EQ(s.results_vector(), r_vec);
}


TEST(d010, scheduler_multi_elements) {
    stb::Scheduler<int, int> s;
    auto worker_a = [](const std::vector<int>& args) {return args[0];};

    s.add_job(2, {worker_a, {2, 2}});
    s.add_job(1, {worker_a, {1, 2}});
    s.add_job(3, {worker_a, {3, 2}});
    s.add_job(5, {worker_a, {5, 2}});

    s.run();

    std::vector<int> r_vec {1, 2, 3, 5};
    ASSERT_EQ(s.results_vector(), r_vec);
}


TEST(d010, scheduler_multi) {
    stb::Scheduler<int, int> s;
    auto worker_a = [](const std::vector<int>& args) {return args[0];};
    auto worker_b = [](const std::vector<int>& args) {return args[1];};

    s.add_job(2, {worker_a, {2, 4}});
    s.add_job(1, {worker_b, {1, 2}});
    s.add_job(3, {worker_a, {3, 6}});
    s.add_job(5, {worker_b, {5, 10}});

    s.run();

    std::vector<int> r_vec {2, 2, 3, 10};
    ASSERT_EQ(s.results_vector(), r_vec);
}
