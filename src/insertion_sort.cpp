#include "assignment/insertion_sort.hpp"

#include <utility>  // move, swap

#include "assignment/partitioning.hpp"  // middle_of

namespace assignment {

  int linear_search(const std::vector<int>& arr, int index) {
    for (int i = 0; i < index; i++) {
      if(arr[i] > arr[index]) return i;
    }

    return index;
  }

  int binary_search(const std::vector<int>& arr, int index) {

    int l = -1, r = index;
    while(l + 1 < r) {
      int middle = (l + r) >> 1;
      if(arr[middle] > arr[index]) {
        r = middle;
      } else {
        l = middle;
      }
    }

    return r;
  }

  void InsertionSort::Sort(std::vector<int>& arr) const {

    for (int index = 1; index < static_cast<int>(arr.size()); index++) {
      const int ins_index = searcher_(arr, index);
      if (ins_index != index) {
        int value = arr[index];
        for (int i = index - 1; i >= ins_index; i--)
          arr[i + 1] = arr[i];
        arr[ins_index] = value;
      }
    }

  }
  InsertionSort::InsertionSort(Searcher searcher) : searcher_{std::move(searcher)} {}

}  // namespace assignment