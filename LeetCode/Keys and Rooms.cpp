//O(n+v)

int flag[1005];

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int roomsLength = rooms.size();
        
        if(roomsLength<=1){
            return 1;
        }
        
        for(int i=0;i<roomsLength;i++){
            flag[i]=0;
        }
        
        queue<int> q;
        q.push(0);
        flag[0]=1;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            
            for(int i=0;i<rooms[current].size();i++){
                if(flag[rooms[current][i]]==0){
                    flag[rooms[current][i]]=1;
                    q.push(rooms[current][i]);
                }
            }
        }
        for(int i=0;i<roomsLength;i++){
            if(!flag[i])return 0;
        }
        return 1;
        
    }
};
