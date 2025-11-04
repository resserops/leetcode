#pragma once
#include <cassert>
#include <cstddef>
#include <unordered_set>
#include <vector>

template <typename T>
class Tracker {
public:
    static void *operator new(std::size_t count) {
        assert(count == sizeof(T));
        void *ptr{::operator new(count)};
        activeObjects_.insert(static_cast<T *>(ptr));
        return ptr;
    }

    static void operator delete(void *ptr) {
        assert(ptr != nullptr);
        activeObjects_.erase(static_cast<T *>(ptr));
        ::operator delete(ptr);
    }

    static void *operator new[](std::size_t count) {
        assert(count % sizeof(T) == 0);
        void *ptr{::operator new[](count)};
        activeArrays_.insert(static_cast<T *>(ptr));
        return ptr;
    }

    static void operator delete[](void *ptr) {
        assert(ptr != nullptr);
        activeArrays_.erase(static_cast<T *>(ptr));
        ::operator delete(ptr);
    }

    static void Clear() {
        std::vector<T *> activeObjects(activeObjects_.begin(), activeObjects_.end());
        for (T *object : activeObjects) {
            delete object;
        }
        std::vector<T *> activeArrays(activeArrays_.begin(), activeArrays_.end());
        for (T *array : activeArrays) {
            delete[] array;
        }
    }

protected:
    Tracker() = default;

private:
    static inline std::unordered_set<T *> activeObjects_;
    static inline std::unordered_set<T *> activeArrays_;
};
