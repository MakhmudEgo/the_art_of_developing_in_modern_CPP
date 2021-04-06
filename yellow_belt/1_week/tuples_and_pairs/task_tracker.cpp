//
// Created by Mahmud Jego on 4/5/21.
//

#include <map>
#include <iostream>
#include <tuple>
// Перечислимый тип для статуса задачи
enum class TaskStatus {
	NEW,          // новая
	IN_PROGRESS,  // в разработке
	TESTING,      // на тестировании
	DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = std::map<TaskStatus, int>;

class TeamTasks {
public:
	// Получить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const std::string& person) const {
		return this->tasks.at(person);
	}

	// Добавить новую задачу (в статусе NEW) для конкретного разработчитка
	void AddNewTask(const std::string& person) {
		this->tasks[person][TaskStatus::NEW]++;
	}

	// Обновить статусы по данному количеству задач конкретного разработчика,
	// подробности см. ниже
	std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(const std::string& person, int task_count) {
		TasksInfo upd, noUpd;
		int task_upd = 0;

		for (auto &item : this->tasks[person]) {
			while (item.second && task_upd < task_count && item.first != TaskStatus::DONE) {
				item.second--;
				task_upd++;
				if (item.first == TaskStatus::NEW) {
					upd[TaskStatus::IN_PROGRESS]++;
				} else if (item.first == TaskStatus::IN_PROGRESS) {
					upd[TaskStatus::TESTING]++;
				} else if (item.first == TaskStatus::TESTING) {
					upd[TaskStatus::DONE]++;
				}
			}
		}
		TasksInfo tmp = upd;

		this->tasks[person][TaskStatus::IN_PROGRESS] += tmp[TaskStatus::IN_PROGRESS];
		this->tasks[person][TaskStatus::TESTING] += tmp[TaskStatus::TESTING];
		this->tasks[person][TaskStatus::DONE] += tmp[TaskStatus::DONE];

		if (this->tasks[person][TaskStatus::NEW] == 0)
			this->tasks[person].erase(TaskStatus::NEW);
		if (this->tasks[person][TaskStatus::IN_PROGRESS] == 0)
			this->tasks[person].erase(TaskStatus::IN_PROGRESS);
		if (this->tasks[person][TaskStatus::TESTING] == 0)
			this->tasks[person].erase(TaskStatus::TESTING);
		if (this->tasks[person][TaskStatus::DONE] == 0)
			this->tasks[person].erase(TaskStatus::DONE);

		for (const auto &item : this->tasks[person]) {
			if (item.second && item.first != TaskStatus::DONE && item.second - tmp[item.first] > 0) {
				noUpd[item.first] = item.second - tmp[item.first];
			}
		}
		std::Next(TaskStatus::NEW);
		return {upd, noUpd};
	}

private:
	std::map<std::string, TasksInfo> tasks;
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
	std::cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
		 ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
		 ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
		 ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << std::endl;
}

int main() {
	/*TeamTasks tasks;
	tasks.AddNewTask("Ilia");
	for (int i = 0; i < 3; ++i) {
		tasks.AddNewTask("Ivan");
	}
	std::cout << "Ilia's tasks: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
	std::cout << "Ivan's tasks: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

	TasksInfo updated_tasks, untouched_tasks;

	tie(updated_tasks, untouched_tasks) =
			tasks.PerformPersonTasks("Ivan", 2);
	std::cout << "Updated Ivan's tasks: ";
	PrintTasksInfo(updated_tasks);
	std::cout << "Untouched Ivan's tasks: ";
	PrintTasksInfo(untouched_tasks);

	tie(updated_tasks, untouched_tasks) =
			tasks.PerformPersonTasks("Ivan", 2);
	std::cout << "Updated Ivan's tasks: ";
	PrintTasksInfo(updated_tasks);
	std::cout << "Untouched Ivan's tasks: ";
	PrintTasksInfo(untouched_tasks);
*/

	TeamTasks tasks;
	for (int i = 0; i < 5; ++i) {
		tasks.AddNewTask("Alice");//  5
	}

	tasks.PerformPersonTasks("Alice", 5);
	tasks.PerformPersonTasks("Alice", 5);
	tasks.PerformPersonTasks("Alice", 1);
	for (int i = 0; i < 5; ++i) {
		tasks.AddNewTask("Alice");//  5
	}
	tasks.PerformPersonTasks("Alice", 2);
	tasks.GetPersonTasksInfo("Alice");
	tasks.PerformPersonTasks("Alice", 4);
	tasks.GetPersonTasksInfo("Alice");
/*
	GetPersonTasksInfo Alice*/

	return 0;
}