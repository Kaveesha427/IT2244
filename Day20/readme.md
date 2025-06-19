<h3>Shared Memory IPC</h3>

<pre>
🔹 1. Writer Process (process1)
* Creates (or accesses) a shared memory segment using shmget().

- Attaches to the memory using shmat().

- Takes user input using fgets() and writes it directly into the shared memory.

 -Then detaches from the shared memory using shmdt().

🔹 2. Reader Process (reader)
Accesses the same shared memory segment using the same key with shmget().

Attaches to the shared memory using shmat().

Reads and displays the data written by the writer process.

Detaches from the shared memory using shmdt().

Finally, deletes the shared memory segment using shmctl() with IPC_RMID.

📌 Key Concepts Demonstrated
ftok(): Generates a unique key using a filename and integer.

shmget(): Creates or accesses a shared memory segment.

shmat(): Attaches the segment to the process's address space.

shmdt(): Detaches the shared memory after use.

shmctl(): Used by the reader to clean up (remove) the memory segment.

  </pre>

![1 0](https://github.com/user-attachments/assets/d6749251-0423-4602-b4e0-d8b40884e92c)
![2](https://github.com/user-attachments/assets/cb8efc04-ef9e-446c-bd88-b6f17d851725)
