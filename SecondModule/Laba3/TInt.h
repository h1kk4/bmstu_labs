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

bool Check(const long &data) {
    return (data >= std::numeric_limits<int>::min() && data <= std::numeric_limits<int>::max());

}

class TInt {
private:
    int Value;
public:

    TInt() {}

    TInt(const long &data) {
        if (Check(data)) {
            Value = data;
        } else throw OverFlow();
    }

    ~TInt() {}

    TInt &operator=(const TInt &rhs) {
        Value = rhs.Value;
        return *this;
    }

    TInt &operator=(const long &rhs) {
        if (Check(rhs)) {
            Value = rhs;
            return *this;
        } else throw OverFlow();
    }

    TInt &operator+=(const TInt &rhs) {
        long tmp = Value + rhs.Value;
        if (Check(tmp)) {
            Value = tmp;
            return *this;
        } else throw OverFlow();

    }

    TInt &operator+=(const long &rhs) {

        long tmp = Value + rhs;
        if (Check(tmp)) {
            Value = tmp;
            return *this;
        } else throw OverFlow();
    }

    TInt &operator-=(const TInt &rhs) {
        long tmp = Value - rhs.Value;
        if (Check(tmp)) {
            Value = tmp;
            return *this;
        } else throw OverFlow();
    }

    TInt &operator-=(const long &rhs) {
        long tmp = Value - rhs;
        if (Check(tmp)) {
            Value = tmp;
            return *this;
        } else throw OverFlow();
    }

    TInt &operator*=(const TInt &rhs) {
        long tmp = Value * rhs.Value;
        if (Check(tmp)) {
            Value = tmp;
            return *this;
        } else throw OverFlow();

    }

    TInt &operator*=(const long &rhs) {
        long tmp = Value * rhs;
        if (Check(tmp)) {
            Value = tmp;
            return *this;
        } else throw OverFlow();

    }

    TInt &operator/=(const TInt &rhs) {
        Value /= rhs.Value;
        return *this;
    }

    TInt &operator/=(const long &rhs) {
        if (Check(rhs)) {
            Value = Value / rhs;
            return *this;
        } else throw OverFlow();
    }

    TInt &operator%=(const TInt &rhs) {
        Value %= rhs.Value;
        return *this;
    }

    TInt &operator%=(const long &rhs) {
        if (Check(rhs)) {
            Value = Value % rhs;
            return *this;
        } else throw OverFlow();
    }

    bool operator==(const TInt &rhs) {
        return (rhs.Value == Value);
    }

    bool operator==(const long &rhs) {
        if (Check(rhs)) {
            return (Value == rhs);
        } else throw OverFlow();
    }

    bool operator<=(const TInt &rhs) {
        return (rhs.Value >= Value);
    }

    bool operator<=(const long &rhs) {
        if (Check(rhs)) {
            return (Value >= rhs);
        } else throw OverFlow();
    }

    bool operator>=(const TInt &rhs) {
        return (rhs.Value <= Value);
    }

    bool operator>=(const long &rhs) {
        if (Check(rhs)) {
            return (Value >= rhs);
        } else throw OverFlow();
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

TInt operator+(const TInt &a, const long &data) {
    TInt c(a);
    return c += data;
}

TInt operator+(const long &data, const TInt &a) {
    TInt c(a);
    return c += data;
}

TInt operator-(const TInt &a, const TInt &b) {
    TInt c(a);
    return c -= b;
}

TInt operator-(const TInt &a, const long &data) {
    TInt c(a);
    return c -= data;
}

TInt operator-(const long &data, const TInt &a) {
    TInt c(a);
    return c -= data;
}

TInt operator/(const TInt &a, const TInt &b) {
    TInt c(a);
    return c /= b;
}

TInt operator/(const TInt &a, const long &data) {
    TInt c(a);
    return c /= data;
}

TInt operator/(const long &data, const TInt &a) {
    TInt c(a);
    return c /= data;
}

TInt operator*(const TInt &a, const TInt &b) {
    TInt c(a);
    return c *= b;
}

TInt operator*(const TInt &a, const long &data) {
    TInt c(a);
    return c *= data;
}

TInt operator*(const long &data, const TInt &a) {
    TInt c(a);
    return c *= data;
}

TInt operator%(const TInt &a, const TInt &b) {
    TInt c(a);
    return c %= b;
}

TInt operator%(const TInt &a, const long &data) {
    TInt c(a);
    return c %= data;
}

TInt operator%(const long &data, const TInt &a) {
    TInt c(a);
    return c %= data;
}

#endif //MODULE2LABA3_TINT_H
