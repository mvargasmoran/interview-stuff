/**
  * Determine if a number is happy
  *
  * A happy number is a number defined by the following process:
  * Starting with any positive integer, replace the number by the sum
  * of the squares of its digits, and repeat the process until the
  * number equals 1 (where it will stay), or it loops endlessly in a
  * cycle which does not include 1.
  * Those numbers for which this process ends in a are happy.
  *
  */
const getDigits = (number) => {
  return number.toString().split('').map(Number);
}

const isHappy = (candidate) => {
  let visited = [];
  while (true) {
    let digits = getDigits(candidate);
    candidate = digits.reduce((reduced, current) => {
      return reduced + current * current;
    }, 0);

    if (candidate === 1) {
      return true;
    }
    if (visited.includes(candidate)) {
      return false;
    }
    visited.push(candidate);
  }
}

console.log(isHappy(19));

