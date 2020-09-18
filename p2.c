#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct students{
    char name[21];
    int age;
}students;
void main()
{
    students st1={"salman",23};
    students *st;
    st=&st1;
    printf("%s and %d",st->name,st->age);

}
