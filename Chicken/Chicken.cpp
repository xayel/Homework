#include <iostream>
#include <cstring>

class Chicken
{
    private:
        int age = 24;
        char *name = nullptr;
    public:
        Chicken(){};
        Chicken(int _age) : age(_age) {};
        Chicken(int _age, const char *_name) : age(_age) 
        {
            int len = strlen(_name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = _name[i];
        };
        ~Chicken()
        {
            if (name != nullptr)
                delete[] name;
        }
        void setAge(int _age)
        {
            age = _age;
        }
        void setName(const char *_name)
        {
            if(name != nullptr)
                delete[] name;
            int len = strlen(_name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = _name[i];
        }

        const char *getName() const
        {
            return name;
        }

        const int &getAge() const
        {
            return age;
        }

        void makeEmpty()
        {
            if (name != nullptr)
                delete[] name;
            name = nullptr;             
        }

        Chicken &operator=(const Chicken &_l)
        {
            if (this == &_l)
                return *this;
            makeEmpty();
            age = _l.age;
            int len = strlen(_l.name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = _l.name[i];
            return *this;
        }

        Chicken(const Chicken &_l)
        {
            age = _l.age;
            int len = strlen(_l.name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = _l.name[i];
        }
        
};


int main()
{
    auto print = [](const Chicken &c){
        std::cout << "Hi, everyone! My name is " << c.getName()
                  << ", I am " << c.getAge() << " years old." << std::endl;
    };
    Chicken c(24, "Kunkun");
    print(c);

    Chicken d;
    d = c;
    print(d);

    Chicken a = c;
    print(a);

    c.setName("Xukun Cai");
    print(c);
    print(a);
    print(d);

    Chicken b;
    b = d = c;
    print(b);
    print(d);
    return 0;
}
