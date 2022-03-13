/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** list
*/

#ifndef KLIST_HPP_
#define KLIST_HPP_

#include "kexceptions.hpp"

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

            void push_back(T val) {
                insert(size(), val);
            }

            void push_front(T val) {
                insert(0, val);
            }

            void insert(unsigned int index, T val) {
                if (index == 0) {
                    node_list *n = new node_list(val, nullptr, _list);
                    _list->_before = n;
                    _list = n;
                    return;
                }
                node_list *tmp = _list;
                while (index > 0 || tmp->_next == nullptr) {
                    index--;
                }
                node_list *n = new node_list(val, tmp, tmp->_next);
                tmp->_next = n;
            }

            void pop_back() {
                node_list _last = getLast();

                if (_last == nullptr)
                    return;
                delete _last;
                _list = _last._before;
            }

            void pop_front() {
                node_list *_lhd = _list;

                delete _lhd;

                _list = _list->_next;
                _list->_before = nullptr;
            }

            unsigned int size() const {
                node_list *tmp = _list;
                unsigned int res = 0;

                while (tmp != nullptr) {
                    tmp = tmp->_next;
                    res++;
                }
                return res;
            }

            void clear() {
                node_list *tmp = _list->_next;
                while (_list != nullptr) {
                    delete _list;
                    tmp = tmp->_next;
                    _list = tmp;
                }
            }

            T& at(unsigned int index) {
                if (index > size()) {
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

            list<T> &operator=(list<T> const&l) {
                clear();
                for (unsigned int i = 0; i < l.size(); i++) {
                    push_back(l.get(i));
                }
                return *this;
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
