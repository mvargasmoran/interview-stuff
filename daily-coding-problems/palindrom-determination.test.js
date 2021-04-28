const palindromeDet = require('./palindrome-determination.js');
test('determines whether a dooubly linked list is a palindrom', () => {
  expect(palindromeDet([1,4,3,4,1])).toBe(true);
  expect(palindromeDet([1,4])).toBe(false);
});
