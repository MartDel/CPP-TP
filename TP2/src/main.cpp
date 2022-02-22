#include "headers.hpp"

int main(void) {
    srand(0);

    // Set up the chrono
    map<double, string> chronos;
    time_point<system_clock> start, end;
    duration<double> elapsed_time;

#ifdef PART2_3
    // Create a random array
    array<int, static_cast<int>(SIZE)> my_array;
    for (int i = 0; i < SIZE; i++) my_array[i] = rand() % MAX_VALUE;

    // Sort the array
    sort(my_array.begin(), my_array.end());
    printArray(my_array);

    // Search for a value
    start = system_clock::now();
    int search_result1 = searchInArray(SEARCHING, my_array);
    end = system_clock::now();
    elapsed_time = end - start;
    chronos.insert(pair<double, string>(elapsed_time.count(), "searchInArray"));

    cout << SEARCHING;
    if (search_result1 == -1)
        cout << " doesn't exist in the array..." << endl;
    else
        cout << " is located on position : " << search_result1 << endl;
#endif

#ifdef PART4_5
    // Create a random vector
    vector<int> my_vector;
    for (int i = 0; i < SIZE; i++) my_vector.push_back(rand() % MAX_VALUE);

    // Sort the array
    sort(my_vector.begin(), my_vector.end());
    printVector(my_vector);

    // Check if the value exists
    start = system_clock::now();
    bool exists = binary_search(my_vector.begin(), my_vector.end(), SEARCHING);
    end = system_clock::now();
    elapsed_time = end - start;
    chronos.insert(pair<double, string>(elapsed_time.count(), "binary_search"));

    cout << SEARCHING << (exists ? " exists !" : " doesn't exist...") << endl;

    // Search a value
    start = system_clock::now();
    auto search_result2 = searchInVector(SEARCHING, my_vector);
    end = system_clock::now();
    elapsed_time = end - start;
    chronos.insert(
        pair<double, string>(elapsed_time.count(), "searchInVector"));

    cout << SEARCHING;
    if (search_result2 == my_vector.end())
        cout << " doesn't exist in the array..." << endl;
    else
        cout << " is located on position : "
             << distance(my_vector.begin(), search_result2) << endl;

#endif

    // Print the chronos map
    cout << endl << "Timers :" << endl;
    for (const auto &item : chronos)
        cout << item.second << " : " << item.first << "s" << endl;

    return 0;
}

#ifdef PART2_3
void printArray(const array<int, SIZE> &a) {
    cout << "My array : { ";
    int i(0);
    for (const auto &item : a) {
        cout << item << ((i < a.size() - 1) ? ", " : "");
        i++;
    }
    cout << " }" << endl;
}

int searchInArray(const int &value, const array<int, 10> &a) {
    int min(0), max = a.size() - 1;

    // Reduce the search interval
    while (min < max) {
        // Calcul mid
        int mid = (min + max) / 2;

        // Update min and max
        if (a[mid] < value)
            min = mid + 1;
        else
            max = mid;
    }

    // Check if value exists
    return a[min] == value ? min : -1;
}
#endif

#ifdef PART4_5
void printVector(const vector<int> &v) {
    cout << "My vector : { ";
    int i(0);
    for (const auto &item : v) {
        cout << item << ((i < v.size() - 1) ? ", " : "");
        i++;
    }
    cout << " }" << endl;
}

vector<int>::iterator searchInVector(const int &value, vector<int> &v) {
    vector<int>::iterator min = v.begin(), max = v.end();

    // Reduce the search interval
    while (min < max) {
        // Calcul mid iterator
        vector<int>::iterator mid = v.begin();
        int mid_distance = distance(min, max) / 2;
        mid = min + mid_distance;

        // Update min and max
        if (*mid < value)
            min = next(mid);
        else
            max = mid;
    }

    // Check if value exists
    return *min == value ? min : v.end();
}
#endif