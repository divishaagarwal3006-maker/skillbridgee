#include <stdio.h>
#include <string.h>

#define MAX 20

struct Student {
    int id;
    char name[50];
    char skill[50];
};

struct Task {
    int id;
    char company[50];
    char title[50];
    char requiredSkill[50];
};

struct Student students[MAX];
struct Task tasks[MAX];

int studentCount = 0;
int taskCount = 0;

/* Register Student */
void addStudent() {
    students[studentCount].id = studentCount + 1;

    printf("\nEnter student name: ");
    scanf("%s", students[studentCount].name);

    printf("Enter skill: ");
    scanf("%s", students[studentCount].skill);

    printf("Student Registered | ID: %d\n", students[studentCount].id);
    studentCount++;
}

/* Add Company Task */
void addTask() {
    tasks[taskCount].id = taskCount + 1;

    printf("\nEnter company name: ");
    scanf("%s", tasks[taskCount].company);

    printf("Enter task title: ");
    scanf("%s", tasks[taskCount].title);

    printf("Enter required skill: ");
    scanf("%s", tasks[taskCount].requiredSkill);

    printf("Task Added | Task ID: %d\n", tasks[taskCount].id);
    taskCount++;
}

/* View All Tasks */
void viewTasks() {
    if (taskCount == 0) {
        printf("\nNo tasks available.\n");
        return;
    }

    printf("\n--- Available Tasks ---\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s | %s | Skill: %s\n",
               tasks[i].id,
               tasks[i].company,
               tasks[i].title,
               tasks[i].requiredSkill);
    }
}

/* Apply for Task */
void applyTask() {
    int taskID;
    char studentSkill[50];

    if (taskCount == 0) {
        printf("\nNo tasks to apply for.\n");
        return;
    }

    printf("\nEnter your skill: ");
    scanf("%s", studentSkill);

    viewTasks();

    printf("\nEnter Task ID to apply: ");
    scanf("%d", &taskID);

    if (taskID < 1 || taskID > taskCount) {
        printf("Invalid Task ID!\n");
        return;
    }

    if (strcmp(studentSkill, tasks[taskID - 1].requiredSkill) == 0) {
        printf("Application Successful! Skill Matched.\n");
    } else {
        printf("Application Failed! Skill Mismatch.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n=== SkillBridge Menu ===\n");
        printf("1. Register Student\n");
        printf("2. Add Company Task\n");
        printf("3. View Tasks\n");
        printf("4. Apply for Task\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: addTask(); break;
            case 3: viewTasks(); break;
            case 4: applyTask(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
