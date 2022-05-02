#include <iostream>
#include <vector>
void simpleSelectionSort(std::vector<int> vi)
{
    int n = vi.size();
    // One by one move boundary of unsorted subviay
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted viay
        int min_index = i;
        for (int j = i + 1; j < n; j++)
            if (vi[j] < vi[min_index])
                min_index = j;
        // Swap the found minimum element with the first element
        std::swap(vi[min_index], vi[i]);
    }
}


// A function to implement bubble sort
void bubbleSort(std::vector<int> vi) {
    bool flag = false;
    int n = vi.size();
    for (int i = 0; i < n - 1; i++){
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++)
            if (vi[j] > vi[j + 1]) {
                std::swap(vi[j], vi[j + 1]);
                flag = true;
            }
    if (!flag) {
        break;
    }
    }
}

void insertionSort(std::vector<int> &vi)
{
    int n = vi.size();
    for (int i = 1; i < n; i++){
        // i is remaining
        int tmp = vi[i]; //get a element tmp
        int j = i - 1;
        for (; j >= 0; j--) {
            // j is sorted, the loop for insert tmp
            // naturally, this could binary search. but me use
            // iterative every element.
            if (vi[j] > tmp)
                vi[j + 1] = vi[j];
        }
        vi[j + 1] = tmp;
    }
}


void printarray(std::vector<int> const &vi)
{
  for (auto x : vi){
    std::cout << x << " ";
  } 
  std::cout << std::endl;
}

int main()
{
    std::vector<int> vi = {64, 25, 12, 22, 11};
    insertionSort(vi);
    std::cout << "Sorted array: \n";
    printarray(vi);
    return 0;
}

