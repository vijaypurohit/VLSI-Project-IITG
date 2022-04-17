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

1. Two types of static task scheduling: Heuristic Based, Random Search Based
2. Heuristic Based is of three types: List Scheduling, Clustering, Task Duplication

List Scheduling Heuristics
--------------------------
1. Maintains a list of all tasks of a given graph according to their priorities
2. Two phases: Task prioritizing phase for selecting highest priority ready task, Processor selection phase for selecting a suitable processor that minimizes a predefined cost function
3. Algorithms are for a fully connected homogeneous processors.
4. Examples are given

Clustering Heuristics
---------------------
1. Maps the tasks (not necessarily a ready task) in a given graph to an unlimited number of clusters
2. Two tasks on the same cluster will be assigned to the same processor
3. Cluster merging such that the remaining number of clusters is equal to the number of processors
4. Cluster mapping such that the clusters are mapped onto the available processors
5. Task ordering is done for the mapped tasks within each processor
6. Examples are given

Task Duplication Heuristics
---------------------------
1. Scheduling a task graph by mapping some of its tasks redundantly that reduces the interprocess communication overhead
2. Algorithms are for unbounded number of identical processors
3. They have higher complexity values

Random Search Based
-------------------
1. Combine the previously gained results and apply some randomizing featuers to get new results


Task Scheduling heuristics for heterogenerous environments
==========================================================
Dynamic Level Scheduling
------------------------
1. Algorithm selects the pair that maximizes the value of dynamic level (formula given in paper)
2. Computation cost of task is the median of the computation costs of the same task on all processors

O(v^3 q)

Mapping Heuristic
-----------------
1. Computation cost of a task on a processor = number of instructions to be executed in the task/speed of the processor
2. Before scheduling: homogeneity of processors is assumed. heterogeneity comes during scheduling
3. Algorithm uses static upward ranks to assign priorities
4. Algorithm does not schedule a task between two already scheduled tasks

O(v^2 q^3) for contention, otherwise O(v^2 q)

Levelized-Min Time Algorithm
----------------------------
1. Two phases: First phase groups the tasks that can be executed in parallel using level attribute, Second phase assigns each task to the fastest available processor
2. Lower level task has higher priority
3. Within the same level, the task with highest computation cost has the highest priority
4. Each task is assigned to a processor that minimizes the computation cost as well as the communication cost with the tasks in the previous levels

O(v^2 q^2) for a fully connected graph


# Task Scheduling Algorithms

Graph attributes used by HEFT and CPOP
--------------------------------------
1. Upward rank of a of a task is the length of critical path from that task to the exit task
2. Entry task downward rank is 0
3. Downward rank of a task is the longest distance from the entry task to the task

HEFT Algorithm
--------------
For bounded number of heterogeneous processors
1. Two major phases: Task prioritizing phase for computing the priorities for all tasks, Processor selection phase for selecting task in order of their priorities and scheduling each selected task on its best processor which minimizes the task's finish time
2. Task Prioritizing phase: Priority of the tasks to be set to their upward rank value
3. Decreasing order of upward rank values provide a topological ordering of the tasks
4. Processor Selection phase: HEFT algorithm has an insertion based policy (we can schedule a task in the idle time i.e. between two already scheduled tasks)
5. Insertion should preserve the precedence constraints, time duration should be enough for the computation cost of the task

O(eq) for e edges and q processors. For dense graphs it is O(v^2 q)

CPOP Algorithm
--------------
1. Priority of each task is assigned with the summation of upward and downward ranks
2. Critical path length is equal to the entry task's priority
3. Task Prioritizing phase: Priority of tasks to be set to their summation of upward rank and downward rank
4. Priority Queue is maintained to extract the tasks with highest priority
5. Processor Selection phase:
	1) Critical Path Processor is the one that minimizes the cumulative computation costs of the tasks on the critical path
	2) Tasks on critical path: scheduled on critical path processor
	3) Other tasks: scheduled on the a processor which minimizes the earliest execution finish time of the task
Both cases consider insertion based scheduling policy

O(e p)


# Experimental Results and Discussion

Comparison metrics
------------------
1. Schedule Length Ratio
	1) Normalized version of Schedule length
	2) Denominator is the sum of computation costs of the tasks on the critical path where all the tasks on critical path are set to the minimum computation cost
	3) Algorithm giving lowest SLR value is considered to be the best
2. Speedup
	1) Sequential Execution Time / Parallel Execution Time
	2) Sequential Execution Time is computed by assigning all tasks to one processor that minimizes the cumulative computation costs
	3) Efficiency = speedup / number of processors
3. Number of Occurrences of better quality of schedules
	1) The number of times an algorithm produces better or worse or equal quality of schedules
4. Running Time of the Algorithms
	1) Among the algorithms that give the minimum SLR values, the one having least running time is considered as the best

Randomly Generated Application Graphs
-------------------------------------
1. Random Graph Generator
	1) Input parameters- Number of tasks in the graph (v), Shape parameter of the graph (alpha), Out degree of a node, Communication to computation ratio (CCR), Range percetnage of computation costs on processors (beta)
	2) Low CCR value implies computation intensive application
	3) Less heterogeneity implies similar execution costs of tasks on any given processor and vice versa
	4) 5x5x3x6x5 = 2250x25 = 56250
2. Performance Results
	1) Average SLR performance ranking: HEFT, CPOP, DLS, MH, LMT
	2) Average speedup ranking: HEFT, DLS, CPOP = MH, LMT
	3) HEFT outperforms in both, CPOP outperforms only in SLR
	4) Running time: HEFT, CPOP, MH, LMT, DLS
	5) Graph Structure: HEFT, CPOP, MH, DLS, LMT -> alpha = 0.5
						HEFT, CPOP = DLS, MH, LMT -> alpha = 1.0
						HEFT, CPOP, DLS, MH, LMT -> alpha = 2.0
	6) CCR: HEFT, DLS, MH, CPOP, LMT -> CCR <= 1.0
			HEFT, CPOP, DLS, MH, LMT -> CCR > 1.0 (Clustering of critical path on the fastest processor results in better quality of schedules)
	7) Number of occurrences: HEFT, DLS, CPOP, MH, LMT
3. Application Graphs of Real World Problems
	1) Gaussian Elimination Algorithm: 
		matrix size = m, no of tasks = ((m^2+m+2)/2)
		HEFT and DLS are best
		Number of processors greater than 8 => HEFT outperforms DLS in terms of efficiency
		HEFT is the most efficient one when performance and cost results are considered together
	2) Fast Fourier Transform:
		





# Alternate pollicies for the phases of HEFT algorithm




# Conclusion

