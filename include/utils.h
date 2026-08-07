#ifndef UTILS_H
#define UTILS_H

#include "common.h"

bool readInt(const char *prompt, int *value);

bool readFloat(const char *prompt, float *value);

bool readString(const char *prompt,
                char *buffer,
                size_t size);

#endif