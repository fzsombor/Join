//
// Created by Fedor Zsombor on 2018. 02. 22..
//

#ifndef JOIN_EXPR_H
#define JOIN_EXPR_H


#include <string>
#include <ostream>

class Expr {
    enum typeValue {
        INT,
        STRING,
        LONG,
        CHAR,
        DOUBLE,
        SHORT,
        ERROR
    };


protected:
    int intExpr;
    double doubleExpr;
    std::string stringExp;
    typeValue type;

public:
    Expr(int intExpr) : intExpr(intExpr) {
        type = INT;
    }

    Expr(double doubleExpr) : doubleExpr(doubleExpr) {
        type = DOUBLE;
    }

    Expr(std::string stringExpr) : stringExp(stringExpr) {
        type = STRING;
    }

    Expr() {
        type = ERROR;
    }

    int getIntExpr() const {
        return intExpr;
    }

    double getDoubleExpr() const {
        return doubleExpr;
    }

    const std::string &getStringExp() const {
        return stringExp;
    }

    typeValue getType() const {
        return type;
    }

    friend std::ostream &operator<<(std::ostream &os, const Expr &expr) {

        switch (expr.type) {
            case INT:
                os << expr.intExpr;
                break;
            case DOUBLE:
                os << expr.doubleExpr;
                break;
            case STRING:
                os << expr.stringExp;
                break;
        }

        return os;
    }

    ~Expr() {
    }

};


#endif //JOIN_EXPR_H
