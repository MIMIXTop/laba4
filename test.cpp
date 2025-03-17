#include <iostream>
#include <list>
#include <string>

class strr
{
private:
    std::string s;
public:
    strr();
    strr(std::string str) : s(str){};
    ~strr();
    strr(strr &)
};

strr::strr(/* args */)
{
}

strr::~strr()
{
}


class test
{
private:
    std::string num;
    std::list<int> list;
public:
    test(){
        std::cout << "Default constr" << std::endl;
    }
    ~test(){
        std::cout << "Destruct" << std::endl;
    };

    test(std::string numb, std::list<int> l) : num(numb), list(l){
        std::cout << "Construct" << std::endl;
    };

    test(test& t){
        num = t.num;
        list = t.list;
        std::cout << "Copy constr" << std::endl;
    }

    test(test&& t){
        num = t.num;
        list = t.list;

        t.num = nullptr;
        t.list.clear();
        std::cout << "Move constr" << std::endl;
    }

    void createCopyList( t, int number){
        for(int i = 0; i < number; ++i){
            list.emplace_back(t);
        }
    }

    void print(){
        std::cout << num << std::endl;
        for (auto &&i : list) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
    }
};

int main(){
    test t;

}



