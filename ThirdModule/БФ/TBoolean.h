//
// Created by Алексей Долматов on 30.04.17.
//
#include <string>
#include <vector>
#include <math.h>
#include <map>

#ifndef BOOL_TBOOLEAN_H
#define BOOL_TBOOLEAN_H

class boolean_function {
public:
    using value_type = bool;
    using size_type = size_t;
    using reference = std::vector<value_type>::reference;
    using const_reference = std::vector<value_type>::const_reference;

    using iterator = typename std::vector<value_type>::iterator;
    using const_iterator = typename std::vector<value_type>::const_iterator;
private:
    std::vector<value_type> Data;
public:


    // возвращает функцию которая равна xn с размерностью dimension
    // пример 1
    // n = 0
    // dimension = 3
    // вернется функция "01010101"
    // пример 2
    // n = 1
    // dimension = 4
    // вернется функция "0011001100110011"
    static boolean_function var(size_t n, size_t dimension) {
        boolean_function func(dimension);
        for (auto i = 0; i + pow(2, n) < func.size(); ++i) {
            if (func[i] != 1 && func[i + pow(2, n)] <= func[func.size() - 1])
                func[i + pow(2, n)] = 1;
        }
        return func;
    };

    // тождественный ноль "от dimension переменных"
    static boolean_function zero(size_t dimension) {
        std::vector<value_type> tmp;
        size_t k = 0;
        while (k != pow(2, dimension)) {
            tmp.push_back(false);
            k++;
        }
        return boolean_function(tmp);
    }

    // тождественная единица "от dimension переменных"
    static boolean_function one(size_t dimension) {
        size_t k = 0;
        std::vector<value_type> tmp;
        while (k != pow(2, dimension)) {
            tmp.push_back(true);
            k++;
        }
        return tmp;
    }

    static boolean_function from_anf(std::vector<value_type> v) {
        std::vector<bool> tmp;
        std::map<int, std::vector<bool>> map1;
        std::vector<bool> fin;
        int j = 0;
        map1[j] = v;
        while (j != v.size()) {
            for (std::vector<bool>::iterator it = map1[j].begin(); it != map1[j].end() - 1; ++it) {
                map1[j + 1].push_back(*(it + 1) ^ *(it));
            }
            ++j;
        }
        for (auto p = map1.begin(); p != map1.end(); p++)
            fin.push_back((*p).second[0]);
        return fin;
    }

    boolean_function() {}

    // задает фунцию тождественного нуля от n переменных
    boolean_function(size_t n) {
        int k = pow(2, n);
        for (int i = 0; i < k; i++)
            Data.push_back(0);
    }

    // задает фунцию от n переменных. значение равно value
    // пример
    // пусть value = 14, т.е. 0...00001110 в двоичной системе
    // а n = 3
    // тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
    boolean_function(unsigned long long value, size_type n) {
        while (value) {
            Data.insert(Data.begin(), (value % 2));
            value = value / 2;
        }
        while (Data.size() < pow(2, n)) {
            Data.insert(Data.begin(), 0);
        }
        std::reverse(Data.begin(), Data.end());

    }

    // пусть table = "01110000"
    // тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
    boolean_function(const std::string &table) {
        size_t i = 0, k = 0, j = 0;
        j = table.size();
        while (j > 0) {
            k += j % 2;
            j = j / 2;
        }
        if (k != 1)
            throw std::exception();
        while (i != table.size()) {
            if (table[i] == '0')
                Data.push_back(false);
            else
                Data.push_back(true);

            ++i;
        }

    }

    // пусть table = {true, false, false, true};
    // тогда АНФ boolean_function будет равна x + y + 1
    boolean_function(const std::vector<value_type> &table) {
        size_t k = 0, j = 0;
        j = table.size();
        while (j > 0) {
            k += j % 2;
            j = j / 2;
        }
        if (k != 1)
            throw std::exception();
        Data = table;
    }

    boolean_function(const std::initializer_list<bool> vars) {
        size_t k = 0, j = 0;
        j = vars.size();
        while (j > 0) {
            k += j % 2;
            j = j / 2;
        }

        if (k != 1)
            throw std::exception();
        for (auto &v : vars) {
            Data.push_back(v);
        }
    }

    boolean_function(const boolean_function &table) {
        Data = table.Data;
    }

    boolean_function &operator=(const boolean_function &rhs) {
        Data = rhs.Data;
        return *this;
    }

    // сложение по модулю 2
    // если разное количество переменных - исключение
    boolean_function &operator+=(const boolean_function &rhs) {
        if (rhs.Data.size() != Data.size())
            throw std::exception();
        for (auto i = 0; i < Data.size(); ++i) {
            Data[i] = Data[i] ^ rhs.Data[i];
        }
        return *this;
    }

    // конъюнкция
    // если разное количество переменных - исключение
    boolean_function &operator*=(const boolean_function &rhs) {
        if (rhs.Data.size() != Data.size())
            throw std::exception();
        for (auto i = 0; i < Data.size(); ++i) {
            Data[i] = Data[i] * rhs.Data[i];
        }
        return *this;
    }

    // дизъюнкция
    // если разное количество переменных - исключение
    boolean_function &operator|=(const boolean_function &rhs) {
        if (rhs.Data.size() != Data.size())
            throw std::exception();
        for (auto i = 0; i < Data.size(); ++i) {
            Data[i] = Data[i] + rhs.Data[i];
        }
        return *this;
    }

    // побитовое отрицание
    boolean_function operator~() {
        std::vector<value_type>::iterator it = Data.begin();
        while (it != Data.end()) {
            *it = !*it;
            it++;
        }
        return *this;
    }

    // true если функции равны
    //  иначе false
    bool operator==(const boolean_function &obj) const {
        std::vector<bool> a1, a2;
        a1 = anf();
        a2 = obj.anf();

        double d1 = 0, d2 = 0;


        for (int x = 0; x < a1.size(); x++) {
            d1 += a1[x] * pow(2, x);
        }
        for (int x = 0; x < a2.size(); x++) {
            d2 += a2[x] * pow(2, x);
        }


        return (d1 == d2);
    }

    // true если одна функция сравнима и больше или равна rhs
    // false если сравнима и меньше rhs
    // logic_error если фунции не сравнимы
    bool operator>=(const boolean_function &rhs) const {
        if (this->size() == rhs.size()) {
            size_t t = 0;
            for (size_t i = 0; i < Data.size(); ++i) {
                if (Data[i] >= rhs.Data[i])
                    ++t;
            }
            if (t == Data.size())
                return true;
            else {
                t = 0;
                for (size_t i = 0; i < Data.size(); ++i) {
                    if (Data[i] <= rhs.Data[i])
                        ++t;
                }
            }
            if (t == Data.size())
                return false;
        }
        throw std::exception();
    }


    reference operator[](size_type ind) {
        if (size() == 0)
            throw std::exception();
        if (ind < 0 || ind >= size())
            throw std::exception();
        return Data[ind];
    }

    const_reference operator[](size_type ind) const {
        if (size() == 0)
            throw std::exception();
        if (ind < 0 || ind >= size())
            throw std::exception();
        return Data[ind];

    }

    reference at(size_type ind) {

        return Data.at(ind);
    }

    const_reference at(size_type ind) const {
        return Data.at(ind);
    }

    iterator begin() {
        return Data.begin();
    }

    iterator end() {
        return Data.end();
    }

    const_iterator cbegin() const {
        return Data.cbegin();
    }

    const_iterator cend() const {
        return Data.cend();
    }

    // длина столбца функции
    size_type size() const throw() {
        return Data.size();
    }

    // количество переменных
    size_type dimension() const throw() {
        size_t k = 0;
        size_t len = Data.size();
        for (k; len > 1; k++)
            len /= 2;
        return k;
    }

    // возвращает значение функции
    // пусть boolean_function задает функцию f(x, y, z)
    // тогда функция вернет f(vars[0], vars[1], vars[2])
    bool operator()(const std::vector<bool> &vars) const {
        std::string tmp;
        for (size_t i = 0; i < vars.size(); ++i) {
            if (vars[i] == 0)
                tmp += "0";
            else
                tmp += "1";
        }
        size_t k = 0, fin = 0;
        for (size_t i = tmp.size(); i > 0; i--) {
            fin += pow(2, k) * tmp[i - 1];
            ++k;
        }
        return Data[fin];
    }

    bool operator()(const std::initializer_list<bool> vars) const {
        std::string tmp;
        for (auto &v : vars) {
            if (v == false)
                tmp += "0";
            else
                tmp += "1";
        }
        int res = 0;
        int k = 0;
        for (int i = tmp.size() - 1; i > -1; i--) {
            if (tmp[i] == '1')
                res += pow(2, k);
            k++;
        }
        return Data[res];
    }


    // T(x1, x2, ..., xN) - текущая функция
    // operator вернет новую функцию, которая равна композиции G = T(fs[0], fs[1], ..., fs[N-1])
    boolean_function operator()(const std::vector<boolean_function> &fs) const {
        if (!fs.size()) return NULL;
        long long int a = 0, b = 0;
        std::vector<std::vector<bool>> tmp;
        for (int x = 0; x < fs.size(); x++) {
            if (a < fs[x].size()) a = fs[x].size();
            tmp.push_back(fs[x].Data);
        }

        std::vector<bool> ans;

        int counter = 0;
        for (int x = 0; x < a; x++) {
            b = 0;
            counter = 0;

            for (int y = tmp.size() - 1; y >= 0; --y) {
                b += tmp[y][x % tmp[y].size()] * pow(2, counter);
                counter++;
            }

            ans.push_back(Data[b]);

        }

        boolean_function ans1(ans);

        return ans1;
    }

    boolean_function operator()(const std::initializer_list<boolean_function> vars) const {

        std::vector<boolean_function> tmp = vars;

        return this->operator()(tmp);
    }

    bool is_monotone() const {
        if (Data.size() == 0)
            throw std::exception();
        for (size_t i = 0; i < Data.size() - 1; ++i)
            if (Data[i] > Data[i + 1])
                return false;
        return true;
    }

    bool is_symmetric() const {
        std::vector<value_type> fin;
        for (size_t i = Data.size() - 1; i > -1; --i) {
            if (Data[i] == true)
                fin.push_back(false);
            else
                fin.push_back(true);
        }

        if (fin == Data)
            return true;
        else
            return false;
    }

    bool is_linear() const {
        std::vector<value_type> a = this->anf();
        size_t t = 0;
        for (size_t i = 1; i < a.size(); ++i) {
            if (i == pow(2, t))
                ++t;
            else if (a[i] == 1)
                return false;
        }
        return true;
    }

    bool is_T1() const {
        return (Data[Data.size() - 1] == 1);
    }

    bool is_T0() const {
        return !(Data[0]);
    }

    bool is_balanced() const {
        size_t i = 0, t = 0, f = 0;
        while (i != Data.size()) {
            if (Data[i] == true)
                ++t;
            else
                ++f;
            i++;
        }
        if (t == f)
            return true;
        else
            return false;
    }

    size_t weight() const {
        size_t i = 0, t = 0;
        while (i != Data.size()) {
            if (Data[i] == true)
                ++t;
            i++;
        }
        return t;
    }

    bool is_functionally_complete_system() const {

        bool f_T0 = is_T0();
        bool f_T1 = is_T1();
        bool s = is_symmetric();
        bool l = is_linear();
        bool m = is_monotone();
        if (f_T0 == false && f_T1 == false && s == false && l == false && m == false)
            return true;
        else
            return false;
    }

    // Возвращает АНФ функции
    std::vector<value_type> anf() const {
        std::vector<bool> res;
        std::vector<bool> tmp = Data;
        for (size_t i = 0; i < size(); ++i) {
            res.push_back(tmp[0]);
            for (size_t j = 0; j < size() - 1; ++j) {
                if (tmp[j] == tmp[j + 1]) {
                    tmp[j] = false;
                    continue;
                }
                tmp[j] = tmp[j] + tmp[j + 1];
            }
        }
        return res;
    }
};

// пусть boolean_function представляет из себя функцию "01110000"
// тогда get_polynom вернет строку "x0 + x1 + x0x1 + x0x2 + x1x2 + x0x1x2"
std::string get_polynom(const boolean_function &rhs) {
    boolean_function c = rhs.anf();
    std::string tmp;
    for (int i = 0; i < c.size(); i++) {
        if (c[i] != 0) {
            if (i == 0) {
                tmp += "1";
                tmp += " + ";
                continue;
            }
            int ch = i;
            std::vector<int> num;
            while (ch > 0) {
                num.push_back(ch % 2);
                ch /= 2;
            }
            for (int j = 0; j < num.size(); j++) {
                if (num[j] == 1) {
                    tmp += "x";
                    tmp += std::to_string(j + 1);
                }
            }
            if (i + 1 != c.size())
                tmp += " + ";
        }
    }
    return tmp;
}


boolean_function operator+(const boolean_function &a, const boolean_function &b) {
    boolean_function f(a);
    f += b;
    return f;
}

boolean_function operator*(const boolean_function &a, const boolean_function &b) {
    boolean_function f(a);
    f *= b;
    return f;
}

boolean_function operator|(const boolean_function &a, const boolean_function &b) {
    boolean_function f(a);
    f |= b;
    return f;
}

bool operator!=(const boolean_function &a, const boolean_function &b) {
    return !(a == b);
}

#endif //BOOL_TBOOLEAN_H
