/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** shared_ptr
*/

#ifndef SHARED_PTR_HPP_
#define SHARED_PTR_HPP_

#include "kexceptions.hpp"

namespace kap35
{
    template<typename T>
    class shared_ptr {
        public:

            shared_ptr(T *val) {
                *this = val;
            }

            shared_ptr(shared_ptr<T> const& ptr) {
                *this = ptr;
            }

            shared_ptr() {
                _val = nullptr;
                _after = nullptr;
                _hd = nullptr;
            }

            ~shared_ptr() {
                clear();
            }

            shared_ptr &operator=(shared_ptr<T> const& ptr) {
                clear();
                if (ptr.isEmpty())
                    return *this;
                _val = ptr._val;

                shared_ptr<T> *last = ptr.getLast();
                last->_after = this;
                _hd = ptr._hd;

                return *this;
            }

            shared_ptr &operator=(T *val) {
                clear();
                _val = val;
                _after = nullptr;
                _hd = nullptr;
                return *this;
            }

            void clear() {
                if (_hd == nullptr && _after == nullptr) {
                    if (_val != nullptr) {
                        delete (T *)_val;
                        _val = nullptr;
                    }
                    return;
                }
                _val = nullptr;
                if (_hd == nullptr) {
                    _after->changeAllHd(_after);
                    _after->_hd = nullptr;
                    return;
                }
                _hd->_after = _after;
            }

            T &get() {
                if (isEmpty())
                    throw exception("no value in shared ptr");
                return *_val;
            }

            bool isEmpty() const {
                if (_val == nullptr)
                    return true;
                return false;
            }

        private:
            shared_ptr<T> *getLast() const {
                if (_after == nullptr)
                    return (shared_ptr<T> *)this;
                return _after->getLast();
            }

            void changeAllHd(shared_ptr *nhd) {
                _hd = nhd;
                if (_after == nullptr)
                    return;
                _after->changeAllHd(nhd);
            }

            T *_val = nullptr;
            shared_ptr<T> *_hd = nullptr;
            shared_ptr<T> *_after = nullptr;
    };

} // namespace kap35


#endif /* !SHARED_PTR_HPP_ */
