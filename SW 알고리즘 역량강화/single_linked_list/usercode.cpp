#define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
    nodeCnt = 0;
    Node node[MAX_NODE] = {};
	head = nullptr;

}

void addNode2Head(int data) 
{
	if(head == nullptr){
		head = getNode(data);

	}
	
	else{
		Node* temp = getNode(data);
		temp->next = head;
		head = temp;
	}
}

void addNode2Tail(int data) 
{
	Node* new_node = getNode(data);
	if(head == nullptr){
		head = new_node;
	}

	else{
		Node* temp = head;
		while(temp->next != nullptr){
			temp= temp->next;
		}

		temp->next = new_node;
	}

}

void addNode2Num(int data, int num) 
{
	Node* new_node = getNode(data);


	if(head!=nullptr){

		if(num == 1){
			addNode2Head(data);
		}

		else{
			Node* prev = head;
			for(int i = 1; i<num-1; i++){
				if(prev->next !=nullptr){
					prev= prev->next;
				}

				else{
					break;
				}
				
			}
			new_node->next = prev->next;
			prev->next = new_node;
	}
		}
		

	else{
		head = new_node;

	}
	

}

void removeNode(int data) 
{

	Node* prev = head;
	
	if(prev->data == data){
		head = prev->next;
	}
	else{
		while(prev->next->data != data && prev->next->next!=nullptr){

			prev = prev->next;
		}

		if(prev->next->data == data){
			Node* target = prev->next;
			if(target->next != nullptr){
				prev->next = target->next;
			}
			else{
				prev->next =nullptr;
			}
		}

	}	
}

int getList(int output[MAX_NODE]) 
{
	Node* temp = head;
	int tempCnt=0;
	while(1){
		output[tempCnt++] = temp->data;
		if(temp->next == nullptr){
			break;
		}
		temp = temp->next;
	}

	return tempCnt;
}