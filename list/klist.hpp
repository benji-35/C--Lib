/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** list
*/

#ifndef KLIST_HPP_
#define KLIST_HPP_

#include "kexceptions.hpp"
#include <iostream>

namespace kap35 {
    class exception;
}

namespace kap35 {
    template<typename T>
    class list {
        public:
            struct node_list {
                T _val;
                node_list *_next;
                node_list *_before;

                node_list(T val, node_list *before = nullptr, node_list *next = nullptr) {
                    _val = val;
                    _next = next;
                    _before = before;
                }
            };

            ~list() {
                clear();
            }

            void push_back(T val) {
                insert(size(), val);
            }

            void push_front(T val) {
                insert(0, val);
            }

            void insert(unsigned int const& index, T val) {
                unsigned int _index = index;
                if (_index == 0) {
                    node_list *n = new node_list(val, nullptr, _list);
                    if (_list != nullptr) {
                        _list->_before = n;
                    }
                    _list = n;
                    return;
                }
                if (_index == size()) {
                    node_list *_last = getLast();
                    _last->_next = new node_list(val, _last, nullptr);
                    return;
                }
                node_list *tmp = _list;
                while (_index > 0 || tmp->_next == nullptr) {
                    _index--;
                }
                node_list *n = new node_list(val, tmp, tmp->_next);
                tmp->_next = n;
            }

            void pop_back() {
                node_list *_last = getLast();

                if (_last == nullptr)
                    return;
                delete _last;
                _list = _last->_before;
            }

            void pop_front() {
                node_list *_lhd = _list;

                delete _lhd;

                _list = _list->_next;
                _list->_before = nullptr;
            }

            void pop_at(unsigned int index) {
                if (index == 0)
                    return pop_front();
                if (index >= size() - 1)
                    return pop_back();
                node_list *tmp = _list;
                while (index > 0) {
                    tmp = tmp->_next;
                }
                ((node_list *)tmp->_before)->_next = tmp->_next;
                delete tmp;
            }

            unsigned int size() const {
                node_list *tmp = _list;
                unsigned int res = 0;

                if (tmp == nullptr)
                    return 0;
                while (tmp) {
                    tmp = tmp->_next;
                    res++;
                }
                return res;
            }

            void clear() {
                node_list *tmp = _list;
                node_list *nxt;

                if (tmp == nullptr) {
                    return;
                }
                nxt = tmp->_next;
                while (tmp) {
                    delete tmp;
                    tmp = nxt;
                    if (nxt != nullptr)
                        nxt = nxt->_next;
                }
                _list = nullptr;
            }

            T& at(unsigned int index) {
                if (index >= size()) {
                    throw exception("index out of range");
                }
                node_list *tmp = _list;
                while (index > 0) {
                    tmp = tmp->_next;
                    index--;
                }
                return tmp->_val;
            }

            T& get(unsigned int index) const {
                node_list *tmp = _list;
                while (index > 0) {
                    tmp = tmp->_next;
                    if (tmp == nullptr)
                        break;
                    index--;
                }
                if (tmp == nullptr)
                    throw exception("index out of range");
                return tmp->_val;
            }

            list<T> &operator=(list<T> const& l) {
                clear();
                for (unsigned int i = 0; i < l.size(); i++) {
                    push_back(l.get(i));
                }
                return *this;
            }

            T &operator[](unsigned int index) {
                return at(index);
            }

        private:
            node_list *getLast() {
                if (_list == nullptr)
                    return nullptr;
                node_list *tmp = _list;
                while (tmp->_next != nullptr)
                    tmp = tmp->_next;
                return tmp;
            }

            node_list *_list = nullptr;
    };

}

#endif /* !KLIST_HPP_ */
