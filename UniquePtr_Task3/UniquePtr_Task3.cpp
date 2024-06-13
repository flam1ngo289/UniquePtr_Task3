#include <iostream>
#include <Windows.h>

template <typename T>
class MyUniquePtr
{
private:
    T* ptr;  

public:
    explicit MyUniquePtr(T* p = nullptr) : ptr(p) {}

    MyUniquePtr(const MyUniquePtr&) = delete;

    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    T& operator*() const { return *ptr; }

    T* release()
    {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    ~MyUniquePtr()
    {
        delete ptr;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    MyUniquePtr<int> ptr(new int(10));
    std::cout << "Значение: " << *ptr << std::endl;
    int* raw_ptr = ptr.release(); 
    std::cout << "Высвобожденное значение: " << *raw_ptr << std::endl;
    delete raw_ptr; 

    return 0;
}
