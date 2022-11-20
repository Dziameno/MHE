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

box_t permutation_of_weight(bin_t bin) {
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

bin_t insert(){
    int capacity, list_size, weight;
    box_t weights;

    std::cout << "Insert capacity :";
    std::cin >> capacity;
    std::cout << "Insert how many packages you want to pack :";
    std::cin >> list_size;


    for (int i = 0; i < list_size; i++){
        std::cout << "Insert weight :";
        std::cin >> weight;
        if(weight > capacity){
            std::cout << "Bin to small" << std::endl;
            list_size += 1;
        } else {
            weights.push_back(weight);
        }
    }

    bin_t insert_bin = {
            .capacity = capacity,
            .weight = weights};

    return insert_bin;
}

int main() {
//        bin_t example = {
//            10,
//            {5,2,9,7,6},
//    };
//    permutation_of_weight(example);

    int option;

    std::cout << "1 - bruteforce\n"
                 "2 - slice sampling\n"
                 "3 - deterministic hill climbing\n"
                 "4 - hill climbing\n";
    std::cout << "Wybierz opcje :";
    std:: cin >> option;

    switch (option){
        case 1:
            permutation_of_weight(insert());
            break;
        case 2:
            std::cout << "slice sampling" << std::endl;
            break;
        case 3:
            std::cout << "deterministic" << std::endl;
            break;
        case 4:
            std::cout << "hill climbing" << std::endl;
            break;
    }


    return 0;
}