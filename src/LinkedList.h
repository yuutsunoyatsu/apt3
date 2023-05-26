#ifndef APT3_LINKEDLIST_H
#define APT3_LINKEDLIST_H

#include <vector>
#include <string>
#include <algorithm>
#include "Node.h"

namespace ppd {

    template<typename T>
    class DoublyLinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        int count;

    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

        ~DoublyLinkedList() {
            clear();
        }

        void push_front(const T& value) {
            auto* newNode = new Node<T>(value);

            if (head == nullptr) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }

            count++;
        }

        void push_back(const T& value) {
            auto* newNode = new Node<T>(value);

            if (tail == nullptr) {
                head = tail = newNode;
            } else {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }

            count++;
        }

        T pop_front() {

            T poppedValue;

            if (head == nullptr) {
                poppedValue = nullptr;
            }
            else {
                Node<T>* temp = head;
                poppedValue = temp->data;

                if (head == tail) {
                    head = tail = nullptr;
                } else {
                    head = head->next;
                    head->prev = nullptr;
                }

                delete temp;
                count--;
            }

            return poppedValue;
        }

        T pop_back() {
            T poppedValue;

            if (tail == nullptr) {
                poppedValue = nullptr;
            }
            else{
                Node<T>* temp = tail;
                poppedValue = temp->data;

                if (head == tail) {
                    head = tail = nullptr;
                } else {
                    tail = tail->prev;
                    tail->next = nullptr;
                }

                delete temp;
                count--;
            }

            return poppedValue;
        }

        void clear() {
            while (head != nullptr) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }

            tail = nullptr;
            count = 0;
        }

        int size() const {
            return count;
        }

        // To use with foreach iteration and other convenient methods
        class Iterator {
        private:
            Node<T>* current;

        public:
            explicit Iterator(Node<T>* node) : current(node) {}

            T& operator*() const {
                return current->data;
            }

            Iterator& operator++() {
                current = current->next;
                return *this;
            }

            Iterator operator++(int) {
                Iterator temp = *this;
                ++(*this);
                return temp;
            }

            Iterator& operator--() {
                current = current->prev;
                return *this;
            }

            Iterator operator--(int) const {
                Iterator temp = *this;
                --(*this);
                return temp;
            }

            bool operator==(const Iterator& other) const {
                return current == other.current;
            }

            bool operator!=(const Iterator& other) const {
                return current != other.current;
            }
        };

        Iterator begin() const {
            return Iterator(head);
        }

        Iterator end() const {
            return Iterator(nullptr);
        }

        Iterator rbegin() const {
            return Iterator(tail);
        }

        Iterator rend() const {
            return Iterator(nullptr);
        }

        T find_and_get(const T& value) const {
            Iterator it = std::find(begin(), end(), value);
            if (it != end()) {
                return *it;
            }
            // Return a default-constructed value of type T to indicate not found
            return T{};
        }
    };



}

#endif //APT3_LINKEDLIST_H
