#ifndef FIXEDBLOCKMEMORYRESOURCE_HPP
#define FIXEDBLOCKMEMORYRESOURCE_HPP

#include <memory_resource>
#include <vector>
#include <cstddef>

class FixedBlockMemoryResource : public std::pmr::memory_resource {
public:
    FixedBlockMemoryResource(std::size_t block_size) : block_size_(block_size) {
        memory_block_ = new char[block_size_];
        free_blocks_.reserve(block_size_ / sizeof(std::size_t));
    }

    ~FixedBlockMemoryResource() {
        delete[] memory_block_;
    }

protected:
    void* do_allocate(std::size_t bytes, std::size_t alignment) override {
        if (bytes > block_size_) {
            throw std::bad_alloc();
        }

        if (!free_blocks_.empty()) {
            void* ptr = free_blocks_.back();
            free_blocks_.pop_back();
            return ptr;
        }

        if (current_offset_ + bytes > block_size_) {
            throw std::bad_alloc();
        }

        void* ptr = memory_block_ + current_offset_;
        current_offset_ += bytes;
        return ptr;
    }

    void do_deallocate(void* p, std::size_t bytes, std::size_t alignment) override {
        free_blocks_.push_back(p);
    }

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }

private:
    char* memory_block_;
    std::size_t block_size_;
    std::size_t current_offset_ = 0;
    std::vector<void*> free_blocks_;
};

#endif // FIXEDBLOCKMEMORYRESOURCE_HPP