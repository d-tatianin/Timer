#include <Timer/Timer.h>

#include <thread>

int main()
{

    {
        // Scoped timer (meant to be used for measuring a function or a scope)
        Timer scopedTimer("Heap allocation test", TimeUnit::AUTO, true); // AUTO means the timer picks the best suitable measurment unit

        int* myArray = new int[500];
        delete[] myArray;
    } // The result is printed once we exit the scope (Takes about 7 microseconds on my machine, pretty fast!)

    // Another timer, this time scoped is set to false and we're measuring in microseconds
    Timer printingTimer("cout with flushing", TimeUnit::MICROSECONDS, false);
    for (int i = 0; i < 1000; i++)
    {
        printingTimer.Reset(); // reset here one more time for better precision
        std::cout << "Test Message" << std::endl;
        printingTimer.PrintElapsedReset(); // prints the elapsed time and resets
    } // Each cout takes about 300 microseconds on my machine (Incredibly slow! Even compared to a big heap allocation!)

    {
        Timer sleepingForOneSecond("One second sleep", true);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    } // This should take about 1 second on average, however, it's not very precise because of the way the OS does its scheduling

    Timer you_can_cout_too;
    std::cout << you_can_cout_too; // This works. Same as you_can_cout_too.GetElapsed()
    you_can_cout_too.SetTimeUnit(TimeUnit::SECONDS); // Changed the measurment unit to seconds

    std::cin.get();
    return 0;
}
