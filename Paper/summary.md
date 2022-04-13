# Abstract

## Background
1. Application Scheduling is NP Complete
2. Existing Algorithms give high scheduling costs or no good quality schedules with lower costs
3. Two algorithms - Heterogeneous Earliest Finish Time (HEFT), Critical Path on a Processor (CPOP)
4. HEFT selects a task with highest upward rank value and assigns it to the processor which minimizes the EFT
5. CPOP takes the summation of upward and downward rank value for prioritizing tasks
	Another difference - Processor selection phase - scheduls critical tasks that minimizes the total execution time of the critical tasks

## Work
1. Designed parametric graph generator that generates weighted DAGs


# Introduction

1. Heterogeneous computing definition
2. General Task Scheduling Problem - Assigning the tasks of the applications to suitable processors and then to order their executions
3. When things are known apriori, static model is used
4. In general form of a static task scheduling problem, applications ==> DAGs, tasks of applications ==> nodes, intertask dependencies ==> edges
5. Node labels ==> computation cost, Edge labels ==> communication cost
6. Task scheduling is NP-Complete for both general and restricted cases

## Clustering Algorithms

Phase-2 needed to map to bounded no of processors

## Task Duplication Based Heuristics

Not practical because of high time complexity

## Genetic Algorithm

Higher execution time than the other alternatives

## Studies on heterogeneous systems

1. Control parameters have high scheduling costs
2. Partition the tasks in the DAG into levels such that there is no dependency between the tasks in the same level. It considers the tasks which are in the current level only which is not good

## Two static algorithms

1. Take bounded no of processors that are fully connected and heterogeneous
2. Motivation is to deliver good quality schedules with lower costs

Upward Rank
-----------
Length of critical path or longest path from the task to an exit task including the computation cost of the task
CPOP targets scheduling all critical tasks onto a single processor which minimizes....





# Task Scheduling Problem

# Related Work

# Task Scheduling Algorithms

# Experimental Results and Discussion

# Alternate pollicies for the phases of HEFT algorithm

# Conclusion