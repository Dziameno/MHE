#include <fstream>
#include <iostream>
#include "json.hpp"
#include <string>

int main(int argc, char **argv) {
    using namespace std;
    std::ifstream file("E:\\CODE\\SEM V\\MHE\\LAB01\\data\\input.json");
    nlohmann::json data = nlohmann::json::parse(file);

    string txt = data["text"];
    int height = data["h"];
    int width = data["w"];
    
    for (int i = 0; i < height; i++) {
        cout << "#";
        for (int length = 1; length < width - 1; length++) {
            if (i == 1 && length <= txt.size()) {
                cout << txt;
                break;
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