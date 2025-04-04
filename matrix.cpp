#include "matrix.hpp"
#include <vector>
#include <iostream>

Matrix::Matrix(std::size_t N) : size(N) {
    nums.resize(N, std::vector<int>(N, 0));
}

Matrix::Matrix(const std::vector<std::vector<int>>& nums) : nums(nums), size(nums.size()) {}

void Matrix::print_matrix() const {
    for (const auto& row : nums) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::operator+(const Matrix &rhs) const {
    Matrix result(size);
    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < size; ++j) {
            result.nums[i][j] = nums[i][j] + rhs.nums[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    Matrix result(size);
    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < size; ++j) {
            for (std::size_t k = 0; k < size; ++k) {
                result.nums[i][j] += nums[i][k] * rhs.nums[k][j];
            }
        }
    }
    return result;
}

void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    if (i < size && j < size) {
        nums[i][j] = n;
    }
}

int Matrix::get_value(std::size_t i, std::size_t j) const {
    if (i < size && j < size) {
        return nums[i][j];
    }
    return 0;
}

std::size_t Matrix::get_size() const {
    return size;
}

int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i) {
        sum += nums[i][i];
    }
    return sum;
}

int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i) {
        sum += nums[i][size - 1 - i];
    }
    return sum;
}

void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 < size && r2 < size) {
        std::swap(nums[r1], nums[r2]);
    }
}

void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 < size && c2 < size) {
        for (std::size_t i = 0; i < size; ++i) {
            std::swap(nums[i][c1], nums[i][c2]);
        }
    }
}