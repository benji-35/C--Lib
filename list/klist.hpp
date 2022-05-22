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

namespace kap35 {
    template<typename T>
    class list {
        public:
            struct node_list {
                T _val;
                shared_ptr<node_list> _next;
                shared_ptr<node_list> _before;

                node_list(T val, shared_ptr<node_list> before, shared_ptr<node_list> next) {
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
                    shared_ptr<node_list> n = new node_list(val, nullptr, _list);
                    if (_list != nullptr) {
                        _list.get()._before = n;
                    }
                    _list = n;
                    return;
                }
                if (_index == size()) {
                    shared_ptr<node_list> _last = getLast();
                    _last.get()._next = new node_list(val, _last, nullptr);
                    return;
                }
                shared_ptr<node_list> tmp = _list;
                while (_index > 0 || tmp.get()._next == nullptr) {
                    _index--;
                }
                shared_ptr<node_list> n = new node_list(val, tmp, tmp.get()._next);
                tmp.get()._next = n;
            }

            void pop_back() {
                pop_at(size() - 1);
            }

            void pop_front() {
                pop_at(0);
            }

            void pop_at(unsigned int index) {
                if (index == 0)
                    return pop_front();
                if (index >= size() - 1)
                    return pop_back();
                shared_ptr<node_list> tmp = _list;
                while (index > 0) {
                    tmp = tmp.get()._next;
                    index--;
                }
                ((shared_ptr<node_list>)tmp.get()._before).get()._next = tmp.get()._next;
                tmp.destroy();
            }

            unsigned int size() const {
                shared_ptr<node_list> tmp = _list;
                unsigned int res = 0;

                if (tmp.isEmpty())
                    return 0;
                while (!tmp.isEmpty()) {
                    tmp = (shared_ptr<node_list>)((node_list &)tmp.get())._next;
                    res++;
                }
                return res;
            }

            void clear() {
                shared_ptr<node_list> tmp = _list;
                shared_ptr<node_list> nxt;

                if (_list.isEmpty() || tmp.isEmpty()) {
                    _list.destroy();
                    return;
                }
                while (!tmp.isEmpty()) {
                    nxt = tmp.get()._next;
                    tmp.destroy();
                    tmp = nxt;
                }
                _list = nullptr;
            }

            T& at(unsigned int index) {
                return get(index);
            }

            T& get(unsigned int index) const {
                shared_ptr<node_list> tmp;

                tmp = _list;
                while (index > 0) {
                    tmp = ((node_list &)tmp.get())._next;
                    if (tmp.isEmpty())
                        break;
                    index--;
                }
                if (tmp.isEmpty()) {
                    char msg[19] = {'i', 'n', 'd', 'e', 'x', ' ', 'o', 'u', 't', ' ', 'o', 'f', ' ', 'r', 'a', 'n', 'g', 'e', 0};
                    throw Exception::ListError(msg);
                }
                return tmp.get()._val;
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
            shared_ptr<node_list> getLast() {
                if (_list.isEmpty())
                    return nullptr;
                shared_ptr<node_list> tmp = _list;
                while (tmp.get()._next != nullptr)
                    tmp = tmp.get()._next;
                return tmp;
            }

            shared_ptr<node_list> _list;
    };

}

#endif /* !KLIST_HPP_ */
