#include <stdio.h>
#include <stdlib.h> // For exit()
#define MAX 10
void create();
void insert();
void deletion();
void search();
void display();
int b[MAX], n, i, pos, e, p;
int main() {
int ch;
char g = 'y';
do {
printf("\nMain Menu");
printf("\n1. Create");
printf("\n2. Delete");
printf("\n3. Search");
printf("\n4. Insert");
printf("\n5. Display");
printf("\n6. Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1:
create();
break;
case 2:
deletion();
break;
case 3:
search();
break;
case 4:
insert();
break;
case 5:
display();
break;
case 6:
exit(0);
break;
default:
printf("\nEnter a correct choice.\n");
}
printf("\nDo you want to continue ::: ");
scanf(" %c", &g); // Added space before %c to ignore any whitespace characters
} while (g == 'y' || g == 'Y');
return 0;
}
void create() {
printf("\nEnter the number of nodes ", MAX);
scanf("%d", &n);
if (n > MAX) {
printf("\nCannot create more than %d elements.\n", MAX);
n = MAX; // Set n to MAX to avoid overflow
}
for (i = 0; i < n; i++) {
printf("\nEnter Element %d: ", i + 1);
scanf("%d", &b[i]);
}
}
void deletion() {
printf("\nEnter the position you want to delete :: ", n - 1);
scanf("%d", &pos);
if (pos < 0 || pos >= n) {
printf("\nInvalid position.\n");
} else {
for (i = pos; i < n - 1; i++) {
b[i] = b[i + 1];
}
n--;
printf("\nThe elements after deletion:\n");
display();
}
}
void search() {
printf("\nEnter the element to be searched: ");
scanf("%d", &e);
int found = 0;
for (i = 0; i < n; i++) {
if (b[i] == e) {
printf("Value %d is at position %d.\n", e, i);
found = 1;
break;
}
}
if (!found) {
printf("Value %d is not in the list.\n", e);
}
}
void insert() {
printf("\nEnter the position where you need to insert (0 to %d): ", n);
scanf("%d", &pos);
if (pos < 0 || pos > n || n >= MAX) {
printf("\nInvalid position or list is full.\n");
} else {
for (i = n; i > pos; i--) {
b[i] = b[i - 1];
}
printf("\nEnter the element to insert: ");
scanf("%d", &p);
b[pos] = p;
n++;
printf("\nThe list after insertion:\n");
display();
}
}
void display() {
printf("\nThe elements of the list ADT are:");
for (i = 0; i < n; i++) {
printf("\n%d", b[i]);
}
printf("\n");
}
