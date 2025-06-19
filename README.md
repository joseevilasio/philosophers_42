<p align="center">
	<img src="https://img.shields.io/github/last-commit/joseevilasio/philosophers_42?color=%2312bab9&style=flat-square"/>
</p>

# philosophers

#### Finished in: 2025-01-29

## About

**Philosophers** is a concurrency programming project based on the classic Dining Philosophers problem. Built in C as part of the 42 School curriculum, its goal is to explore thread synchronization, deadlock avoidance, and resource sharing in multithreaded environments.

We implemented two distinct approaches using **POSIX threads (pthreads)** and **mutexes**, exploring different synchronization strategies to solve the problem efficiently. The challenge required managing edge cases like starvation, timing precision, and accurate death detection within strict system constraints.

Through this project, we deepened our understanding of:
- Thread creation and management
- Mutual exclusion and race condition prevention
- Deadlock detection and prevention
- Time-sensitive operations and scheduling

## Build

Clone the repository:
```shell
git clone https://github.com/joseevilasio/philosophers_42.git
```
Enter the cloned directory:
```shell
cd philosophers_42
```
Run `make` to compile the program:
```shell
make
```

## Usage

Run the program with the following arguments:
```shell
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:
```shell
./philo 5 800 200 200
```

This command will simulate 5 philosophers sitting at a table, each with a time_to_die of 800ms, time_to_eat of 200ms, and time_to_sleep of 200ms.

## The Norm

This project is written in accordance with the 42 School's "The Norm" (_Version 4_). To review the Norm, [click here](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf).

## Contributions

If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.

### Message to Students

The key to mastering this project lies in understanding thread behavior, timing, and the true nature of shared memory. Don’t rush into coding—plan your logic, visualize each state, and don’t be afraid to debug at the system level.
