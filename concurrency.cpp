#include "include.h"
#include <thread>
#include <mutex>
#include<future>

using namespace std::chrono_literals;
// data shared between threads
std::list<int> g_Data;

std::mutex g_Mutex;
// function to simulate a long task
void download(std::string file, int &x, const int &y){
    int j=0;
    println("ID of this thread : ", std::this_thread::get_id());
    println("Download started :", file);
    for(int i = 0; i< y; i++){
        // std::lock_guard<std::mutex> mtx(g_Mutex); //automatic lock/unlock mutex, based on RAII
        g_Mutex.lock();
        g_Data.push_back(i);
        g_Mutex.unlock();
    }

    std::this_thread::sleep_for(std::chrono::seconds(2)); // sleep current thread
    println("Download ended");
}

void threads(){
    std::string file = "music.mp4";
    int x = 50000000, y = 18;
    
    // thread constructor is variadic, pass the args of the function as well
    std::thread th1(download, file, std::ref(x), std::cref(y)); // use helper functions to pass by (const)reference 
    std::thread th2(download, file, std::ref(x), std::cref(y));
    println("Thread1 ID:", th1.get_id()); 
    println("Thread2 ID:", th2.get_id()); 
    // th1.detach();
    if(th1.joinable()){
        th1.join();
    }
    th2.join();
    println("Size of shared data : ", g_Data.size());

    int cores = std::thread::hardware_concurrency();
    println("#Cores on this machine:", cores);
}


int async_task(int &x, const int &y, std::promise<int>& data){
    // thread is automatically created
    int sum{0};
    for(int i=0;i<y;i++){
        print(".");
        sum+=i;
        std::cout<<std::flush;
        std::this_thread::sleep_for(300ms);
    }

    // wait on the promise
    auto fut = data.get_future();
    println("[Task] Waiting for promised data from Main thread");
    auto res = fut.get(); // get() on future object
    println("[Task] Got promised data from Main thread = ", res);
    println("[Task] returns");
    return sum;
}
void async_demo(){
    int x = 50000000, y = 10;
    // create a promise and share it with the async task
    std::promise<int> data;
    // result must be explictly captured to run this task asynchronously
    // std::future<return type> is returned by std::async
    println("[Main] Started [Task]");
    std::future<int> result = std::async(std::launch::async, async_task,std::ref(x),std::cref(y), std::ref(data)); // can pass any callable, returns an object
    println("[Main] continues its execution");
    std::this_thread::sleep_for(5s);
    println("[Main] sets promised data");
    data.set_value(100);

    if(result.valid())
        // result.wait();
        println("[Main] Future of [Task] is valid");
        auto status = result.wait_for(1s);
        switch(status){
            case std::future_status::deferred:
                println("[Main] : [Task] is deferred");
                break;
            case std::future_status::ready: break;
            case std::future_status::timeout: println("[Main] : [Task] is still running");break;
        }
        //get() blocks until the result is received.
        println("[Main] receives Result is = ", result.get(), "from [Task]"); // with std::launch::deferred, task starts executing when get() 

}
int main(){
    async_demo();
}



/*
To use pthread, add -lpthread at the end
C++11 added support for concurrency
Thread class is defined in the standard namespace.
By default every thread is joinable, (needs to be joined).
You can detach a thread when you dont want to join. Once a thread is detached it can never become joinable.
std::async -> high level concurrency -> task-level. A task is a function which is automatically execeuted in separate thread.
std::promise and std::future come in pair
std::future is created by std::promise which is created by std::async.
Promise/future allow safe data sharing between threads.
Once you call get on the future, you cannot get() again.
Promise provides a thread-safe way to store and share a value or an exception.
This shared state can be accessed later from another thread through a future object.
Promise/future are two endpoints of a communication channel.
One operation stores a value in a promise and other operation will retrieve it through a future asynchronously.
Promise object can be used only once.
Promise/future can also be used to propogate exception between threads.
*/