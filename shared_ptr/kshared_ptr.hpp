/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** shared_ptr
*/

#ifndef SHARED_PTR_HPP_
#define SHARED_PTR_HPP_

namespace kap35
{
    template<typename T>
    class shared_ptr {
        public:
            shared_ptr() {
                _val = nullptr;
                _after = nullptr;
                _hd = nullptr;
            }

            shared_ptr(T *ptr) {
                clear();
                _val = ptr;
                _after = nullptr;
                _hd = nullptr;
            }

            shared_ptr(shared_ptr const& ptr) {
                (shared_ptr)*this = ptr;
            }

            ~shared_ptr() {
                clear();
            }

            shared_ptr &operator=(shared_ptr const& ptr) {
                clear();
                _val = ptr._val;

                shared_ptr *last = ptr.getLast();
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
                _val = nullptr;
                if (_hd == nullptr && _after == nullptr) {
                    delete _val;
                    return;
                }
                if (_hd == nullptr) {
                    _after->changeAllHd(_after);
                    _after->_hd = nullptr;
                    return;
                }
                _hd->_after = _after;
            }

            T &get() {
                return *_val;
            }

        private:
            shared_ptr *getLast() {
                if (_after == nullptr)
                    return this;
                return _after->getLast();
            }

            void changeAllHd(shared_ptr *nhd) {
                _hd = nhd;
                if (_after == nullptr)
                    return;
                _after->changeAllHd(nhd);
            }

            T *_val;
            shared_ptr *_hd;
            shared_ptr *_after;
    };

} // namespace kap35


#endif /* !SHARED_PTR_HPP_ */
