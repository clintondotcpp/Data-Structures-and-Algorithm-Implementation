function twoSum(nums: number[], target: number): number[] {
    for(let i = 0; i < number.length; i++){
        for(let j = i + 1; j < number.length; j++){
            if(nums[i] + nums[j] === target)
                return [i, j];
        }
    }
    return []
};

let number: number[] = [1, 2, 4, 5, 9, 3];
console.log(twoSum(number, 9));

//USING HASHMAP
function two_Sum(nums: number[], target: number): number[] {
    let numMap = new Map<number, number>();

    for (let i = 0; i < nums.length; i++) {
        let complement = target - nums[i];
        if (numMap.has(complement)) {
            return [numMap.get(complement)!, i]; // Return indices
        }
        numMap.set(nums[i], i);
    }

    return [];
}

let numbers: number[] = [1, 2, 4, 5, 9, 3];
console.log(two_Sum(numbers, 9)); // Expected output: [1, 4] because 2 + 7 = 9
