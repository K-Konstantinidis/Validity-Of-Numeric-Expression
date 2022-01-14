/*************************************************************************
        Copyright © 2021 Konstantinidis Konstantinos

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define max 35

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean type_of_set[max];

void Implementation(type_of_set set);
void Universal(type_of_set set);
boolean Insertion(int i, type_of_set set, char xar[max], char in, char close);
boolean Member(int stoixeio, type_of_set set);
boolean EqualSets(type_of_set s1, type_of_set s2);
boolean Subset(type_of_set s1, type_of_set s2);
void Union(type_of_set s1, type_of_set s2, type_of_set un);
void Intersection(type_of_set s1, type_of_set s2, type_of_set tomi);
void Difference(type_of_set s1, type_of_set s2, type_of_set diafora);
void PrintSet(type_of_set set, char xar[max]);

int main(){
    int i;
    type_of_set S, T, un, inter, diff;
    boolean isa;
    char xar[max], in, close;
    boolean flag = TRUE;

    Implementation(S);
    for(i=0; i<max; i++){
        flag = Insertion(i, S, xar, in, close);
        if(!flag)
            break;
    }
    printf("\n");
    printf("S:");
    PrintSet(S, xar);
    printf("\n\n");

    Implementation(T);
    for(i=0; i<max; i++){
        flag = Insertion(i, T, xar, in, close);
        if(!flag)
            break;
    }
    printf("\n");
    printf("T:");
    PrintSet(T, xar);
    printf("\n\n");

    if(EqualSets(S, T))
        printf("The two sets are equal\n\n");

    if(Subset(S, T))
        printf("S Subset of T\n\n");

    if(Subset(T, S))
        printf("T Subset of S\n\n");

    Union(S, T, un);
    printf("Union:");
    PrintSet(un, xar);
    printf("\n\n");

    Intersection(S, T, inter);
    printf("Intersection:");
    PrintSet(inter, xar);
    printf("\n\n");

    Difference(S, T, diff);
    printf("Difference(S - T):");
    PrintSet(diff, xar);
    printf("\n\n");

    Difference(T, S, diff);
    printf("Difference(T - S):");
    PrintSet(diff, xar);
    printf("\n\n");

    system("PAUSE");
}

void PrintSet(type_of_set set, char xar[max]){
    int i;
    printf("{");
    for(i=0; i<max; i++)
        if(set[i] == TRUE)
            printf("%c",xar[i]);
    printf("}");
}

void Implementation(type_of_set set){
    int i;
    for(i=0; i<max; i++)
        set[i] = FALSE;
}

boolean Insertion(int i, type_of_set set, char xar[max], char in, char close){
    printf("Add character: ");
    scanf(" %c",&in);
    xar[i] = in;
    set[i] = TRUE;
    printf("Do you want to add more?('y'->Yes 'n'->No): ");
    scanf(" %c",&close);
    while(close!='n' && close!='y'){
        printf("Wrong input.\nDo you want to add more?('y'->Yes 'n'->No): ");
        scanf(" %c",&close);
    }
    if(close=='n')
        return FALSE;
    else
        return TRUE;
}

boolean EqualSets(type_of_set s1, type_of_set s2){
    int i;
    boolean equal;

    equal = TRUE;
    i=0;
    while(i<max && equal)
        if(Member(i,s1) != Member(i,s2))
            equal = FALSE;
        else
            i++;
    return equal;
}

boolean Member(int i, type_of_set set){
    return set[i];
}

boolean Subset(type_of_set s1, type_of_set s2){
    int i;
    boolean subset;

    subset = TRUE;
    i=0;
    while(i<max && subset)
        if(Member(i, s1) && !Member(i, s2))
            subset = FALSE;
        else
            i++;
    return subset;
}

void Union(type_of_set s1, type_of_set s2, type_of_set un){
    int i;

    for(i=0; i<max; i++)
        un[i] = Member(i, s1) || Member(i, s2);
}

void Intersection(type_of_set s1, type_of_set s2, type_of_set inter){
    int i;

    for(i=0; i<max; i++)
        inter[i] = Member(i, s1) && Member(i, s2);
}

void Difference(type_of_set s1, type_of_set s2, type_of_set diff){
    int i;

    for(i=0; i<max; i++)
        diff[i] = Member(i, s1) && (!Member(i, s2));
}
