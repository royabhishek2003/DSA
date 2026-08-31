
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first=-1;
        int secondlast=-1;
        int last=-1;
        int mindis=INT_MAX;
        ListNode* prev= head;
        ListNode* curr= head->next;
        int count=1;
        while(curr->next){
            if(curr->val > prev->val && curr->val > curr->next->val){
                if(secondlast == -1){
                    secondlast=count;
                    first=secondlast;
                }
                else if(last == -1){
                    mindis= min(mindis, count - secondlast);
                    last=count;
                }else{
                    secondlast= last;
                    last=count;
                    mindis= min(mindis,count-secondlast);
                }
                
            }
            else if(curr->val < prev->val && curr->val < curr->next->val){
                if(secondlast == -1){
                    secondlast=count;
                    first=secondlast;
                }
                else if(last == -1){
                    mindis= min(mindis, count - secondlast);
                    last=count;
                }else{
                    secondlast= last;
                    last=count;
                    mindis= min(mindis,count-secondlast);
                }
            }
            count+=1;
            curr= curr->next;
            prev= prev->next;
        }
        if(last == -1){
            return {-1,-1};
        }
        return {mindis, last - first};
    }
};