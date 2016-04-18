template<typename T>
class SharedMatrixPointer
{
public:
    SharedMatrixPointer() :
        data(nullptr),
        counter(new int(0))
    {}

    SharedMatrixPointer(T* data) :
        data(data),
        counter(new int(1))
    {}

    ~SharedMatrixPointer()
    {
        destroy();
    }

    SharedMatrixPointer(const SharedMatrixPointer<T>& other) :
        data(other.data),
        counter(other.counter)
    {
        *counter += 1;
    }

    int useCount() const { return *counter; }

    bool unique() const { return useCount() == 1; }
    bool empty() const { return data == nullptr; }
    void reset(T* data)
    {
        destroy();
        this->data = data;
        *counter = 1;
    }

    T* rawPtr() const { return data; }

    T operator*() { return *data; }

    T& operator[](int i)
    {
        return data[i];
    }

    friend void swap(SharedMatrixPointer<T>& first, SharedMatrixPointer<T>& second)
    {
        using std::swap;

        swap(first.data, second.data);
        swap(first.counter, second.counter);
    }

private:
    void destroy()
    {
        *counter -= 1;
        if (useCount() == 0)
        {
            delete[] data;
            delete counter;
        }
    }

    T* data;
    int* counter;
};
