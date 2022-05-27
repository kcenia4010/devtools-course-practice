// Copyright 2022 Zaitseva Ksenia

#include "include/deicstra_application.h"

bool DeicstraApplication::help(int argc, const char* argv[], std::size_t& top,
                               std::vector<std::vector<std::size_t>>& graf) {
  if (argc <= 3) {
    return false;
  }

  std::vector<std::size_t> vector;
  vector.push_back(0);

  for (int i = 2; i < argc; ++i) {
    if (argv[i][0] == '|')
      continue;
    else if (argv[i][1] == ')') {
      top = atoi(argv[i + 1]);
      vector.push_back(0);
      break;
    } else {
      vector.push_back(atoi(argv[i]));
    }
  }
  if (std::sqrt(vector.size()) != static_cast<int>(std::sqrt(vector.size()))) {
    return false;
  }

  graf.resize(sqrt(vector.size()));
  for (int i = 0; i < graf.size(); i++) {
    for (int j = 0; j < graf.size(); j++) {
      graf[i].push_back(vector[i * graf.size() + j]);
    }
  }
  if (top >= 0 && top < graf.size())
    return checkGraf(graf);
  else
    return false;
}

bool DeicstraApplication::checkGraf(
    const std::vector<std::vector<std::size_t>>& graf) {
  for (int i = 0; i < graf.size(); i++) {
    if (graf[i][i] != 0) {
      return false;
    }
    for (int j = 0; j < graf.size(); j++) {
      if (graf[i][j] != graf[j][i]) {
        return false;
      }
      if (graf[i][j] < 0) return false;
    }
  }
  return true;
}

std::string DeicstraApplication::operator()(int argc, const char* argv[]) {
  std::cout << "This is algorithm Deicstra application.\n"
            << "Please provide arguments in following format:\n"
            << "$ " << argv[0] << " <matrix> <target vertice>\n\n"
            << "Example: " << argv[0] << " (0 2 1 | 2 0 3 | 1 3 0) 0 \n\n";
  std::size_t top;
  std::vector<std::vector<std::size_t>> graf;
  if (!help(argc, argv, top, graf)) {
    std::cout << "Incorrect parametrs.\n";
    return std::string();
  }
  Algorithm Deicstra;
  std::vector<std::size_t> res = Deicstra.getDeicstra(graf, top);
  std::string print_result =
      "Distance between vertices " + toString(top) + " and\n\t";
  for (std::size_t i = 0; i < res.size(); i++) {
    print_result += toString(i) + " is " + toString(res[i]) + "\n\t";
  }
  return print_result;
}
