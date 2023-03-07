#include <iostream>
#include <fstream>
#include <string>

int getNumberOfRobbers(int G) {
    int N = 1000, remainingGoldBars;
    bool allRobersTookBars = true;  // checks if all robbers took bars

    for (N; N > 0; N--) {
        remainingGoldBars = G;
        allRobersTookBars = true;
        for (int j = 0; j < N; j++) {
            // robbers can only take golden bars if remainder of remainingGoldBars and N is 1
            if (remainingGoldBars % N == 1) {   
                remainingGoldBars -= remainingGoldBars / N + 1;
            }
            else {
                allRobersTookBars = false;
                break;
            }
        }
        // if remainingGoldBars can be divided by N and all robbers took bars, return the number of robbers as the solution
        if (remainingGoldBars % N == 0 && allRobersTookBars) return N;
    }
    return 0;   // if solution wasn't found, return 0
}

int main(int argc, char* argv[])
{
    if (argc != 2) return -1;

    std::ifstream infile(argv[1]);
    std::ofstream outfile("output.txt");

    int G, N;  // number of gold bars

    if (infile.is_open()) {   // checking whether the file is open
        while (infile >> G) {   // read line by line
            if (G == -1) break;
            std::string output = "st. zlatih palic: " + std::to_string(G) + " - ";

            std::cout << "st. zlatih palic: " << G << " - ";
            N = getNumberOfRobbers(G);
            if (N != 0) {
                std::cout << "st. roparjev: " << N << "\n";
                output += "st. roparjev: " + std::to_string(N) + "\n";
            }
            else {
                std::cout << "ni resitve!\n";
                output += "ni resitve!\n";
            }

            outfile << output;
        }
    }

    outfile.close();


    // check for possible results
    //int results[1000];
    //memset(results, 0, sizeof(results));

    //for (G = 1; G < INT_MAX; G++) {
    //    results[getNumberOfRobbers(G)]++;
    //}

    //for (int i = 0; i < sizeof(results) / sizeof(int); i++) {
    //    std::cout << "Result: " << i << ", number: " << results[i] << "\n";
    //}
}
