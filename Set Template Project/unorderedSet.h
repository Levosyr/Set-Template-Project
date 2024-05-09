#ifndef UNORDEREDSET_H
#define UNORDEREDSET_H

#include "arrayListType.h" // Include the provided header file for array list
#include "unorderedArrayListType.h" // Include the provided header file for unordered array list

template <class Type>
class unorderedSet : public unorderedArrayListType<Type> {
public:
    // Function to insert an element at the end of the set
    void insertEnd(const Type& newItem);

    // Function to insert an element at a specific position in the set
    void insertAt(int location, const Type& newItem);

    // Function to replace the element at a specific position in the set
    void replaceAt(int location, const Type& newItem);

    // Overload the + operator to perform set union
    unorderedSet<Type> operator+(const unorderedSet<Type>& otherSet) const;

    // Overload the - operator to perform set intersection
    unorderedSet<Type> operator-(const unorderedSet<Type>& otherSet) const;
};

// Function to insert an element at the end of the set
template <class Type>
void unorderedSet<Type>::insertEnd(const Type& newItem) {
    if (this->seqSearch(newItem) == -1) {
        this->insertLast(newItem);
    }
}

// Function to insert an element at a specific position in the set
template <class Type>
void unorderedSet<Type>::insertAt(int location, const Type& newItem) {
    if (this->seqSearch(newItem) == -1) {
        this->insertAt(newItem, location);
    }
}

// Function to replace the element at a specific position in the set
template <class Type>
void unorderedSet<Type>::replaceAt(int location, const Type& newItem) {
    if (this->seqSearch(newItem) == -1) {
        this->replaceAt(location, newItem);
    }
}

// Overload the + operator to perform set union
template <class Type>
unorderedSet<Type> unorderedSet<Type>::operator+(const unorderedSet<Type>& otherSet) const {
    unorderedSet<Type> unionSet = *this;
    for (int i = 0; i < otherSet.listSize; ++i) {
        if (unionSet.seqSearch(otherSet.list[i]) == -1) {
            unionSet.insertEnd(otherSet.list[i]);
        }
    }
    return unionSet;
}

// Overload the - operator to perform set intersection
template <class Type>
unorderedSet<Type> unorderedSet<Type>::operator-(const unorderedSet<Type>& otherSet) const {
    unorderedSet<Type> intersectionSet;
    for (int i = 0; i < this->listSize; ++i) {
        if (otherSet.seqSearch(this->list[i]) != -1) {
            intersectionSet.insertEnd(this->list[i]);
        }
    }
    return intersectionSet;
}

#endif
