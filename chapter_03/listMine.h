#ifndef listMine_H
#define listMine_H
#include <stdio.h>
#include <iostream>

template <typename Object>
// bidirectional linked list
class listMine {

private:
    // list is constructed with node, each node contains data
    struct Node
    {
        /* data */
        Object data;
        Node* prev;
        Node* next;

        Node(const Object & x = Object(), Node *p= NULL, Node *n = NULL) 
        : data(x), 
            prev(p),
            next(n) 
            { }
    };

public:

    class const_iterator {
    public:
        const_iterator()
        : current(NULL) 
        { }
        
        const_iterator& operator = (const const_iterator &rhs) {
            current = rhs.current;
            return *this;
        }

        const Object& operator* () const {
            return retrieve();
        }

        const_iterator& operator++ () {
            current = current->next;
            return *this;
        }

        const_iterator operator++ (int) {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator == (const const_iterator &rhs) const {
            return current == rhs.current;
        }

        bool operator != (const const_iterator &rhs) const {
            return !(*this == rhs);
        }

    protected:
        Node *current;

        Object & retrieve() const {
            return current->data;
        }

        const_iterator(Node *x) 
        : current(x) 
        { }

        friend class listMine<Object>;

    };

    // iterator extends from const_iterator
    class iterator : public const_iterator {
    public:

        iterator () {}

        Object& operator * () {
            return retrieve();
        }

        const Object& operator* () const {
            return const_iterator::operator*();
        }

        iterator& operator++ () {
            current = current->next;
            return *this;
        }

        iterator& operator-- () {
            //prefix --
            current = current->prev;
            return *this;
        }

        iterator operator++ (int) {
            //postfix ++
            iterator old = *this;
            ++(*this);
            return old;
        }

        iterator operator-- (int) {
            //postfix --
            iterator old = *this;
            --(*this);
            return old;
        }

        iterator& operator= (const iterator &rhs) {
            current = rhs.current;
            return *this;
        }

    protected:
        iterator(Node *p)
        :const_iterator(p) 
        { }

    friend class listMine<Object>;
    
    };

public:
    listMine() {
        init();
    }

    listMine(const listMine& rhs) {
        init();
        if(this != &rhs)
            *this = rhs;
    }

    const listMine & operator = (const listMine& rhs) {
        if(this == &rhs)
            return *this;

        clear();
        for(const_iterator itr = rhs.begin(); itr != rhs.end(); itr++) {
            push_back(*itr);
        } 
        return *this;
    }

    ~listMine () {
        clear();
        delete head;
        delete tail;
    }

    iterator begin() {
        return iterator(head->next);
    }

    const const_iterator begin() const {
        return const_iterator(head->next);
    }

    iterator end() {
        return iterator(tail);
    }

    const const_iterator end() const {
        return const_iterator(tail);
    }

    int size() const {
        return theSize;
    }

    bool isEmpty() const {
        return theSize == 0;
    }

    Object& front() {
        return *begin();
    }

    const Object& front() const {
        return *begin();
    }

    Object& back() {
        return *--end();
    }

    const Object& back() const {
        return *--end();
    }

    void push_back (const Object &x) {
        insert(end(),x);
    }

    void pop_back() {
        erase(--end());
    }

    void push_front(const Object &x) {
        insert(begin(),x);
    }

    void pop_front() {
        erase(begin());
    }

    iterator insert(iterator itr, const Object &x) {
        Node *n = (itr--).current;
        Node *p = itr.current;
        p->next = n->prev = new Node(x, p, n);

        theSize++;
        return ++itr;
    }

    iterator erase(iterator itr) {
        Node *node = (itr--).current;
        Node *p = itr.current;
        p->next = node->next;
        node->next->prev = p;
        delete node;

        theSize--;
        return ++itr;
    }

    iterator erase(iterator from, iterator end) {
        for(iterator itr = from; itr != end;)
            itr=erase(itr);
        return end;
    }

    void print_list() {
        for(const_iterator itr = begin(); itr != end(); itr++)
            cout << *itr << endl;
    }

private:
    void init () {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }

    void clear() {
        while(!isEmpty()) {
            pop_back();
        }
    }

private:
    int theSize;
    Node* head;
    Node* tail;

};
#endif
