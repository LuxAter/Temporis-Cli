#include "any.hpp"
#include "parser.hpp"

int main(int argc, char const* argv[]) {
  cli::Parser parser;
  parser.SetVersion("Temporis-Cli v0.0");
  parser.AddArgument(std::vector<std::string>{"-h", "--help"}, "help",
                     "Displays this help mesage");
  parser.AddArgument(std::vector<std::string>{"--version"}, "version",
                     "Displays the version");
  parser.ArgumentGroup("Timer Arguments");
  parser.AddArgument("start", "start_bool", "set_true",
                     "Prompts user for timer and starts it");
  parser.AddArgument(std::vector<std::string>{"-s", "--start"}, "start",
                     "Starts timmer for specified task");
  parser.AddArgument("end", "end_bool", "set_true",
                     "Prompts user for timer and ends it");
  parser.AddArgument(std::vector<std::string>{"-e", "--end"}, "end",
                     "Ends timer for specified task");
  parser.AddArgument("end-all", "end_all", "set_true",
                     "Ends all currently active timers");
  parser.AddArgument("status", "status", "set_true",
                     "Retuns list of running timmers");
  parser.AddArgument("create", "create_bool", "set_true",
                     "Prompts user for timer and creates new timmer");
  parser.AddArgument(std::vector<std::string>{"-c", "--create"}, "create",
                     "Creates a new timmer");
  parser.AddArgument("delete", "delete_bool", "set_true",
                     "Prompts user for timer and deletes timmer");
  parser.AddArgument(std::vector<std::string>{"-d", "--delete"}, "delete",
                     "Deletes a timmer");
  parser.ArgumentGroup("Report Arguments");
  parser.AddArgument(std::vector<std::string>{"-r", "--report"}, "report",
                     "Returns report of given type [day, week, month, year]");
  parser.AddArgument(std::vector<std::string>{"-p", "--project"}, "project",
                     "Reports only time on designated project");
  std::map<std::string, cli::Any> args = parser.ParseArgs(argc, argv);
  return 0;
}
