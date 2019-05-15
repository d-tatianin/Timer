# Timer
A simple C++ timer for measuring the performance of your application.

## Using the timer:
### - Create an instance of timer in the scope (function/method) you want to measure the performance of. 
- First parameter is optional and it takes in a string literal, which is used to set the name of the current timer instance, set to         "Unknown" unless explicitly specified. 
- Second parameter is optional and is responsible for setting the unit of measurment, it is set to MILISECONDS by default unless otherwise   specified. You can also set it to SECONDS, or MINUTES.

### - The desturctor is automatically called after exiting the scope, which will log a message to the console containing the name of the timer, as well as the amount of time the timer lived for before getting destroyed.


