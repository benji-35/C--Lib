/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "klist.hpp"
#include "kexceptions.hpp"

namespace kep35 {
    class exception;
    class list;
}

namespace kap35 {

    template<typename KEY, typename CONTENT>
    class Map {
        public:
            struct node_map {
                KEY _key;
                CONTENT _cont;
                node_map *_next;
                node_map *_before;

                node_map(KEY key, CONTENT content, node_map *before = nullptr, node_map *next = nullptr) {
                    _key = key;
                    _cont = content;
                    _next = next;
                    _before = before;
                }
            };

            CONTENT &get(KEY const& k) {
                node_map *tmp = _list;

                while (tmp != nullptr) {
                    if (tmp->_key == k)
                        return tmp->_cont;
                    tmp = tmp->_next;
                }
                throw exception("no key found");
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

            unsigned int size() const {
                node_map *tmp = _list;
                unsigned int res = 0;

                while (tmp != nullptr) {
                    tmp = tmp->_next;
                    res++;
                }
                return res;
            }

            void add(KEY key, CONTENT content) {
                node_map *nnode = new node_map(key, content, _list, nullptr);

                if (_list == nullptr) {
                    _list = nnode;
                    return;
                }
                getLast()->_next = nnode;
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
            }

            void remove(KEY const& k) {
                if (!keyExists(k))
                    return;
                node_map *tmp = _list;

                while (tmp != nullptr) {
                    if (tmp->_key == k) {
                        ((node_map *)tmp->_before)->_next = tmp->_next;
                        delete tmp;
                        break;
                    }
                    tmp = tmp->_next;
                }
            }

            Map<KEY, CONTENT> &operator=(Map<KEY, CONTENT> const& map) {
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
