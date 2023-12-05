#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

class monitor {
private:
    // no. of readers
    int rcnt;

    // no. of writers
    int wcnt;

    // no. of readers waiting
    int waitr;

    // no. of writers waiting
    int waitw;

    // condition variable to check whether reader can read
    condition_variable canread;

    // condition variable to check whether writer can write
    condition_variable canwrite;

    // mutex for synchronization
    mutex condlock;

public:
    monitor() {
        rcnt = 0;
        wcnt = 0;
        waitr = 0;
        waitw = 0;
    }

    // mutex provide synchronization so that no other thread
    // can change the value of data
    void beginread(int i) {
        unique_lock<mutex> lock(condlock);

        // if there are active or waiting writers
        if (wcnt == 1 || waitw > 0) {
            // incrementing waiting readers
            waitr++;

            // reader suspended
            canread.wait(lock);
            waitr--;
        }

        // else reader reads the resource
        rcnt++;
        cout << "reader " << i << " is reading\n";
        lock.unlock();
        canread.notify_all();
    }

    void endread(int i) {
        // if there are no readers left then writer enters monitor
        unique_lock<mutex> lock(condlock);

        if (--rcnt == 0)
            canwrite.notify_one();
    }

    void beginwrite(int i) {
        unique_lock<mutex> lock(condlock);

        // a writer can enter when there are no active
        // or waiting readers or other writer
        if (wcnt == 1 || rcnt > 0) {
            ++waitw;
            canwrite.wait(lock);
            --waitw;
        }
        wcnt = 1;
        cout << "writer " << i << " is writing\n";
        lock.unlock();
    }

    void endwrite(int i) {
        unique_lock<mutex> lock(condlock);
        wcnt = 0;

        // if any readers are waiting, threads are unblocked
        if (waitr > 0)
            canread.notify_one();
        else
            canwrite.notify_one();
    }
};

// global object of monitor class
monitor M;

void reader(int i) {
    int c = 0;

    // each reader attempts to read 5 times
    while (c < 5) {
        this_thread::sleep_for(chrono::milliseconds(1));
        M.beginread(i);
        M.endread(i);
        c++;
    }
}

void writer(int i) {
    int c = 0;

    // each writer attempts to write 5 times
    while (c < 5) {
        this_thread::sleep_for(chrono::milliseconds(1));
        M.beginwrite(i);
        M.endwrite(i);
        c++;
    }
}

int main() {
    thread r[2], w[2];
    int id[2];
    for (int i = 0; i < 2; i++) {
        id[i] = i;

        // creating threads which execute reader function
        r[i] = thread(reader, id[i]);

        // creating threads which execute writer function
        w[i] = thread(writer, id[i]);
    }

    for (int i = 0; i < 2; i++) {
        r[i].join();
    }
    for (int i = 0; i < 2; i++) {
        w[i].join();
    }

    return 0;
}
