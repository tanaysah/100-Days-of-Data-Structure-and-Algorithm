//You are given an integer array arr[]. You need to find the maximum sum of a subarray (containing at least one element) in the array arr[].
//tanaysah

int maxSubarraySum(int arr[], int n) {
    int maxSum = arr[0];
    int currSum = arr[0];

    for (int i = 1; i < n; i++) {
        if (currSum < 0)
            currSum = arr[i];
        else
            currSum += arr[i];

        if (currSum > maxSum)
            maxSum = currSum;
    }

    return maxSum;
}
