#ifndef APT3_NODE_H
#define APT3_NODE_H

namespace ppd{
    template<typename T>
    class Node {
    public:
        T data;
        Node<T>* prev;
        Node<T>* next;

        explicit Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
        bool operator==(const Node& other);
    };

    template<typename T>
    bool Node<T>::operator==(const Node& other) {
        return this->data == other.data;
    }
}



#endif //APT3_NODE_H
