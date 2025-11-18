#ifndef RADGRAD_LIB_TENSOR_SHAPE_H_
#define RADGRAD_LIB_TENSOR_SHAPE_H_


#include <vector>
#include <cstddef>

namespace radgrad {

// Shape manipulation helpers
// Utilities for working with tensor shapes and dimensions
class Shape {
    public:
        Shape(const std::vector<size_t>& shape);
        size_t size() const;
        size_t dims() const;
        size_t shape(size_t index) const;
        size_t& operator[](size_t index);
        const size_t& operator[](size_t index) const;
        bool operator==(const Shape& other) const;
        bool operator!=(const Shape& other) const;
    private:
        std::vector<size_t> shape_;
};

} // namespace radgrad

#endif // RADGRAD_LIB_TENSOR_SHAPE_H_

