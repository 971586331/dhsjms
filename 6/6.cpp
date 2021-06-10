
/**
 * 装饰模式
 */

#include <stdio.h>
#include <string>
#include <iostream>

// 人类
class Person
{
private:
    std::string name;
public:
    Person()
    {

    }
    Person(std::string name)
    {
        this->name = name;
    }

    virtual void show()
    {
        std::cout << "装扮的" << name;
    }
};

// 服饰类
class Costume : public Person
{
    protected:
    Person * component;

    public:
    void Decorate(Person * component)
    {
        this->component = component;
    }

    void show() 
    {
        if( component != NULL )
            component->show();
    }
};

// TShirts类
class TShirts : public Costume
{
    private:

    public:
    void show() 
    {
        std::cout << "TShirts ";
        Costume::show();
    }
};

// pants类
class pants : public Costume
{
    private:

    public:
    void show() 
    {
        std::cout << "pants ";
        Costume::show();
    }
};

// slipper类
class slipper : public Costume
{
    private:

    public:
    void show() 
    {
        std::cout << "slipper ";
        Costume::show();
    }
};

int main()
{
    Person * xc = new Person("小菜");

    TShirts * ts = new TShirts();
    pants * pa = new pants();
    slipper * sl = new slipper();

    pa->Decorate(xc);
    ts->Decorate(pa);
    sl->Decorate(ts);
    sl->show();

    return 0;
}
