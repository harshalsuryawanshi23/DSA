#include <mutex>
#include <semaphore>
using namespace std;

class DiningPhilosophers {
    binary_semaphore fork0{1};
    binary_semaphore fork1{1};
    binary_semaphore fork2{1};
    binary_semaphore fork3{1};
    binary_semaphore fork4{1};

    binary_semaphore* fork[5] = {
        &fork0, &fork1, &fork2, &fork3, &fork4
    };

    mutex m;

public:
    DiningPhilosophers() {}

    void wantsToEat(
        int philosopher,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork
    ) {

        {
            lock_guard<mutex> lock(m);

            fork[philosopher]->acquire();
            fork[(philosopher + 1) % 5]->acquire();
        }

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        putRightFork();

        fork[philosopher]->release();
        fork[(philosopher + 1) % 5]->release();
    }
};