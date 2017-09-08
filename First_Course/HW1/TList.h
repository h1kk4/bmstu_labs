//
// Created by Алексей Долматов on 09.06.17.
//

#ifndef FORWARD_LIST_TLIST_H
#define FORWARD_LIST_TLIST_H

#include <iostream>

template<class T>

class TForwardList {
private:

    using value_type = T;
    using size_type = size_t;
    using reference = value_type &;
    using const_reference = const value_type &;

public:

    struct Node {
        value_type Data;
        Node *Next;

    };

private:

    Node *Head;
    size_type Count;

public:

    TForwardList() {
        Head = nullptr;
        Count = 0;
    };

    TForwardList(size_type num, const value_type &val = value_type()) {
        Head = nullptr;
        Count = 0;
        while (Count != num) {
            push_back(val);
        }
    };

    TForwardList(std::initializer_list<value_type> init) {
        Head = nullptr;
        Count = 0;
        for (auto &i : init) {
            push_back(i);
        }
    };

    TForwardList(const TForwardList<value_type> &obj) {
        Head = nullptr;
        if (obj.Count) {
            Node *tmp = obj.Head;
            while (Count != obj.Count) {
                push_back(tmp->Data);
                tmp = tmp->Next;
            }
        } else Count = 0;
    };

    TForwardList &operator=(const TForwardList<value_type> &obj) {
        if (&obj == this) return *this;
        if (Count) clear();
        Head = nullptr;
        if (obj.Count) {
            Node *tmp = obj.Head;
            while (Count != obj.Count) {
                push_back(tmp->Data);
                tmp = tmp->Next;
            }
        } else Count = 0;
        return *this;
    };

    ~TForwardList() {
        clear();
    };

    bool empty() const {
        return !Count;
    };

    void push_back(const value_type &val) {
        if (!Head) push_front(val);
        else {
            Node *tmp = Head;
            while (tmp->Next) tmp = tmp->Next;
            Node *newNode = new Node;
            newNode->Data = val;
            tmp->Next = newNode;
            newNode->Next = nullptr;
            Count++;
        }

    };

    void pop_front() {
        Node *tmp = Head->Next;
        delete Head;
        Head = tmp;
        Count--;
    };


    void push_front(const value_type &val) {
        if (!Head) {
            Head = new Node;
            Head->Data = val;
            Head->Next = nullptr;
        } else {
            Node *tmp = new Node;
            tmp->Data = val;
            tmp->Next = Head;
            Head = tmp;
        }
        Count++;
    };

    void remove(const value_type &val) {
        Node *tmp = Head;
        Node *tmp2 = nullptr;
        while (tmp) {
            tmp2 = tmp->Next;
            if (tmp->Data == val) {
                if (tmp == Head) {
                    delete Head;
                    Head = tmp2;
                } else {
                    Node *before = Head;
                    while (before->Next != tmp) before = before->Next;
                    before->Next = tmp->Next;
                    delete tmp;
                }
                Count--;
            }
            tmp = tmp2;
        }
    };


    void clear() {
        while (Head) {
            Node *tmp = Head->Next;
            delete Head;
            Head = tmp;
        }
        Head = nullptr;
        Count = 0;
    };

    void swap(TForwardList<value_type> &ob) {
        std::swap(Count, ob.Count);
        std::swap(Head, ob.Head);
    }


    void sort() {
        Node *tmp1 = Head;
        Node *tmp2 = Head->Next;
        while (tmp1->Next) {
            while (tmp2) {
                if (tmp1->Data > tmp2->Data) {
                    std::swap(tmp1->Data, tmp2->Data);
                }
                tmp2 = tmp2->Next;
            }
            tmp1 = tmp1->Next;
            tmp2 = tmp1->Next;
        }
    };

    reference front() {
        return Head->Data;
    };

    const_reference front() const {
        return Head->Data;
    };

    void reverse() {
        if (Count == 1) return;
        Node *head = Head;
        Node *last = Head;
        while (last->Next) last = last->Next;
        for (size_type i = 0; i < Count / 2; ++i) {
            std::swap(head->Data, last->Data);
            head = head->Next;
            Node *tmp = Head;
            while (tmp->Next != last) tmp = tmp->Next;
            last = tmp;
        }
    };

    class TIterator {
    private:

        Node *Ptr;

    public:

        TIterator() {
            Ptr = new Node;
        }

        TIterator(Node *p) : Ptr(p) {};

        TIterator(const TIterator &obj) {
            Ptr = obj.Ptr;
        }

        TIterator &operator=(const TIterator &obj) {
            if (&obj == this) return *this;
            if (Ptr) delete Ptr;
            Ptr = obj.Ptr;
            return *this;
        }

        bool operator==(const TIterator &other) const {
            return (Ptr == other.Ptr);
        };

        bool operator!=(const TIterator &other) const {
            return (Ptr != other.Ptr);
        };

        reference operator*() const {
            if (Ptr) return (Ptr->Data);

        };

        const_reference operator*() {
            if (Ptr) return (Ptr->Data);

        }

        TIterator &operator++() {
            if (Ptr) Ptr = Ptr->Next;

            return *this;
        };

        const TIterator operator++(int) {
            TIterator it = Ptr;
            ++it;
            Ptr = it.Ptr;
            return it;
        }


        Node *node() const {
            return Ptr;
        }
    };


private:

    using iterator = TIterator;
    using const_iterator = const TIterator;

public:

    TForwardList(const_iterator _first, const_iterator _last) {
        Head = nullptr;
        Node *tmp = nullptr;
        TIterator head(_first);
        while (head != _last) {
            if (!Head) {
                Head = new Node;

                Head->Next = nullptr;
                Head->Data = head;
                head++;
                Count++;
            } else {
                tmp = new Node();
                tmp->Data = head;
                tmp->Next = Head;
                Head = tmp;
                head++;
                Count++;
            }
        }
        reverse();
    };


    iterator insert_after(const_iterator pos, const_reference value) {
        if (pos == end()) {
            push_back(value);
            Node *last = Head;
            while (last != nullptr) last = last->Next;
            return TIterator(last);
        } else {
            Node *position = pos.node();
            Node *nodeNew = new Node;
            nodeNew->Data = value;
            nodeNew->Next = position->Next->Next;
            position->Next = nodeNew;
            Count++;
            return TIterator(nodeNew);
        }

    };

    iterator erase_after(const_iterator position) {
        Node *tmp = Head;
        while (tmp->Next) tmp = tmp->Next;
        Node *next = position.node();
        next = next->Next->Next;
        Node *pos = position.node();
        delete pos->Next;
        pos->Next = next;
        return TIterator(next);
    };

    iterator erase_after(const_iterator _position, const_iterator _last) {
        TIterator tmp(_position);
        Node *first = _position.node();
        Node *last = _last.node();
        while (first->Next != last) {
            Node *next = first;
            next = next->Next->Next;
            delete first->Next;
            first->Next = next;
            first = first->Next;
            Count--;
        }
        return last;
    };

    iterator end() {
        return TIterator(nullptr);
    };


    iterator begin() {
        return TIterator(Head);
    };


    bool operator==(const TForwardList<value_type> &rhs) const {
        if (Count != rhs.Count) return false;
        Node *head = Head;
        Node *headRhs = rhs.Head;
        while (head) {
            if (head->Data != headRhs->Data) return false;
            head = head->Next;
            headRhs = headRhs->Next;
        }
        return true;
    };

};

#endif //FORWARD_LIST_TLIST_H
