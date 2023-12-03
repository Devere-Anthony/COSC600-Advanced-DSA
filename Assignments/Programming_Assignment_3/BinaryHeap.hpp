#include <vector>
#include <iostream>

template <typename T>
class BinaryHeap
{
public:
    explicit BinaryHeap(int capacity = 100)
        : heapArray(1), currentSize{0} {};

    explicit BinaryHeap(const std::vector<T> &items)
        : heapArray(items.size() + 10), currentSize{int(items.size())}
    {
        // copy all items into internal heap array,
        // notice the offset by 1
        for (int i{}; i < items.size(); ++i)
            heapArray[i+1] = items[i];
        
        buildSwaps = buildHeap();
    }

    void insert(const T& x)
    {
        // double allocation size as needed
        if(currentSize == heapArray.size() - 1)
            heapArray.resize(heapArray.size() * 2);

        // percolate up
        int hole = ++currentSize;
        T copy = x;

        heapArray[0] = std::move(copy);
        for(; x < heapArray[hole / 2]; hole /= 2)
        {
            heapArray[hole] = std::move(heapArray[hole/2]);
            buildSwaps++;
        }
        heapArray[hole] = std::move(heapArray[0]);
    }

    std::string GetHeapArrayString() {
      if (currentSize == 0) {
         return std::string("[]");
      }
      
      std::string arrayString("[");
      arrayString += std::to_string(heapArray[1]);
      for (int i = 2; i <= currentSize; i++) {
         arrayString += ", ";
         arrayString += std::to_string(heapArray[i]);
      }
      arrayString += "]";
      return arrayString;
   }

   int GetCurrentSize() {return currentSize;}
   int GetBuildSwaps() {return buildSwaps;}

private:
    int currentSize;   // number of elements in heap
    std::vector<T> heapArray;   // internal heap array
    int buildSwaps{};

    int buildHeap()
    {
        /* build heap in linear time */
        int total_swaps{};
        for (int i = currentSize / 2; i > 0; --i)
        {
            int swaps = percolateDown(i);
            total_swaps += swaps;
        }
        return total_swaps;
    }

    int percolateDown(int hole)
    {
        int child;
        int swaps{};
        T temp = std::move(heapArray[hole]);

        for (; hole * 2 <= currentSize; hole = child)
        {
            child = hole * 2;
            if (child != currentSize && heapArray[child + 1] < heapArray[child])
                ++child;
            if (heapArray[child] < temp)
            {
                heapArray[hole] = std::move(heapArray[child]);
                swaps++;
            }
            else   
                break;
        }
        heapArray[hole] = std::move(temp);
        return swaps;
    }
};