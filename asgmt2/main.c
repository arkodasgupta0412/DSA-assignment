#include <stdio.h>
#include "p8.c"

int main()
{
    // Initialize the list
    Node *l1 = init_l();

    // Create some nodes
    Node *n1 = create(5);
    Node *n2 = create(10);
    Node *n3 = create(8);
    Node *n4 = create(3);
    Node *n5 = create(11);

    // Insert n1 at the front of the list
    printf("Inserting 5 at the front:\n");
    insert_front(n1, &l1);
    print(l1);

    // Insert n2 after n1
    printf("Inserting 10 after 5:\n");
    insert_after(n2, &n1);
    print(l1);

    // Insert n3 at the front of the list
    printf("Inserting 8 at the front:\n");
    insert_front(n3, &l1);
    print(l1);

    // Insert n4 after n3
    printf("Inserting 3 after 8:\n");
    insert_after(n4, &n3);
    print(l1);

    // Insert n5 after n1
    printf("Inserting 11 after 5:\n");
    insert_after(n5, &n1);
    print(l1);

    // Test deleting the front node
    printf("Deleting the front node:\n");
    delete_front(&l1);
    print(l1);

    // Test deleting after n5
    printf("Deleting node after 11:\n");
    delete_after(&n5);
    print(l1);

    // Test if the list is empty
    printf("Is the list empty? %s\n", empty_l(l1) ? "Yes" : "No");

    // Test if we are at the end of the list
    printf("Is n2 at the end? %s\n", atend_l(n2) ? "Yes" : "No");

    return 0;
}
