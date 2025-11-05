#ifndef RADGRAD_LIB_TENSOR_TENSOR_H_
#define RADGRAD_LIB_TENSOR_TENSOR_H_


namespace radgrad {
namespace tensor {

class Tensor {
  public:
    // // Constructor: create tensor from shape and data pointer
    // Tensor(const std::vector<size_t>& shape, float* data, bool owns_data = false);
    
    // // Constructor: create tensor from shape and copy data
    // Tensor(const std::vector<size_t>& shape, const float* data);
    
    // // Constructor: create tensor with uninitialized data
    // explicit Tensor(const std::vector<size_t>& shape);
    
    // // Destructor
    // ~Tensor();
    
    // // Copy Constructor
    // Tensor(const Tensor& other);
    
    // // Copy Assignment Operator
    // Tensor& operator=(const Tensor& other);
    
    // // Move Constructor
    // Tensor(Tensor&& other) noexcept;
    
    // // Move Assignment Operator
    // Tensor& operator=(Tensor&& other) noexcept;

    void SayHello();
    
};

} // namespace tensor 
} // namespace radgrad

#endif // RADGRAD_LIB_TENSOR_TENSOR_H_
