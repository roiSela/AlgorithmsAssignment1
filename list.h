#pragma once
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;
};

template <typename T> class List {
private:
    Node<T>* head;
public:
    List() {
        head = nullptr;
        head->prev = nullptr;
        head->next = nullptr;
    }

    //val will be the new head of the list
    void push(T val) {
        Node<T>* newLinkedListMember = new Node<T>();
        newLinkedListMember ->data = val;
        newLinkedListMember->next = head;

        head->prev = newLinkedListMember;
        head = newLinkedListMember;
        head->prev = nullptr;
    }

    //this function delets *all* appearences of val on the list
    void deleteListMember(T val)
    {
        Node<T>* currentListMemberToCheck = head;
        while (currentListMemberToCheck != nullptr)
        {
            if (currentListMemberToCheck->data == val)
            {
                currentListMemberToCheck->prev->next = currentListMemberToCheck->next;
                currentListMemberToCheck->next->prev = currentListMemberToCheck->prev;
                delete[] currentListMemberToCheck;
            }
            else
            {
                currentListMemberToCheck = currentListMemberToCheck->next;
            }
        }

    }

    //return true if val is in the list and flase if not
    bool search(T val) {
        Node<T>* currentListMemberToCheck = head;
        while (currentListMemberToCheck!=nullptr)
        {
            if (currentListMemberToCheck->data == val)
            {
                return true;
            }
            else
            {
                currentListMemberToCheck = currentListMemberToCheck->next;
            }
        }

        return false;
        
    }


    //return true if the list is empty,false else.
    bool isThisListEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }

    }


    //this function deletes the list in full.
    void deleteTheList()
    {
        Node<T>* currentListMemberToDelete = head;
        Node<T>* temp;
        while (currentListMemberToDelete!=nullptr)
        {
            temp = currentListMemberToDelete->next;
            delete[] currentListMemberToDelete;
            currentListMemberToDelete = temp;
        }

        head = nullptr;
        head->prev = nullptr;
        head->next = nullptr;
    }
};

//int main() {
//    List<int> list;
//
//    list.push(1);
//    list.push(2);
//    list.push(3);
//
//    std::cout << list.pop() << std::endl;
//    std::cout << list.search(2) << std::endl;
//    std::cout << list.pop() << std::endl;
//
//    return 0;
//}