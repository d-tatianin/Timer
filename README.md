# Timer
A simple header-only C++ timer for measuring the performance of your application.

Observational error: ~100 nanoseconds in release with optimizations/inlining enabled.

## Using the timer:
### - Create an instance of Timer by calling one of the constructors.
- `Timer()` -> Sets the timer name to `"Unnamed"` and the unit of time to `AUTO`. Result is printed upon destructor call.
- `Timer(TimeUnit unit)` -> Sets the timer name to `"Unnamed"` and the unit of time to `unit`. Result is printed upon destructor call.
- `Timer(const char* name)` -> Sets the timer name to `name` and the unit of time to `AUTO`. Result is printed upon destructor call.
- `Timer(const char* name, bool printResultUponDestruction)` -> Sets the timer name to `name` and the unit of time to `AUTO`. Result is printed upon destructor call if `printResultUponDestruction` was set to `true`.
- `Timer(const char* name, TimeUnit unit)` -> Sets the timer name to `name` and the unit of time to `unit`. Result is printed upon destructor call.
- `Timer(const char* name, TimeUnit unit, bool printResultUponDestruction)` -> Sets the timer name to `name` and the unit of time to `unit`. Result is printed upon destructor call if `printResultUponDestruction` was set to `true`.
---
### - Getting your result:
- `~Timer()` -> same as `ResetAndShowResult()` unless `printResultUponDestruction` is `false`.
- `void Reset()` -> Resets the timer but does not return nor print the result.
- `void ResetAndShowResult()` -> Logs the result to the console and resets the timer.
- `void SetTimeUnit(TimeUnit unit)` -> Sets the unit of time used by the current timer to `unit`.
- `double ResetAndGetTime()` -> Resets the timer and returns the elapsed time converted to the unit of time selected.
- `double GetTime()` -> Returns the elapsed time converted to the measurement unit selected but does not reset the timer.
---
### - There is a total of 6 available units of time that reside inside the unscoped Unit enum inside the TimeUnit namespace:
- `AUTO`
- `NANOSECONDS`
- `MICROSECONDS`
- `MILLISECONDS`
- `SECONDS`
- `MINUTES`

The `AUTO` time unit is meant to be used with `ResetAndShowResult()` as it converts the elapsed time into the most convenient unit of time depending on the result. If the time unit is set to `AUTO`, the `GetTime()` and `ResetAndGetTime()` member functions will return the elapsed time in milliseconds. You can change this behavior by setting the `DEFAULT_AUTO_UNIT_GETTER_` define to the desired unit of time.

The timer automatically converts elapsed time into selected unit of time whenever neccessary.
