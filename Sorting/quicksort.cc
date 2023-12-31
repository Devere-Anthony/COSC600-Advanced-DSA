/* simple implementation of quicksort algorithm */
#include <iostream>
#include <vector>

template<typename T>
void print_vector(std::vector<T>& vec)
{
    std::cout << "(";
    for (int i{}; i < vec.size(); i++)
    {
        if (i == vec.size() - 1)
            std::cout << vec[i] << ")\n";
        else
            std::cout << vec[i] << ", ";
    }
}

template<typename T>
int partition(std::vector<T>& vec, int low_index, int high_index)
{
    /* partitions the elements in an array into two smaller subarrays 
     * primarily for use with the quicksort algorithm 
     */

    // select middle element as pivot
    int midpoint = low_index + (high_index - low_index) / 2;
    T pivot = vec[midpoint];

    // partition into low and high partions 
    bool done = false;

    while (!done) 
    {
        /* shift the indexes and swap as needed to create the 
         * low and high partitions
         */

        // move low index right until an element is >= the pivot element
        while (vec[low_index] < pivot)
            low_index += 1;

        // move right index left until an element is <= the pivot element
        while (pivot < vec[high_index])
            high_index -= 1;

        // if zero or one elments remain, then all the numbers are partitioned
        if (low_index >= high_index)
            done = true;
        else 
        {
            // Swap low and high index values 
            int temp = vec[low_index];
            vec[low_index] = vec[high_index];
            vec[high_index] = temp;

            // update low and high indexes
            low_index += 1;
            high_index -= 1;
        }
    }

    // return the highest index of the low partition
    return high_index;
}

template<typename T>
void quicksort(std::vector<T>& vec, int low_index, int high_index)
{
    // base case: single element list
    if (low_index >= high_index)
        return;
    
    // compute the low index
    int low_end_index = partition(vec, low_index, high_index); 

    // partition and sort low side
    quicksort(vec, low_index, low_end_index);

    // partition and sort high side
    quicksort(vec, low_end_index + 1, high_index);
}

int main()
{
    std::vector<int> v1{4,34,10,25,1};
    std::cout << "Input: "; print_vector(v1); 
    quicksort(v1, 0, 4);
    std::cout << "Output: "; print_vector(v1); std::cout << "\n\n";

    std::vector<int> v2{10,2,78,4,45,32,7,11};
    std::cout << "Input: "; print_vector(v2);
    quicksort(v2, 0, 7);
    std::cout << "Output: "; print_vector(v2); std::cout << "\n\n";

}
