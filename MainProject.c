#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <iostream>
#include <fstream>
#include <cstring>
// #include <regex>

// NOTE: compile with -std=c++11 flag

using namespace std;

struct Process
{
    int pid;
    int burstTime;
    int arrivalTime;  
    int priority;
    int wt;  // Process waiting time
    int rbt; // Process remaining time
    struct Process *next;
    struct Process *prev;
};

struct Algorithm
{
    int method;
    int pMode; // Preemptive mode
    int n;     // time quantum for Round-Robin Scheduling
} alg = {0, 0, 0};

Process *initialHeader = nullptr;

string methods[5] = {"None", "First Come, First Served Scheduling", "Shortest-Job-First Scheduling", "Priority Scheduling", "Round-Robin Scheduling"};
string pModes[2] = {"OFF", "ON"};
string outputFilename;

// App function declarations
void validateParams(int, char **);
void getInitialProcesses(const string &filename);
void loadMainMenu();
void handleSchedulingMethod();
void handlePMode();
void handleShowResult();
void handleEndProgram();

// Linked list function declarations
struct Process *createProcess(int, int, int, int);
struct Process *insertFront(Process *, int, int, int, int);
struct Process *insertBack(Process *, int, int, int, int);
void deleteProcesses(Process **);
void sortProcesses(Process **, string);

int main(int argc, char **argv)
{
    validateParams(argc, argv);

    outputFilename = argv[4];

    getInitialProcesses(argv[2]);
    loadMainMenu();

    return 0;
}

// App templates
