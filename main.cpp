#include <iostream>
#include <string>
#include <array>
#include <windows.h>


std::array<std::string, 100> eightbyeight = { "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", 
                                            "X", ".", ".", ".", ".", ".", ".", ".", ".", "X",
                                            "X", ".", ".", ".", ".", ".", ".", ".", ".", "X", 
                                            "X", ".", ".", ".", ".", ".", ".", ".", ".", "X", 
                                            "X", ".", ".", ".", ".", ".", ".", ".", ".", "X",
                                            "X", ".", ".", ".", ".", ".", ".", ".", ".", "X", 
                                            "X", ".", ".", ".", ".", ".", ".", ".", ".", "X", 
                                            "X", ".", ".", ".", ".", ".", ".", ".", ".", "X", 
                                            "X", ".", ".", ".", ".", ".", ".", ".", ".", "X", 
                                            "X", "X", "X", "X", "X", "X", "X", "X", "X", "X"
};

std::array<std::string, 100> eightbyeight_buffer = eightbyeight;
std::array<int, 8> neighbors = { -11, -10, -9, -1, 1, 9, 10, 11 };
int main()
{
    int cell;
    int parsed_cell;
    bool constraint = true;

    std::cout << "  0 1 2 3 4 5 6 7 8 9\n";
    for (int i = 0; i < 10; i++) {
        std::cout << i << " ";
        for (int j = 0; j < 10; j++) {
            std::cout << eightbyeight[i * 10 + j] << " ";
        }
        std::cout << "\n";
    }

    do {
        std::cin >> cell;
        if ((cell > 11) && (cell < 111)) {
            eightbyeight[cell] = "o";
        }
        else {
            constraint = false;
        }
    }
    while (constraint);

    while (true) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                std::cout << eightbyeight[i * 10 + j] << " ";
            }
            std::cout << "\n";
        }

        for (int i = 0; i < 100; i++) {
            if (eightbyeight[i] == "o") {
                int neighbor_count = 0;
                for (int offset : neighbors) {
                    if (eightbyeight[i + offset] == "o") {
                        neighbor_count++;
                    }
                }
                if ((neighbor_count != 2) && (neighbor_count != 3)) {
                    eightbyeight_buffer[i] = ".";
                    continue;
                }
            }

            if (eightbyeight[i] == ".") {
                int neighbor_count = 0;
                for (int offset : neighbors) {
                    if (eightbyeight[i + offset] == "o")
                    {
                        neighbor_count++;
                    }
                }

                if (neighbor_count == 3) {
                    eightbyeight_buffer[i] = "o";
                    continue;
                }
                else {
                    continue;
                }

            }
        }
        std::cout << "\n";
        Sleep(1000);
        eightbyeight = eightbyeight_buffer;
        system("CLS");
    }
}