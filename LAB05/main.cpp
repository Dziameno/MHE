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
//            std::cout << " ";

        } else {
            weight.push_back(count);
//            std::cout << " | ";
            max_size = count;
            bins_required += 1;
        }
//        std::cout << count;
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

void print_best(bin_t bin, result_bin_t result, int best_itr){
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
    std::cout << std::endl << "i:" << best_itr << " ";
    std::cout << "l:" << result.lose << " ";
    std::cout << "b:" << result.min_bins << "\n\n";
}

box_t bruteforce(bin_t bin, int iterations) {
    result_bin_t result;
    int best_itr = 0;
    for(int i = 0; i < iterations; i++) {
        std::next_permutation(bin.weight.begin(), bin.weight.end());
        result_bin_t output = bin_and_lose_counter(bin);
        if (output.lose < result.lose || result.lose == 0 && output.min_bins < result.min_bins ||
            result.min_bins == 0) {
            best_itr = i;
            result = output;

        }
//            print_best(output.bin, output, i);
    }


    std::cout << "\n\nBruteforce best" << std::endl;
    print_best(bin, result, best_itr);
    return result.bin.weight;
}

box_t random_sampling(bin_t bin, int iterations) {
    result_bin_t result;
    int best_itr;
    std::random_device rd;
    std::mt19937 g(rd());
    for(int i = 0; i < iterations; i++) {
        std::shuffle(bin.weight.begin(), bin.weight.end(),g);
        result_bin_t output = bin_and_lose_counter(bin);
        if (output.lose < result.lose || result.lose == 0 && output.min_bins < result.min_bins ||
            result.min_bins == 0) {
            best_itr = i;
            result = output;
        }
//        print_best(output.bin, output, i);
    }

    std::cout << "\n\nRandom sampling best" << std::endl;
    print_best(bin, result, best_itr);
    return result.bin.weight;
}

int evaluate(bin_t bin, result_bin_t result){
    int max_size = 0;
    for (auto best: result.bin.weight) {
        max_size += best;
        if (max_size <= bin.capacity) {
        } else {
            max_size = best;
        }
    }

    return result.lose;
}

bin_t generate_random_solution(bin_t bin) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(bin.weight.begin(), bin.weight.end(),g);

    return bin;
}

bin_t randomize_solution(bin_t bin) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<int> uniform(0, bin.weight.size() - 1);
    int first_random_index = uniform(g);
    std::uniform_int_distribution<int> uniform2(0, bin.weight.size() - 1);
    int second_random_index = uniform2(g);

    std::swap(bin.weight[first_random_index], bin.weight[second_random_index]);

    return bin;
}

bin_t hill_climb_det(bin_t bin, int iterations) {
    result_bin_t result;
    int best_itr;
    for(int i = 0; i < iterations; i++) {
        bin_t output = randomize_solution(bin);
        result_bin_t output_result = bin_and_lose_counter(output);
        if (output_result.lose < result.lose || result.lose == 0 && output_result.min_bins < result.min_bins ||
            result.min_bins == 0) {
            best_itr = i;
            result = output_result;
            bin = output;
        }
//        print_best(output, output_result, i);
    }

    std::cout << "\n\nHill climbing det best" << std::endl;
    print_best(bin, result, best_itr);
    return bin;

}


bin_t hill_climb_random(bin_t bin, int iterations){
    result_bin_t result;
    int best_itr = 0;
    bin_t best_solution = generate_random_solution(bin);
    result_bin_t best_result = bin_and_lose_counter(best_solution);
    std::cout << std::endl;
    for(int i = 0; i < iterations; i++) {
        std::vector<bin_t> neighbors;
        neighbors.push_back(randomize_solution(best_solution));
        neighbors.push_back(best_solution);
        for (auto neighbor: neighbors) {
            result_bin_t output = bin_and_lose_counter(neighbor);
            if (output.lose < best_result.lose || best_result.lose == 0 && output.min_bins < best_result.min_bins ||
                best_result.min_bins == 0) {
                best_itr = i;
                best_result = output;
                best_solution = neighbor;
            }
        }
//        print_best(bin, best_result, i);
    }

    std::cout << "\n\nHill climb random best" << std::endl;
    print_best(bin, best_result, best_itr);
    return best_solution;

}

bin_t tabu_search(bin_t bin, int iterations){
    result_bin_t result;
    int best_itr = 0;
    bin_t best_solution = generate_random_solution(bin);
    result_bin_t best_result = bin_and_lose_counter(best_solution);

    std::vector<bin_t> tabu_list;
    tabu_list.push_back(best_solution);
    std::cout << std::endl;
    for(int i = 0; i < iterations; i++) {
        std::vector<bin_t> neighbors;
        neighbors.push_back(randomize_solution(best_solution));
        neighbors.push_back(best_solution);
        for (auto neighbor: neighbors) {
            result_bin_t output = bin_and_lose_counter(neighbor);
            if (output.lose < best_result.lose || best_result.lose == 0 && output.min_bins < best_result.min_bins ||
                best_result.min_bins == 0) {
                best_itr = i;
                best_result = output;
                best_solution = neighbor;
            }
        }

        tabu_list.push_back(best_solution);
        if (tabu_list.size() > 10) {
            tabu_list.erase(tabu_list.begin());
        }

    }

    std::cout << "\n\nTabu search best" << std::endl;
    print_best(bin, best_result, best_itr);
    return best_solution;

}

int main() {
    bin_t example = {
            9,
            {6,6,5,5,5,4,4,4,4,2,2,2,2,
             3,3,7,7,5,5,8,8,4,4,5}

    };

    int i = 10000;
    bruteforce(example, i);
    random_sampling(example,i);
    hill_climb_det(example, i);
    hill_climb_random(example, i);
    tabu_search(example, i);


}