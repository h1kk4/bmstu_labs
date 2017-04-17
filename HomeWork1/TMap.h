//
// Created by Алексей Долматов on 16.04.17.
//
#include <iostream>

#ifndef HWORK1_TMAP_H
#define HWORK1_TMAP_H

template<
        class Key,
        class T,
        class Compare = std::less<Key>
>
class TMap {

    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<key_type, mapped_type>;
    using size_type = size_t;
    using iterator = value_type *;
    using const_iterator = const value_type *;

private:

    struct TNode {
        value_type Data;
        TNode *Left;
        TNode *Right;
    };

public:
    ///////////////////////////////You invade the danger zone

    TNode *Root;
    size_type Length;

    class Iterator : public TMap {
    public:

        TNode *Ptr;


    public:
        Iterator() : Ptr(nullptr) {}

        ~Iterator() {}

        Iterator(const Iterator &p) : Ptr(p.Ptr) {}

        Iterator(TNode *p) : Ptr(p) {}

        Iterator &operator=(TNode *p) {
            if (Ptr != p)
                Ptr = p;
            return *this;
        }


        Iterator &operator=(const Iterator &p) {
            if (this != &p)
                Ptr = p.Ptr;
            return *this;
        }

        Iterator &operator++(int) {
            if (!Ptr)
                return *this;

        }


        value_type *operator->() {
            return &(Ptr->Data);
        }


    };


    ///////////////////////////////You are leaving the danger zone



    value_type *Find(const key_type &data) {
        TNode *curNode = Root;
        TNode *prevNode = curNode;

        do {
            prevNode = curNode;
            if (curNode->Data.first == data) {
                return &(curNode->Data);
            }
            if (curNode->Data.first > data)
                curNode = curNode->Left;
            else
                curNode = curNode->Right;
        } while (curNode != nullptr);

        throw std::out_of_range("Out of Range");
    }

    value_type *TryInsert(const value_type &data) {
        if (Root == nullptr) {
            TNode *tmp = new TNode;
            tmp->Data = data;
            tmp->Right = nullptr;
            tmp->Left = nullptr;
            Root = tmp;
            Length++;
            return &(Root->Data);
        }

        TNode *curNode = Root;
        TNode *prevNode = curNode;

        do {
            prevNode = curNode;
            if ((curNode->Data.first == data.first)) {
                return &(curNode->Data);
            }
            if (Compare()(curNode->Data.first, data.first))
                curNode = curNode->Right;
            else
                curNode = curNode->Left;
        } while (curNode != nullptr);

        TNode *tmp = new TNode;
        tmp->Data = data;
        tmp->Right = nullptr;
        tmp->Left = nullptr;
        (prevNode->Data.first < data.first) ? prevNode->Right = tmp : prevNode->Left = tmp;
        Length++;
        return &(tmp->Data);
    }


    void copy(TMap &map, const TNode &rhs) {
        map.insert(rhs.Data);
        if (rhs.Left)
            copy(map, *(rhs.Left));
        if (rhs.Right)
            copy(map, *(rhs.Right));
    }

    void Delete(TNode **root) {
        if (*root == NULL)
            return;
        if ((*root)->Left != NULL)
            Delete(&(*root)->Left);
        if ((*root)->Right != NULL)
            Delete(&(*root)->Right);
        *root = NULL;

    }

public:

    TMap() : Root(nullptr), Length(0) {}

    virtual ~TMap() {
        (*this).clear();
    }

    TMap(std::initializer_list<value_type> list) {
        Root = nullptr;
        Length = 0;
        for (value_type item : list) {
            insert(item);
        }
    }

    TMap &operator=(TMap &other) {
        if (this->Root)
            (*this).clear();
        copy(*this, *(other.Root));
        return *this;

    }

    T &at(const Key &key) {
        return Find(key)->second;
    }

    T &operator[](Key &&key) {
        std::pair<key_type, mapped_type> p1(key, NULL);
        return TryInsert(p1)->second;

    }

    void insert(const value_type &data) {
        TryInsert(data);

    }

    void clear() {
        Delete(&(this->Root));
        Length = 0;
    }

    Iterator begin() const throw() {
        TNode *ptr = Root;
        Iterator prev = ptr;
        while (ptr->Left) {
            prev = ptr;
            ptr = ptr->Left;
        }
        return prev;
    }

    Iterator end() const throw() {
        Iterator it = nullptr;
        return it;
    }

    size_type size() const {
        return Length;
    }

    Iterator find(const Key &key) {

    }

    size_type count(const Key &key) const {

    }

};

#endif //HWORK1_TMAP_H
