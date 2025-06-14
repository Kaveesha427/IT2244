<h1>📝Inter Process Communication</h1>

![1](https://github.com/user-attachments/assets/47f2bca4-906a-40cf-a178-4480fac89648)


<pre>
  
<h3>This program demonstrates Inter-Process Communication (IPC) using message queues in C.</h3>

-The sender program creates a message queue using msgget() and sends data using msgsnd().
  It first generates a unique key using ftok().

-The receiver program uses the same key to access the queue, then retrieves
  the message using msgrcv() and displays it.

-Finally, the receiver deletes the message queue using msgctl() with IPC_RMID to clean up resources.

<h3>Key Points:</h3>
  
-ftok() generates a unique key based on a file and an ID.

-msgget() creates or accesses a message queue.

-msgsnd() sends a message to the queue.

-msgrcv() receives a message from the queue.

-msgctl() is used to delete the queue when it's no longer needed.
</pre>
