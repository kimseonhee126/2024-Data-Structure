#include <stdio.h>
#include <string.h>

struct studentTag {
    char name[10];
    int age;
    double gpa;
};

struct studentTag s1;

int main() {
    strcpy(s1.name, "kim");
    s1.age = 20;
    s1.gpa = 4.3;
};