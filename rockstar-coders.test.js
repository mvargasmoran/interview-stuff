const getThirdMostCommon = require('./rockstar-coders.js');

test('returns B as third most common', () => {
  expect(getThirdMostCommon("ABCDBCDCDD")).toBe('B');
  expect(getThirdMostCommon("CBBAAA")).toBe('C');
  expect(getThirdMostCommon("AAABBBCCC")).toBe(null);
  expect(getThirdMostCommon("AAABB")).toBe(null);
  expect(getThirdMostCommon("AAABBCCCDDEEEFG")).toBe('F/G');
  expect(getThirdMostCommon("AAABBCCCDDEEEFGHZZXXYY")).toBe('F/G/H');
});

