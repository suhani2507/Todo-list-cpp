# To-Do List in C++
This is my first C++ project. It's a to-do list that runs in the terminal. You can add tasks, see them, delete them and mark them as done. The tasks get saved in a text file, so they're still there when you open the program again.

## What it does
- Add a task
- View all tasks (completed ones show [X], the rest show [ ])
- Delete a task by its number
- Mark a task as done by its number
- Saves to todo_tasks.txt when you exit and loads it back when you start again

## How to run
You need g++ installed. Compile it like this:

```
g++ main.cpp -o todo
```

Then run it with `./todo` (or `todo.exe` on Windows).

## What I learned
Working with vectors and structs, reading and writing from files, and handling wrong input without the program crashing.
