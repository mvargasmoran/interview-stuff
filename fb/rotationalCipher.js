// Add any extra import statements you may need here


// Add any helper functions you may need here
function charReplacement(cipherSet, item, rotationFactor) {
  let replacedItem;
  let replacementIndex = 0;
  let keyPos = cipherSet.indexOf(item);
  let cipherLength = cipherSet.length;
  let rot = rotationFactor;
  if (rotationFactor > cipherLength) {
    rot %= cipherLength;
  }

  let shouldMoveForward = (+keyPos + rot) <= (cipherLength - 1);
  if (shouldMoveForward) {
    replacementIndex = +keyPos + rot;
  } else {
    replacementIndex = (+keyPos + rot) - cipherLength;
  }

  replacedItem = cipherSet[replacementIndex];

  return replacedItem;
}

function rotationalCipher(input, rotationFactor) {
  // Write your code here
  const alphabet = 'abcdefghijklmnopqrstuvwxyz'.split('');
  const ALPHABET = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'.split('');
  const numbers = '0123456789'.split('');
  const inputArray = input.split('');

  let rotated = inputArray.map(item => item.replace(/./g, ''));
  for (let index = 0; index < inputArray.length; index++) {
    if (!inputArray[index].match(/[a-zA-Z0-9]/)) {
      rotated[index] = inputArray[index];
      continue;
    }

    let replacedItem;

    // use module operator to get the real offset
    if (inputArray[index].match(/[0-9]/)) {
      replacedItem = charReplacement(numbers, inputArray[index], rotationFactor);
    }

    if (inputArray[index].match(/[a-z]/)) {
      replacedItem = charReplacement(alphabet, inputArray[index], rotationFactor);
    }

    if (inputArray[index].match(/[A-Z]/)) {
      replacedItem = charReplacement(ALPHABET, inputArray[index], rotationFactor);
    }
    rotated[index] = replacedItem;
  }
  console.log(rotated.join(''));

  return rotated.join('');
}










// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!
function printString(str) {
  var out = '["' + str + '"]';
  return out;
}

var test_case_number = 1;

function check(expected, output) {
  var result = (expected == output);
  var rightTick = "\u2713";
  var wrongTick = "\u2717";
  var out;
  if (result) {
    out = rightTick + ' Test #' + test_case_number;
    console.log(out);
  }
  else {
    out = '';
    out += wrongTick + ' Test #' + test_case_number + ': Expected ';
    out += printString(expected);
    out += ' Your output: ';
    out += printString(output);
    console.log(out);
  }
  test_case_number++;
}

var input_1 = "All-convoYs-9-be:Alert1.";
var rotationFactor_1 = 4;
var expected_1 = "Epp-gsrzsCw-3-fi:Epivx5.";
var output_1 = rotationalCipher(input_1, rotationFactor_1);
check(expected_1, output_1);

var input_2 = "abcdZXYzxy-999.@";
var rotationFactor_2 = 200;
var expected_2 = "stuvRPQrpq-999.@";
var output_2 = rotationalCipher(input_2, rotationFactor_2);
check(expected_2, output_2);

// Add your own test cases here



var input_3 = "xyz";
var rotationFactor_3 = 3;
var expected_3 = "abc";
var output_3 = rotationalCipher(input_3, rotationFactor_3);
check(expected_3, output_3);
