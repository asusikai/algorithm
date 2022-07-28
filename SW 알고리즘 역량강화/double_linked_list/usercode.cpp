#define MAX_NODE 10000

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
int nowCnt;
Node* head;
Node* tail;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
    nodeCnt = 0;
    nowCnt = 0;
    head = nullptr;
    tail = nullptr;

    for(int i =0; i<MAX_NODE; i++){
        node[i].data = 0;
        node[i].next = nullptr;
        node[i].prev = nullptr;
    }

}

void addNode2Head(int data)
{
    Node* new_node = getNode(data);
    if(head == nullptr){
        head = new_node;
        tail = head;
    }

    else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    nowCnt++;

    //printf("head:%d\n", head->data);
    //printf("tail:%d\n",tail->data);

}

void addNode2Tail(int data) 
{
    
    if(tail == nullptr){
        Node* new_node = getNode(data);
        tail = new_node;
        head = tail;
    }

    else{
        Node* new_node = getNode(data);
        tail->next= new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    nowCnt++;
    //printf("head:%d\n", head->data);
    //printf("tail:%d\n",tail->data);
    //printf("tail->prev:%d\n",tail->prev->prev->data);
}

void addNode2Num(int data, int num) 
{

    if(head == nullptr){
        Node* new_node = getNode(data);
        head = new_node;
        tail = head;

        //printf("head:%d\n", head->data);
        //printf("tail:%d\n",tail->data);
        //printf("tail->prev:%d\n",tail->prev->data);
        nowCnt++;
        return ;
    }

    if(num == 1){

        Node* new_node = getNode(data);
        new_node->next = head;
        head->prev = new_node;
        head = new_node;

        //printf("head:%d\n", head->data);
        //printf("tail:%d\n",tail->data);
        //printf("tail->prev:%d\n",tail->prev->data);
        nowCnt++;
        return ;
    }

    if (num > nowCnt)
    {
        Node* new_node = getNode(data);
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
        nowCnt++;
        //printf("head:%d\n", head->data);
        //printf("tail:%d\n",tail->data);
        //printf("tail->prev:%d\n",tail->prev->data);
        return ;
    }

    //middle
    Node* new_node = getNode(data);
    Node* prevNode = head;

    for(int i=1; i<num-1; i++){
        prevNode = prevNode->next;
    }
    new_node->next = prevNode->next;
    new_node->prev = prevNode;
    new_node->next->prev = new_node;
    prevNode->next = new_node;
    nowCnt++;

    //printf("head:%d\n", head->data);
    //printf("tail:%d\n",tail->data);
    //printf("tail->prev:%d\n",tail->prev->data);
    return ;

}

int findNode(int data) 
{
    int Cnt = 1;
    Node* targetNode = head;
    while(targetNode->data != data && targetNode!= nullptr){
        targetNode = targetNode->next;
        Cnt++;
    }

    if(targetNode != nullptr){
        return Cnt;
    }
    
    return -1;

}

void removeNode(int data) 
{
    if(head == nullptr){
        return ;
    }

    nowCnt--;

    if(head->data == data){
        Node* temp = head;
        head = head->next;
        temp->next =nullptr;
        head->prev = nullptr;


        //printf("head:%d\n", head->data);
        //printf("tail:%d\n",tail->data);
        //printf("tail->prev:%d\n",tail->prev->data);
        return ;
    }

    if(tail->data == data){
        Node* temp = tail;
        tail = temp->prev;
        temp->prev = nullptr;
        tail->next = nullptr;

        //printf("head:%d\n", head->data);
        //printf("tail:%d\n",tail->data);
        //printf("tail->prev:%d\n",tail->prev->data);
        return ;
    }

    Node* prevNode = head;

    while(prevNode->next->data!=data && prevNode->next->next!=nullptr){
        prevNode = prevNode->next;
    }

    if(prevNode->next->data == data){
        Node* targetNode = prevNode->next;
        prevNode->next = targetNode->next;
        prevNode->next->prev = prevNode;

        //printf("head:%d\n", head->data);
        //printf("tail:%d\n",tail->data);
        //printf("tail->prev:%d\n",tail->prev->data);

        return ;
    }
    
    return ;
}

int getList(int output[MAX_NODE]) 
{
    if(head == nullptr){
        return 0;
    }

    Node* searchNode = head;
    int Cnt = 0;
    while(searchNode != nullptr){
        output[Cnt++] = searchNode->data;
        //printf("data:%d\n", searchNode->data);
        searchNode =searchNode->next;
    }

    return Cnt;

}

int getReversedList(int output[MAX_NODE]) 
{
    if(tail == nullptr){
        return 0;
    }

    Node* reversesearchNode = tail;
    int Cnt = 0;
    while(reversesearchNode != nullptr){
        output[Cnt++] = reversesearchNode->data;
        //printf("data:%d\n", reversesearchNode->data);
        reversesearchNode = reversesearchNode->prev;
    }

    return Cnt;

}