void merge_sort(int start,int end){
    if(start>=end){
        return;
    }
    int start1=start,end1=(start+end)/2,start2=end1+1,end2=end;
    merge_sort(start1,end1);
    merge_sort(start2,end2);
    int k=start;
    while(start1<=end1&&start2<=end2){
        arr[k++]=a[start1]<a[start2]?a[start1++]:a[start2++];
    }
    while(start1<=end1){
        arr[k++]=a[start1++];
    }
    while(start2<=end2){
        arr[k++]=a[start2++];
    }
    for(int i=start;i<=end;i++){
        a[i]=arr[i];
    }
}