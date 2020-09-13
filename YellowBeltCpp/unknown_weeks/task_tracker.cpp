class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return person_to_info.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person) {
        person_to_info[person][TaskStatus::NEW]++;
        person_to_count[person]++;
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
        TasksInfo first;
        TasksInfo second;
        TasksInfo copy = person_to_info[person];
        TasksInfo clear = person_to_info[person];
        if (task_count > person_to_count[person]) {
            task_count = person_to_count[person];
        }
        for (int i = 0; i < task_count; ++i) {
            if (person_to_info[person][TaskStatus::NEW] > 0) {
                person_to_info[person][TaskStatus::NEW]--;
                copy[TaskStatus::NEW]--;
                copy[TaskStatus::IN_PROGRESS]++;
            }
            else if (person_to_info[person][TaskStatus::IN_PROGRESS] > 0) {
                person_to_info[person][TaskStatus::IN_PROGRESS]--;
                copy[TaskStatus::IN_PROGRESS]--;
                copy[TaskStatus::TESTING]++;
            }
            else if (person_to_info[person][TaskStatus::TESTING] > 0) {
                person_to_info[person][TaskStatus::TESTING]--;
                copy[TaskStatus::TESTING]--;
                copy[TaskStatus::DONE]++;
                person_to_count[person]--;
            }
        }
        first[TaskStatus::IN_PROGRESS] = clear[TaskStatus::NEW] - person_to_info[person][TaskStatus::NEW];
        first[TaskStatus::TESTING] = clear[TaskStatus::IN_PROGRESS] - person_to_info[person][TaskStatus::IN_PROGRESS];
        first[TaskStatus::DONE] = clear[TaskStatus::TESTING] - person_to_info[person][TaskStatus::TESTING];
        second = person_to_info[person];
        second.erase(TaskStatus::DONE);
        person_to_info[person] = copy;
        tuple<TasksInfo, TasksInfo> result(first, second);
        for (auto now : copy) {
            if (now.second == 0) {
                person_to_info[person].erase(now.first);
            }
        }
        for (auto now : first) {
            if (get<0>(result).at(now.first) == 0)
                get<0>(result).erase(now.first);
        }
        for (auto now : second) {
            if (get<1>(result).at(now.first) == 0)
                get<1>(result).erase(now.first);
        }
           return result;
    }
private:
    map<string, TasksInfo> person_to_info;
    map<string, int> person_to_count;
};
