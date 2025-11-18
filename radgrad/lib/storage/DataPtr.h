#ifndef RADGRAD_LIB_STORAGE_DATAPTR_H_
#define RADGRAD_LIB_STORAGE_DATAPTR_H_


#include <cstddef>
#include <memory>

namespace radgrad {

// Provides a custom deleter implementation for a
// std::unique_ptr<void> that allows for custom deletion
// of the underlying data.
class DataPtr {
    public:
        DataPtr(void* data, size_t size);
    private:
        std::unique_ptr<void> data_;
    };

} // namespace radgrad

#endif // RADGRAD_LIB_STORAGE_DATAPTR_H_
