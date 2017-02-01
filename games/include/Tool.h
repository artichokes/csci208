#ifndef TOOL_H
#define TOOL_H

#include <string>

// Represents a Tool, e.g. Rock, Paper Scissors
class Tool {
 public:
  // Creates a Tool with the given string
  Tool(std::string tool);

  // Gets the type of the Tool
  // @return The type of the Tool
  std::string getType() const;

  // Fights the Tool against another Tool
  // @return -1 if cannot fight, 0 if tie, 1 if this object wins, and 2 if the other object wins
  virtual int fight(Tool *other) = 0;

  // Outputs the type of the Tool to an ostream
  friend std::ostream &operator<<(std::ostream &os, const Tool &tool);

 private:
  // The type of the Tool
  std::string type;
};

#endif //TOOL_H
