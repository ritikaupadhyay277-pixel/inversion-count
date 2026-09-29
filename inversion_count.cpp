
class Solution {
public:
 // merge sort
 int merge (vector<int>&arr, int low, int mid,int high) {
    vector<int>temp; 
    int left= low;
    int ryt= mid+1 ; 
    long long count =0; 

    while(left<=mid && ryt <=high){
        if(arr[left]<=arr[ryt]){
            temp.push_back(arr[left]);
                left++ ; 
        }
         // ryt array is smaller 
        else {
            temp.push_back(arr[ryt]) ;
            count += (mid-left+1) ; 
            ryt++ ; 
        }
    }
    // left array got exhausted first but ryt is still left
    while (ryt<=high) {
        temp.push_back(arr[ryt]);
        ryt++ ; 
    }

    while (left <=mid){
        temp.push_back(arr[left]);
          left++ ;
    }
    for(int i =low; i<=high; i++){
        arr[i]=temp[i-low];
       
    }
     return count;
    
}

int ms (vector<int>&arr, int low, int high ) {
    long long int count =0; 
    if(low==high) return count ;  // only one element left, array exhausted 
    int mid = (low+high)/2;
    
    // dividing
    count+= ms (arr,low,mid);       // handles the left part
    count+= ms (arr,mid+1,high);    // handles ryt part
    //merging
    count+= merge (arr,low,mid,high); 
    return count;


 }
   long long int numberOfInversions(vector<int> nums) {
    int n = nums.size();
    long long int count=0; 
    count= ms(nums,0,n-1);
       return count; }
    };
