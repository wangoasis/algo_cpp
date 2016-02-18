#ifndef vectorMine_H
#define vectorMine_H

#include <iostream>
using std::cout; using std::endl;

template <typename Object>
class vectorMine {
public:

    explicit vectorMine (int initSize = 0) 
        : theCapacity(initSize + SPARE_CAPACITY) , theSize(initSize) {
        objects = new Object[theCapacity];
    }

    vectorMine (const vectorMine & rhs) 
        : objects(NULL) {

        operator=(rhs);
    }

    ~vectorMine () {
        delete [] objects;
    }

    const vectorMine & operator = (const vectorMine & rhs) {

        if(this != &rhs) {
            delete [] objects;
            theCapacity = rhs.capacity();
            theSize = rhs.size();

            objects = new Object[theCapacity];
            for(int i = 0; i < size(); i++)
                objects[i] = rhs.objects[i];
        }
        return *this;
    }

    void resize(int newSize) {
        if(newSize > capacity())
            reserve(newSize * 2 + 1);
        theSize = newSize;
    }

    void reserve(int newCapacity) {
        if(newCapacity < theSize)
            return;

        Object *old = objects;

        objects = new Object[newCapacity];
        for(int i = 0; i < size(); i++)
            objects[i] = old[i];

        theCapacity = newCapacity;

        delete [] old;
    }

    Object & operator [] (int index) {
        if(index >= 0 && index < size())
            return objects[index];
        else {
            cout << "Out of Bounds !!!" << endl;
            return objects[0];
        }
    }

    const Object & operator [] (int index) const {
        if(index >= 0 && index < size())
            return objects[index];
        else {
            cout << "Out of Bounds !!!" << endl;
            return objects[0];
        }
    }

    bool isEmpty() const {
        return theSize == 0;
    }

    int size() const {
        return theSize;
    }

    int capacity() const {
        return theCapacity;
    }

    void pushBack(const Object & x) {
        if(theSize == capacity())
            reserve(2 * capacity() + 1);
        objects[theSize++] = x;
    }

    void popBack() {
        
        theSize--;
    }

    const Object & back() {
        return objects[theSize - 1];
    }

    typedef Object* iterator;
    typedef const Object* const_iterator;

    iterator begin() {
        return &objects[0];
    }

    const const_iterator begin() const {
        return &objects[0];
    }

    iterator end() {
        return &objects[theSize];
    }

    const const_iterator end() const {
        return &objects[theSize];
    }

    iterator insert(iterator pos, const Object & x) {
        ++theSize;
        if(theSize > theCapacity)
            theCapacity = theSize;
        for(iterator iter = end(); iter != pos; --iter)
            *iter = *(iter-1);
        *pos = x;
        return pos;
    }

    iterator erase(iterator pos) {
        if(pos == end()) {
            cout << "out of bound!" << endl;
            return pos;
        }

        --theSize;
        for(iterator iter = pos; iter != end(); ++iter)
            *(iter) = *(iter+1);
        return pos;
    }

    enum { SPARE_CAPACITY = 16 };

private:
    int theSize;
    int theCapacity;
    Object* objects;
};

#endif
