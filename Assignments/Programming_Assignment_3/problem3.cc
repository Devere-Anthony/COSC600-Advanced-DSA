/* Filename: problem3.cc
 *
 * Author: Devere Anthony Weaver 
 * 
 * Assignment: Programming Assignment 3
 * Problem: Problem 3
 * 
 * Description: This program implements the count sort algorithm and uses it to
 * sort a vector of randomized values. 
 */

#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <vector>

template <typename T>
void print_vector(std::vector<T> &vec)
{
    std::cout << "(";
    for (int i{}; i < vec.size(); i += 100)
    {
        if (i == 4900)
            std::cout << vec[i] << ")\n";
        else 
            std::cout << vec[i] << ", ";
    }
}

template <typename T>
void countSort(std::vector<T> &vec)
{
    /* implementation of count sort algorithm */
    std::vector<int> output(vec.size());
    std::vector<int> count(vec.size());
    int max{vec[0]};

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] > max)
            max = vec[i];
    }

    for (int i = 0; i < vec.size(); i++)
        count[vec[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        output[count[vec[i]] - 1] = vec[i];
        count[vec[i]]--;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = output[i];
    }

    print_vector(vec);
}

std::vector<int> generate_random(int low, int high, int n)
{
    /* generate n random numbers in the interval [low, high] */
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(low, high);
    std::vector<int> v{};
    for (int i = 0; i < n; i++)
        v.push_back(distr(gen));
    return v;
}

int main()
{
    std::cout << "Count Sort:\n";
    std::vector<int> vec = generate_random(0, 500, 5000);
    std::cout << "Input (every 100th): ";
    print_vector(vec);
    std::cout << "\nOutput (every 100th): ";
    auto start = std::chrono::high_resolution_clock::now();
    countSort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "\n\nExecution time: " << duration.count() << " nanoseconds.\n";
}