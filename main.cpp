//
// Created by Chris on 8/3/17.
//

#include <iostream>
#include <thread>

void pause_thread(int n)
{
    std::this_thread::sleep_for (std::chrono::seconds(n));
    std::cout << "pause of " << n << " seconds ended\n";
}

int main()
{
    std::cout << "Spawning and detaching 3 threads...\n";
    std::thread (pause_thread,1).detach();

    std::thread (pause_thread,2).detach();

    std::thread (pause_thread,3).detach();

    std::cout << "Done spawning threads.\n";

    std::cout << "Wait 5 seconds for main thread...\n";
    pause_thread(5);
    return 0;
}