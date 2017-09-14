#ifndef TEMPORIS_TASK_CLI
#define TEMPORIS_TASK_CLI

#include <time.h>

namespace temporis {
  class Task {
    Task(std::string name_);
    Task(std::string name_, std::string project_);
    Task(std::string name_, struct tm due_);
    Task(std::string name_, std::string project_, struct tm due_);

    void CalculateUrgency();

    int u_id;
    double urgency;
    std::string name, project;
    struct tm entry, due;
    bool status;
  };
}  // namespace temporis

#endif /* ifndef TEMPORIS_TASK_CLI */
