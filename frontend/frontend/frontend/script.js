let tasks = [];

function addStudent() {
    alert("Student Registered Successfully!");
}

function addTask() {
    let company = document.getElementById("company").value;
    let title = document.getElementById("title").value;
    let skill = document.getElementById("tskill").value;

    tasks.push({
        id: tasks.length + 1,
        company,
        title,
        skill
    });

    alert("Task Added!");
}

function viewTasks() {
    let list = document.getElementById("taskList");
    list.innerHTML = "";

    tasks.forEach(t => {
        let li = document.createElement("li");
        li.innerText = ${t.id}. ${t.company} - ${t.title} (${t.skill});
        list.appendChild(li);
    });
}

function applyTask() {
    let skill = document.getElementById("applySkill").value;
    let id = document.getElementById("taskId").value;

    let task = tasks[id - 1];

    if (!task) {
        alert("Invalid Task ID");
        return;
    }

    if (skill === task.skill) {
        alert("Application Successful!");
    } else {
        alert("Skill Mismatch!");
    }
}
