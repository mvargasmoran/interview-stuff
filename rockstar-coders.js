/*

    Create a function that counts how many times each chars appears in a string a return the third most common

    Ex.
        ABCDBCDCDD -> B (A1, B2, C3, D4)
        CBBAAA -> C
        AAABBBCCC -> null
        AAABB -> null
        AAABBCCCDDEEEFG -> F/G (A3,B2,C3,D2,E3,F1,G1)
*/


function getThirdMostCommon(txt) {
  let mostCommon = null;
  const charArray = Array.from(txt);

  let charCount = {};
  charArray.forEach((char) => {
    if(charCount[char]) {
      charCount[char] += 1;
      return;
    }
    charCount[char] = 1;
  });

  const sortingArray = [];

  Object.entries(charCount).forEach(([key, val]) => {
    sortingArray.push({
      char: key,
      count: val,
    });
  });

  let groupedQuantities = [];
  sortingArray.map((charCount) => {
    if(!groupedQuantities['group-'+charCount.count]) {
      groupedQuantities['group-'+charCount.count] = [];
    }
    groupedQuantities['group-'+charCount.count].push(charCount);
  });

  let groupedQuantitiesValues = Object.values(groupedQuantities);

  groupedQuantitiesValues.sort((last, current) => {
    return last[0].count >= current[0].count;
  });
  groupedQuantitiesValues.sort((last, current) => {
    return last.length <= current.length
  });

  let answer = [];
  if(groupedQuantitiesValues[2]) {
    if (groupedQuantitiesValues[2].length >= 1) {
      groupedQuantitiesValues[2].map((currentVal) => {

        answer.push(currentVal.char);
      }, '');
    } else {
      answer.push(groupedQuantitiesValues[2][0].char);
    }
  } else {
    answer = null;
  }

  answer = answer ? answer.join('/') : answer;

  return answer;
}


module.exports = getThirdMostCommon;
