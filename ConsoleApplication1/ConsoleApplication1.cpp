#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class MyClass {
public:
    void DoWork() {
        this_thread::sleep_for(chrono::milliseconds(3000));
        std::cout << "flow number" << this_thread::get_id() << "\t START DoWork" << std::endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        std::cout << "flow number" << this_thread::get_id() << "\t STOP DoWork" << std::endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
    }

    int Sum(int a, int b) {
        this_thread::sleep_for(chrono::milliseconds(2000));
        std::cout << "flow number" << this_thread::get_id() << "\t START SUM" << std::endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        std::cout << "flow number" << this_thread::get_id() << "\t STOP SUM" << std::endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        return a + b;
    }
};


int main() {
    MyClass m;
    int result;
    auto f = [&](int a = 5, int b = 12) {result = m.Sum(a, b); };
    thread th(f);
    thread t([&]() {m.DoWork(); });
    // cout << Sum(5,6)<<endl;

    for (size_t i = 0; i < 20; i++) {
        cout << "flow number" << this_thread::get_id() << "\t iteration number " << i << "\n";
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    th.join();
    t.join();

    std::cout << result << std::endl;
    return 0;
}

