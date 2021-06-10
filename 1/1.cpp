
/**
 * 简单工厂模式
 */

#include <stdio.h>
#include <string>

// 运算抽像类
class Operation
{
// protected:

public:
    virtual double GetResult()
    {
        double result = 0;
        return result;
    }
    double NumA = 0;
    double NumB = 0;
};

// 加法运算类
class OperationAdd : public Operation
{
private:
    /* data */
public:
    double GetResult()
    {
        double result = 0;
        result = NumA + NumB;
        return result;
    }
};

// 减法运算类
class OperationSub : public Operation
{
private:
    /* data */
public:
    double GetResult()
    {
        double result = 0;
        result = NumA - NumB;
        return result;
    }
};

// 乘法运算类
class OperationMul : public Operation
{
private:
    /* data */
public:
    double GetResult()
    {
        double result = 0;
        result = NumA * NumB;
        return result;
    }
};

// 除法运算类
class OperationDiv : public Operation
{
private:
    /* data */
public:
    double GetResult()
    {
        double result = 0;
        result = NumA / NumB;
        return result;
    }
};

// 运算工厂类
class OperationFactory
{
public:
    static Operation * createOperate(char operate)
    {
        Operation *oper = NULL;
        switch (operate)
        {
        case '+':
            oper = new OperationAdd();
            break;
        case '-':
            oper = new OperationSub();
            break;
        case '*':
            oper = new OperationMul();
            break;
        case '/':
            oper = new OperationDiv();
            break;
        default:
            break;
        }
        return oper;
    }
};

int main()
{
    OperationFactory fac;
    Operation *oper = fac.createOperate('+');
    oper->NumA = 1;
    oper->NumB = 2;
    double result = oper->GetResult();
    printf("result = %f \n", result);

    return 0;
}
