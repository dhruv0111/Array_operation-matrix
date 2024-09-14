//DoLeetcode Everyday
#include<iostream>
#include<vector>
#include<limits.h>
#include<unordered_map>
#include<set>
using namespace std;

void TransposeMatrix(int arr[][3], int rows, int col, int Transporse[][3]){
    for(int i =0;i<rows;i++){
        for(int j = 0;j<col;j++){
            // swap(arr[i][j],arr[j][i]);
            Transporse[i][j]=arr[j][i];
        }
        
    }
}

void RotateMatrixBy90(int arr[][3],int N){
    for(int i = 0;i<N/2;i++){
        for(int j = i;j < N - i -1;j++){
            //Swap element of each cycle
            //Store First element of row and col in temp variable
            int temp = arr[i][j];
            //Store bottom of Left into top of left
            arr[i][j] = arr[N-1-j][i];
            //Stoe bottom of right into bottom of left
            arr[N - 1 -j][i] = arr[N-1-i][N-1-j];
            //Store top of right into bottom of right
            arr[N-1-i][N-1-j] = arr[j][N-1-i];
            //Store bottom of left into top of left
            arr[j][N-1-i] = temp;
        }
    }
    
}

void DisplayMatrix(int arr[][3], int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<arr[i][j]<<" ";
        
        }
        cout<<endl;
    }
}

void InplaceRotate(int arr[][4], int N){
    for(int i = 0;i<N/2;i++){
        for(int j =i;j<N-i-1;j++){
            //Step1: store current element in the temp;
            int temp = arr[i][j];
            //Step2: movel values from right to left means arr[0][3] into arr[0][0];
            arr[i][j] = arr[j][N-1-i];
            //Step2: move values from bottom to right ;
            arr[j][N-1-i] = arr[N-1-i][N-1-j];
            //Step4:move values to Left to Right
            arr[N-1-i][N-1-j] = arr[N-1-j][i];
            //Step5: put value of temp vaiable
            arr[N-1-j][i] = temp;
        }
    }
    //print matrix
    // DisplayMatrix(arr,N);
}

void SortZeroONeTwo(vector<int>&v,int size){

    int low =0;
    int high = size -1;
    int i=0;
    while (i<=high)
    {
        if(v[i] ==0){
            swap(v[low],v[i]);
            low++;
            i++;
        }
        else if (v[i] ==1)
        {
            i++;
        }
        else{
            swap(v[i],v[high]);
            high--;
        
        }
        
    }
    for(int i=0;i<size;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
}

void negativeNumberLeftSide(vector<int>&v, int size){
    int low = 0;
    int i = 0;//traverse the vector
    while(i<=size){
        if(v[i]<0){
            swap(v[i],v[low]);
            i++;
            low++;
        }
        else{
            swap(v[low],v[i]);
            i++;
        }
    }
   
}

int findDuplicate(vector<int>&v, int size){
    int mark = -1;
    int i =0;
    while(i<=size){
        int index = abs(v[i]);
        if(v[v[i]]<0){
            return index;
        }
        v[index] *=-1;
        i++;
    }
    return mark;
}

void missingElement(vector<int>v, int size){
    //Visited method
    vector<bool>visited(size + 1, false);
    int repeating = -1;
    int missing = -1;

    for(int i = 0;i<size;i++){
        if(visited[v[i]]){
            repeating = v[i];
        }
        else{
            visited[v[i]] = true;
        }
    }

    for(int i = 1;i<=size;i++){
        if(!visited[i]){
            missing = i;
            break;
        }
    }
    cout<<"Repeating element is"<<repeating<<endl;
    cout<<"Missing : "<<missing<<endl;

}

int findRepeatingElement(vector<int>arr, int size){
    //Double LOOP -> It has T.C = O(n2)
    // for(int i = 0;i<size;i++){
    //     for(int j = i+1;j<size;j++){
    //         if(arr[i]==arr[j]){
    //             return arr[i];
    //         }
    //     }
    // }

    //using Hashed method
    unordered_map<int,int>hash;
    //This loop store the value of occurence of element
    for(int i =0;i<size;i++){
        hash[arr[i]]++;
    }

    for(int i =0;i<size;i++){
        if(hash[arr[i]] > 1){
            return i + 1;
        }
    }
    return -1;

}

vector<int> commonElementIn3SortedArray(vector<int>arr,vector<int>brr,vector<int>crr, int sizeA,int sizeB, int sizeC){
    //Using Set here
    vector<int>ans;
    set<int>st;
    int i=0, j=0, k = 0;
    while(i<sizeA && j<sizeB && k<sizeC){
        if(arr[i] == brr[j] && brr[j] == crr[k]){
            st.insert(arr[i]);
            i++, j++,k++;
        }
        else if(arr[i]<brr[j]){
            i++;
        }
        else if(brr[j]<crr[k]){
            j++;
        }
        else{
            k++;
        }
    }
    for(auto i: st){
        ans.push_back(i);
    }
    return ans;
}

void waveMatrix(vector<vector<int>>arr,int rows, int cols){
    for(int i = 0;i<cols;i++){
        if((i & 1)==0){
            for(int j =0;j<rows;j++){
                cout<<arr[j][i]<<" ";
            }
        }
        else{
            for(int j =rows -1;j>=0;j--){
                cout<<arr[j][i]<<" ";
            }
        }
    }

}

vector<int> spiralMatrix(vector<vector<int>>arr,int rows, int cols){
    vector<int>ans;
    int total_Element = rows*cols;
    int startingRow = 0;
    int endingCol = cols -1;
    int endingRow = rows -1;
    int startingCol = 0;

    int Count =0;
    while(Count < total_Element){
        //Print Starting Row
        for(int i =startingCol;i<=endingCol && Count<total_Element;i++){
            ans.push_back(arr[startingRow][i]);
            Count++;
        }
        startingRow++;
        //Print EndingCol
        for(int i = startingRow;i<=endingRow && Count<total_Element;i++){
            ans.push_back(arr[i][endingCol]);
            Count++;
        }
        endingCol--;
        //Print endingRow
        for(int i = endingCol;i>=startingCol && Count<total_Element;i--){
            ans.push_back(arr[endingRow][i]);
            Count++;
        }
        endingRow--;
        //Print starting Col
        for(int i = endingRow;i>=startingRow && Count<total_Element;i--){
            ans.push_back(arr[i][startingCol]);
            Count++;
        }
        startingCol++;
    }
    return ans;
}

void DiplayVector(vector<int>v,int size){
    for(int i=0;i<size;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){

    //Spriral Matrix
    // vector<vector<int>>arr = {{1,2,3},{4,5,6},{7,8,9}};
    // int rows = arr.size();
    // int cols = arr[0].size();
    // vector<int> ans =  spiralMatrix(arr,rows, cols);
    // cout<<"Here is Sprial Print of Matrix"<<endl;
    // DiplayVector(ans, ans.size());

    //Wave Print a Matrix
    // vector<vector<int>>arr = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    // int rows = arr.size();
    // int cols = arr[0].size();
    // waveMatrix(arr, rows,cols);

    //Common Elements in 3 Sorted Array
    // vector<int>arr = {1, 5, 10, 20, 40, 80};
    // vector<int>brr = {6, 7, 20, 80, 100};
    // vector<int>crr = {3, 4, 15, 20, 30, 70, 80, 120};
    // int sizeA = arr.size();
    // int sizeB = brr.size();
    // int sizeC = crr.size();
    // vector<int>ans = commonElementIn3SortedArray(arr,brr,crr, sizeA, sizeB, sizeC);
    // for(int i =0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }

     //First Repeatiang element
    //  vector<int>arr = {1,5,3,4,3,6};
    //  int size = arr.size();
    //  int ans = findRepeatingElement(arr,size);
    //  cout<<"First Repeating Elemnet is "<<ans;

    //Missing Element from an array
    // vector<int>v= {1,3,4,3,5};
    // int size = v.size();
    // missingElement(v,size);

    //Find the duplicate in array
    // vector<int>v = {1,2,3,4,2};
    // int size = v.size() -1;
    // int ans = findDuplicate(v,size);
    // cout<<"Duplicate number is"<<ans;
    // cout<<endl;

    //Move -ve number left side of array i
    // vector<int>v= {1,0,20,-7,8,-5,-11,9};
    // int size = v.size() - 1;
    // negativeNumberLeftSide(v,size);
    // DiplayVector(v,size);

    // //Sort 0,1,2
    // vector<int>vec {0,1,0,0,2,0};
    // int size = vec.size(); 
    // SortZeroONeTwo(vec,size);
    // cout<<"Sort Zero, One and Two"<<endl;

    // Rotate Matrix by 90 degree in clockwise direction
    // int arr[3][3] = {{1,2,3}, {4, 5, 6}, {7, 8, 9}};
    // int N = 3;
    // cout<<"Matrix before Rotate"<<endl;
    // DisplayMatrix(arr,N);
    // RotateMatrixBy90(arr, N);
    // cout<<"Rotate Matrix "<<;endl;
    // DisplayMatrix(arr,N);

    // Inplace rotate square matrix by 90 degrees by forming cycles:
    // int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    // int N = 4;
    // InplaceRotate(arr,N);
    // DisplayMatrix(arr,N);

    //Transpose Matrix
    // int arr[3][3] = {{2,4,6}, {1, 3, 5}, {9,11,13}};
    // int rows = 3;
    // int col = 3;
    // int Transporse[3][3];
    // cout<<"Print 2D matrix"<<endl;
    // for(int i =0;i<rows;i++){
    //     for(int j=0;j<col;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // TransposeMatrix(arr,rows, col,Transporse);
    // cout<<"Transpose Matrix is"<<endl;
    // for(int i =0;i<rows;i++){
    //     for(int j =0;j<col;j++){
    //         cout<<Transporse[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}