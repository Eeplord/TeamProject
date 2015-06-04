#ifndef ID_H
#define ID_H

#include <string>
#include <fstream>

class Id {
private:
  static int generateId_;
  int id_;

public:

  // Generates a new unique id.
  Id();

  // Creates a new id object with the id provided.
  Id(int id);
  ~Id();

  // Looks the username up from basePath/userIdPath
  // Returns the path name corresponding to the userId.
  static std::string find(const std::string&);

  int getId() { return id_; }
};

#endif