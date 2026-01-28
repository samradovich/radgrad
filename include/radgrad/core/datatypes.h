#ifndef RADGRAD_CORE_DATATYPES_H
#define RADGRAD_CORE_DATATYPES_H

#include <cstddef>
#include <cstdint>
#include <vector>

namespace radgrad {
namespace core {

    enum class DataType : uint8_t {
        F16,
        F32,
        F64,
        I16,
        I32,
        I64
    };

    using Shape = std::vector<size_t>;
    using Strides = std::vector<size_t>;

    // Type traits, helpers, etc.

} // namespace core
} // namespace radgrad

#endif
