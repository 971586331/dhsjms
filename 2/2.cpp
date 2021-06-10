
/**
 * 策略模式
 */

#include <stdio.h>
#include <string>

enum CHARE_TYPE_E
{
    CASH_NORMAL,    // 正常收费
    CASH_REBATE,    // 打折收费
    CASH_RETURN,    // 满减收费
};

// 收费超类
class cashSuper
{
private:
    /* data */
public:
    virtual double acceptCash(double money)
    {
        return money;
    }
};

// 正常收费类
class cashNormal : public cashSuper
{
    public:
    double acceptCash(double money)
    {
        return money;
    }
};

// 打折收费类
class cashRebate : public cashSuper
{
    private:
    double moneyRebate = 1.0;

    public:
    cashRebate(double rebate)
    {
        moneyRebate = rebate;
    }

    double acceptCash(double money)
    {
        return money * moneyRebate;
    }
};

// 满减收费类
class cashReturn : public cashSuper
{
    private:
    double moneyFull = 0.0;
    double moneyReturn = 0.0;

    public:
    cashReturn(double Full, double Return)
    {
        moneyFull = Full;
        moneyReturn = Return;
    }

    double acceptCash(double money)
    {
        double result = money;
        if( money > moneyFull )
            result = money - ((money/moneyFull)*moneyReturn);
        return result;
    }
};

// 收费工厂策略类
class CashFactory
{
    private:
    cashSuper * cs;

    public:
    CashFactory(cashSuper * super)
    {
        cs = super;
    }

    double GetResult(double money)
    {
        return cs->acceptCash(money);
    }
};

int main()
{
    double result;
    CashFactory *fac;

    fac = new CashFactory(new cashNormal());
    result = fac->GetResult(100);
    printf("result = %f \n", result);

    fac = new CashFactory(new cashRebate(0.8));
    result = fac->GetResult(100);
    printf("result = %f \n", result);

    fac = new CashFactory(new cashReturn(200, 50));
    result = fac->GetResult(1000);
    printf("result = %f \n", result);

    return 0;
}
