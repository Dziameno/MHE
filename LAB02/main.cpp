#include <iostream>
#include <vector>

struct bin_t {
    int weight_list_size;
    int capacity;
    std::vector<int> weight;
    std::vector<std::string> bin_sum;
};

std::ostream &operator<<(std::ostream &o, const bin_t &bin) {
    using namespace std;
    o << "weights: ";
    for (int x : bin.weight) {
        o << "*" << x << "* ";
    }
    o << endl << "bins: ";
    for (const auto & y : bin.bin_sum) {
        o << "|" << y<< "| ";
    }
    return o;
}

/*
 *
 */

int main() {
    using namespace std;
    vector<int> result_bins;

    bin_t example_v1 = {
            7,
            10,
            {2, 5, 4, 7,1, 3, 8},
            {"","","","",""}
    };

    bin_t solution_v1 = {
            7,
            10,
            {2, 5, 4, 7,1, 3, 8},
            { "8+2", "7+3", "5+4+1", "","" }
    };

    cout << example_v1 << endl;
    cout << solution_v1 << endl;
    return 0;
}
