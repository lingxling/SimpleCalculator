#include "calculate.h"
#include <stack>
#include <sstream>
#include <iomanip>

const std::string Calculate::regStr = "^[+\\-]{0,1}(\\()*\\d+(\\.\\d+)?([+\\*/\\-]\\d+(\\.\\d+)?)*(\\))*([+\\-\\*/](\\()*\\d+(\\.\\d+)?([+\\*/\\-]\\d+(\\.\\d+)?)*(\\))*)*";

int Calculate::getPriority(char ch){  //获取优先级
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return -1;
}
bool Calculate::isBracketMatched(std::string str) {
    std::stack<char> brackets;
    for (unsigned int i = 0; i < str.length(); ++i) {
        if (str[i] == '(') brackets.push('(');
        if (str[i] == ')') {
            if (brackets.empty()) return false;
            brackets.pop();
        }
    }
    if (brackets.empty()) return true;
    return false;
}
QString Calculate::cal(QString expr){
    std::regex reg(regStr);
    std::string s = expr.toStdString();
    if (!isBracketMatched(s)) return expr;
    if (std::regex_match(s, reg)) {
        if (s[0] != '-' && s[0] != '+') return QString::fromStdString(calcPosfix(infixToPosfix(s)));
        return QString::fromStdString(calcPosfix(infixToPosfix(s.substr(1))));
    }
    return expr;
}

/*
 * 将包含小括号和小数的中缀表达式转为后缀表达式
 */
std::string Calculate::infixToPosfix (std::string inExpr) {
    if (inExpr.length() == 0) return inExpr;
    std::stack<char> op;
    std::string posfix = "";
    for (unsigned int i = 0; i < inExpr.length(); ++i) {
        if (inExpr[i] >= '0' && inExpr[i] <= '9') {
            while (i < inExpr.length() && ((inExpr[i] >= '0' && inExpr[i] <= '9') || inExpr[i] == '.')) {
                posfix.push_back(inExpr[i]);
                ++i;
            }
            --i;
            posfix.push_back(' ');  // 在数字、字符之间插入空格
        }
        else if (inExpr[i] == '(') op.push(inExpr[i]);
        else if (inExpr[i] == ')') {
            while (!op.empty() && op.top() != '(') {
                char tmp = op.top();
                op.pop();
                posfix.push_back(tmp);
                posfix.push_back(' ');
            }
            if (!op.empty()) op.pop();
        }
        else {
            if (op.empty()) op.push(inExpr[i]);
            else {
                while (!op.empty()) {
                    char tmp = op.top();
                    if (getPriority(tmp) >= getPriority(inExpr[i])) {
                        posfix.push_back(tmp);
                        posfix.push_back(' ');
                        op.pop();
                    }
                    else break;
                }
                op.push(inExpr[i]);
            }
        }
    }
    while (!op.empty()) {
        posfix.push_back(op.top());
        posfix.push_back(' ');
        op.pop();
    }
    return posfix;
}

/*
 * 计算含有小数的后缀表达式
 */
std::string Calculate::calcPosfix (std::string PosExpr){
    if (PosExpr.length() == 0) return PosExpr;
    std::stack<double> numbers;
    for (unsigned int i = 0; i < PosExpr.length(); ++i) {
        if (PosExpr[i] == ' ') continue;
        if (PosExpr[i] >= '0' && PosExpr[i] <= '9') {
            std::string dig = "";
            while (i < PosExpr.length() && ((PosExpr[i] >= '0' && PosExpr[i] <= '9') || PosExpr[i] == '.')) {
                dig.push_back(PosExpr[i]);
                ++i;
            }
            --i;
            numbers.push(std::stod(dig));
        }
        else {
            double a = numbers.top();
            numbers.pop();
            double b = numbers.top();
            numbers.pop();
            switch (PosExpr[i]) {
            case '+':
                numbers.push(b + a);
                break;
            case '-':
                numbers.push(b - a);
                break;
            case '*':
                numbers.push(b * a);
                break;
            case  '/':
                numbers.push(b / a);
                break;
            }
        }
    }
    std::stringstream ss;
    ss << std::setprecision(15) << numbers.top();
    return ss.str();
}
