
![1](https://github.com/user-attachments/assets/99471ee5-2028-41bf-a707-f4fe9335ef2b)

This program demonstrates Interprocess Communication (IPC) using System V message queues in C with the help of fork().

🔍 What the Code Does:
The program creates a message queue using a fixed key (1111).

  -It uses fork() to create a child process.

 -Parent process: Sends a message containing a name, registration number, and age.

 -Child process: Receives that message from the message queue.

 -The child then displays the received data and finally deletes the message queue.

🧠 Key Concepts Demonstrated:
msgget(): Create or access a message queue.

 -msgsnd(): Send a message from the parent.

 -msgrcv(): Receive a message in the child.

 -msgctl(): Delete the message queue after use.

 -fork(): Run both sender and receiver in the same program.


