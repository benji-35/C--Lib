/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "klist.hpp"
#include <iostream>

#ifndef K_SIZE_T
    namespace kap35 {
        typedef unsigned long size_t;
    }
#endif

#ifndef KEY_NOT_FOUND
    #define KEY_NOT_FOUND "key not found\0"
#endif

namespace kep35 {
    class list;
}

namespace kap35 {

    template<typename KEY, typename CONTENT>
    class map {
        public:
            struct node_map {
                KEY _key;
                CONTENT _cont;
                node_map *_next = nullptr;
                node_map *_before = nullptr;

                node_map(KEY key, CONTENT content, node_map *before = nullptr, node_map *next = nullptr) {
                    _key = key;
                    _cont = content;
                    _next = next;
                    _before = before;
                }
            };

            ~map() {
                clear();
            }

            CONTENT &get(KEY const& k) {
                node_map *tmp = _list;

                while (tmp != nullptr) {
                    if (tmp->_key == k)
                        return tmp->_cont;
                    tmp = tmp->_next;
                }
                throw Exception::MapError((char *)KEY_NOT_FOUND);
            }

            bool keyExists(KEY const& k) {
                node_map *tmp = _list;

                while (tmp != nullptr) {
                    if (tmp->_key == k)
                        return true;
                    tmp = tmp->_next;
                }
                return false;
            }

            size_t size() const {
                node_map *tmp = _list;
                size_t res = 0;

                while (tmp != nullptr) {
                    tmp = tmp->_next;
                    res++;
                }
                return res;
            }

            void add(KEY key, CONTENT content) {

                node_map *last = getLast();

                if (_list == nullptr) {
                    _list = new node_map(key, content, last, nullptr);
                    return;
                }
                last->_next = new node_map(key, content, last, nullptr);
            }

            void clear() {
                node_map *tmp = _list;
                node_map *nxt = nullptr;

                if (tmp == nullptr)
                    return;
                nxt = tmp->_next;
                while (tmp) {
                    delete tmp;
                    tmp = nxt;
                    if (nxt != nullptr)
                        nxt = nxt->_next;
                }
                _list = nullptr;
            }

            void remove(KEY const& k) {
                if (!keyExists(k))
                    return;
                node_map *tmp = _list;

                while (tmp) {
                    if (tmp->_key == k) {
                        ((node_map *)tmp->_before)->_next = tmp->_next;
                        delete tmp;
                        break;
                    }
                    tmp = tmp->_next;
                }
            }

            map<KEY, CONTENT> &operator=(map<KEY, CONTENT> const& map) {
                clear();
            }

        protected:
        private:
            node_map *getLast() {
                if (_list == nullptr)
                    return nullptr;
                node_map *tmp = _list;
                while (tmp->_next != nullptr)
                    tmp = tmp->_next;
                return tmp;
            }

            node_map *_list = nullptr;
    };

}

#endif /* !MAP_HPP_ */
