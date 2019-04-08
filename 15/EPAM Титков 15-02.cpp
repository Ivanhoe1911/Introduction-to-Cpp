/**
*
* ������ ����
* 2. ���������� ����� ��� ������ � ����������� �������. �������� ������ - ����� �����.
* ������� ������. ����� � ������ ������������ ������� � ������� ���.
*
*/

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

class SList					// ����� "����������� ������".
{
public:
	SList();				// ����������� �� ���������.
	SList(int data);		// ����������� � ����������.
	~SList();				// ����������.
	void addNode(int);		// ������� ���������� �������� � ������.
	void showNodes();		// ������� ������ ��������� ������ �� �����.
	int findMax();			// ������� ������ ������������� �������� � ������.
	void delNode(int);		// ������� �������� �������� ������ �� ��������.

	int createCount;		// ������� ��������� � ������, ��� �������.
private:
	struct Node				// ������� ������: ��������� � �������.
	{
		int data;			// ������ ��������: ����� �����.
		Node *nextNode;		// ��������� �� ��������� ������� � �������.
	} *firstNode, *lastNode;// ��������� �� ������ � ��������� �������� ������.	
};

SList::SList()				// ����������� �� ���������.
{
	firstNode = NULL;		// ��������� �������� ������ �� ��������, �.�.
	lastNode = NULL;		// ��� ����� ������� ����� ������� ���������� ��������.

	createCount = 0;		// ������������� �������� ��������� � ������.
}

SList::SList(int data)			// ����������� � ����������.
{
	firstNode = new Node;		// �������� ������ ������ � ������.

	firstNode->data = data;		// ���������� ������� �������� �������.
	firstNode->nextNode = NULL; // ������ ������ �������� �������
	lastNode = firstNode;		// ����� � ���������.

	createCount = 1;			// ������������� �������� ��������� � ������.
}

SList::~SList()					// ����������.
{
	int delCount = 0;			// ������� ���������� ��������� ��������� ������, ��� �������.
	Node *temp = firstNode;		// �������� �������� ��� ��������� ����������, ������� � �������.

	// ��������� �� ������ ������� ���������� � ����������, � ��� ���������� ������,
	// ���������� �� ��������� ��������� ���������. � ��� �� �����.
	while (firstNode != NULL)		// ���� ����������� ���� �� ������ �� ���������� �������� ������.
	{
		firstNode = temp->nextNode;	// ��������� �� ������ ������� ��������� � ����������,
		delete temp;				// � ���������� ������ ������� ���������.
		temp = firstNode;			// ������� ���������� ��������� � ���������� ��������.
		++delCount;					// ������� �������� - ���������� ����������.
	}
	lastNode = NULL;				// ��������� ��������� �� ��������� ������, �������������.
	// ����� �� ����� ���������� ��������� �������� ������, ���������� ��� �������� ������.
	cout << "�������� ����������, ������� " << delCount
		<< " ��������(��) �� " << createCount << '.' << endl;
}

void SList::addNode(int data)	// ������� ���������� �������� � ������.
{
	++createCount;				// ���������� �������� ������� � ������, ��� �������.

	// ���� �������� ����������� �� ���������, �� ��������� ��� ��� � ���� ������� ������.
	if (firstNode == NULL)
	{
		firstNode = new Node;		// ��������� ������ ��� ������� �������� � ������.

		firstNode->data = data;		// ���������� ������� �������� �������.
		firstNode->nextNode = NULL; // ������ ������ �������� �������
		lastNode = firstNode;		// ����� � ���������.

		return;				// ����� �� �������, �.�. �������� ������� �������� �� ���� ��������.
	}

	// ���� � ������ ��� ���� ��������.
	Node *newNode = new Node;		// ������������ ������ ��������.

	newNode->data = data;			// ���������� ��� �������.
	newNode->nextNode = NULL;		// ������ �� ����� ������� ���������.

	lastNode->nextNode = newNode;	// ��������� ������� ������ ��������� �� ����� ��� �� ���������.
	lastNode = newNode;				// ����� ������� ����������� ���������.
}

void SList::showNodes()				// ������� ������ ������� � �������.
{
	Node *temp = firstNode;			// ��������� ���������� ����� ���������� ������ � ������� ��������.
	while (temp != NULL)			// ���� �����������, ���� �� ������ �� ��������� ������,
	{								// � �� �������� ���� ������� ��� ���.
		cout << temp->data << ' ';	// ����� �� ����� �������� ����������� ������.
		temp = temp->nextNode;		// ���������� ���������� ��������� �� ��������� ������.
	}
}

int SList::findMax()			// ������� ������ ������������� �������� � ������.
{
	int max = firstNode->data;	// ������������� ������� �������� � ������ � �������� ���� ��� ���������.

	Node *temp = firstNode->nextNode;	// ��������� ��������� ���� �� ������,
	while (temp != NULL)				// ���� � ��� ���� ��������.
	{
		if (temp->data > max)	// ���� ������� ������� ������ ������ �������������,
		{						// �� �� ����� ������������
			max = temp->data;
		}
		temp = temp->nextNode;	// ������� � ���������� �������� � ������.
	}
	return max;					// ������� ���������� ������������� �������� ��������.
}

void SList::delNode(int del)		// ������� �������� �������� ������ �� ��������.
{
	Node *temp = firstNode;			// ��������� ���������, ����� ������������ �� ���������, ������� � �������.

	// ���� ��� ������, ����� ��������� ������� �������� ������, �.�. ���� ������ ��������� �� ������ ������.
	while (firstNode != NULL && firstNode->data == del)	// ���� ������������ ���� ���� ��� ���������,
	{													// ����� �������� ����������� ������ ������� ��������.
		firstNode = firstNode->nextNode;	// ��������� ������� �������� ����������� �� ���������.
		delete temp;						// ������� ������ �� ������� ��������.
		--createCount;						// ���������� �������� ��������� ������.
		if (firstNode == NULL)				// ���� ��������� ������� ������� ���������,
		{									// �� ���������� ��������� � �� ��������� �������
			lastNode = NULL;				// � ����� �� ������� �.�. ������ ������ ���������.
			return;
		}
		temp = firstNode;					// ��������� ��������� ����������� �� ����� ������ �������,
	}										// ���� ��� ���� ��� ���������.

	// ���� ��� ���� ��������� �������. ������������ ��������� ��������� � ��������� �� ��������� ������,
	// �.�. ��� �������� ������� ����� ��� ���� ���������, �������� ����� ��������� ������.
	lastNode = firstNode;					// ������� ��������� ��������� ������ � ������ ������.
	temp = lastNode->nextNode;				// ��������� ��������� ��������� ��������� �� ��� ��������.
	while (temp != NULL)
	{
		if (temp->data == del)				// ���� ������ �������� ��������,
		{
			lastNode->nextNode = temp->nextNode;	// �� ���������� ������ ��������� �� ������ ����� ���������,
			delete temp;							// � ������� ������ ��������� �� ������.
			temp = lastNode->nextNode;
			--createCount;					// ���������� �������� ��������� � ������.
		}
		else								// ���� ������ �� �������� ��������, �� ������� � ���������.
		{
			lastNode = temp;
			temp = lastNode->nextNode;
		}
	}
}

void pushMain(SList*, int);	// ������� ���������� ������������ ��������, �� ����� �������� ������.
void pushRand(SList*);		// ������� ���������� ������������ ������ ���������� ����������.
void pushManual(SList*);	// ������� ���������� ������������ ������ �������.

int main()
{
	setlocale(LC_ALL, "ru");

	int choice;			// ���������� ��� �������� ����.
	SList myList;		// �������� ���������� ������.

	// ������� ����.
	while (true)
	{
		cout << "����������� ������." << endl
			<< "1) ��������� ������ ���������� ����������." << endl
			<< "2) ��������� ������ �������." << endl
			<< "3) ������� ������������ �������� �� ������." << endl
			<< "4) ������� ���������� ������ �� �����." << endl
			<< "5) �����." << endl
			<< "�������� �������: ";
		cin >> choice;

		switch (choice)
		{
		case 1:	system("cls");
			pushRand(&myList);								// ���������� ��������� �������� � ������.
			cout << "�������� ���������." << endl << endl;
			break;
		case 2:	system("cls");
			pushManual(&myList);							// ���������� � ������ �������� � ������.
			cout << "�������� ���������." << endl << endl;
			break;
		case 3:	system("cls");
			if (myList.createCount == 0)					// ���� ������ ������, �� ��������� ��������������.
			{
				cout << "������� �������� ��������!"
					<< endl << endl;
				break;
			}
			cout << "�������� ������ �� ��������:" << endl;	// ����� ��������� ������ �� �����.
			myList.showNodes();								// ������ �� �������� ������������� ��������.	
			cout << endl << "������������ ������� ������: "
				<< myList.findMax() << endl;				// ��������� ������������ ��������.
			myList.delNode(myList.findMax());				// �������� ������������� ��������.
			cout << "�������� ������ ����� ��������:" << endl;	// ����� ��������� ������ �� �����.
			myList.showNodes();								// ������ ����� �������� ������������� ��������.	
			cout << endl << endl;
			break;
		case 4: system("cls");
			cout << "�������� ������:" << endl;				// ����� ��������� ������ �� �����.
			myList.showNodes();
			cout << endl << endl;
			break;
		case 5: system("cls");
			cout << "�� ��������!" << endl;
			myList.~SList();								// ����� ����������� �������, ��� �������.
			exit(0);
		default:
			exit(1);
		}
	}

	cout << endl << endl;
	system("pause");
}

// ����� ������� ���������� �������� � ������, �� ����� �������� ������ �������.
void pushMain(SList* slist, int data)
{
	slist->addNode(data);
}

// ������� ��������� ��������� � ������ �������.
void pushManual(SList *slist)
{
	int n;
	cout << "������� �������� ������ ���������?: ";
	cin >> n;

	cout << "������� ����������� �������� ����� ������: ";
	int data;

	for (int i = 0; i < n; i++)	// �������� ������� ��������� ���������� �������� ���������� ���
	{
		cin >> data;			// � ����� ��� ������� �������� ��������.
		pushMain(slist, data);
	}
}

void pushRand(SList *slist)
{
	srand(time(NULL));			// ������������� ���.

	int n;
	cout << "������� �������� ������ ���������?: ";
	cin >> n;

	for (int i = 0; i < n; i++)	// �������� ������� ��������� ���������� �������� ���������� ���
	{
		pushMain(slist, rand() % 21 - 10); // � � ��� ���������� ��������� �������� (-10; 10).
	}
}