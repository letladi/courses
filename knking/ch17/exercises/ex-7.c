/**
 * By freeing p in the loop body, p = p->next becomes an udefined operation since p now refers to 
 * freed memory.
 * 
 * struct node* temp;
 * p = first;
 * while (p != NULL) {
 *    temp = p;
 *    p = p->next;
 *    free(temp);
 * }
 */ 