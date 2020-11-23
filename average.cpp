// Copyright (c) 2020 Marcus A. Mosley All rights reserved.
//
// Created by Marcus A. Mosley
// Created on November 2020
// This program finds the average of a 2D array

#include <iostream>
#include <iomanip>
#include <random>


template <int rows, int cols>
float array_average(int (&passed_number_array)[rows][cols]) {
    // This function finds the average of a 2D array

    int sum = 0;

    for (size_t row_value = 0; row_value < rows; ++row_value) {
        for (size_t column_value = 0; column_value < cols; ++column_value)
            sum += passed_number_array[row_value][column_value];
    }

    float average = sum / 6;

    return average;
}


int main() {
    // This function receives input

    int number;
    float average = 0;
    const int rows = 3;
    const int columns = 2;
    int number_array[rows][columns];

    // Input

    for (int row_value = 0; row_value < rows; row_value++) {
        for (int column_value = 0; column_value < columns; column_value++) {
            std::random_device random_device;
            std::mt19937 engine{random_device()};
            std::uniform_int_distribution<> dist(1, 50);
            number = dist(engine);
            number_array[row_value][column_value] = number;
            std::cout << "The random number is: "
                << std::fixed << number << std::endl;
        }
    }
    std::cout << " " << std::endl;

    // Call Functions
    average = array_average(number_array);

    std::cout << "The average is " << std::setprecision(2) << average
    << std::endl;
}
