// header file for array class

#ifndef _Array_HPP
#define _Array_HPP

using namespace std;

template <class T> 
class Array { // it's no longer named Array, its name is Array<T>
    public:
        // constructor
        Array(); // default constructor
        Array(int size); // constructor with input array size
        Array(const Array<T>& arr); // copy construtor

        // destructor
        ~Array();

        // operator overloading
        Array<T>& operator = (const Array<T>& arr); // assignment operator
        T& operator [] (int idx); // get or assign point at certain index
        const T& operator [] (int idx) const; // make sure that the object does not change and the return reference unchangeable

        // accessor
        int Size() const; // return the size of array
        T& GetElement(int idx) const; // return the element at certain index

        // modifier
        void SetElement(int idx, const T& p); // set point in certain index

        // static get/set function
        static int DefaultSize();
        static void DefaultSize(int size);

    private:
        T* m_data; // dynamic C array
        int m_size; // size of array
        static int default_size; // default size
};

#endif