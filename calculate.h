#ifndef CALCULATE_H
#define CALCULATE_H

#include <QString>
#include <string>
#include <regex>

class Calculate
{
public:
    Calculate() {}
    ~Calculate() {}
    static QString cal(QString s);
private:
    static std::string infixToPosfix (std::string inExpr);  // 中缀表达式转后缀
    static std::string calcPosfix (std::string PosExpr);  // 计算后缀表达式
    static int getPriority(char ch);
    static const std::string regStr;
    static bool isBracketMatched(std::string str);
};

#endif // CALCULATE_H
