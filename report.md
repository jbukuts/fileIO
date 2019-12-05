# Question 1:
/proc is a virtual file system that is created on boot of the OS and destroyed at the time the system shuts down.
/proc contains information about the processes that are currently running.
/proc also allows for communciation between the user space and the kernel space.

As for /proc/$pid/maps that outputs rows where aech shows a region of contiguous virtual memory in a process or thread.
This relates to the last project as each of these rows is essentially a VMA entry in a task_struct as the row contains address bounds, pertaining process, as well as permissions.

# Question 2:
A loadable kernel module is an object file that contains code that can extend the existing base kernel of the operating system. They are usually used to add system calls to the kernel.


# Question 3:
Comparison of the APIs and different file descriptors

|  API       | Description                                                                               |
|:----------:|-------------------------------------------------------------------------------------------|
| `open()`   | Useful for allocating an amount of memory that is less than a page size                   |
| `fopen()`  | Allows for buffering IO that can be faster than open                                      |
| `mmap()`   | A method of memory-mapped file I/O that implements demand paging. The file is mapped to pages of the virtual address space and then to a block of hardware memory         |

|  Descriptor| Description                                                                               |
|:----------:|-------------------------------------------------------------------------------------------|
| File Descriptor       | Integer that desctibes that possible actions that can performed on given file. For instance                   |
| File Pointer          | Allows for buffering IO that can be faster than open                                      |
| File Desc Struct      |        |
| Open File Description |        |


