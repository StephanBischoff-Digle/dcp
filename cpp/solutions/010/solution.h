#pragma once

#include <functional>
#include <utility>
#include <queue>
#include <cstdint>
#include <vector>

namespace stb {


template <typename RType, typename ArgType>
struct Job {
    std::function<RType(const std::vector<ArgType>&)> task;
    std::vector<ArgType> arguments;
};

template <typename RType, typename ArgType>
using PJob = std::pair<std::uint8_t, Job<RType, ArgType>>;

template <typename RType, typename ArgType>
struct PJob_CMP {
    bool operator()(const PJob<RType, ArgType>& a, const PJob<RType, ArgType>& b) {
        return a.first > b.first;
    }

};

/**
 * The Scheduler is a one shot job worker.
 * Internally it uses a priority queue to order the jobs by priority.
 */
template <typename RType, typename ArgType>
class Scheduler {
private:
    std::priority_queue<
        stb::PJob<RType, ArgType>,
        std::vector<PJob<RType, ArgType>>,
        PJob_CMP<RType, ArgType>> job_queue;
    std::vector<RType> results;

public:

    void add_job(std::uint8_t priority, const Job<RType, ArgType>& job) {
        job_queue.push({priority, job});
    }

    void run() {
        while (!job_queue.empty()) {
            auto job = job_queue.top().second;
            job_queue.pop();
            
            results.push_back(job.task(job.arguments));
        }
    }

    const std::vector<RType>& results_vector() const {return results;}
};
}
