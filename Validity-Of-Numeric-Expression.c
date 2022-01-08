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
#include <string.h>

typedef char StackElementType;
typedef struct StackNode *StackPointer;

typedef struct StackNode{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);

main(){
    StackElementType Item;
    StackElementType str[40];
    StackPointer Stack;
    boolean found;
    int n, i = 0;

    CreateStack(&Stack);

    printf("Insert a mathematical expression: ");
    scanf("%s", str);

    found = TRUE;

    n = strlen(str);

    for(i=0; i<n; i++){
        if ((str[i]=='{') || (str[i]=='[') || (str[i]=='('))
            Push(&Stack, str[i]);
        else if((str[i]=='}') || (str[i]==']') || (str[i]==')')){
            if(EmptyStack(Stack)){
                found = FALSE;
                break;
            }
            else{
                Pop(&Stack, &Item);

                if((str[i]=='}') && (Item!='{')){
                    found = FALSE;
                    break;
                }
                else if((str[i]==']')&& (Item!='[')){
                    found = FALSE;
                    break;
                }
                else if((str[i]==')') && (Item!='(')){
                    found = FALSE;
                    break;
                }
            }
        }
    }

    if((found == FALSE) || (!EmptyStack(Stack)))
        printf("WRONG\n");
    else
        printf("CORRECT\n");

    system("PAUSE");
}

void CreateStack(StackPointer *Stack){
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack){
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item){
	StackPointer TempPtr;

    TempPtr = (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item){
    StackPointer TempPtr;

    if (EmptyStack(*Stack))
   	    printf("EMPTY Stack\n");
   else{
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}
