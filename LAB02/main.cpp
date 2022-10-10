#include <iostream>
#include <vector>

struct bin_t {
    int weight_list_size;
    int capacity; // pojemność pojemnika
    std::vector<int> weight;
    std::vector<std::string> bin_sum;
};

/**
 * -1 values are in "bag"
 */

std::ostream &operator<<(std::ostream &o, const bin_t &bin) {
    using namespace std;
    o << "weights: ";
    for (int x = 0; x < bin.weight.size(); x++) {
        o << "*" << bin.weight[x] << "* ";
    }
    o << endl << "bins: ";
    for (int y = 0; y < bin.bin_sum.size(); y++) {
        o << "|" << bin.bin_sum[y]<< "| ";
    }
    return o;
}

int main() {
    using namespace std;
    std::vector<int> result_bins;
    bin_t example_v1 = {
            7,
            10,
            {2, 5, 4, 7,1, 3, 8},
            { "8+2", "7+3", "5+4+1" }
    };
    cout << example_v1 << endl;
    return 0;
}