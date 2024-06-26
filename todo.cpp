#include <iostream>
#include <vector>
using namespace std;

class todo {
private:
    int id;
    string name;
    string description;
    bool status;
public:
    void display_task() {
        cout << "ID          : " << id << endl;
        cout << "Name        : " << name << endl;
        cout << "Description : " << description << endl;
        cout << "Status      : " << (status ? "completed" : "pending") << endl << endl;
    }

    void setdata(int a, string b, string c) {
        id = a;
        name = b;
        description = c;
        status = false;
    }

    void update_status() {
        status = true;
    }

    void update_name(string b) {
        name = b;
    }

    void update_description(string c) {
        description = c;
    }

    int get_id() {
        return id;
    }

    bool get_status() {
        return status;
    }
};

class todo_list {
private:
    vector<todo> t_list;
public:
    void new_task() {
        int id;
        string name, description;

        cout << "Enter id: ";
        cin >> id;
        cin.ignore(); // To clear the newline character left by cin

        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter description: ";
        getline(cin, description);

        todo t;
        t.setdata(id, name, description);
        t_list.push_back(t);
    }

    void delete_task(int id) {
        for (auto i = t_list.begin(); i != t_list.end(); i++) {
            if (i->get_id() == id) {
                t_list.erase(i);
                cout << "Task with ID " << id << " has been deleted." << endl;
                return;
            }
        }
        cout << "Task with ID " << id << " not found." << endl;
    }

    void show_tasks() const {
        if (t_list.empty()) {
            cout << "No tasks available." << endl;
        } else {
            for (auto task : t_list) {
                task.display_task();
            }
        }
    }

    void update_task_name(int id, string name) {
        for (auto i = t_list.begin(); i != t_list.end(); i++) {
            if (i->get_id() == id) {
                i->update_name(name);
                cout << "Task with ID " << id << " has been updated." << endl;
                return;
            }
        }
        cout << "Task with ID " << id << " not found." << endl;
    }

    void update_task_desc(int id, string description) {
        for (auto i = t_list.begin(); i != t_list.end(); i++) {
            if (i->get_id() == id) {
                i->update_description(description);
                cout << "Task with ID " << id << " has been updated." << endl;
                return;
            }
        }
        cout << "Task with ID " << id << " not found." << endl;
    }

    void update_task_status(int id) {
        for (auto i = t_list.begin(); i != t_list.end(); i++) {
            if (i->get_id() == id) {
                i->update_status();
                cout << "Task with ID " << id << " has been updated." << endl;
                return;
            }
        }
        cout << "Task with ID " << id << " not found." << endl;
    }

    void completed_task() const {
        if (t_list.empty()) {
            cout << "No tasks available." << endl;
        } else {
            for (auto task : t_list) {
                if (task.get_status()) {
                    task.display_task();
                }
            }
        }
    }

    void incomplete_task() const {
        if (t_list.empty()) {
            cout << "No tasks available." << endl;
        } else {
            for (auto task : t_list) {
                if (!task.get_status()) {
                    task.display_task();
                }
            }
        }
    }
};

int main() {
    todo_list my_list;

    int choice;
    do {
        cout << "\n1. Add new task\n2. Delete task\n3. Show tasks\n4. Update task name\n5. Update task description\n6. Update task status\n7. Show completed tasks\n8. Show incomplete tasks\n9. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                my_list.new_task();
                break;
            case 2: {
                int id;
                cout << "Enter ID of the task to delete: ";
                cin >> id;
                my_list.delete_task(id);
                break;
            }
            case 3:
                my_list.show_tasks();
                break;
            case 4: {
                int id;
                string name;
                cout << "Enter ID of the task to be updated: ";
                cin >> id;
                cin.ignore(); // To clear the newline character left by cin
                cout << "Enter new name of the task: ";
                getline(cin, name);
                my_list.update_task_name(id, name);
                break;
            }
            case 5: {
                int id;
                string description;
                cout << "Enter ID of the task to be updated: ";
                cin >> id;
                cin.ignore(); // To clear the newline character left by cin
                cout << "Enter new description of the task: ";
                getline(cin, description);
                my_list.update_task_desc(id, description);
                break;
            }
            case 6: {
                int id;
                cout << "Enter ID of the task to update status: ";
                cin >> id;
                my_list.update_task_status(id);
                break;
            }
            case 7:
                my_list.completed_task();
                break;
            case 8:
                my_list.incomplete_task();
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}
