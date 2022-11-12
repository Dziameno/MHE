#include <iostream>
#include <vector>
#include <numeric>

using box_t = std::vector<int>;

struct bin_t {
    int capacity = 0;
    box_t weight;
};

struct result_bin_t {
    int lose = 0;
    int min_bins = 0;
    bin_t bin;
};

std::ostream &operator<<(std::ostream &o, const bin_t &bin) {
    using namespace std;
    o << "weights: ";
    for (int x: bin.weight) {
        o << " " << x << " ";
    }
    return o;
}

result_bin_t count_through_weights(const bin_t &bin) {
    box_t weight;
    int lose = 0;
    int max_size = 0;
    int bins_required = 1;
    int sum_of_weights = 0;

    for (int count: bin.weight) {
        max_size += count;

        if (max_size <= bin.capacity) {
            weight.push_back(count);
            std::cout << " ";

        } else {
            weight.push_back(count);
            std::cout << " | ";
            max_size = count;
            bins_required += 1;
        }
        std::cout << count;
    }

    sum_of_weights = std::accumulate(bin.weight.begin(), bin.weight.end(), decltype(bin.weight)::value_type(0));
    lose = (bin.capacity*bins_required) - sum_of_weights;

    bin_t temp_bin = {
            .capacity = bin.capacity,
            .weight = weight};

    result_bin_t result_bin = {
            .lose = lose,
            .min_bins = bins_required,
            .bin = temp_bin};

    return result_bin;
}

box_t permutation_of_weight(bin_t &bin) {
    result_bin_t result;
    while (std::next_permutation(bin.weight.begin(), bin.weight.end())) {
        result_bin_t output = count_through_weights(bin);
        if (output.lose < result.lose || result.lose == 0 && output.min_bins < result.min_bins ||
            result.min_bins == 0) {
            result = output;
        }
        std::cout << "\n lose:" << output.lose;
        std::cout << " bins:" << output.min_bins << "\n\n";
    }

    std::cout << " Best solution: ";
    int max_size = 0;
    for (auto best: result.bin.weight) {
        max_size += best;
        if (max_size <= bin.capacity) {
            std::cout << " ";
        } else {
            std::cout << " | ";
            max_size = best;
        }
        std::cout << best;
    }
    std::cout << "\n lose:" << result.lose;
    std::cout << " bins:" << result.min_bins << std::endl;
    return result.bin.weight;
}

int main() {
    bin_t example = {
            10,
            {5,2,9,7,6,8,3,2},
    };

    permutation_of_weight(example);

    return 0;
}