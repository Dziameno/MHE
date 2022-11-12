#include <iostream>
#include <vector>

using box_t = std::vector<int>;

struct bin_t {
    int capacity = 0;
    box_t weight;
};

struct result_bin_t {
    int lose = 0;
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

//box_t count_through_weights(const bin_t &bin) {
//    std::vector<int> result_bin;
//    int max_size = 0;
//    int lose = 0;
//    int bins_required = 1;
//    for (int count: bin.weight) {
//        max_size += count;
//        if (max_size <= bin.capacity) {
//            result_bin.push_back(count);
//            std::cout << ' ';
//        }
//        else{
//            result_bin.push_back(count);
//            std::cout << " | ";
//            max_size = count;
//            bins_required += 1;
//        }
//        std::cout << count;
//    }
//
//    std:: cout << std::endl << "r:" << bins_required << std::endl;
//    std:: cout <<"lose: " << lose;
//    return result_bin;
//}

result_bin_t count_through_weights(const bin_t &bin)
{
    box_t weight;
    int lose = 0;
    int max_size = 0;

    for (int count : bin.weight)
    {
        max_size += count;
        if (max_size > bin.capacity)
        {
            int before_add = max_size - count;
            lose = lose + (bin.capacity - before_add);
            weight.push_back(before_add);
            std::cout << "|";
            max_size = count;
        }
        std::cout << "" << count;
    }

    bin_t temp_bin = {
            .capacity = bin.capacity,
            .weight = weight};

    result_bin_t result_bin = {
            .lose = lose,
            .bin = temp_bin};

    return result_bin;
}

box_t permutation_of_weight(bin_t &bin){
    result_bin_t result;
    while(std::next_permutation(bin.weight.begin(), bin.weight.end())) {
        result_bin_t output = count_through_weights(bin);
        if (output.lose < result.lose || result.lose == 0) {
            result = output;
        }
        std::cout << "\nlose:" << output.lose;
        std::cout << " bins:" << output.bin.weight.size() + 1 << "\n\n";
    }
    std::cout << "Best solution:";
    std::cout << "\nlose:" << result.lose;
    std::cout << " bins:" << result.bin.weight.size() + 1<< std::endl;
        return result.bin.weight;
}


int main() {
    bin_t example = {
            10,
            {2, 7,7,5,2,4},
    };

    permutation_of_weight(example);

    return 0;
}