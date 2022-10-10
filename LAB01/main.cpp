#include <fstream>
#include <iostream>
#include "json.hpp"
#include <string>

int main(int argc, char **argv) {
    using namespace std;

    string file = argv[1];
    std::ifstream f(file);
    nlohmann::json data = nlohmann::json::parse(f);

    string txt = data["text"];
    int height = data["h"];
    int width = data["w"];
    int horizontal_center = (width-1)/2;
    int vertical_center = (height-1)/2;
    int iteration = 0;


    for (int i = 0; i < height; i++) {
        cout << "#";
        for (int txt_length = 1; txt_length < width - 1; txt_length++) {
            if (i == vertical_center  && txt_length >= horizontal_center - (txt_length/2) && txt.size() >= iteration) {
                cout << txt[iteration];
                iteration++;
            }
            else if (i > 0 && i < height - 1) {
                cout << " ";
            }
            else
                cout << "#";
        }
        cout << "#\n";
    }
    return 0;
}