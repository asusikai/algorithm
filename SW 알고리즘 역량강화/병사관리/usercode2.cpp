#define MAX_SOLDIER 100000

struct Soldier{
    int id;
    int team;
    int score;
    Soldier* next;
};
Soldier soldier[MAX_SOLDIER];
Soldier head[5];
int soldierCnt;
void init()
{
    for(int i=0; i<5; i++){
        head[i].next = nullptr;
    }
    soldierCnt = 0;

}

Soldier* getsoldier(int mID, int mTeam, int mScore){
    soldier[soldierCnt].id = mID;
    soldier[soldierCnt].team = mTeam;
    soldier[soldierCnt].score =mScore;

    return &soldier[soldierCnt++];

}

void hire(int mID, int mTeam, int mScore)
{
    Soldier* new_soldier = getsoldier(mID, mTeam, mScore);
    new_soldier->next = head[mTeam-1].next;
    head[mTeam-1].next = new_soldier;
}

void fire(int mID)
{
    Soldier* prev;
    int flag = 0;

    for(int i=0; i<5; i++){
        prev = &head[i];

        while(prev->next->id != mID && prev->next!=nullptr){
            prev = prev->next;
        }

        if(prev->next!=nullptr){
            prev->next = prev->next->next;
            flag = 1;
        }

        if(flag == 1){
            break;
        }
    }    
}

void updateSoldier(int mID, int mScore)
{
    Soldier* temp;
    int flag = 0;
    for(int i = 0; i<5; i++){
        temp = head[i].next;
        while(temp->id != mID && temp->next != nullptr){
            temp = temp->next;
        }

        if(temp->id == mID){
            temp->score = mScore;
            flag = 1;
        }

        if(flag == 1){
            break;
        }
    }
}

void updateTeam(int mTeam, int mChangeScore)
{
    Soldier* temp = head[mTeam-1].next;

    while(temp != nullptr){
        if(temp->score + mChangeScore > 5){
            temp->score = 5;
        }

        else if(temp->score + mChangeScore < 1){
            temp->score = 1;
        }

        else{
            temp->score = temp->score + mChangeScore;
        }

        temp = temp->next;
    }

}

int bestSoldier(int mTeam)
{
    Soldier* temp = head[mTeam-1].next;
    
    int high_score = 0;
    int sID;

    while(temp!= nullptr){
        if(temp->score > high_score){
            high_score = temp->score;
            sID = temp->id;
        }

        else if(temp->score == high_score && temp->id > sID){
            sID = temp->id;
        }

        temp = temp->next;
    }
    return sID;

    return 0;
}