// suppose an array like this [[],[],[],],here k = 3 and size of array is 0
if(arr.size() == 0) // if their is no element i.e zero element
return NULL;
sort(arr.begin(), arr.end()); // sort the vector on the basis of values
// start making links b/w the elements of vector
for(int i = 0; i < arr.size() - 1; i++)
{
arr[i].second -> next = arr[i + 1].second;
}
// in the next of last node put NULL
arr[arr.size() - 1].second -> next = NULL;
return arr[0].second; // return first node of the vector
}
};
​
**Solution - II (Further optimization in time as well as in space, Using priority queue, Accepted)-**
​
Now, we want to become a good programmer and anyhow we want to optimize our soloution.
The main point is to observe here is that every linked list is already sorted and our task is just to merge them.
Our approach to merge linked list is same as about merge function of merge sort.
In merge sort, we have just two arrays / linked list but here we have 'k' linked list.
So by using min heap we compare k node values and add the smallest one to the final list.
One property of min heap we have to remember here is that, it keeps smallest element always on the top, so using that property we merge our k sorted linked list.
Suppose if total number of nodes present in all linked list is 'n'
Time Complexity --> O(n log k) // as we are using min heap
Space Complexity --> O(k) // at a single point of time min heap always handle the k elements
It paases [ 133 / 133] in built test cases
Code (C++)
​
/**
* Definition for singly-linked list.