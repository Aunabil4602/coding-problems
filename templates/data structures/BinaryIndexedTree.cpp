int query(int index){
    int sum = 0;
    while(index>0){
        sum+=dp[index];
        index-=(index&-index);
    }
    return sum;
}

void update(int index, int value){
    while(indexd<dp.size()){
        dp[index]+=value;
        index+=(index&-index);
    }
}
