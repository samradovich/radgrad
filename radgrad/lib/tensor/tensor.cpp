#include "radgrad/lib/tensor/tensor.h"
#include <stdio.h>

namespace radgrad {
namespace tensor {

void tensor::display() {
  printf("tensor: %d\n", data);
}

} // namespace tensor
} // namespace radgrad
