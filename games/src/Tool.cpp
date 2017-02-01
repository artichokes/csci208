#include "Tool.h"

Tool::Tool(std::string type) : type(type) { }

std::string Tool::getType() const { return this->type; }

std::ostream &operator<<(std::ostream &os, const Tool &tool) {
  return os << tool.getType();
}
