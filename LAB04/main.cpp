#include <iostream>
#include <vector>
#include <numeric>
#include <random>

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

result_bin_t bin_and_lose_counter(const bin_t &bin) {
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

box_t next_permutation_of_weight(bin_t bin, int iterations) {
    result_bin_t result;
        for(int i = 0; i < iterations; i++) {
            std::next_permutation(bin.weight.begin(), bin.weight.end());
            result_bin_t output = bin_and_lose_counter(bin);
            if (output.lose < result.lose || result.lose == 0 && output.min_bins < result.min_bins ||
                result.min_bins == 0) {
                result = output;
            }
            std::cout << std::endl << i << " ";
            std::cout << output.lose << " ";
            std::cout << output.min_bins << std::endl;
        }


    std::cout << "\n\nBruteforce best" << std::endl;
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
    std::cout << std::endl << "i:" << iterations << " ";
    std::cout << "l:" << result.lose << " ";
    std::cout << "b:" << result.min_bins << "\n\n";

    return result.bin.weight;
}

box_t random_sampling(bin_t bin, int iterations) {
    result_bin_t result;
    std::random_device rd;
    std::mt19937 g(rd());
    for(int i = 0; i < iterations; i++) {
        std::shuffle(bin.weight.begin(), bin.weight.end(),g);
            result_bin_t output = bin_and_lose_counter(bin);
            if (output.lose < result.lose || result.lose == 0 && output.min_bins < result.min_bins ||
                result.min_bins == 0) {
                result = output;
            }
        std::cout << std::endl << i << " ";
        std::cout << output.lose << " ";
        std::cout << output.min_bins << std::endl;
    }

    std::cout << "\n\nRandom sampling best" << std::endl;
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
    std::cout << std::endl << "i:" << iterations << " ";
    std::cout << "l:" << result.lose << " ";
    std::cout << "b:" << result.min_bins << "\n\n";

    return result.bin.weight;
}

bin_t generate_random_solution(int iterations){
    result_bin_t result;
    static std::random_device rd;
    static std::mt19937 mt(rd());
    bin_t rand_sol;
    int random_capacity = rand_sol.capacity;
    std::uniform_int_distribution<int> cap(1,100);
    random_capacity = cap(mt);
    std::uniform_int_distribution<int> dist(1,random_capacity);

    for(int i = 0; i < iterations; i++){
        rand_sol.weight.push_back(dist(mt)) ;
    }

    bin_t insert_bin = {
            .capacity = random_capacity,
            .weight = rand_sol.weight};

    return insert_bin;
}


int main() {
        bin_t example = {
            10,
            {5,2,9,7,6,2,10,5,4},
    };

    next_permutation_of_weight(example, 5);
    random_sampling(example,10);


}