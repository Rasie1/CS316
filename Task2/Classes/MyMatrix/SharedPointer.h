class ReferenceCounter
{
private:
    int counter;

public:
    void add()
    {
        counter++;
    }

    int release()
    {
        return --counter;
    }

    bool unique()
    {
        return counter == 1;
    }
};

template<typename T>
class SharedPointer
{
private:
    T* data;
    ReferenceCounter* reference;

public:
    SharedPointer() :
        data(0),
        reference(0)
    {
        reference = new ReferenceCounter();
        reference->add();
    }

    SharedPointer(T* pValue) :
        data(pValue),
        reference(0)
    {
        reference = new ReferenceCounter();
        reference->add();
    }

    SharedPointer(const SharedPointer<T>& sp) :
        data(sp.data),
        reference(sp.reference)
    {
        reference->add();
    }

    ~SharedPointer()
    {
        if (reference->release() == 0)
        {
            delete data;
            delete reference;
        }
    }

    T& operator* ()
    {
        return *data;
    }

    T* operator-> ()
    {
        return data;
    }

    SharedPointer<T>& operator = (const SharedPointer<T>& sp)
    {
        if (this != &sp)
        {
            if(reference->release() == 0)
            {
                delete data;
                delete reference;
            }

            data = sp.data;
            reference = sp.reference;
            reference->add();
        }
        return *this;
    }

    T* get() const { return data; }

    bool unique() const { return reference->unique() == 1; }

};
