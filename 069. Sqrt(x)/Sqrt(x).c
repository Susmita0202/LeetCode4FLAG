int mySqrt(int x) {
    if(x<2){
        return x;
    }
    int max=x, min=1;
    while(min<=max){
        int mid=min+((max-min)/2);
        if(mid== x/mid){
            return mid;
        }
        else if(mid< x/mid){
            min=mid+1;
        }else{
            max=mid-1;
        }
    }
    return max;
}
