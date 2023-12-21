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
	printf("-  1.ģ������Ʈ  2.ģ���߰�  3.ģ������  4.����  -\n");
	printf("-                                                -\n");
	printf("--------------------------------------------------\n");
	printf("��ȣ : ");
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

		printf("�̸� : ");
		scanf_s("%s", cName,50);
		printf("��ȣ : ");
		scanf_s("%s", cPhone_Number,12);

		AddFriend(cName, cPhone_Number);
	}
		break;
	case 3:
	{
		bool bFind = false;
		char cName[50] = "";
		printf("������ �̸� : ");
		scanf_s("%s", cName, 50);

		bFind = DeleteFriend(cName);
		if (bFind)
		{
			printf("%s ���� ���� �Ϸ��߽��ϴ�.\n", cName);
		}
		else
		{
			printf("%s ���� ã�� ���߽��ϴ�.\n", cName);
		}
	}
		break;
	case 4:
		break;
	default:
		printf("�߸� �Է��ϼ̽��ϴ�. \n");
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
		if (strcmp(pTarget->Name, Name) == 0) // ã�� �̸��� ���ٸ�.
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