// C++17 features:: std::invoke 

#include <iostream>
#include <functional>

template <typename Callable>
class Proxy
{
    Callable _c;
    public:
        Proxy(Callable c)
            : _c(c){}
        template<class... Args>
        decltype(auto) operator()(Args&&... args)
        {
            return std::invoke(_c, std::forward<Args>(args)...);
        }
};

auto add = [](int x, int y) { return x + y; };

int main()
{
    Proxy<decltype(add)> P {add};
    
    std::cout <<  P(1, 2);

    std::cout << "\n\nstd::invoke\n----------------------------\n";

    std::cout << "Invokes a Callable Object with Parameters -> " << 
                  "Examples of Callable Objects are\n";

    std::cout << "std::function or std::bind where " <<
         "an object can be called like a regular function.\n";


    return 0;
}