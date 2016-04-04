template<typename T>
class SharedMatrixPointer
{
public:
    SharedMatrixPointer() :
        data(nullptr),
        counter(0)
    {}

    SharedMatrixPointer(T* data) :
        data(data),
        counter(1)
    {}

    ~SharedMatrixPointer()
    {
        destroy();
    }

    SharedMatrixPointer(const SharedMatrixPointer<T>& other) :
        data(other.data),
        counter(other.useCount() + 1)
    {

    }

    int useCount() const { return counter; }

    bool unique() const { return useCount() == 1; }
    bool empty() const { return data == nullptr; }
    void reset(T* data)
    {
        destroy();
        this->data = data;
    }

    T* rawPtr() const { return data; }

    T operator*() { return *data; }

    T& operator[](int i)
    {
        return data[i];
    }

private:
    void destroy()
    {
        counter--;
        if (useCount() == 0)
            delete[] data;
    }

    T* data;
    int counter;
};
