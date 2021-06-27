// Determine if any 3 integers in an array sum to 0.


let result = 0;
let candidates = [];
for (let index = 0; index < 3; index++) {
  if (inputArray[index]
  result = inputArray[index];

}
let isZero = (result === 0);


[7, 10, 3, -1, 3, -2] = True(-1, 3, -2)

[7, 10, 3, 1, 0] = False ti














// You are given an array of integers. Write an algorithm that brings all nonzero elements to the left of the array, and returns the number of nonzero elements. The algorithm should operate in place, i.e. shouldn't create a new array. The order of the nonzero elements does not matter. The numbers that remain in the right portion of the array can be anything.


// Example: given the array [ 1, 0, 2, 0, 0, 3, 4 ], a possible answer is [ 4, 1, 3, 2, ?, ?, ? ], 4 non-zero elements, where "?" can be any number.


inputArray = [1, 0, 2, 0, 0, 3, 4];
let swap;
for (let index = inputArray.length - 1; index < 0; i--) {
  if (inputArray[index] === 0) {

    for (let j = 0; inputArray.length - 1; index++) {
      if (!inputArray[index - 1] === 0) {
        swap = inputArray[0];
        inputArray[0] = inputArray[index];
        inputArray[index] = 0;
      }
    }
  }
}




