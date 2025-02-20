function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
    
};

function bubblesort(num: number[], size): number[]{
    for(let step = 0;  step < size - 1; step++){
        let swapped: boolean = false;
        for(let i = 0; i < step - size -1; i++){
            if(number[i] < number[i + 1]){
                let temp = number[i];
                number[i] = number[i + 1];
                number[i + 1] = temp;
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}