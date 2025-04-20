#include <ctime>
#include <string>
#include <iostream>
#include <vector>
#include <thread>

// on linux
#include <unistd.h>


using namespace std::literals;

class Machine
{
public:
    virtual int cpu_n_core() = 0;
    virtual ~Machine() = 0;
};

Machine::~Machine()
{
}

class Linux : public Machine
{
public:
    int cpu_n_core() {
        return sysconf(_SC_NPROCESSORS_ONLN);
    }
};

std::string get_greet(const std::string& who) {
    return "Hello " + who;
}

void print_localtime() {
    std::time_t result = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&result));
}

void worker(std::stop_token stop, int id)
{
    for (;;) {
        std::cout << "Thread #" << id << " is executing\n";
        std::this_thread::sleep_for(200ms);
        if (stop.stop_requested()) {
            std::cout << "Thread #" << id << " is exiting\n";
            break;
        }
    }
}

int main(int argc, char** argv) {
    std::string who = "world";
    if (argc > 1) {
        who = argv[1];
    }
    int n_core = 0;
    int n_task = 0;

    Machine *hardware = new Linux();
    n_core = hardware->cpu_n_core();
    delete hardware;
    n_task = n_core * 2 + 2;

    std::cout << get_greet(who) << " you have " << n_core << " cores on your hardware" << std::endl;
    std::cout << "You can run " << n_task << " parallel task!\n";

    int array[] = {11, 22, 33, 44, 55};

    for (auto item: array) {
        std::cout << item << std::endl;
    }

    std::vector<std::jthread *> threads;
    for (int i = 0; i < n_task; i++) {
        threads.push_back(new std::jthread(worker, i));
    }

    std::this_thread::sleep_for(10s);
    for (auto th : threads) {
        th->request_stop();
    }

    for (auto th : threads) {
        th->join();
    }

    print_localtime();
    return 0;
}
