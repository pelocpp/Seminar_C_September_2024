#pragma once

// type
struct DynamicIntArray
{
// private:
    int*    m_data;
    size_t  m_length;
};

// API: function prototypes

// c'tor
int initDynamicIntArray(struct DynamicIntArray* da, size_t length);
void releaseDynamicIntArray(struct DynamicIntArray* da);

// getter
size_t getLength(struct DynamicIntArray* dynArray);

// methods
void fillDynamicIntArray(struct DynamicIntArray* da, int value);
void printDynamicIntArray(struct DynamicIntArray* da);

int resizeDynamicIntArray(struct DynamicIntArray* da, int newLength);
int shrinkToFitDynamicIntArray(struct DynamicIntArray* array);
