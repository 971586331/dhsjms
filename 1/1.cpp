
/**
 * 简单工厂模式
 */

#include <stdio.h>
#include <string>

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
