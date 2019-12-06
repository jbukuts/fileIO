# Question 1:
/proc is a virtual file system that is created on boot of the OS and destroyed at the time the system shuts down.
/proc contains information about the processes that are currently running.
/proc also allows for communciation between the user space and the kernel space.

As for /proc/$pid/maps that outputs rows where aech shows a region of contiguous virtual memory in a process or thread.
This relates to the last project as each of these rows is essentially a VMA entry in a task_struct as the row contains address bounds, pertaining process, as well as permissions.

Three other interesting functions:

### /proc/self
When a process accesses this magic symbolic link, it resolves to the process's own /proc/[pid] directory. This would have been useful for last project to verify system call results.

### /proc/thread-self
When a thread accesses this magic symbolic link, it resolves to the process's own /proc/self/task/[tid] directory.

### /proc/[a-z]*
Various other files and subdirectories under /proc expose system-wide information.

# Question 2:
A loadable kernel module is an object file that contains code that can extend the existing base kernel of the operating system. They are usually used to add system calls to the kernel.


# Question 3:
Comparison of the APIs and different file descriptors

|  API       | Description                                                                               |
|:----------:|-------------------------------------------------------------------------------------------|
| `open()`   | Lower level POSIX system call that does not make use of buffering therefore slower than `fopen()`. Desirable when buffering is not optimal, for instance, with things like reading/writing to pipes                 |
| `fopen()`  | Allows for buffering IO that can be faster than `open()` and also part of the C standard library making it portable to use between systems                                     |
| `mmap()`   | A method of memory-mapped file I/O that implements demand paging. The file is mapped to pages of the virtual address space and then to a block of hardware memory         |

|  Descriptor| Description                                                                               |
|:----------:|-------------------------------------------------------------------------------------------|
| File Descriptor       | Integer that OS uses to keep track of all open files.                 |
| File Pointer          | C standard library-level construct, used to represent a file. Wraps the file descriptor, add buffering among other things to make file I/O easier                                   |
| File Desc Struct      | The kernel keeps a table of open file descriptors for each process, mapping these small integers to the file descriptor structure. This struct is `struct fd` |
| Open File Description | The open file description contains information about the way the file is open (meaning mode) as well as the position in the file system. The open file description structure is in `struct file`        |


