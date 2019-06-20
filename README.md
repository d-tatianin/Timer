# Timer
A simple header-only C++ timer for measuring the performance of your application.

Observational error: ~200 nanoseconds.

## Using the timer:
### - Create an instance of Time by calling one of the constructors.
- `Timer()` -> Sets the timer name to `"Unknown"` and the measurement unit to `MILLISECONDS`. Result is printed upon destructor call.
- `Timer(MeasurmentUnit unit)` -> Sets the timer name to `"Unknown"` and the measurement unit to `unit`. Result is printed upon destructor call.
- `Timer(const char* name)` -> Sets the timer name to `name` and the measurement unit to `MILLISECONDS`. Result is printed upon destructor call.
- `Timer(const char* name, bool printResultUponDestruction)` -> Sets the timer name to `name` and the measurement unit to `MILLISECONDS`. Result is printed upon destructor call if `printResultUponDestruction` is `true`.
- `Timer(const char* name, MeasurmentUnit unit)` -> Sets the timer name to `name` and the measurement unit to `unit`. Result is printed upon destructor call.
- `Timer(const char* name, MeasurmentUnit unit, bool printResultUponDestruction)` -> Sets the timer name to `name` and the measurement unit to `unit`. Result is printed upon destructor call if `printResultUponDestruction` is `true`.
---
### - Getting your result:
- `~Timer()` -> same as `ResetAndShowResult()` unless `printResultUponDestruction` is `false`.
- `void Reset()` -> Resets the timer but does not return nor print the result.
- `void ResetAndShowResult()` -> Logs the result to the console and resets the timer.
- `float ResetAndGetTime()` -> Resets the timer and returns the elapsed time converted to the measurement unit selected.
- `float GetTime()` -> Returns the elapsed time converted to the measurement unit selected but does not reset the timer.
---
### - There is a total of 5 available measurement units that reside inside the unscoped MeasurementUnit enum:
- `NANOSECONDS`
- `MICROSECONDS`
- `MILLISECONDS`
- `SECONDS`
- `MINUTES`

The timer automatically converts elapsed time into selected measurement unit whenever neccessary.
