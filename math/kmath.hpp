/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** kmath
*/

#ifndef KMATH_HPP_
#define KMATH_HPP_

#include "kstring.hpp"

namespace kap35 {
    class string;
} // namespace kap35


namespace kap35 {
    
    class math {
        public:

        static string intToBinary(unsigned int const& i) {
            string res;
            unsigned int d = 1;
            unsigned int tmpI = i;

            while (d < i)
                d *= 2;

            while (d > 0) {

                if (tmpI >= d) {
                    tmpI -= d;
                    res += "1";
                } else {
                    res += "0";
                }
                d /= 2;
            }

            while (res[0] == '0') {
                res.advance(1);
                if (res.size() == 0)
                    break;
            }

            return res;
        }

        static unsigned int binToUInt(string const& str) {
            string strTmp = str;
            unsigned int res = 0;
            unsigned int mult = 1;

            strTmp.inverse();

            for (unsigned int i = 0; i < strTmp.size(); i++) {
                if (strTmp[i] == '1') {
                    res += mult;
                }
                mult *= 2;
            }
            return res;
        }

        static string intToHexa(unsigned int const& i) {
            string bin = intToBinary(i);
            string res = "";

            while (bin.size() % 4) {
                string tmpBin = "0";
                tmpBin += bin;
                bin = tmpBin;
            }

            list<string> bits = bin.devide(4);

            for (unsigned int bit = 0; bit < bits.size(); bit++) {
                unsigned int binInt = binToUInt(bits[bit]);

                if (binInt < 10) {
                    res += (char)(binInt + 48);
                } else {
                    res += (char)(binInt + 55);
                }
            }

            return res;
        }

        static bool sivisible(int const& nb, int const& div) {
            return false;
        }

        static bool sivisible(unsigned int const& nb, unsigned int const& div) {
            return false;
        }

        static bool sivisible(float const& nb, float const& div) {
            return false;
        }

    };
    
} // namespace kap35


#endif /* !KMATH_HPP_ */
