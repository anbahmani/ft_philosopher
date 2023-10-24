[![fr](https://img.shields.io/badge/language-fr-blue.svg)](https://github.com/anbahmani/ft_philosopher/blob/master/README.fr.md)

## Table of Contents
1. [Introduction](#introduction)
2. [Project Description](#project-description)
3. [Simulation Details](#simulation-details)
4. [Objectives](#objectives)
5. [Challenges](#challenges)
6. [Run program](#run-program)

## Introduction
The "Dining Philosophers" is a classic synchronization problem that puts into perspective the challenges of ensuring proper resource management, deadlock prevention, and process synchronization in a multitasking environment. This project simulates the conditions and parameters of this renowned concept in a visual and interactive manner.

## Project Description
In this simulation, we delve into a scenario involving philosophers with three simple life activities: eating, thinking, and sleeping. The setting is a round table with a hearty meal at the center, surrounded by silent philosophers who must never communicate. The challenge is to simulate their actions while preventing any philosopher from starving, showcasing real-time multitasking and synchronization.

## Simulation Details
- Philosophers: Each philosopher represents an independent thread or process. Their actions are cyclic and continuous, moving from one state to another.
- Resources: The forks represent limited resources, essential for the philosophers' primary activity of eating. Each philosopher needs two forks to eat.
- States: Each philosopher transitions through three states:
	- Eating: The philosopher picks up the forks on their left and right side, eats for a while, and then puts down the forks.
	- Sleeping: After eating, the philosopher goes to sleep, not requiring any resources.
	- Thinking: Post-sleep, the philosopher engages in thought, still independent of resources.
- Life Cycle: The cycle continues indefinitely until the simulation concludes, typically upon the unfortunate event of a philosopher's demise due to starvation.

## Objectives
- Starvation-Free: The primary objective is to ensure that no philosopher starves, i.e., each philosopher gets a fair chance to eat before they run out of time.
- Deadlock Prevention: The simulation must prevent system deadlock, ensuring that the 'circular wait' condition does not occur.
- Resource Management: Proper handling of resources (forks), ensuring they are available for each philosopher's turn to eat.
- Synchronization: Implement synchronization mechanisms to manage philosopher actions and resource requests efficiently.

## Challenges
- Silence Rule: Philosophers do not communicate, making preemptive action based on another's state impossible.
- Ignorance of Others' State: Philosophers cannot determine if others are about to starve, emphasizing individual resource management.
- Survival: It goes without saying that the ultimate challenge is to keep all philosophers alive throughout the simulation.

## Run program

```
  git clone git@github.com:anbahmani/philosopher.git
  cd philosopher ; make ; ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat] (optional)
```


This project is a hands-on exercise in understanding and implementing multitasking principles, resource allocation strategies, and synchronization mechanisms in a constrained environment. It requires careful observation, swift decision-making, and real-time problem-solving skills to maintain a balance in the philosophers' world.