#include <iostream>

#include <string>
#include <vector>
#include <map>

#include <algorithm>
#include <numeric>
#include <cmath>

enum Grade {
    F = 1,
    D,
    C,
    B,
    A
};

struct Student {
    std::string FIO;
    std::string Group;
    std::map<std::string, Grade> Grades;
};

std::vector<Student> LoadStudents() {
    return {
            {
                    "Anna",  "G7",
                    {
                            {"math",    Grade::D},
                            {"cs",      Grade::A},
                            {"english", Grade::A},
                            {"dutch", Grade::B},
                    }
            },
            {
                    "Petr",  "G7",
                    {
                            {"math",    Grade::B},
                            {"cs",      Grade::A},
                            {"dutch",   Grade::C},
                    }
            },
            {
                    "Vova",  "G1",
                    {
                            {"math",    Grade::A},
                            {"english", Grade::F},
                    }
            },
            {
                    "Vasya", "G3",
                    {
                            {"math",    Grade::C},
                            {"english", Grade::F},
                            {"cs",      Grade::B},
                            {"dutch", Grade::C},
                    }
            },
            {
                    "Anton", "G4",
                    {
                            {"math",    Grade::A},
                            {"english", Grade::A},
                            {"dutch",   Grade::C},
                            {"cs",    Grade::C},
                    }
            },
            {
                    "Masha", "G2",
                    {
                            {"math",    Grade::A},
                    }
            },
            {
                    "Sasha", "G6",
                    {
                            {"english", Grade::C},
                            {"russian", Grade::C},
                            {"dutch",   Grade::F},
                    }
            },
            {
                    "Jeka",  "G2",
                    {
                            {"english", Grade::A},
                    }
            },
            {
                    "Sveta", "G3",
                    {
                    }
            }
    };
}

struct MathBestMark {
    int mark;
    bool flag = true;
    std::string FIO;

    void operator()(Student &student) {
        if (flag && (student.Grades.find("math") != student.Grades.end())) {
            FIO = student.FIO;
            mark = student.Grades["math"];
            flag = false;
        }
        auto it = student.Grades.find("math");
        if (it != student.Grades.end()) {
            if (student.Grades.at("math") > mark && !flag) {
                FIO = student.FIO;
                mark = student.Grades.at("math");
            }
        }
    }


};

struct WorthMiddleMark {
    bool flag = true;
    size_t MiddleMark;
    std::string FIO;

    void operator()(Student &student) {
        size_t summ = 0;
        if (flag) {
            for (auto it = student.Grades.begin(); it != student.Grades.end(); ++it) {
                summ += it->second;
            }
            FIO = student.FIO;
            MiddleMark = summ / student.Grades.size();
            flag = false;
        } else {
            for (auto it = student.Grades.begin(); it != student.Grades.end(); ++it) {
                summ += it->second;
            }
            if (student.Grades.size() != 0) {
                if ((MiddleMark > (summ / student.Grades.size()))) {
                    MiddleMark = summ / student.Grades.size();
                    FIO = student.FIO;
                }
            }
        }
    }


};


struct Max {
    bool flag = true;
    size_t Count;
    std::string FIO;

    void operator()(Student &student) {
        if (flag) {
            Count = student.Grades.size();
            FIO = student.FIO;
            flag = false;
        } else {
            if (Count < student.Grades.size()) {
                FIO = student.FIO;
                Count = student.Grades.size();
            }
        }
    }

};

struct PrinterStudent {
    std::string neededGroup;

    void operator()(const Student &s) const {
        if (neededGroup == s.Group)
            std::cout << s.FIO << " studies in " << s.Group << std::endl;
    }
};


struct TwoParam {
    void operator()(const Student &s) const {
        if ((s.Grades.find("math") != s.Grades.end() && (s.Grades.find("cs")) != s.Grades.end())) {
            if (s.Grades.at("math") == 4 && s.Grades.at("cs") == 5)
                std::cout << s.FIO << " studies in " << s.Group << " good at cs" << std::endl;
        }
    }
};

struct AddLiterature {

    void operator()(Student &student) {
        size_t summ = 0;
        for (auto it = student.Grades.begin(); it != student.Grades.end(); ++it) {
            summ += it->second;
        }
        if (student.Grades.size() == 0) {
            student.Grades["Literature"] = Grade(1);
        } else
            student.Grades["Literature"] = (Grade) (int(ceil(summ / student.Grades.size())));
    }
};

struct DutchMark {
    void operator()(Student &student) {
        if (student.Grades.find("dutch") != student.Grades.end())
        std::cout << student.FIO << " studies in " << student.Group << " learning dutch, mark is "
                  << student.Grades.at("dutch") << std::endl;
        else
            std::cout << student.FIO << " studies in " << student.Group << " don't learning dutch" << std::endl;
    }
};

int main() {
    std::vector<Student> students = LoadStudents();

    auto it = std::for_each(students.begin(), students.end(), MathBestMark());
    std::cout << it.FIO << std::endl;

    auto it1 = std::for_each(students.begin(), students.end(), WorthMiddleMark());
    std::cout << "Have the wothr middle mark " << it1.FIO << " it's equal " << it1.MiddleMark << std::endl;

    auto it2 = std::for_each(students.begin(), students.end(), Max());
    std::cout << "Max " << it2.FIO << std::endl;

    std::for_each(students.begin(), students.end(), PrinterStudent{"G7"});

    std::for_each(students.begin(), students.end(), TwoParam());

    std::for_each(students.begin(), students.end(), AddLiterature());

    std::for_each(students.begin(), students.end(), DutchMark());

    return 0;
}