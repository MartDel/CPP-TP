#include <utility>
#include "headers.hpp"

int main(void) {
    // Set up the chrono
    map<double, string> chronos;
    time_point<system_clock> start, end;
    duration<double> elapsed_time;

    // Get all prime numbers
    vector<int> primes = getAllPrime(N);
    
    /* -------------------------- Associative container ------------------------- */

    set<int> my_set;
    multiset<int> my_multiset;
    map<int, int> my_map;
    multimap<int, int> my_multimap;

    // Fill the start container : my_set
    while (primes.size()) {
        my_set.insert(primes.back());
        primes.pop_back();
    }

    // Start the race
    start = system_clock::now();
    for (size_t i = 0; i < nb_round; i++) {
        // set to multiset
        while (!my_set.empty()) {
            auto deleted = my_set.erase(my_set.cbegin());
            my_multiset.insert(*deleted);
        }

        // multiset to map
        while (!my_multiset.empty()) {
            auto deleted = my_multiset.erase(my_multiset.cbegin());
            my_map.insert(pair<int, int>(*deleted, *deleted));
        }

        // map to multimap
        while (!my_map.empty()) {
            auto deleted = my_map.erase(my_map.cbegin());
            my_multimap.insert(*deleted);
        }

        // multimap to set
        while (!my_multimap.empty()) {
            auto deleted = my_multimap.erase(my_multimap.cbegin());
            my_set.insert((*deleted).first);
        }
    }

    // Get the race timer
    end = system_clock::now();
    elapsed_time = end - start;
    chronos.insert(pair<double, string>(elapsed_time.count(), "associative"));

    /* ----------------------- Not associative containers ----------------------- */

    list<int> my_list;
    queue<int> my_queue;
    stack<int> my_stack;

    // Fill the start container : primes
    while (!my_set.empty()) {
        auto deleted = my_set.erase(my_set.cbegin());
        primes.push_back(*deleted);
    }

    // Start the race
    start = system_clock::now();
    for (size_t i = 0; i < nb_round; i++) {
        // vector to list
        while (!primes.empty()) {
            my_list.push_back(primes.back());
            primes.pop_back();
        }

        // list to queue
        while (!my_list.empty()) {
            my_queue.push(my_list.back());
            my_list.pop_back();
        }

        // queue to stack
        while (!my_queue.empty()) {
            my_stack.push(my_queue.back());
            my_queue.pop();
        }

        // stack to vector
        while (!my_stack.empty()) {
            primes.push_back(my_stack.top());
            my_stack.pop();
        }
    }

    // Get the race timer
    end = system_clock::now();
    elapsed_time = end - start;
    chronos.insert(pair<double, string>(elapsed_time.count(), "non associative"));

    // Show timers
    for (auto& item : chronos)
        cout << item.second << " : " << item.first << endl;

    return 0;
}

bool is_prime(const int& n) {
    // 1, 0, negative and pair numbers are not prime
    if (n <= 1 || n % 2 == 0)
        return false;
    // 2 are prime
    else if (n == 2 || n < sqrt(n))
        return true;
    else {
        for (size_t i = 3; i < n - 1; i++)
            // n is divisible, so not prime
            if (n % i == 0) return false;
        return true;
    }
}

vector<int> getAllPrime(const int n) {
    vector<int> primes;
    for (size_t i = 0; i < n; i++)
        if (is_prime(i))
            primes.push_back(i);
    return primes;
}