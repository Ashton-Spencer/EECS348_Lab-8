#include "matrix.hpp"
#include <iostream>
#include <string>
#include <fstream>


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
    std::cout << "8) End Program" << std::endl;
}

int main(int argc, char *argv[]) {
    int input;
    bool matrix_inputed = false;
    std::string fileName;
    std::cout << "Enter File Name: ";
    std::cin >> fileName;
    std::ifstream inputFile(fileName);
    int n;
    inputFile >> n;
    Matrix matrix1 = Matrix(n);
    Matrix matrix2 = Matrix(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            inputFile >> val;
            matrix1.set_value(i, j, val);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            inputFile >> val;
            matrix2.set_value(i, j, val);
        }
    }
    std::cout << "Matrix 1:\n";
    matrix1.print_matrix();
    std::cout << "Matrix 2:\n";
    matrix2.print_matrix();
    while (true) {
        print_options();
        std::cin >> input;
        if (input == 1) {
            std::cout << "Enter File Name: ";
            std::cin >> fileName;
            std::ifstream inputFile(fileName);
            int n;
            inputFile >> n;
            Matrix matrix1 = Matrix(n);
            Matrix matrix2 = Matrix(n);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    int val;
                    inputFile >> val;
                    matrix1.set_value(i, j, val);
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    int val;
                    inputFile >> val;
                    matrix2.set_value(i, j, val);
                }
            }
            std::cout << "Matrix 1:\n";
            matrix1.print_matrix();
            std::cout << "Matrix 2:\n";
            matrix2.print_matrix();
        } else if (input == 2) {
            Matrix result = matrix1 + matrix2;
            std::cout << "Sum of matrices:\n";
            result.print_matrix();
        } else if (input == 3) {
            Matrix result = matrix1 * matrix2;
            std::cout << "Product of matrices:\n";
            result.print_matrix();
        } else if (input == 4) {
            int input2;
            std::cout << "Choose Matrix 1 or 2" << std::endl;
            std::cin >> input2;
            if (input2 == 1) {
                std::cout << "Main diagonal sum: " << matrix1.sum_diagonal_major() << "\n";
                std::cout << "Secondary diagonal sum: " << matrix1.sum_diagonal_minor() << "\n";
            } else if (input2 == 2) {
                std::cout << "Main diagonal sum: " << matrix2.sum_diagonal_major() << "\n";
                std::cout << "Secondary diagonal sum: " << matrix2.sum_diagonal_minor() << "\n";
            }
        } else if (input == 5) {
            int input2;
            std::cout << "Choose Matrix 1 or 2" << std::endl;
            std::cin >> input2;
            std::size_t r1, r2;
            std::cout << "Enter two row indices to swap: ";
            std::cin >> r1 >> r2;
            if (input2 == 1) {
                if (r1 < matrix1.get_size() && r2 < matrix1.get_size()) {
                    matrix1.swap_rows(r1, r2);
                    matrix1.print_matrix();
                } else {
                    std::cout << "Invalid row indices.\n";
                }
            } else if (input2 == 2) {
                if (r1 < matrix2.get_size() && r2 < matrix2.get_size()) {
                    matrix1.swap_rows(r1, r2);
                    matrix1.print_matrix();
                } else {
                    std::cout << "Invalid row indices.\n";
                } 
            }
        } else if (input == 6) {
            int input2;
            std::cout << "Choose Matrix 1 or 2" << std::endl;
            std::cin >> input2;
            if (input2 == 1) {
                std::size_t c1, c2;
                std::cout << "Enter two column indices to swap: ";
                std::cin >> c1 >> c2;
                if (c1 < matrix1.get_size() && c2 < matrix1.get_size()) {
                    matrix1.swap_cols(c1, c2);
                    matrix1.print_matrix();
                } else {
                    std::cout << "Invalid column indices.\n";
                }
            } else if (input2 == 2)  {
                std::size_t c1, c2;
                std::cout << "Enter two column indices to swap: ";
                std::cin >> c1 >> c2;
                if (c1 < matrix2.get_size() && c2 < matrix2.get_size()) {
                    matrix2.swap_cols(c1, c2);
                    matrix2.print_matrix();
                } else {
                    std::cout << "Invalid column indices.\n";
                }
            }
        } else if (input == 7) {
            int input2;
            std::cout << "Choose Matrix 1 or 2" << std::endl;
            std::cin >> input2;
            if (input2 == 1) {
                std::size_t row, col;
                int val;
                std::cout << "Enter row, column, and new value: ";
                std::cin >> row >> col >> val;
                if (row < matrix1.get_size() && col < matrix1.get_size()) {
                    matrix1.set_value(row, col, val);
                    matrix1.print_matrix();
                } else {
                    std::cout << "Invalid indices.\n";
                }
            } else if (input2 == 2) {
                std::size_t row, col;
                int val;
                std::cout << "Enter row, column, and new value: ";
                std::cin >> row >> col >> val;
                if (row < matrix2.get_size() && col < matrix2.get_size()) {
                    matrix2.set_value(row, col, val);
                    matrix2.print_matrix();
                } else {
                    std::cout << "Invalid indices.\n";
                }
            }
        } else if (input == 8){
            break;
        } else {
            std::cout << "Invalid Choice" << std::endl;
        }
    }
    return 0;
}
