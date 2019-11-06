#include "capstone.h"
#include <iostream>
#include <fstream>

class IAlgorithm
{
public:
    virtual std::string getStructure(char **RNA) = 0;
    virtual ~IAlgorithm();
};
