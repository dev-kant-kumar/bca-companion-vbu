# Unit 5: Introduction to System Administration & System Calls in Linux
### BCA C5003 — Linux Programming

---

## Part A: Introduction to System Administration

---

### 1. File System in Linux

The Linux file system is a hierarchical structure that organizes all files and directories under a single root directory `/`.

#### Key Characteristics:
- Everything in Linux is treated as a **file** (including devices, directories, and processes).
- The file system starts at the **root directory** (`/`).
- It follows the **Filesystem Hierarchy Standard (FHS)**.

#### Important Directories:

| Directory | Purpose |
|-----------|---------|
| `/`       | Root of the entire file system |
| `/bin`    | Essential user command binaries (ls, cp, mv) |
| `/sbin`   | System binaries (for root/admin use) |
| `/etc`    | Configuration files |
| `/home`   | User home directories |
| `/var`    | Variable data (logs, spool files) |
| `/tmp`    | Temporary files |
| `/usr`    | User programs and data |
| `/dev`    | Device files |
| `/proc`   | Virtual filesystem for process information |
| `/lib`    | Shared libraries |
| `/mnt`    | Mount points for temporary filesystems |
| `/boot`   | Boot loader files |

#### File System Types:
- **ext2** – Second Extended Filesystem (no journaling)
- **ext3** – Third Extended Filesystem (with journaling)
- **ext4** – Fourth Extended Filesystem (most widely used)
- **xfs** – High-performance journaling filesystem
- **vfat** – Compatible with Windows FAT32
- **nfs** – Network File System (used for remote access)

#### Mounting a File System:
```bash
mount /dev/sdb1 /mnt/usb       # Mount a device
umount /mnt/usb                 # Unmount a device
df -h                           # Display disk usage
du -sh /home/user               # Disk usage of a directory
```

#### Inodes and File System Internals:
- Every file has an **inode** containing metadata: permissions, owner, size, timestamps, and pointers to data blocks.
- The inode does **not** store the filename — filenames are stored in directory entries.
- Commands:
```bash
ls -i filename     # Show inode number
stat filename      # Show detailed inode information
```

---

### 2. System Administrator and Their Role

The **System Administrator (SA)** or **sysadmin** is responsible for managing and maintaining a Linux system.

#### Who is a System Administrator?
- A privileged user (typically **root**) who has full control over the system.
- Also known as the **superuser**.
- Root user has UID = **0**.

#### Responsibilities of a System Administrator:
1. **User Management** – Creating, modifying, and deleting user accounts.
2. **File System Management** – Managing disk space, mounting/unmounting drives.
3. **Security Management** – Setting file permissions, managing firewalls, user access.
4. **Network Administration** – Configuring IP addresses, DNS, network interfaces.
5. **Software Management** – Installing, updating, and removing packages.
6. **Backup and Recovery** – Regular backups using tools like `tar`, `rsync`, `dump`.
7. **Process Management** – Monitoring and controlling running processes.
8. **System Monitoring** – Checking system logs, performance metrics.
9. **Boot Management** – Managing boot loaders (GRUB).
10. **Scheduling Tasks** – Using `cron` and `at` for automated task scheduling.

#### Becoming Root (Superuser):
```bash
su             # Switch to root (asks for root password)
su - username  # Switch to another user
sudo command   # Run a single command as root
sudo -i        # Open root shell using sudo
```

---

### 3. Functions of a System Manager

The system manager (sysadmin) performs both **routine** and **emergency** tasks.

#### A. User Account Management:

```bash
useradd username        # Add new user
passwd username         # Set/change password
usermod -aG group user  # Add user to a group
userdel username        # Delete a user
userdel -r username     # Delete user and home directory
groupadd groupname      # Create a group
groups username         # List groups of a user
who                     # Show logged-in users
w                       # Show who is logged in and what they're doing
last                    # Login history
```

#### B. Disk and File System Management:

```bash
fdisk -l                # List all disk partitions
mkfs.ext4 /dev/sdb1     # Format partition with ext4
mount /dev/sdb1 /data   # Mount partition
fsck /dev/sdb1          # Check and repair filesystem
df -h                   # Disk usage summary
du -sh *                # Size of each file/directory
```

#### C. Package Management:

```bash
# Debian/Ubuntu based:
apt-get install package   # Install software
apt-get remove package    # Remove software
apt-get update            # Update package list
apt-get upgrade           # Upgrade all installed packages

# Red Hat/CentOS based:
yum install package
rpm -ivh package.rpm      # Install RPM package
rpm -e package            # Remove RPM package
```

#### D. Process Management:

```bash
ps aux              # List all running processes
top                 # Interactive process monitor
kill PID            # Kill a process by PID
kill -9 PID         # Force kill
killall processname # Kill all processes by name
nice -n 10 command  # Start process with priority
renice 5 PID        # Change priority of running process
bg                  # Send process to background
fg                  # Bring process to foreground
jobs                # List background jobs
```

#### E. System Monitoring:

```bash
uptime              # System uptime and load average
vmstat              # Virtual memory statistics
iostat              # CPU and I/O statistics
free -h             # Memory usage
cat /proc/cpuinfo   # CPU information
cat /proc/meminfo   # Memory information
dmesg               # Kernel ring buffer (boot messages)
```

#### F. Log Management:

```bash
cat /var/log/syslog         # General system logs
cat /var/log/auth.log       # Authentication logs
cat /var/log/kern.log       # Kernel logs
journalctl                  # View systemd logs
tail -f /var/log/syslog     # Live log monitoring
```

#### G. Cron – Task Scheduling:

```bash
crontab -e          # Edit current user's cron jobs
crontab -l          # List cron jobs
crontab -r          # Remove all cron jobs
```

**Cron Syntax:**
```
*  *  *  *  *  command
│  │  │  │  └── Day of week (0-7, Sun=0 or 7)
│  │  │  └───── Month (1-12)
│  │  └──────── Day of month (1-31)
│  └─────────── Hour (0-23)
└────────────── Minute (0-59)
```

**Example:**
```bash
0 2 * * * /home/user/backup.sh    # Run backup at 2 AM daily
*/5 * * * * /usr/bin/check.sh     # Run every 5 minutes
```

#### H. Network Administration:

```bash
ifconfig               # Show/configure network interfaces
ip addr show           # Show IP addresses
ping hostname          # Test network connectivity
netstat -tuln          # Show open ports
ss -tuln               # Modern replacement for netstat
hostname               # Show system hostname
route                  # Show routing table
```

---

### 4. Practical Aspects of System Administration

#### A. Backup and Recovery:

```bash
# Using tar:
tar -cvf backup.tar /home/user      # Create archive
tar -czvf backup.tar.gz /home/user  # Compressed archive
tar -xvf backup.tar                 # Extract archive
tar -xzvf backup.tar.gz             # Extract compressed archive

# Using rsync (incremental backup):
rsync -avz /source/ /destination/
rsync -avz /home/ user@remote:/backup/

# Using cp for simple copy:
cp -r /home/user /backup/user_backup
```

#### B. File Permissions Management:

```bash
chmod 755 file       # rwxr-xr-x
chmod 644 file       # rw-r--r--
chmod u+x file       # Add execute for owner
chmod go-w file      # Remove write from group and others
chown user file      # Change file owner
chown user:group file
chgrp group file     # Change group ownership
```

**Permission Numeric Values:**
| Value | Permission |
|-------|-----------|
| 4     | Read (r)   |
| 2     | Write (w)  |
| 1     | Execute (x)|

#### C. Security Practices:
- Disable root login via SSH (`/etc/ssh/sshd_config` → `PermitRootLogin no`)
- Use `sudo` instead of logging in as root
- Set strong passwords using `passwd`
- Monitor failed login attempts via `/var/log/auth.log`
- Configure firewall using `iptables` or `ufw`

```bash
ufw enable               # Enable firewall
ufw allow 22             # Allow SSH
ufw deny 23              # Deny telnet
ufw status               # Show firewall rules
```

---

### 5. Visual Attributes (Terminal & Display)

Linux terminals support **ANSI escape codes** to change text appearance — color, bold, italic, underline, etc.

#### ANSI Escape Code Format:
```
\033[CODEm   or   \e[CODEm
```

#### Common Codes:

| Code | Effect         |
|------|----------------|
| 0    | Reset/Normal   |
| 1    | Bold           |
| 2    | Dim            |
| 4    | Underline      |
| 5    | Blink          |
| 7    | Reverse video  |
| 30–37| Foreground color (Black, Red, Green, Yellow, Blue, Magenta, Cyan, White) |
| 40–47| Background color |

#### Example in Shell:
```bash
echo -e "\033[1;32mHello World\033[0m"   # Bold green text
echo -e "\033[4;31mError!\033[0m"        # Underlined red text
```

#### Example in C:
```c
printf("\033[1;34mBlue Bold Text\033[0m\n");
printf("\033[0;31mRed Text\033[0m\n");
```

#### `tput` Command (Portable Approach):
```bash
tput bold           # Set bold
tput setaf 2        # Set foreground to green
tput sgr0           # Reset all attributes
tput cup 5 10       # Move cursor to row 5, col 10
tput clear          # Clear terminal
```

---

## Part B: System Calls and C Function Library

---

### 6. Linux System Call Library Function and Math Library

#### What is a System Call?
A **system call** is the interface between a user-space program and the Linux kernel. It is the mechanism by which programs request services from the OS.

#### How System Calls Work:
```
User Program → System Call → Kernel → Hardware
```

Programs use system calls via:
1. **C Library wrappers** (from `glibc`) — standard interface
2. **Direct syscall** — using the `syscall()` function

#### Common System Calls in Linux:

| Category | System Call | Purpose |
|----------|-------------|---------|
| File I/O | `open()`, `read()`, `write()`, `close()` | File operations |
| Process | `fork()`, `exec()`, `exit()`, `wait()` | Process control |
| File System | `stat()`, `mkdir()`, `rmdir()`, `unlink()` | FS operations |
| Memory | `brk()`, `mmap()`, `munmap()` | Memory management |
| Signals | `signal()`, `kill()`, `pause()` | Signal handling |
| IPC | `pipe()`, `shmget()`, `msgget()` | Inter-process communication |
| Network | `socket()`, `connect()`, `bind()`, `listen()` | Networking |
| Info | `getpid()`, `getuid()`, `time()` | System information |

#### `getpid()` and `getuid()` Example:
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Process ID: %d\n", getpid());
    printf("Parent PID: %d\n", getppid());
    printf("User ID:    %d\n", getuid());
    printf("Group ID:   %d\n", getgid());
    return 0;
}
```

#### `fork()` System Call:
Creates a new child process (copy of parent).

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
    } else if (pid == 0) {
        printf("Child process: PID = %d\n", getpid());
    } else {
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    }
    return 0;
}
```

#### `exec()` Family:
Replaces the current process image with a new program.

```c
#include <unistd.h>
execl("/bin/ls", "ls", "-l", NULL);    // Execute ls -l
execlp("ls", "ls", "-l", NULL);        // Search in PATH
execv("/bin/ls", argv);                 // Using argument array
```

---

### 7. Math Library in C (`math.h`)

The C math library provides mathematical functions. To use, include `<math.h>` and link with `-lm`.

```bash
gcc program.c -o program -lm
```

#### Common Math Functions:

| Function | Description | Example |
|----------|-------------|---------|
| `sqrt(x)` | Square root | `sqrt(25.0)` → 5.0 |
| `pow(x,y)` | x raised to y | `pow(2,8)` → 256.0 |
| `abs(x)` | Absolute value (int) | `abs(-5)` → 5 |
| `fabs(x)` | Absolute value (float) | `fabs(-3.14)` → 3.14 |
| `ceil(x)` | Round up | `ceil(2.3)` → 3.0 |
| `floor(x)` | Round down | `floor(2.9)` → 2.0 |
| `log(x)` | Natural logarithm | `log(2.718)` → ~1.0 |
| `log10(x)` | Log base 10 | `log10(100)` → 2.0 |
| `sin(x)` | Sine (radians) | `sin(M_PI/2)` → 1.0 |
| `cos(x)` | Cosine (radians) | `cos(0)` → 1.0 |
| `tan(x)` | Tangent (radians) | `tan(M_PI/4)` → 1.0 |
| `exp(x)` | e^x | `exp(1)` → 2.718 |
| `round(x)` | Round to nearest | `round(2.5)` → 3.0 |

#### Example:
```c
#include <stdio.h>
#include <math.h>

int main() {
    double x = 25.0;
    printf("sqrt(%.1f) = %.2f\n", x, sqrt(x));
    printf("pow(2, 10) = %.0f\n", pow(2, 10));
    printf("ceil(4.3) = %.1f\n", ceil(4.3));
    printf("floor(4.9) = %.1f\n", floor(4.9));
    return 0;
}
```

---

### 8. Standard I/O Package (`stdio.h`)

The **Standard I/O library** (`stdio.h`) provides buffered input/output functions. It is part of the C standard library (`libc`).

#### Key Functions:

| Function | Purpose |
|----------|---------|
| `printf()` | Formatted output to stdout |
| `scanf()` | Formatted input from stdin |
| `fprintf()` | Formatted output to a file |
| `fscanf()` | Formatted input from a file |
| `fgets()` | Read a line from file/stdin |
| `fputs()` | Write a string to file/stdout |
| `fgetc()` | Read a character from file |
| `fputc()` | Write a character to file |
| `fopen()` | Open a file |
| `fclose()` | Close a file |
| `feof()` | Check end of file |
| `fflush()` | Flush I/O buffer |
| `rewind()` | Reset file pointer to beginning |
| `fseek()` | Move file pointer to position |
| `ftell()` | Return current file position |
| `sprintf()` | Write formatted string to buffer |
| `sscanf()` | Read formatted data from string |
| `perror()` | Print error message |

#### `printf()` Format Specifiers:
| Specifier | Type |
|-----------|------|
| `%d` | Integer |
| `%f` | Float |
| `%lf` | Double |
| `%c` | Character |
| `%s` | String |
| `%x` | Hexadecimal |
| `%o` | Octal |
| `%p` | Pointer |
| `%e` | Scientific notation |

---

### 9. File Handling in C

Linux C programs use **file handles (FILE\*)** for standard I/O and **file descriptors (int)** for system-level I/O.

#### A. Standard File Descriptors:
| Descriptor | Name | Purpose |
|------------|------|---------|
| 0 | `stdin` | Standard Input |
| 1 | `stdout` | Standard Output |
| 2 | `stderr` | Standard Error |

#### B. File Handling with `stdio.h` (Buffered I/O):

```c
#include <stdio.h>

int main() {
    FILE *fp;

    // Writing to a file
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    fprintf(fp, "Hello, Linux Programming!\n");
    fclose(fp);

    // Reading from a file
    char buffer[100];
    fp = fopen("output.txt", "r");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);

    return 0;
}
```

#### File Opening Modes:
| Mode | Description |
|------|-------------|
| `"r"` | Read only (file must exist) |
| `"w"` | Write (creates or truncates file) |
| `"a"` | Append (creates if not exists) |
| `"r+"` | Read and write |
| `"w+"` | Read and write (truncates) |
| `"a+"` | Read and append |
| `"rb"`, `"wb"` | Binary read/write |

#### C. File Handling with System Calls (Unbuffered I/O):

Uses `open()`, `read()`, `write()`, `close()` from `<fcntl.h>` and `<unistd.h>`.

```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd;
    char buf[100];

    // Create and write to file
    fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    char *msg = "Hello from system call!\n";
    write(fd, msg, strlen(msg));
    close(fd);

    // Read from file
    fd = open("test.txt", O_RDONLY);
    int n = read(fd, buf, sizeof(buf));
    buf[n] = '\0';
    printf("Read: %s", buf);
    close(fd);

    return 0;
}
```

#### `open()` Flags:
| Flag | Description |
|------|-------------|
| `O_RDONLY` | Open for reading only |
| `O_WRONLY` | Open for writing only |
| `O_RDWR` | Open for reading and writing |
| `O_CREAT` | Create file if it doesn't exist |
| `O_TRUNC` | Truncate file to zero length |
| `O_APPEND` | Write at end of file |
| `O_EXCL` | Error if file already exists |

#### `fseek()` and `ftell()` Example:
```c
FILE *fp = fopen("data.txt", "r");
fseek(fp, 0, SEEK_END);        // Move to end
long size = ftell(fp);          // Get position (file size)
rewind(fp);                     // Back to beginning
fclose(fp);
printf("File size: %ld bytes\n", size);
```

**`fseek()` Whence Values:**
| Value | Meaning |
|-------|---------|
| `SEEK_SET` | From beginning of file |
| `SEEK_CUR` | From current position |
| `SEEK_END` | From end of file |

---

### 10. Command Line Parameters in C

Command line arguments are passed to `main()` via `argc` and `argv`.

```c
int main(int argc, char *argv[]) {
    // argc = argument count (includes program name)
    // argv = argument vector (array of strings)
}
```

#### Example:
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}
```

**Running:**
```bash
./program hello world 42
```
**Output:**
```
Number of arguments: 4
argv[0] = ./program
argv[1] = hello
argv[2] = world
argv[3] = 42
```

#### Accessing Arguments:
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s num1 num2\n", argv[0]);
        return 1;
    }
    int a = atoi(argv[1]);   // String to integer
    int b = atoi(argv[2]);
    printf("Sum = %d\n", a + b);
    return 0;
}
```

#### Useful Conversion Functions:
| Function | Description |
|----------|-------------|
| `atoi(str)` | String to int |
| `atof(str)` | String to float/double |
| `atol(str)` | String to long |
| `strtol(str, endptr, base)` | String to long (with error check) |

---

### 11. Linux–C Interface

The **Linux–C interface** refers to how C programs interact directly with the Linux kernel using system calls and POSIX APIs.

#### Key Header Files:

| Header | Purpose |
|--------|---------|
| `<stdio.h>` | Standard I/O (printf, scanf, fopen, etc.) |
| `<stdlib.h>` | General utilities (malloc, free, atoi, exit) |
| `<string.h>` | String manipulation |
| `<unistd.h>` | POSIX API (read, write, fork, exec, getpid) |
| `<fcntl.h>` | File control (open, O_RDONLY, etc.) |
| `<sys/types.h>` | Data types (pid_t, uid_t, size_t) |
| `<sys/stat.h>` | File status (stat, chmod) |
| `<signal.h>` | Signal handling |
| `<errno.h>` | Error numbers |
| `<math.h>` | Math functions (link with -lm) |
| `<time.h>` | Date and time functions |

#### `stat()` System Call – File Information:
```c
#include <sys/stat.h>
#include <stdio.h>

int main() {
    struct stat st;
    if (stat("test.txt", &st) == 0) {
        printf("Size:  %ld bytes\n", st.st_size);
        printf("Inode: %ld\n", (long)st.st_ino);
        printf("Mode:  %o\n", st.st_mode);
        printf("UID:   %d\n", st.st_uid);
    }
    return 0;
}
```

#### Signal Handling:
```c
#include <signal.h>
#include <stdio.h>

void handler(int sig) {
    printf("Caught signal: %d\n", sig);
}

int main() {
    signal(SIGINT, handler);    // Catch Ctrl+C
    signal(SIGTERM, handler);   // Catch kill command
    while(1) pause();           // Wait for signals
    return 0;
}
```

#### `errno` – Error Handling:
```c
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *fp = fopen("nonexistent.txt", "r");
    if (fp == NULL) {
        printf("Error %d: %s\n", errno, strerror(errno));
        // Output: Error 2: No such file or directory
    }
    return 0;
}
```

#### Memory Management:
```c
#include <stdlib.h>

int *arr = (int *)malloc(10 * sizeof(int));   // Allocate memory
arr = (int *)realloc(arr, 20 * sizeof(int));  // Resize
free(arr);                                     // Free memory

// Allocate and zero-initialize
int *arr2 = (int *)calloc(10, sizeof(int));
free(arr2);
```

---

### 12. C Files (Compiling and Linking in Linux)

#### File Types in a C Project:
| Extension | Description |
|-----------|-------------|
| `.c` | C source file |
| `.h` | Header file |
| `.o` | Object file (compiled, not linked) |
| `.a` | Static library |
| `.so` | Shared/dynamic library |
| (no extension) | Executable |

#### Compilation Stages:

```
Source (.c)  →  Preprocessor  →  Compiler  →  Assembler  →  Object (.o)  →  Linker  →  Executable
```

#### GCC Commands:

```bash
gcc hello.c -o hello             # Compile and link
gcc -c hello.c                   # Compile only (creates hello.o)
gcc hello.o -o hello             # Link object file
gcc hello.c -o hello -lm         # Link math library
gcc -Wall hello.c -o hello       # Enable all warnings
gcc -g hello.c -o hello          # Include debug info
gcc -O2 hello.c -o hello         # Optimize (level 2)
```

#### Multi-File Compilation:
```bash
gcc -c main.c           # → main.o
gcc -c utils.c          # → utils.o
gcc main.o utils.o -o program   # Link into executable
```

#### Using Makefile:
```makefile
CC = gcc
CFLAGS = -Wall -g

program: main.o utils.o
	$(CC) $(CFLAGS) -o program main.o utils.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

utils.o: utils.c
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f *.o program
```

```bash
make          # Build project
make clean    # Remove compiled files
```

#### Static vs Shared Libraries:

**Creating a Static Library:**
```bash
gcc -c mylib.c
ar rcs libmylib.a mylib.o
gcc main.c -L. -lmylib -o program
```

**Creating a Shared Library:**
```bash
gcc -fPIC -shared mylib.c -o libmylib.so
gcc main.c -L. -lmylib -o program
export LD_LIBRARY_PATH=.
```

---

## Summary Table

| Topic | Key Concept |
|-------|-------------|
| File System | Hierarchical structure starting at `/`; inode stores file metadata |
| System Admin | Root user (UID 0) manages users, disk, processes, security |
| Sysadmin Tools | `useradd`, `chmod`, `mount`, `cron`, `kill`, `df`, `top` |
| Visual Attributes | ANSI escape codes `\033[CODEm`, `tput` commands |
| System Calls | Kernel interface: `open`, `read`, `write`, `fork`, `exec`, `stat` |
| Math Library | `#include <math.h>`, link with `-lm`: `sqrt`, `pow`, `sin`, `log` |
| Standard I/O | `#include <stdio.h>`: `printf`, `scanf`, `fopen`, `fclose`, `fgets` |
| File Handling | `FILE*` with `fopen/fclose`; int fd with `open/read/write/close` |
| Command Line Args | `main(int argc, char *argv[])`, `atoi()` for conversion |
| Linux–C Interface | Headers: `unistd.h`, `fcntl.h`, `signal.h`, `errno.h` |
| C Files | GCC stages: preprocess → compile → assemble → link |

---

## Important Short Answer Points

1. **System Administrator** is the root user (UID=0) responsible for all system management tasks.
2. **System calls** are the interface between user programs and the kernel.
3. **`fork()`** creates a child process; returns 0 to child, PID to parent, -1 on error.
4. **`fopen()` vs `open()`**: `fopen` is buffered (stdio), `open` is unbuffered (system call).
5. **Math library** must be linked with `-lm` flag during compilation.
6. **`argc`** = count of arguments; **`argv[0]`** = program name itself.
7. **ANSI escape codes**: `\033[1;32m` = bold green, `\033[0m` = reset.
8. **`errno`** stores error codes; `strerror(errno)` gives human-readable message.
9. **`stat()`** system call returns file metadata (size, inode, permissions, timestamps).
10. **`exec()` family** replaces the current process; used after `fork()` to run new programs.

---

*BCA Semester 6 | Linux Programming (BCA C5003) | Unit 5 Notes*
