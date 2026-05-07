*This project has been created as part of the 42 curriculum by texeber.*

# Philosophers

## Description

The Philosophers project is an introduction to multithreading and process synchronization in C.  
The goal of the project is to solve the classic Dining Philosophers Problem, which demonstrates common issues in concurrent programming such as:

- Race conditions
- Deadlocks
- Starvation
- Resource sharing

Each philosopher is represented by a thread and alternates between:
- thinking
- eating
- sleeping

To eat, a philosopher must acquire two forks (shared resources protected with mutexes).  
The challenge is to ensure that philosophers can eat without causing deadlocks or starving other philosophers.

This project focuses on:
- POSIX threads (`pthread`)
- Mutex synchronization
- Precise timing management
- Concurrent programming concepts
- Safe shared memory access

# Instructions

## Compilation

To compile use:

```bash
make
```

Available Makefile rules:
```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

## Execution

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep number_of_times_each_philosopher_must_eat
```
### Arguments

1. `number_of_philosophers:` Number of philosophers/forks.
2. `time_to_die:` Time in ms before a philosopher dies if they don't eat.
3. `time_to_eat:` Time in ms spent eating.
4. `time_to_sleep:` Time in ms spent sleeping.
5. `number_of_times_each_philosopher_must_eat:` (optional) Simulation stops once all philosophers have eaten enough.

###Example
```bash
./philo 5 800 200 200
```
This launches:

- 5 philosophers
- philosophers die after 800ms without eating
- eating takes 200ms
- sleeping takes 200ms

# Resources

## Documentation

- POSIX thread documentation:<br>
	https://man7.org/linux/man-pages/man7/pthreads.7.html
- Mutex documentation:<br>
	https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3.html
	https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html

## Helpful videos and articles

- https://medium.com/@denaelgammal/dining-philosophers-problem-42-project-guide-mandatory-part-a20fb8dc530e
- https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2
- https://www.youtube.com/watch?v=ldJ8WGZVXZk
- https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2

## AI Usage

AI tools were used during the development of this project for:

- understanding concurrency concepts
- clarifying pthread and mutex behavior
- debugging synchronization issues
- README formatting and documentation

All implementation, testing, and final validation were completed manually.