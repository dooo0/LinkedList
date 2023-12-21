#include "LinkedList.h"

int main()
{
	int nCmd = 0;
	while (nCmd != 4)
	{
		nCmd = PrintHome();
	}

	return 0;
}

int PrintHome()
{
	int nNum = 0;

	printf("--------------------------------------------------\n");
	printf("-                                                -\n");
	printf("-  1.친구리스트  2.친구추가  3.친구삭제  4.종료  -\n");
	printf("-                                                -\n");
	printf("--------------------------------------------------\n");
	printf("번호 : ");
	scanf_s("%d", &nNum);
	printf("\n");

	switch (nNum)
	{
	case 1:
		PrintFriendList();
		break;
	case 2:
	{
		char cName[50] = "";
		char cPhone_Number[12] = "";

		printf("이름 : ");
		scanf_s("%s", cName,50);
		printf("번호 : ");
		scanf_s("%s", cPhone_Number,12);

		AddFriend(cName, cPhone_Number);
	}
		break;
	case 3:
	{
		bool bFind = false;
		char cName[50] = "";
		printf("삭제할 이름 : ");
		scanf_s("%s", cName, 50);

		bFind = DeleteFriend(cName);
		if (bFind)
		{
			printf("%s 님을 삭제 완료했습니다.\n", cName);
		}
		else
		{
			printf("%s 님을 찾지 못했습니다.\n", cName);
		}
	}
		break;
	case 4:
		break;
	default:
		printf("잘못 입력하셨습니다. \n");
		break;
	}

	return nNum;
}

void AddFriend(char Name[], char Phone_Number[])
{
	Friend* stFriend = (Friend*)malloc(sizeof(Friend));

	strcpy_s(stFriend->Name, 50, Name);
	strcpy_s(stFriend->Phone_Number,12, Phone_Number);
	stFriend->pNext = nullptr;

	if (pStart == nullptr)
	{
		pStart = pEnd = stFriend;		
	}
	else 
	{
		pEnd->pNext = stFriend;
		pEnd = stFriend;
	}

	nFriendCount++;
}

void PrintFriendList()
{
	Friend* pCurrent = pStart;
	while (pCurrent != nullptr)
	{
		printf("%s / %s\n\n", pCurrent->Name, pCurrent->Phone_Number);
		pCurrent = pCurrent->pNext;
	}
}

bool DeleteFriend(char Name[])
{
	bool bFind = false;
	Friend* pTarget = pStart;
	Friend* pBeforeTarget = nullptr;
	for (int i = 0; i < nFriendCount; i++)
	{		
		if (strcmp(pTarget->Name, Name) == 0) // 찾은 이름이 같다면.
		{
			bFind = true;
			
			if (pTarget == pStart)
			{
				pStart = pTarget->pNext;
			}
			else
			{
				if (pTarget == pEnd)
				{
					pEnd = pBeforeTarget;
					pBeforeTarget->pNext = nullptr;
				}
				else
				{
					pBeforeTarget->pNext = pTarget->pNext;
				}
			}

			free(pTarget);
			nFriendCount--;

			break;
		}
		else
		{
			pBeforeTarget = pTarget;
			pTarget = pTarget->pNext;
		}
	}

	return bFind;
}