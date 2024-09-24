#include <iostream>

class Parent
{
public:
    void speak()
    {
        std::cout << "parent!" << std::endl;
    }
};

class Brother : public Parent
{
public:
    void speak()
    {
        std::cout << "brother!" << std::endl;
    }
};

class Sister : public Parent
{
};

int main(int argc, char *argv[])
{
    Parent parent;
    Brother brother;

    Parent *ppb = &parent;

    Brother *pbb = static_cast<Brother *>(ppb);

    std::cout << pbb << std::endl;
    pbb->speak(); // Undefined Behaviour - pointed object is parent and not brother

    return 0;
}
