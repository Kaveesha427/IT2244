<h4>🗓️Date :-23/05/2025</h4>
<h3>Activity</h3>
<pre>
P has Q and R children.Q has one child(A).R has two child(B and C)
first get 3 inputs from user.
After,
A->Find Factorial
B->Find Fibbonacci
C-> Find Prime Numbers
</pre>

<pre>
#include <stdio.h></stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int A, B, C;

int main() {
    // Input section
    printf("Enter Number A (for factorial): ");
    scanf("%d", &A);
    printf("Enter Number B (for Fibonacci): ");
    scanf("%d", &B);
    printf("Enter Number C (to check Prime): ");
    scanf("%d", &C);
    printf("\n");

    int f1 = fork();  // Create Q

    if (f1 == 0) {
        // ---- Q Process ----
        printf("[Q] PID: %d, PPID: %d\n", getpid(), getppid());

        int f3 = fork();  // Create A (child of Q)

        if (f3 == 0) {
            // ---- A Process ----
            int fact = 1;
            for (int i = A; i > 0; i--) {
                fact *= i;
            }
            printf("[A - Factorial] A = %d, Result = %d, PID: %d, PPID: %d\n",
                   A, fact, getpid(), getppid());
        } else {
            wait(NULL);  // Q waits for A
        }

    } else {
        int f2 = fork();  // Create R

        if (f2 == 0) {
            // ---- R Process ----
            printf("[R] PID: %d, PPID: %d\n", getpid(), getppid());

            int f4 = fork();  // Create B (Fibonacci)

            if (f4 == 0) {
                // ---- B Process ----
                int num1 = 0, num2 = 1;

                printf("[B - Fibonacci] B = %d, PID: %d, PPID: %d\n", B, getpid(), getppid());
                printf("Fibonacci Sequence: %d %d", num1, num2);

                for (int i = 0; i < B - 2; i++) {
                    int result = num1 + num2;
                    printf(" %d", result);
                    num1 = num2;
                    num2 = result;
                }
                printf("\n");

            } else {
                int f5 = fork();  // Create C (Prime check)

                if (f5 == 0) {
                    // ---- C Process ----
                    int isPrime = 1;

                    if (C <= 1) {
                        isPrime = 0;
                    }
                    for (int i = 2; i <= C / 2; i++) {
                        if (C % i == 0) {
                            isPrime = 0;
                            break;
                        }
                    }

                    if (isPrime) {
                        printf("[C - Prime] %d is a Prime number.\n", C);
                    } else {
                        printf("[C - Prime] %d is NOT a Prime number.\n", C);
                    }
                    printf("[C] PID: %d, PPID: %d\n", getpid(), getppid());

                } else {
                    wait(NULL); // R waits for B
                    wait(NULL); // R waits for C
                }
            }

        } else {
            wait(NULL); // Main waits for R
            wait(NULL); // Main waits for Q
        }
    }

    return 0;
}

</pre>
<pre>
  <h3>🔍 What does wait() do?</h3>
When a parent process creates a child using fork(), the child runs in parallel.
But once the child finishes, it becomes a zombie process (a "dead" process waiting to be cleaned up).

✅ wait() tells the parent to wait until the child is finished, and then cleans it up.

⭐ Without wait():
The child may finish before the parent.

If the parent doesn't wait, the child becomes a zombie process.

Too many zombies = resource leak.

⭐ With wait():
Parent pauses and waits for the child to finish.

The operating system cleans up the child process properly.

Helps avoid zombies.


</pre>

![1](https://github.com/user-attachments/assets/335ded5e-314c-4b9f-922a-7add5df59f71)
