Good evening, everyone. I am Vijay Purohit. We are going to present performance effective and low complexity task scheduling for heterogeneous computing. In this paper we are mainly focusing on two novel scheduling algorithms i.e. HEFT(Heterogeneous Earliest Finish Time) and CPOP (Critical Path on a Processor). 

# Introduction
First of all we shall see what is heterogeneous computing. Diverse sets of resources interconnected with a high speed network provides a new computing platform called heterogenous computing system which can support execution of computation intensive parallel and distributed applications.

General Task Scheduling Problem is to assign the tasks of the applications to suitable processors and then to order their executions.

In static task scheduling, Applications are represented by DAG where the ndoes represent the application tasks and the edges represent the intertask data dependencies. Node labels show to computation cost i.e. the expected computation time and edge labels show the communication cost i.e. the expected communication time between tasks.

Objective function of this problem is to assign the tasks of the applications to suitable processors and then to order their executions such that the task precendence requiremenets are satisfied and a minimum overall completion time is minimized.

There is a significant amount of research done on the systems with homogeneous processors. Some of the heuristics are mentioned here.

Clustering Algorithms are for unbounded number of processors so not practical.

Task-Duplication Based Heuristics and Genetic Algorithms are not practical due to their high time complexity. GA also requires extensive tests to find optimal values.

Previous researches on heterogeneous systems consider tasks only on a single level, so they may not give good results since we don't consider all ready tasks.

In this paper two static scheduling algorithms are given which consider bounded number of processors that are fully connected. Motivation is to deliver good quality schedules with lower costs.

# Task Scheduling Provblem
