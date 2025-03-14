Node *merge(Node *l1, Node *l2)
{

    if (l1 == NULL)
        return l2;

    if (l2 == NULL)
        return l1;

    Node *temp = new Node(-1);

    Node *ptr = temp;

    while (l1 != NULL && l2 != NULL)

    {

        if (l1->data < l2->data)

        {

            ptr->child = l1;

            ptr = l1;

            l1 = l1->child;
        }

        else

        {

            ptr->child = l2;

            ptr = l2;

            l2 = l2->child;
        }
    }

    if (l1 == NULL)

    {

        ptr->child = l2;
    }

    else

    {

        ptr->child = l1;
    }

    return temp->child;
}

Node *flattenLinkedList(Node *head)

{

    // Write your code here

    if (head == NULL)
        return head;

    Node *l1 = head;

    Node *l2 = flattenLinkedList(head->next);

    l1->next = NULL;

    Node *ans = merge(l1, l2);

    return ans;
}