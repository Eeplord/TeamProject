#ifndef ID_H
#define ID_H

#include "stdafx.h"

class Id {
private:
  static int generateId_;
  int id_;

public:
  const static std::string idPath_;

  // Generates a new unique id.
  Id();

  // Creates a new id object with the id provided.
  Id(int id);

  // Looks the username up from basePath/userKeyPath.
  // Arguments: username, path?
  // Returns the path name corresponding to the userId if path set to true,
  // else returns the id as a string.
  static std::string find(const std::string&, const bool&);
  static std::string createPath(const std::string&);

  // Creates a new path name for userId.
  // Return a new path name corresponding to the userId.
  std::string getPath();

  int getId() { return id_; }
};

#endif