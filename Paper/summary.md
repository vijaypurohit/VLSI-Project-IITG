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

1. Scheduling system model contains Application, Target Computing Environment and Performance Criteria
2. Application is represented by DAG
3. Nodes are tasks and Edges are precedence constraints
4. ___Data___ is a vxv matrix where dataij = amount of data to be transmitted from nodei to nodej
5. Entry Task: A task without any parent
6. Exit Task: A task without any child
7. Pseudo entry and Pseudo exit tasks with zero costs
8. Target computing Environment: Set ___Q___ of q heterogeneous processors connected in full mesh topology
9. ___W___ is a vxq matrix where Wij gives the estimated execution time to complete task ni on processor pj
10. Average Execution Cost
11. ___B___ is a qxq matrix stores the data transfer rates
12. ___L___ vector of q dimension contains communication startup costs
13. Communication cost of edge
14. EST and EFT
15. For entry tasks, EST is 0
16. EST and EFT become AST and AFT after a task gets scheduled
17. Schedule length is the latest exit task's AFT


# Related Work




# Task Scheduling Algorithms




# Experimental Results and Discussion




# Alternate pollicies for the phases of HEFT algorithm




# Conclusion

