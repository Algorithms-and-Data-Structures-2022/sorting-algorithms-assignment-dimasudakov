#include "assignment/merging.hpp"

#include <cassert>    // assert
#include <algorithm>  // copy

namespace assignment {

  void merge(std::vector<int>& arr, int start, int middle, int stop, std::vector<int>& buf) {
    assert(start >= 0 && start < arr.size() && stop >= start && stop < arr.size() && middle >= start && middle <= stop);

    int left_offset = start;
    int right_offset = middle + 1;

    int buf_offset = 0;

    while (left_offset <= middle && right_offset <= stop) {
      if(arr[left_offset] < arr[right_offset]) {
        buf[buf_offset] = arr[left_offset];
        left_offset++;
      } else {
        buf[buf_offset] = arr[right_offset];
        right_offset++;
      }
      buf_offset++;
    }

    while(left_offset <= middle) {
      buf[buf_offset++] = arr[left_offset++];
    }
    while(right_offset <= stop) {
      buf[buf_offset++] = arr[right_offset++];
    }

    for(int i = start; i <= stop; i++) {
      arr[i] = buf[i - start];
    }
  }

}  // namespace assignment