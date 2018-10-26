typedef struct tListElement
{
	tListElement *next;
	int distance;
	int degrees;
	bool is_turning;
	bool tail;
	bool head;
} tListElement;

const int kNumbOfListItems = 100;
tListElement listElements[kNumbOfListItems];

void initList(tListElement *list, int nListSize)
{
	tListElement *pCurr;
	tListElement *pNext;

	memset(list, 99, sizeof(tListElement) * nListSize);
	memset(list, 0, sizeof(tListElement) * nListSize);
	pCurr = list;
	pCurr->tail = true;
	pCurr->head = false;

	pNext = pCurr;
	for (int index = 0; index < nListSize; ++index)
	{
		pCurr = pNext;
		pNext += sizeof(tListElement);  // Kludge until compiler fixed.
		pCurr->distance = index*11;
		pCurr->degrees = index;
		pCurr->is_turning=true;
		pCurr->next = pNext;
	}
};
void print_list(tListElement *head) {
    tListElement * current = head;

    while (current != NULL) {
        writeDebugStream("The distance is :%d the degrees is: %d and turning is: %d\n", current->distance,current->degrees,current->is_turning);
        current = current->next;
    }
};

task main ()
{
	tListElement *head = &listElements[0];
	initList(&listElements[0], kNumbOfListItems);
	print_list(listElements);
}
