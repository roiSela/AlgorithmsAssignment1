#pragma once
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(T data) : data(data) {}
};

template <typename T> class List {
private:
    Node<T>* head;
    int size;

public:
    List() {
        head = nullptr;
        size = 0;
    }

    //val will be the new head of the list
    void push(T val) {
        auto newLinkedListMember = new Node<T>(val);
        newLinkedListMember->data = val;
        newLinkedListMember->next = head;
        newLinkedListMember->prev = nullptr;

        if(head==nullptr){
            head=newLinkedListMember;
        }
        else{
            head->prev=newLinkedListMember;
            head=newLinkedListMember;
        }
        size++;
    }

    //this function deletes *all* appearances of val on the list
    void deleteListMember(T val)
    {
        Node<T>* currentListMemberToCheck = head;
        while (currentListMemberToCheck != nullptr)
        {
            if (currentListMemberToCheck->data == val)
            {
                if(currentListMemberToCheck->next!= nullptr){
                    currentListMemberToCheck->next->prev = currentListMemberToCheck->prev;
                }
                if(currentListMemberToCheck->prev!= nullptr){
                    currentListMemberToCheck->prev->next = currentListMemberToCheck->next;
                }
                delete[] currentListMemberToCheck;
                size--;
            }
            else
            {
                currentListMemberToCheck = currentListMemberToCheck->next;
            }
        }

    }

    //return true if val is in the list and false if not
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
        size = 0;
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