/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** kmath
*/

#ifndef KMATH_HPP_
#define KMATH_HPP_

#include "kstring.hpp"
#include "klist.hpp"

namespace kap35 {
    class string;
}

namespace kap35 {

    class math {
        public:

        static string uintToBinary(size_t const& i) {
            string res;
            size_t d = 1;
            size_t tmpI = i;

            if (i == 0)
                return "0";
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

        static size_t binToUInt(string const& str) {
            string strTmp = str;
            size_t res = 0;
            size_t mult = 1;

            strTmp.inverse();

            for (size_t i = 0; i < strTmp.size(); i++) {
                if (strTmp[i] == '1') {
                    res += mult;
                }
                mult *= 2;
            }
            return res;
        }

        static size_t hexaToUInt(string const& str) {
            list<string> bits;

            for (size_t i = 0; i < str.size(); i++) {
                switch (str[i]) {
                    case '0':
                        bits.pushBack("0000");
                        break;
                    case '1':
                        bits.pushBack("0001");
                        break;
                    case '2':
                        bits.pushBack("0010");
                        break;
                    case '3':
                        bits.pushBack("0011");
                        break;
                    case '4':
                        bits.pushBack("0100");
                        break;
                    case '5':
                        bits.pushBack("0101");
                        break;
                    case '6':
                        bits.pushBack("0110");
                        break;
                    case '7':
                        bits.pushBack("0111");
                        break;
                    case '8':
                        bits.pushBack("1000");
                        break;
                    case '9':
                        bits.pushBack("1001");
                        break;
                    case 'A':
                        bits.pushBack("1010");
                        break;
                    case 'B':
                        bits.pushBack("1011");
                        break;
                    case 'C':
                        bits.pushBack("1100");
                        break;
                    case 'D':
                        bits.pushBack("1101");
                        break;
                    case 'E':
                        bits.pushBack("1110");
                        break;
                    case 'F':
                        bits.pushBack("1111");
                        break;
                    default:
                        break;
                }
            }

            string bitsStr;

            for (size_t i = 0; i < bits.size(); i++)
                bitsStr += bits[i];

            return binToUInt(bitsStr);
        }

        static string uintToHexa(size_t const& i) {
            string bin = uintToBinary(i);
            string res = "";

            while (bin.size() % 4) {
                string tmpBin = "0";
                tmpBin += bin;
                bin = tmpBin;
            }

            list<string> bits = bin.divide(4);

            for (size_t bit = 0; bit < bits.size(); bit++) {
                size_t binInt = binToUInt(bits[bit]);

                if (binInt < 10) {
                    res += (char)(binInt + 48);
                } else {
                    res += (char)(binInt + 55);
                }
            }

            return res;
        }

        static string uintToOctal(size_t const& i) {
            string res;
            string bin = uintToBinary(i);
            while (bin.size() % 3) {
                string tmpBin = "0";
                tmpBin += bin;
                bin = tmpBin;
            }
            
            list<string> bins = bin.divide(3);

            for (size_t i = 0; i < bins.size(); i++) {
                string tmpInt(octalFrom3Bin(bins[i]));

                res += tmpInt;
            }

            return res;
        }

        static size_t octalToUint(string const& str) {
            string bin = "";

            for (size_t i = 0; i < str.size(); i++) {
                bin += binFrom1Octal(str[i]);
            }

            return binToUInt(bin);
        }

        static string uintToViceminal(size_t const& i) {
            return "";
        }

        static string uintToTrentadal(size_t const& i) {
            string res = "";
            string bin = uintToBinary(i);

            while (bin.size() % 35) {
                string tmpStr = "0";

                tmpStr += bin;
                bin = tmpStr;
            }
            list<string> bins = bin.divide(5);
            for (size_t i = 0; i < bins.size(); i++) {
                size_t valBin = binToUInt(bins[i]);
                if (valBin < 10) {
                    res += (char)(valBin + 48);
                } else {
                    res += (char)(valBin + 55);
                }
            }

            while (res.size() > 1) {
                if (res[0] != '0')
                    break;
                res.remove(0);
            }
            return res;
        }

        static size_t trentadalToUint(string const& str) {
            string bin;

            for (size_t i = 0; i < str.size(); i++) {
                string sstr = "";
                if (str[i] >= '0' && str[i] <= '9') {
                    sstr = uintToBinary(str[i] - 48);
                } else if (str[i] >= 'A' && str[i] <= 'V') {
                    sstr = uintToBinary(str[i] - 55);
                } else {
                    return binToUInt(bin);
                }

                while (sstr.size() < 5) {
                    string ssstr = "0";
                    ssstr += sstr;
                    sstr = ssstr;
                }

                bin += sstr;
            }
            return binToUInt(bin);
        }

        static string addBinary(string const& b1, string const& b2) {
            size_t r1 = binToUInt(b1);
            size_t r2 = binToUInt(b2);

            size_t r3 = r1 + r2;

            return uintToBinary(r3);
        }

        static string addHexa(string const& h1, string const& h2) {
            size_t r1 = hexaToUInt(h1);
            size_t r2 = hexaToUInt(h2);

            size_t r3 = r1 + r2;

            return uintToHexa(r3);
        }

        static string addOctal(string const& o1, string const& o2) {
            size_t r1 = octalToUint(o1);
            size_t r2 = octalToUint(o2);

            size_t r3 = r1 + r2;

            return uintToOctal(r3);
        }

        private:
            static size_t octalFrom3Bin(string const& bin) {
                return binToUInt(bin);
            }

            static string binFrom1Octal(char const& octal) {
                switch (octal) {
                case '1':
                    return "001";
                case '2':
                    return "010";
                case '3':
                    return "011";
                case '4':
                    return "100";
                case '5':
                    return "101";
                case '6':
                    return "110";
                case '7':
                    return "111";
                default:
                    return "000";
                }
            }
    };   
}

#endif /* !KMATH_HPP_ */
