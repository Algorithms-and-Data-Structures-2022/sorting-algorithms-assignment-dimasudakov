#include "assignment/partitioning.hpp"

#include <utility>  // swap
#include <cassert>  // assert

namespace assignment {

  int median_of_three(const std::vector<int>& arr, int start, int stop) {
    assert(!arr.empty() && start >= 0 && stop < arr.size() && start <= stop);

    const int size = stop - start + 1;

    if (size < 3) {
      return stop;
    }

    const int middle = middle_of(start, stop);

    int a = arr[start], b = arr[middle], c = arr[stop];

    if((b <= a && a <= c) || (c <= a && a <= b)) return start;
    if((a <= b && b <= c) || (c <= b && b <= a)) return middle;
    if((a <= c && c <= b) || (b <= c && c <= a)) return stop;
  }

  int partition(std::vector<int>& arr, int start, int stop, int pivot) {
    assert(pivot >= start && pivot <= stop);
    assert(!arr.empty() && start >= 0 && stop < arr.size() && start <= stop);

    const int pivot_value = arr[pivot];

    std::swap(arr[pivot], arr[stop]);

    int curr_pivot_index = start;

    for (int index = start; index < stop; index++) {
      if (arr[index] < pivot_value) {
        std::swap(arr[curr_pivot_index], arr[index]);
        curr_pivot_index++;
      }
    }

    std::swap(arr[curr_pivot_index], arr[stop]);

    return curr_pivot_index;
  }

}  // namespace assignment