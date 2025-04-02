#include "matrix.hpp"
#include <vector>
#include <iostream>

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:
class Matrix {

private:     
    std::vector<std::vector<int>> nums;
    size_t size;

public:
    Matrix::Matrix(size_t N) {
    // initialize an empty NxN matrix
    nums.resize(N, std::vector<int>(N, 0));
    size = N;
}

// e.g. for a member function:

void Matrix::print_matrix() const {
    // print out the matrix
    for (const auto&row : nums) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

Matrix operator+(const Matrix &rhs) const {
    Matrix result_matrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result_matrix.nums[i][j] = nums[i][j] + rhs.nums[i][j];
        }
    }
}

Matrix operator*(const Matrix &rhs) const {

}

void set_value(std::size_t i, std::size_t j, int n) {
    nums[i][j] = n;
}

int get_value(std::size_t i, std::size_t j) const {
    return nums[i][j];
}

int get_size() const {
    return size;
}

int sum_diagonal_major() const {
    int sum;
    int j = 0;
    for (int i = 0; i <size; i++) {
        sum += nums[i][j];
        j++;
    }
    return sum;
}

int sum_diagonal_minor() const {
    int sum;
    int j = size - 1;
    for (int i = 0; i<size; i++) {
        sum += nums[i][j];
        j--;
    }
    return sum;
}

void swap_rows(std::size_t r1, std::size_t r2) {

}

void swap_cols(std::size_t c1, std::size_t c2) {

}
};