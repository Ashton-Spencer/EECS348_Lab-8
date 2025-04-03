#include "matrix.hpp"
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[]) {
    int input;
    bool matrix_inputed = false;
    while (1) {
        print_options();
        std::cin >> input;
        if (input == 1) {
        std::string fileName;
        std::cout << "Enter File Name" << std::endl;
        std::cin >> fileName;
        std::ifstream inputFile(fileName);
        int n;
        std::getline(inputFile, n);
        Matrix matrix1(n);
        Matrix matrix2(n);
        } else if (input == 2 && matrix_inputed == true) {
            matrix1 + matrix2;
        } else if (input == 3 && matrix_inputed == true) {
            
        } else if (input == 4 && matrix_inputed == true) {
            
        } else if (input == 5 && matrix_inputed == true) {
            
        } else if (input == 6 && matrix_inputed == true) {
            
        } else if (input == 7 && matrix_inputed == true) {
            
        } else if (matrix_inputed == false){
            std::cout << "Matrix Not inputed" << std::endl;
        }else {
            std::cout << "Invalid Choice" << std::endl;
        }
    }
    return 0;
}

void print_options() 
{
    std::cout << "Choose an Option" << std::endl;
    std::cout << "1) Read Values from File" << std::endl;
    std::cout << "2) Add Two Matrices and Display Result" << std::endl;
    std::cout << "3) Multiply Two Matrices and Display Result" << std::endl;
    std::cout << "4) Get the Sum of Matrix Diagonal Elements" << std::endl;
    std::cout << "5) Swap Matrix Rows and Display the Result" << std::endl;
    std::cout << "6) Swap Matrix Columns and Display the Result" << std::endl;
    std::cout << "7) Update Matrix Rows and Display the Result" << std::endl;
}