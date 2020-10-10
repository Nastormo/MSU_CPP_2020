#include <iostream>
#include <memory>
#include <functional>

class A {
public:
static void * operator new(size_t size) {
    std::cout << "operator new!" << std::endl;
    return ::operator new(size);
}

static void operator delete(void *p, size_t size) {
    std::cout << "operator delete!" << std::endl;
    return ::operator delete(p);
}
};

template <class T>
struct custom_allocator {
std::function<void*(size_t size)> dummy_new;
std::function<void(void *p, size_t size)> dummy_delete;
typedef T value_type;
custom_allocator() noexcept 
    : dummy_new(T::operator new),
      dummy_delete(T::operator delete) 
{}

template <class U> 
custom_allocator (const custom_allocator<U>& other) noexcept 
    : dummy_new(U::operator new), 
      dummy_delete(U::operator delete)
{}

T* allocate (std::size_t n) { 
    std::cout << "operator allocate!" << std::endl;
    return static_cast<T*>(dummy_new(n*sizeof(T))); 
}

void deallocate (T* p, std::size_t n) { 
    std::cout << "operator deallocate!" << std::endl;
    dummy_delete(p, n); 
}
};

int main() {
    auto sp = std::allocate_shared<A>(custom_allocator<A>());
}