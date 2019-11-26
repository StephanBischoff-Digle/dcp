#pragma once

#include <functional>
#include <utility>
#include <queue>
#include <cstdint>
#include <vector>

namespace stb {


/**
 * @brief Job structure holds a function and the functions arguemnts
 */
template <typename RType, typename ArgType>
struct Job {
    std::function<RType(const std::vector<ArgType>&)> task;     //!< The actual job to be run
    std::vector<ArgType> arguments;                             //!< The arguments the job should use
};


/**
 * Shorthand alias for the pair that holds the job priority and the job
 */
template <typename RType, typename ArgType>
using PJob = std::pair<std::uint8_t, Job<RType, ArgType>>;

/**
 * @brief The PJob_CMP class is nessesary for comparing two PJob for the priority queue used by the scheduler.
 */
template <typename RType, typename ArgType>
struct PJob_CMP {
    bool operator()(const PJob<RType, ArgType>& a, const PJob<RType, ArgType>& b) {
        return a.first > b.first;
    }
};

/**
 * The Scheduler is a one shot job worker.
 * Internally it uses a priority queue to order the jobs by priority.
 * The lower the priority the earlier the job is executed.
 */
template <typename RType, typename ArgType>
class Scheduler {
private:
    std::priority_queue<
        stb::PJob<RType, ArgType>,
        std::vector<PJob<RType, ArgType>>,
        PJob_CMP<RType, ArgType>> job_queue;    //!< The queue for the job
    std::vector<RType> results;                 //!< The results of the executed jobs

public:

    /**
     * @brief Add a job to the Scheduler
     * @param priority The priority of the job. The lower, the higher is the priority.
     * @param job The job that is executed once the Scheduler is run.
     */
    void add_job(std::uint8_t priority, const Job<RType, ArgType>& job) {
        job_queue.push({priority, job});
    }

    /**
     * @brief Runs Scheduler, which in turns runs all the jobs and stores the results in the order of execution.
     */
    void run() {
        results.clear();
        while (!job_queue.empty()) {
            auto job = job_queue.top().second;
            job_queue.pop();
            
            results.push_back(job.task(job.arguments));
        }
    }

    /**
     * @brief Returns the result vector.
     * @returns The result vector
     */
    const std::vector<RType>& results_vector() const {return results;}
};
}
