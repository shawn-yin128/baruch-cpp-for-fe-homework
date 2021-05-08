#ifndef FunctionObject_HPP
#define FunctionObject_HPP

template <typename T>
class FunctionObject {
    private:
        T target;

    public:
        // Constructors
        FunctionObject();
        FunctionObject(const T& t);
        FunctionObject(const FunctionObject<T>& source);

        // Destructor
        ~FunctionObject();

        // Member operator overloading
        FunctionObject<T>& operator = (const FunctionObject<T>& source);
        bool operator () (const T& t) const;
};

#ifndef FunctionObject_CPP
#include "function_object.cpp"
#endif

#endif