#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Friend
{
	char Name[50];
	char Phone_Number[12];
	struct Friend* pNext;
};

int nFriendCount = 0;

struct Friend* pStart = nullptr;
struct Friend* pEnd = nullptr;

void AddFriend(char Name[], char Phone_Number[]);
void PrintFriendList();
int PrintHome();
bool DeleteFriend(char Name[]);