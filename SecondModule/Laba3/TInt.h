//
// Created by Алексей Долматов on 14.03.17.
//

#ifndef MODULE2LABA3_TINT_H
#define MODULE2LABA3_TINT_H

#include <istream>
#include <string>

class OverFlow : public std::exception {
public:
    const char *what() const noexcept { return "Ooops! Overflow!\n"; }
};

bool Check(const long long &data) {
    if (data >= std::numeric_limits<int>::min() && data <= std::numeric_limits<int>::max()){
        return true;
    } else throw OverFlow();

}

class TInt {
private:
    int Value;
public:

    TInt() {}

    TInt(const long long &data) {
        if (Check(data)) Value = data;

    }

    ~TInt() {}



    TInt &operator=(const TInt &rhs) {
        Value = rhs.Value;
        return *this;
    }

    TInt &operator=(const long long &rhs) {
        if (Check(rhs)) {
            Value = rhs;
            return *this;
        }
    }
    TInt &operator=(const int &rhs) {
        if (Check(rhs)) {
            Value = rhs;
            return *this;
        }
    }

    TInt &operator+=(const TInt &rhs) {
        long long tmp = (long long )Value + rhs.Value;
        if (Check(tmp)) {
            Value = tmp;
            return *this;
        }

    }

    TInt &operator+=(const long long &rhs) {

        long long tmp = Value + rhs;
        if (Check(tmp)) {
            Value = tmp;
            return *this;
        }
    }
    TInt &operator+=(const int &rhs) {

        long long tmp = Value + rhs;
        if (Check(tmp)) {
            Value = tmp;
            return *this;
        }
    }
    TInt &operator-=(const TInt &rhs) {
        long long tmp = (long long )Value - rhs.Value;
        if (Check(tmp)) {
            Value = tmp;
            return *this;
        }
    }

    TInt &operator-=(const long long &rhs) {
        long long tmp = Value - rhs;
        if (Check(tmp)) {
            Value = tmp;
            return *this;
        }
    }
    TInt &operator-=(const int &rhs) {
        long long tmp = Value - rhs;
        if (Check(tmp)) {
            Value = tmp;
            return *this;
        }
    }
    TInt &operator*=(const TInt &rhs) {
        long long tmp = (long long )Value * rhs.Value;
        if (Check(tmp)) {
            Value = tmp;
            return *this;
        }

    }

    TInt &operator*=(const int &rhs) {
        long long tmp = (long long )Value * rhs;
        if (Check(tmp)) {
            Value = tmp;
            return *this;
        }

    }

    TInt &operator*=(const long long &rhs) {
        long long tmp = Value * rhs;
        if (Check(tmp)) {
            Value = tmp;
            return *this;
        }

    }

    TInt &operator/=(const TInt &rhs) {
        Value /= rhs.Value;
        return *this;
    }
    TInt &operator/=(const int &rhs) {
        Value /= rhs;
        return *this;
    }

    TInt &operator/=(const long long &rhs) {
        if (Check(rhs)) {
            Value = Value / rhs;
            return *this;
        }
    }

    TInt &operator%=(const TInt &rhs) {
        Value %= rhs.Value;
        return *this;
    }
    TInt &operator%=(const int &rhs) {
        Value %= rhs;
        return *this;
    }
    TInt &operator%=(const long long &rhs) {
        if (Check(rhs)) {
            Value = Value % rhs;
            return *this;
        }
    }

    bool operator==(const TInt &rhs) {
        return (rhs.Value == Value);
    }
    bool operator==(const int &rhs) {
        return (rhs == Value);
    }
    bool operator==(const long long &rhs) {
        if (Check(rhs)) {
            return (Value == rhs);
        }
    }

    bool operator<=(const TInt &rhs) {
        return (rhs.Value >= Value);
    }
    bool operator<=(const int &rhs) {
        return (rhs >= Value);
    }
    bool operator<=(const long long &rhs) {
        if (Check(rhs)) {
            return (Value >= rhs);
        }
    }

    bool operator>=(const TInt &rhs) {
        return (rhs.Value <= Value);
    }
    bool operator>=(const int &rhs) {
        return (rhs <= Value);
    }
    bool operator>=(const long long &rhs) {
        if (Check(rhs)) {
            return (Value >= rhs);
        }
    }

    operator int() {
       return Value;
    }
    friend std::ostream &operator<<(std::ostream &out, const TInt x);

};

std::ostream &operator<<(std::ostream &out, const TInt x) {
    out << x.Value;
    return out;
}

TInt operator+(const TInt &a, const TInt &b) {
    TInt c(a);
    return c += b;
}

TInt operator+(const TInt &a, const long long &data) {
    TInt c(a);
    return c += data;
}

TInt operator+(const long long &data, const TInt &a) {
    TInt c(a);
    return c += data;
}
TInt operator+(const int &data, const TInt &a) {
    TInt c(a);
    return c += data;
}
TInt operator+(const TInt &data, const int &a) {
    TInt c(a);
    return c += data;
}
TInt operator-(const TInt &a, const TInt &b) {
    TInt c(a);
    return c -= b;
}
TInt operator-(const int &a, const TInt &b) {
    TInt c(a);
    return c -= b;
}
TInt operator-(const TInt &a, const long long &data) {
    TInt c(a);
    return c -= data;
}

TInt operator-(const long long &data, const TInt &a) {
    TInt c(a);
    return c -= data;
}

TInt operator/(const TInt &a, const TInt &b) {
    TInt c(a);
    return c /= b;
}

TInt operator/(const TInt &a, const long long &data) {
    TInt c(a);
    return c /= data;
}

TInt operator/(const long long &data, const TInt &a) {
    TInt c(a);
    return c /= data;
}
TInt operator/(const int &data, const TInt &a) {
    TInt c(a);
    return c /= data;
}
TInt operator/(const TInt &data, const int &a) {
    TInt c(a);
    return c /= data;
}
TInt operator*(const TInt &a, const TInt &b) {
    TInt c(a);
    return c *= b;
}
TInt operator*(const int &a, const TInt &b) {
    TInt c(a);
    return c *= b;
}
TInt operator*(const TInt &a, const long long &data) {
    TInt c(a);
    return c *= data;
}

TInt operator*(const long long &data, const TInt &a) {
    TInt c(a);
    return c *= data;
}

TInt operator%(const TInt &a, const TInt &b) {
    TInt c(a);
    return c %= b;
}

TInt operator%(const TInt &a, const long long &data) {
    TInt c(a);
    return c %= data;
}

TInt operator%(const long long &data, const TInt &a) {
    TInt c(a);
    return c %= data;
}
TInt operator%(const int &data, const TInt &a) {
    TInt c(a);
    return c %= data;
}

#endif //MODULE2LABA3_TINT_H
