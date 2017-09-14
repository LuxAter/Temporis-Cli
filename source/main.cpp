#include "any.hpp"
#include "parser.hpp"

void HandleInput(std::map<std::string, cli::Any> args) {
  if (args["add"] == cli::Any(true)) {
  }
}

int main(int argc, char const* argv[]) {
  cli::Parser parser;
  parser.SetVersion("Temporis-Cli v0.0");
  parser.AddArgument(std::vector<std::string>{"-h", "--help"}, "help",
                     "Displays this help mesage");
  parser.AddArgument("add", "add", "set_true", "Creates a new task");
  parser.AddArgument("delete", "delete", "set_true", "Deletes a task");
  parser.AddArgument("done", "done", "set_true", "Compleates a task");
  parser.AddArgument("start", "start", "set_true",
                     "Starts work on a task or project");
  parser.AddArgument("stop", "stop", "set_true",
                     "Stops work on a task or project");
  parser.AddArgument("Date", "date", "date", "Gets date");
  parser.AddArgument("Time", "time", "time", "Gets time");
  parser.AddArgument("Date/Time", "date_time", "date_time",
                     "Gets date and time");
  parser.AddArgument("ID", "id", "int", "ID of task to act upon");
  parser.AddArgument("Name", "name", "string",
                     "Name of task or project to act upon");
  std::map<std::string, cli::Any> args = parser.ParseArgs(argc, argv);
  for (std::map<std::string, cli::Any>::iterator it = args.begin();
       it != args.end(); ++it) {
    std::cout << it->first << ":" << it->second << "\n";
  }
  HandleInput(args);
  return 0;
}
