#ifndef GATTER_PRINT_H
#define GATTER_PRINT_H

#include <iostream>

#include "gatter_logik.hpp"

ostream& operator<<(ostream& out, binaerGatter& g);
ostream& operator<<(ostream& out, unaerGatter& g);

#endif