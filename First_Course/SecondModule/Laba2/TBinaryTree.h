//
// Created by Алексей Долматов on 12.03.17.
//

#ifndef MODULE2LABA2_TBINARYTREE_H
#define MODULE2LABA2_TBINARYTREE_H

#include <exception>
#include <iostream>


struct TExistElementException
        : public std::exception {
    TExistElementException(char const *const message) throw()
            : std::exception() {
    }
};


struct TNotFoundException
        : public std::exception {
    TNotFoundException(char const *const message) throw()
            : std::exception() {}
};

class TBinaryTree {
public:
    using value_type = int;

    struct TNode {
        value_type Data;
        TNode *Right;
        TNode *Left;

    private:
        TNode(const value_type &data, TNode *next = nullptr, TNode *prev = nullptr)
                : Data(data), Right(next), Left(prev) {}

        TNode()
                : Data(value_type()), Right(nullptr), Left(nullptr) {}

        ~TNode() {
            delete Left;
            delete Right;
        }

        friend class TBinaryTree;
    };

private:
    TNode *Root = nullptr;

    static void Print(std::ostream &out, TBinaryTree::TNode *node) {
        if (node) {
            Print(out, node->Left);
            out << std::endl << node->Data;
            Print(out, node->Right);
        }
    }

public:
    TBinaryTree() {}

    ~TBinaryTree() {
        delete Root;
    }

    void Insert(const value_type &data) {
        if (!TryInsert(data))
            throw TExistElementException("element already exist");
    }

    bool TryInsert(const value_type &data) {
        if (Root == nullptr) {
            Root = new TNode(data);
            return true;
        }

        TNode *curNode = Root;
        TNode *prevNode = curNode;
        do {
            prevNode = curNode;
            if (curNode->Data == data)
                return false;
            if (curNode->Data < data)
                curNode = curNode->Right;
            else
                curNode = curNode->Left;
        } while (curNode);

        TNode *newNode = new TNode(data);
        (prevNode->Data < data) ? prevNode->Right = newNode : prevNode->Left = newNode;
        return true;
    }

    // Требуется реализовать функцию поиска элемента
    // Если узел содержит искомый элемент, то функция возвращает указатель на этот узел
    // Если элемента в дереве не найдено, то функция генерирует исключение TNotFoundException
    /*
    TNode * Find(const value_type & value)
    {
        if (Root== nullptr){
            throw TNotFoundException("Not found");
        }
        TNode *curNode=Root;
        do {
            if (curNode->Data == value)
                return curNode;
            if (curNode->Data < value)
                curNode = curNode->Right;
            else
                curNode = curNode->Left;
        } while (curNode);
        throw TNotFoundException("Not found");
    }
     */
    TNode *Find(const value_type &value) {

        TNode *CurNode = Root;
        while (CurNode != nullptr) {
            if (CurNode->Data == value) {
                return CurNode;
            } else {
                if (CurNode->Data > value) {
                    CurNode = CurNode->Left;
                } else
                    CurNode = CurNode->Right;
            }
        }
        throw TNotFoundException("Not found");
    }


    friend std::ostream &operator<<(std::ostream &out, const TBinaryTree &tree);
};

std::ostream &operator<<(std::ostream &out, const TBinaryTree &tree) {
    TBinaryTree::Print(out, tree.Root);
    return out;
}

#endif //MODULE2LABA2_TBINARYTREE_H
