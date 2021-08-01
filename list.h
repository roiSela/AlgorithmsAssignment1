#pragma once
#include <iostream>
using namespace std;

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

        if (head == nullptr) {
            head = newLinkedListMember;
        }
        else {
            head->prev = newLinkedListMember;
            head = newLinkedListMember;
        }
        size++;
    }

    //delets the tale of the list and return it (this function presums that the list it not empty,so we need to check that first before
    //calling it)
    T pop()
    {
        T toReturn; //we need to return current tail
        Node<T>* ToDelete = head; //we need to delete current tail

        while (ToDelete->next != nullptr)
        {
            ToDelete = ToDelete->next;
        }
        //now toDelete is our current tail.
        toReturn = ToDelete->data;

        //lets divide into cases

        if (ToDelete == head)
        {
            head->prev = nullptr;
            head->next = nullptr;
            head = nullptr;
            delete[] ToDelete;
        }
        else //we have at least two elements
        {
            ToDelete->prev->next = nullptr;
            delete[] ToDelete;
        }
    

        return toReturn;

    }


    //this function deletes one appearance of val from the list
    void deleteListMember(T val)
    {
        Node<T>* currentListMemberToCheck = head;
        while (currentListMemberToCheck != nullptr)
        {
            if (currentListMemberToCheck->data == val)
            {
                if (currentListMemberToCheck->next != nullptr) {
                    currentListMemberToCheck->next->prev = currentListMemberToCheck->prev;
                }
                if (currentListMemberToCheck->prev != nullptr) {
                    currentListMemberToCheck->prev->next = currentListMemberToCheck->next;
                }
                if (currentListMemberToCheck == head)
                {          
                    currentListMemberToCheck->prev = nullptr;
                    head = head->next;
                 
                }
                delete[] currentListMemberToCheck;
                size--;
                break; //we only delete one qppearance of val
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
        while (currentListMemberToCheck != nullptr)
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
        while (currentListMemberToDelete != nullptr)
        {
            temp = currentListMemberToDelete->next;
            delete[] currentListMemberToDelete;
            currentListMemberToDelete = temp;
        }      
        size = 0;
    }

    Node<T>* getHeadOfList()
    {
        
        return  head;

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