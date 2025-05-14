# pipex

## 🛠 42cursus - pipex

This project is a simplified reimplementation of shell piping.  
It allows you to execute two commands with input/output redirection, as in:

```bash
< file1 cmd1 | cmd2 > file2
````

---

## ✅ Purpose

The goal of this project is to understand **Unix process control**, **file descriptor manipulation**, and **inter-process communication** using **pipes**.
You will practice creating child processes via `fork()`, redirecting input/output with `dup2()`, and executing commands with `execve()`.

---

## 📁 Project Structure

```text
pipex/
├── includes/
├── src/
│   ├── pipex/
│   └── pipex_bonus/
├── Makefile
└── README.md
```

---

## 🔧 How to Compile

```bash
make
```

It will generate the `pipex` executable.

To clean object files:

```bash
make clean
```

To remove all binaries and object files:

```bash
make fclean
```

---

## 🚀 Usage

### Mandatory Mode

```bash
./pipex infile "cmd1" "cmd2" outfile
```

Executes:

```bash
< infile cmd1 | cmd2 > outfile
```

### Bonus Mode: `here_doc`

```bash
./pipex here_doc LIMITER "cmd1" "cmd2" outfile
```

Executes:

```bash
<<LIMITER cmd1 | cmd2 >> outfile
```

Appends to `outfile`.

### Bonus Mode: Multiple Pipes

```bash
./pipex infile "cmd1" "cmd2" "cmd3" "cmdN" outfile
```

Executes:

```bash
< infile cmd1 | cmd2 | cmd3 | ... | cmdN > outfile
```

---

## 🔍 Features

* Argument parsing and validation
* Error handling with descriptive messages
* PATH resolution for commands
* Input/output file management
* `execve`-based execution in child processes
* Unix pipe and process control

---

## 🧠 Key Functions Used

* `pipe()`
* `fork()`
* `execve()`
* `dup2()`
* `waitpid()`
* `access()`, `open()`, `close()`

---

## 📚 Resources

* man pages: `man pipe`, `man dup2`, `man fork`, `man execve`
* 42 official subject PDF

---

## 🔑 License

This project is part of the 42Seoul curriculum and follows its evaluation policy.
