/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** list
*/

#ifndef KLIST_HPP_
#define KLIST_HPP_

#include "kexceptions.hpp"
#include "kshared_ptr.hpp"
#include <iostream>
#include "kutils.hpp"

#ifndef K_SIZE_T
    namespace kap35 {
        typedef unsigned long size_t;
    }

#endif

namespace kap35 {

    template<typename T>
    class list {
        public:
            struct NodeList {
                NodeList* next = nullptr;
                NodeList* previous = nullptr;
                T value;

                NodeList(T val, NodeList* nxt = nullptr, NodeList* prev = nullptr) {
                    value = val;
                    next = nxt;
                    previous = prev;

                    if (previous != nullptr) {
                        previous->next = this;
                    }
                    if (next != nullptr) {
                        next->previous = this;
                    }
                }
            };

            /**
             * @brief Destroy the list<T> object
             * 
             *  A1 - A2 - N - A3 - A4
             * 
             * 
             */

            ~list<T>() {
                clear();
            }

            //functions

            void pushFront(T val) {
                pushAt(val, 0);
            }

            void pushBack(T val) {
                pushAt(val, size());
            }

            void pushAt(T val, size_t index) {
                if (index == 0) {
                    DEB_K("insert at front");
                    if (hd == nullptr) {
                        hd = new NodeList(val);
                    } else {
                        NodeList *nHd = new NodeList(val, hd);
                        hd = nHd;
                    }
                    return;
                }
                if (index >= size()) {
                    DEB_K("insert at end");
                    NodeList *last = getLast();
                    if (last == nullptr) {
                        pushAt(val, 0);
                    } else {
                        NodeList *nnl = new NodeList(val, nullptr, last);
                    }
                    return;
                }
                DEB_K("insert at " + std::to_string(index));
                NodeList *_at = getAt(index);
                NodeList *nnl = new NodeList(val, _at, _at->previous);
            }

            void popFront() {
                popAt(0);
            }

            void popBack() {
                popAt(size());
            }

            void popAt(size_t index) {
                if (index == 0) {
                    NodeList *tmp = hd;
                    if (tmp == nullptr)
                        return;
                    hd = hd->next;
                    delete tmp;
                    return;
                }
                if (index >= size()) {
                    NodeList *tmp = getLast();
                    if (tmp == nullptr) {
                        popAt(0);
                        return;
                    }
                    tmp->previous->next = nullptr;
                    delete tmp;
                }
                NodeList *tmp = getAt(index);
                tmp->previous->next = tmp->next;
                tmp->next->previous = tmp->previous;
                delete tmp;
            }

            T &at(size_t index) const {
                if (index < size()) {
                    return getAt(index)->value;
                }
                throw Exception::ListError((char *)INDEX_OUT_OF_RANGE);
            }

            size_t size() const {
                size_t res = 0;
                NodeList *tmp = hd;
                while (tmp != nullptr) {
                    res++;
                    if (tmp != nullptr)
                        tmp = tmp->next;
                }
                return res;
            }

            void clear() {
                while (size() > 0) {
                    popFront();
                }
                
            }

            void append(list<T> const& l) {
                NodeList *tmp = l.hd;
                while (tmp != nullptr) {
                    pushBack(tmp->value);
                    tmp = tmp->next;
                }
            }

            //operators

            T& operator [](size_t index) {
                return at(index);
            }

            list<T> &operator=(list<T> const& l) {
                clear();
                append(l);
                return *this;
            }

        private:
            NodeList *hd = nullptr;
    
            NodeList *getLast() const {
                if (size() == 0)
                    return hd;
                NodeList *tmp = hd;
                while (tmp->next != nullptr) {
                    tmp = tmp->next;
                }
                return tmp;
            }
            NodeList *getAt(size_t index) const {
                size_t curr = 0;
                if (index >= size())
                    return nullptr;
                NodeList *tmp = hd;
                for (size_t i = 0; i < index; i++) {
                    tmp = tmp->next;
                }
                return tmp;
            }
    };

}

#endif /* !KLIST_HPP_ */
