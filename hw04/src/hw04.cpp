#include <hw04.h>

size_t hw04(const int* input_array, size_t elem_count) {
  int* out_data = new int[1];
  size_t out_data_size = 1;
  size_t current_index = 0;
  int sum = 0;

  for (size_t i = 0; i < elem_count; ++i) {
    if (input_array[i] < 0) {
      break;
    }

    if (current_index >= out_data_size) {
      int* new_out_data = new int[out_data_size * 2];
      for (size_t j = 0; j < out_data_size; ++j) {
        new_out_data[j] = out_data[j];
      }
      delete[] out_data;
      out_data = new_out_data;
      out_data_size *= 2;
    }

    out_data[current_index] = input_array[i];
    sum += input_array[i];
    current_index++;
  }

  delete[] out_data;
  return sum;
}
