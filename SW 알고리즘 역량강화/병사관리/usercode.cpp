#define MAX_SOLDIER 100000

struct Soldier{
    int id;
    int team;
    int score;
    Soldier* next;
};

Soldier soldier[MAX_SOLDIER];
int soldierCnt;
Soldier head;

Soldier* getsoldier(int mID, int mTeam, int mScore){
    soldier[soldierCnt].id = mID;
    soldier[soldierCnt].team = mTeam;
    soldier[soldierCnt].score =mScore;

    return &soldier[soldierCnt++];

}

void init()
{
    soldierCnt = 0;
    head.next = nullptr;

}

void hire(int mID, int mTeam, int mScore)
{
    Soldier* new_soldier = getsoldier(mID, mTeam, mScore);
    new_soldier->next = head.next;
    head.next = new_soldier;
}

void fire(int mID)
{
    Soldier* prev = &head;

    while(prev->next->id != mID){
        prev = prev->next;
    }


    prev->next = prev->next->next;
}

void updateSoldier(int mID, int mScore)
{
    Soldier* temp = head.next;
    while(temp->id != mID){
        temp = temp->next;
    }


    temp->score = mScore;

}

void updateTeam(int mTeam, int mChangeScore)
{
    Soldier* temp = head.next;
    while(temp != nullptr){
        if(temp->team == mTeam){
            
            if((temp->score)+mChangeScore > 5){
                temp->score = 5;
            }

            else if((temp->score)+mChangeScore < 1){
                temp->score = 1;
            }

            else{
                temp->score = (temp->score)+mChangeScore;
            }

        }

        temp = temp->next;
    }
}

int bestSoldier(int mTeam)
{
    Soldier* temp = head.next;
    int max_score = 0;
    int sID;
    while(temp != nullptr){
        if(temp->team == mTeam){
            if(temp->score > max_score){
                max_score = temp->score;
                sID = temp->id;
            }

            else if((temp->score) == max_score && temp->id > sID){
                sID = temp->id;
            }
        }

        temp = temp->next;
    }

    return sID;
}