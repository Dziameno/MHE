#include <iostream>
#include <vector>
#include <numeric>

struct bin_t {
    int capacity;
    std::vector<int> weight;
};

std::ostream &operator<<(std::ostream &o, const bin_t &bin) {
    using namespace std;
    o << "weights: ";
    for (int x: bin.weight) {
        o << " " << x << " ";
    }
    return o;
}

std::vector<int> count_through_weights(const bin_t &bin) {
    std::vector<int> single_bin;
    int max_size = 0;
    int lose = 0;
    int bins_required = 0;
    std::cout << '|';
    for (int count: bin.weight) {
        max_size += count;
        if (max_size <= bin.capacity) {
            single_bin.push_back(count);
            std::cout << count;
//            for(std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
//                sum_of_elems += *it;
//            lose = bin.capacity -single_bin.size();
//            std::cout << lose;
        }
        else{
            std::cout << '|';
            single_bin.push_back(count);
            std::cout << count << "|";
            max_size = 0;
            bins_required += 2;
        }
    }
    std::cout << '|' << std::endl;
    std:: cout <<"bins required: " << bins_required;
    return single_bin;
}

std::vector<int> signle_bin(){

}


int main() {
    using namespace std;
    std::vector<int> result_bins;
    bin_t example = {
            10,
            {2, 7,7,5,3,8,2},
    };


    cout << example << endl;
    count_through_weights(example);
//    cout << '|';
//    for (auto bin: count_through_weights(example)) {
//        cout << bin;
//    }
//    cout << '|';

    return 0;
}