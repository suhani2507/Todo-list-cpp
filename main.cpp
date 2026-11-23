#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <vector>


using namespace std;

struct Task{
    string title;
    bool done;
};

void saveTasks(const vector<Task>& tasks){
    ofstream out("todo_tasks.txt");
    for(int i = 0; i < tasks.size(); i++){
        out << tasks[i].done << " " << tasks[i].title << "\n";
    }
}

void loadTasks(vector<Task>& tasks){
    ifstream in("todo_tasks.txt");
    if(!in)
    return;

    int flag;
    while (in >> flag) {
        in.ignore();
        string title;
        getline(in, title);

        Task t;
        t.title = title;
        t.done = (flag == 1);
        tasks.push_back(t);
    }
}

int main()
{
    vector<Task> tasks;
    loadTasks(tasks);
    int choice = -1;
    do{
    cout << "***** To-Do list *****" << "\n"
    "Choose an operation:\n"
    "1. Add task\n"
    "2. View tasks\n"
    "3. Delete task\n"
    "4. Mark tasks as done\n"
    "5. Edit tasks\n"
    "0. Exit\n"
    "Enter your choice: ";
    cin >> choice;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');    // deletes all non-numeric junk from cin
        cout << "Invalid input. Please enter a number \n";
        continue;
    }
    cin.ignore();
    if(choice == 1){
        Task task;
        cout << "Enter a new task: ";
        getline(cin, task.title);
        task.done = false;
        tasks.push_back(task);
    }
    else if(choice == 2){
        if(tasks.empty()){
            cout << "No tasks yet. \n";
        }
        else{
            for(int i = 0; i < tasks.size(); i++){
                string status = tasks[i].done ? "[X]" : "[ ]";
                cout << to_string(i+1) + ". " + status + " " << tasks[i].title << "\n";
            }
        }
    }
    else if(choice == 3){
        if(tasks.empty()){
            cout << "No tasks to delete. \n";
        }
        else{
            int num;
            cout << "Enter the task number: ";
            cin >> num;
            if(num < 1 || num > tasks.size()){
            cout << "Invalid task number\n";
            }
            else{
            tasks.erase(tasks.begin() + (num-1));
            }
        }
    }
    else if(choice == 4){
        int num;
        cout << "Enter the task number: ";
        cin >> num;
        if(num < 1 || num > tasks.size()){
            cout << "Invalid task number \n";
        }
        else{
            tasks[num - 1].done = true;
            cout << "Task is marked done! \n";
        }
    }
    else if(choice == 5){
        int num;
        cout << "Enter the task number: ";
        cin >> num;
        if(num < 1 || num > tasks.size()){
            cout << "Invalid task number \n";
        }
        else{
            cin.ignore();
            cout << "Enter the new task: ";
            getline(cin, tasks[num - 1].title);
            cout << "Task Updated!\n";
        }
    }
    saveTasks(tasks);
    }
    while(choice != 0);
    cout << "Goodbye!";
    return 0;
}
