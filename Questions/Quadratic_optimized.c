#include<stdio.h>

struct Poly {
	int deg;
	int constant;
	struct Poly* next;
};

typedef struct Poly poly;

void addNode(poly** head, int constant, int deg)
{
	poly* temp = (poly*)malloc(sizeof(poly));
	if (temp == NULL) {
		printf("Memeory could not be allocated\n");
	}
	else {
		temp->deg = deg;
		temp->constant = constant;
		if (*head == NULL) {
			*head = temp;
			(*head)->next = NULL;
		}
		else {
			temp->next = *head;
			*head = temp;
		}
	}

}

void addEquations(poly* eq1, poly* eq2)
{
	poly* temp1;
	poly* temp2;
	while (eq2 != NULL)
	{
		temp1 = eq1->next;
		temp2 = eq2;
		if (temp1 != NULL) {

			if (eq1->deg > eq2->deg&&eq1->next->deg < eq2->deg) {
				eq1->next = eq2;
				eq2 = eq2->next;
				temp2->next = temp1;

				eq1 = eq1->next;

			}
			else if (eq1->deg == eq2->deg) {
				eq1->constant += eq2->constant;
				eq2 = eq2->next;
			}
			else {
				eq1 = eq1->next;
			}
		
		}

		else {
			if (eq1->deg == eq2->deg) {
				eq1->constant = eq1->constant + eq2->constant;
				eq2 = eq2->next;
			}
			else {
				eq1->next = eq2;
				break;
			}
		}

	}
}

int main()
{
	poly* eq1 = NULL;
	poly* eq2 = NULL;
	poly* temp;
	int deg1, deg2;
	int i, c;

	printf("Enter highest degree of eq1\n");
	scanf("%d", &deg1);
	printf("Enter information about first equation\n");
	for (i = 0; i <= deg1; i++)
	{
		printf("Enter cofficient of x having degree %d: ", i);
		scanf("%d", &c);
		if (c != 0)
			addNode(&eq1,c,i);
	}

	printf("\nEnter highest degree of eq2\n");
	scanf("%d", &deg2);
	printf("Enter information about second equation\n");
	for (i = 0; i <= deg2; i++)
	{
		printf("Enter cofficient of x having degree %d: ", i);
		scanf("%d", &c);
		if (c != 0)
			addNode(&eq2, c, i);
	}

	if (deg1 > deg2) { addEquations(eq1, eq2); temp = eq1; }
	else { addEquations(eq2, eq1); temp = eq2; }

	while (temp != NULL)
	{
		printf("%dx^%d + ", temp->constant, temp->deg);
		temp = temp->next;
	}

	getch();
	return 0;
}